#!/usr/bin/ruby
index = <<EOF
<!DOCTYPE html>

<html>
	<head>
		<meta charset="UTF-8">
		<title>The Problem with the Mainstream Engineering Establishment</title>
		<link rel='stylesheet' href='css.css'>
	</head>

	<body>

		<h1>Articles &ndash; Read In Order</h1>
		
		<ul>
%s
		</ul>
	</body>
</html>
EOF

list = []
Dir.glob("*.html") do |i|
  if i != "index.html"
    raise i unless i.match?(/^\d+\.html$/)
  else
    next
  end

  i = i.to_i

  list << i
end

list.sort!
titles = []

list.each_with_index do |i, index|
  index += 1
  raise unless i == index
end

puts list.max
list.each do |i|
  prev = i - 1
  if prev == 0
    prev = "index"
  end
  next_ = i + 1
  if next_ == 17
    next_ = "index"
  end

  end_ = "<div class='article_link'><a href=\"#{prev}.html\">Previous article</a>
<a href=\"#{next_}.html\">Next article</a></div>
</body>
</html>"
  text = File.read(i.to_s + ".html")
  v = text.gsub(/(<\/body|<\/html>).*/, "").gsub(/^\s*<a href=\"\d+.html\">.*/, "").gsub(/<div class='article_link'>.*/, "").strip
  if i == 11
    v = "<!DOCTYPE html>
<html>
<head>
<meta charset=\"UTF-8\">
<title>The Solution of Foundationallib</title>
<link rel='stylesheet' href='css.css'>
</head>
<body>
<h1>The Solution of Foundationallib</h1>
<h2>By G.C.</h2>"
    v += "\n" * 20
    v += File.read("../README.md")
  end

  v = v.gsub /!\[Alt text\]\((.*?)\)/ do |q|
    "<img src=#{($1).dump} />"
  end

  v << end_.strip

  File.write i.to_s + ".html", v
  title = nil
  text.scan(/<title>(.*?)<\/title>/) do |i|
    title = $1
  end

  titles << [i, title]
end

fmt = ""
titles.each do |i|
  fmt << ("            <li style=\"padding:12px;\"><a href=\"%s.html\">%s</a></li>\n" % i)
end
File.write("index.html", index % fmt)
