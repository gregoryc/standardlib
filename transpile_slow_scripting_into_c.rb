#!/usr/bin/env ruby
#
#
#
# transpile_slow_scripting_into_c.rb
# Usage: transpile_slow_into_c.rb <file-to-transpile> <out-file [/dev/stdout] by default>

# The output then has helpful comments to allow you to easily transpile the scripting language into fast C, either with ChatGPT or manually.
# This is an invaluable resource to help you speed up code - in general.
# And the C functions in this library are very very fast and tested.
#
# I would appreciate someone making this script longer and better to acommodate for more languages.
# That would be a great contribution. Please email me <gregorycohennew@gmail.com>.
#
#
# It would be great if this took an OpenAI API key and then used GPT4 to transpile.
# Could do a hell of a good and safe job - because these functions are really obvious how they work and have exceptional error handling.
#

def green(str = "", file = STDOUT)
  if file.tty?
    green = "\033[0;32m"
    nc = "\033[0m" # No Color
    file.puts green << str << nc << "\n"
  else
    file.puts str
  end
end

if ARGV.size != 1 && ARGV.size != 2
  GREEN = '\033[0;32m'
  NC = '\033[0m' # No Color
  green "transpile_slow_into_c.rb"
  green
  green "Usage: transpile_slow_into_c.rb <file-to-transpile> <out-file [/dev/stdout] by default>"
  green
  green
  green "The output then has helpful comments to allow you to easily transpile the scripting language into fast C, either with ChatGPT or manually."
  green "This is an invaluable resource to help you speed up code - in general."

  green "And the C functions in this library are very very fast and tested."

  green

  green "I would appreciate someone making this script longer and better to acommodate for more languages."

  green "That would be a great contribution. Please email me <gregorycohennew@gmail.com>."
  green
  green "It would be great if this took an OpenAI API key and then used GPT4 to transpile."
  green "Could do a hell of a good and safe job - because these functions are really obvious how they work and have exceptional error handling."

  exit 1
end
outfile = ARGV[1] || "/dev/stdout"
green("Writing to #{outfile}", file = STDERR)

H = File.read(`find -name HEADERS_ONLY_FUNCTIONS.h`.chomp("\n"))
H_LINES = H.split("\n")
$out = String.new

def puts(str = "")
  $out << str << "\n"
end

$comments = 0
in_ = File.read(ARGV.first)

def tr(*a)
  $comments += 1
  first = a.shift.split(/\s+OR\s+/i)
  rest = a.flatten
  if rest.size > 1
    q = "#                     "
    q2 = q + "    "
    newline = "\n"
  else
    q = ""
    q2 = ""
    newline = " "
  end

  num = 0

  first = first.map do |i|
    res = String.new
    if first.size > 1
      #num += 1
      #res << num.to_s << ". "
    end
    res + i + "()"
  end.join(" or ")

  num = 0

  rest = rest.map do |i|
    if i.class == Array
      raise rest.to_s
    end
    res = String.new
    if rest.size > 1
      num += 1
      res << num.to_s << ". "
    end
    res << i.chomp(";")

    if rest.size > 1
      res << "\n"
    else
      res << " "
    end

    res << q
  end.join(" or ")

  "    # Transpile #{first} with | #{newline}" << q2 << (rest) << " as appropriate."
end

line_n = 0
in_.each_line do |line|
  line_n += 1
  if line_n == 2
    require "shellwords"
    puts "# Generated from #{File.basename __FILE__}"
    nlines = "#\n" + `echo #{"Allows for easy transpilation from slow languages that hinder people's lives in many ways (scriping languages) into machine-efficient code that actually runs the same operations without wasting CPU power, electricity, money, time, user's (programmer's) programmatic interactivity (ability to quickly run and recompile near-instantly) or people's attention, and is somewhat ideal.".shellescape}  | fmt -w 78`
    nlines << "\n" << `echo #{"You can easily (manually, or with AI) transpile this code now into code that actually runs fast - and actually compiles quickly (C++, Crystal and Rust can't do this and are awful at it, especially the latter two - Zig maybe is good); is safe; has good error handling; and performs the intended operations, with ease.".shellescape}  | fmt -w 78`
    nlines.gsub! "\n", "\n# "

    puts nlines
    nlines = nil
  end

  newline = line.chomp("\n")
  if newline.strip == ""
    puts
    next
  end

  if (newline.include? "length") || (newline.include? "size")
    newline << tr("length or size", (["strlen()"] + H_LINES.grep(/_size\(/)))
  end

  if newline.include? "replace"
    newline << tr("replace", H_LINES.grep(/replace_all\(/))
  end
  if newline.include? "uniq"
    newline << tr("uniq", H_LINES.grep(/uniq\(/))
  end

  # PHP
  if newline.include? "file_get_contents"
    newline << tr("file_get_contents", H_LINES.grep(/read_file_into_array\(/))
  end

  # Python, Ruby
  if newline.include? "readlines"
    newline << tr("readlines", H_LINES.grep(/read_file_into_array\(/))
  end

  # Ruby
  if newline.include? "File.read"
    newline << tr("File.read", H_LINES.grep(/read_file_into_string\(/))
  end

  if newline.include? "sort"
    newline << tr("sort", H_LINES.grep(/sort(?:ed)?_long_longs\(/)).chomp("\n").chomp(".") + " or similar functions depending on the type name"
  end
  if newline.include? "gsub!"
    newline << tr("gsub!", H_LINES.grep(/replace_all.*\(/))
  elsif newline.include? "gsub"
    newline << tr("gsub", H_LINES.grep(/replace_all.*\(/))
  end

  if newline.include? "delete"
    newline << tr("delete", H_LINES.grep(/del_key\(/))
  end

  if newline.include? "split"
    newline << tr("split", H_LINES.grep(/split\(/))
  end

  if newline.include? "join"
    newline << tr("join", H_LINES.grep(/join\(/))
  end

  if newline.include? "strip"
    newline << tr("strip", H_LINES.grep(/strip\(/))
  end
  if newline.include? "map"
    fs = H_LINES.grep(/filesystem.*\(/)
    newline << tr("map", H_LINES.grep(/map.*\(/) - fs)
  end

  if newline.include? "start_with?"
    newline << tr("start_with?", H_LINES.grep(/starts_with.*\(/))
  end
  if newline.include? "start_with"
    newline << tr("start_with", H_LINES.grep(/starts_with.*\(/))
  end

  if newline.include? "end_with?"
    newline << tr("end_with?", H_LINES.grep(/ends_with.*\(/))
  end

  if newline.include? "end_with"
    newline << tr("end_with", H_LINES.grep(/ends_with.*\(/))
  end
  if newline.include? "starts_with"
    newline << tr("starts_with", H_LINES.grep(/starts_with.*\(/))
  end
  if newline.include? "ends_with"
    newline << tr("ends_with", H_LINES.grep(/ends_with.*\(/))
  end

  if newline.include? "count"
    newline << tr("count", H_LINES.grep(/count.*\(/))
  end

  puts newline
end

File.open(outfile, "w") do |file|
  file.puts $out
end

green("Wrote #{$comments} transpilation comments.", file = STDERR)
