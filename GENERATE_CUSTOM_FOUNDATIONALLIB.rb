#!/usr/bin/env ruby

if ARGV.size != 3
  warn "Generate custom \`foundationallib' library (github.com/gregoryc/foundationallib) with a given prefix to make it customized and to avoid any possibility whatsoever of namespace collisons."
  puts
  warn "Usage #{__FILE__} <origin_header_file> <prefix (e.g., \"l\", \"g\", [your company name], etc.> <custom_header_output_file>"
  exit 1
end
f = File.read(ARGV[0])
PREFIX = ARGV[1]
PREFIX2 = ARGV[1] + "_FOUNDATIONAL_LIB_"
OUTPUT_FILE = ARGV[2]

l = 0
funcs = []
f.each_line do |i|
  l += 1
  while true
    if i.start_with? "FOUNDATIONAL_LIB_FUNC"
      i.split.each do |q|
        if q.include? "("
          i = i.split("{")[0]
          raise i if i.include? "{"
          funcs << [i, q.split("(", 2)[0].gsub("*", "")]
          break
        end
      end
    end
    break
  end
end
dups = (funcs.map do |i|
  i[1]
end.to_a)

dups.each do |i|
  if dups.count(i) > 1
    puts "Dup " + i
  end
end

dups.uniq!

dups.each do |i|
  puts i

  [" ", "*", ")", "("].each do |init|
    f.gsub!(init + i + "(") do |i|
      new = init + (PREFIX + i[1..-2]) + "("
    end

    f.gsub!(init + i + ")") do |i|
      new = init + (PREFIX + i[1..-2]) + ")"
    end

    f.gsub!(init + i + ",", " " + PREFIX + i + ",") do |i|
      new = init + (PREFIX + i[1..-2]) + ","
    end
  end
end

%w[DictKeyValue SetKey FrozenDict Dict FrozenSet Set].each do |i|
  f.gsub! " " + i, " " + PREFIX + i
  f.gsub! PREFIX + PREFIX, PREFIX
end

macros = []

f.each_line do |line|
  line = line[0..-1]

  if line.start_with? "#define"
    line = line["#define ".size..-1]
    if line.size > 1 && line[-1] == "\\"
      line = line[0..-2]
    end

    line = line.split(" ", 2)[0]
    line = line.split("(", 2)[0]

    macros << line
  end
end
macros.delete "_CRT_RAND_S"
puts macros
macros.each do |macro|
  f.gsub! macro, PREFIX + macro
end
File.write OUTPUT_FILE, f
