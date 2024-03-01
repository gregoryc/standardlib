#!/usr/bin/env ruby
def wr(file, data)
  File.write(file, data)

  puts "Wrote #{data.size} to #{file}"
end

begin
  Dir.chdir "tools"
rescue
end

README = <<README
# foundationallib

<h2>Finally, a cross-platform, portable, well-designed, secure, robust, maximally-efficient C foundational library &mdash; Making Engineering And Computing Fast, Secure, Responsive And Easy.</h2>
<br>
<ul class="features-list">
<li><strong>Enables better Engineering Solutions and Security broadly and foundationally where Software Creation or Development or Script Creation is concerned - whether this be on a local, business, governmental or international basis, and makes things easier - and Computing in General.</strong> Don't Reinvent the Wheel - Use Good Wheels - Be Safe And Secure.</li>
<br>
<li><strong>Enables a free-flowing dynamic computer usage that you need, deserve and should have, simply because you have a computer. With full speed and with robustness. You deserve to be able to use your computer wholly and fully, with proper and fast operations.</strong></li>
<br><li><strong>Enables flexibility and power - makes C accessible to the masses (and faster and more secure) with easy usage and strives to bring people up, not degrade the character or actions of people.</strong> This is a fundamental and unequivocal philosophy difference between this library and many subsections of Software Engineering and the mainstream engineering establishment. For instance, in Python, you cannot read a file easily &ndash; you have to read it line-by-line or open a file, read the lines, then close it. With this library, you can efficiently read 10,000 files in one function call. This library gives power. Any common operation, there ought to be a powerful function for.<br><br>We should not bitch around with assembly when we don't want to; we should also have full speed. Some old "solutions" deliver neither, then culturally degrade programmers because their tools are bad - actually, it just degrades programmers, and gives them bad tools. COBOL is an example ...<br><br>Human technology is about empowerment &ndash; people must fight for it to be empowerment, we don't have time to have AI systems kill us because we want to have bad tools and be weak. We must fight.</li>
</ul>
<br>
<ul>
<h2>About Foundationallib</h2>
<li>→<strong>Cross platform</strong> - works perfectly in embedded, server, desktop, and all platforms - tested for Windows and UNIX - 64-bit and 32-bit, includes a 3-aspect test suite, with more to come.</li>
<li>→<strong>Bug free. Reliable. Dependable. Secure. Tested well.</strong></li>
<li>→<strong>Zero Overhead</strong> - Only 1 byte due to the power of the error handling, can be configured will full power.</li>
<li>→<strong>Static Inline Functions if you want them</strong> (optional) - Eliminating function call overhead to 0 if you wish, for improved performance.</li>
<li>→<strong>Custom allocators</strong> - if you want it.</li>
<li>→<strong>Custom error handling</strong> - if you want it.</li>
<li>→<strong>Safe functions</strong> warn the programmer about NULL values and unused return values. Can be configured to not compile if not Secure. Optional null-check macros in every library function. Does not use any of <code>"gets", "fgets", "strcpy", "strcat", "sprintf", "vsprintf", "scanf", "fscanf", "system", "chown", "chmod", "chgrp", "alloca", "execl", "execle", "execlp", "execv", "execve", "execvp", "bcopy", "bzero"</code>. You can configure it to never use any unsafe functions.</li>
<li>→<strong>Portable</strong> - works on all platforms, using platform specific features (using #ifdefs) to make functions better and faster.</li>
<li>→<strong>Multithreading support</strong> (optional), with list_comprehension_multithreaded (accepts any number of threads, works in parallel using portable C11 threads)</li>
<li>→<strong>Networking support</strong> (optional), using libcurl - making it extremely easy to download websites and arrays of websites - features other languages do not have.</li>
<li>→Very good and thorough <strong>Error Handling</strong> and <strong>allocation overflow</strong> checking (good for <strong>Security and Robustness</strong>) in the functions.
Allows the programmer to dynamically choose to catch all errors in the functions with a handler (default or custom), or to ignore them. No need to ALWAYS say "if (.....) if you don't want to. Can be changed at runtime.</li>
<li>→<strong>Public Domain</strong> so you make the code how you want. (No need to "propitiate" to some "god" of some library).</li>
<li>→<strong>Minimal abstractions or indirection of any kind or needless slow things that complicate things</strong> - macros, namespace collision, typedefs, structs, object-orientation messes, slow compilation times, bloat, etc., etc.</li>
<li>→<strong>No namespace pollution</strong> - you can generate your <span style=font-style:normal;><b>own version</b></span> with any prefix you like!</li>
<li>→<strong>Relies <span style=font-style:normal;>minimally</span> on C libraries - it can be fully decoupled from LIB C and can be statically linked.</strong></li>
<li>→<span style=font-style:normal;><b>Very small</b></span> - 13K Lines of Code (including Doxygen comments and following of Best Practices)</li>
<li>→<strong>No Linkage Issues or  dependency hell</strong></li>
<li>→<strong>Thorough and clear documentation</strong>, with examples of usage.</li>
<li>→<strong>No licensing restrictions whatsoever - use it for your engineering project, your startup, your Fortune 500 company, your personal project, your throw-away script, your government.</strong></li>
<li>→<strong>Makes C like Python or Perl or Ruby in many ways - or more easy</strong></li>
<li>→<strong>Easy Straightforward Transpilation Support</strong> - to make current code, much faster - all without any bloat (See transpile_slow_scripting_into_c.rb). 
<li><h4>In many cases, there is now a direct mapping of functions from other languages into optimized C.
See the example script in this repository. This makes optimizing your Python / Perl / Ruby / PHP etc. script very easy, either manually or through the use of AI.</h4></li>
</ul>
</p>
</div>
<div class=pane style='border: 0;border-right: 1px dotted rgb(200, 200, 200); background-color: rgb(255, 255, 190);'>
<div class="library-details"><h2 style=color:green;>Foundationallib Features</h2>
<p class=feature>
<strong>Functional Programming Features</strong> - <code>map, reduce, filter,</code> List Comprehensions in C and much more!</p>
<p class=feature><strong>Expands C's Primitives for easy manipulation of data types</strong> such as Arrays, Strings, <code>Dict</code>, <code>Set</code>, <code>FrozenDict</code>, <code>FrozenSet</code> - <strong>and enables easy manipulation, modification,
alteration, comparison, sorting, counting, IO (printing) and duplication of these at a very comfortable level</strong> -
something very, very rare in C or C++, <i>all without any overhead.</i></p>

<p class=feature><strong>More comfortable IO</strong> - read and write entire files with ease, and convert
complex types into strings or print them on the screen with ease. </p>

<p class=feature><strong>A powerful general purpose Foundational Library</strong> - <i>which has anything and
everything you need</i> - from <code>replace_all()</code> to <code>replace_memory()</code> to <code>find_last_of()</code> to 
to <code>list_comprehension()</code> to <code>shellescape()</code> to <code>read_file_into_string()</code> to
<code>string_to_json()</code> to <code>string_to_uppercase()</code> to <code>to_title_case()</code> to <code>read_file_into_array()</code> to <code>read_files_into_array()</code> to <code>map()</code>
to <code>reduce()</code> to <code>filter()</code> to <code>list_comprehension_multithreaded()</code> to <code>frozen_dict_new_instance()</code> 
to <code>backticks()</code> - everything you would want to make quick and optimally efficient C programs, this has it.</p>
<div style='height: 1px; border: 0;border-bottom: 1px dashed rgb(200, 200, 200);'></div>

<p class=performance><span>Helps to make programs hundreds of times faster than other languages with similar ease of creation.</span>
<hr>

<p class=feature><strong>Easily take advantage of CPU cores with list_comprehension_multithreaded()</strong>.<br><br>You can specify the number of threads, the transform and the filter functions, and this will transform your data - all in parallel. Don't have a multithreaded environment? Then disable it (set the flag).</p>
<hr>
<h3>You don't want to be reinventing the wheel and hoping that your memory allocation is secure enough - and then failing. <strong>Security Is Paramount.</strong></h3>

<h3>You don't want to be waiting <span style='color:rgb(240, 0, 0);'>a day</span> for an operation to complete when it could take <span style='color:rgb(30, 30, 255);'>less than an hour</span>.</h3>
<br><p>This library is founded on very strong and unequivocal goals and philosophy. In fact, I have written many articles about the foundation of this library and more relevantly the broader context. See the Articles folder - for some of the foundation of this library.</p>

<br><p>This library is an ideal and a dream - not just a Software Library. As such, I would highly suggest that you support me in this mission. Even if it's different from the status quo. Are you a Rust or Zig fan? Then make a Rust or Zig version of this ideal. Let's go. Give me an email.</p>
</div>
</div>
<br>

    No Copyright - Public Domain - 2023, Gregory Cohen <gregorycohennew@gmail.com>


    DONATION REQUEST: If this free software has helped you and you find
    it valuable, please consider making a donation to support the ongoing
    development and maintenance of this project. Your contribution helps
    ensure the availability of this library to the community and encourages
    further improvements.


                          Donations can be made at:
                 https://www.paypal.com/paypalme/cfoundationallib


Note: The best way to contact me is through email, not social media. Please
feel very free to email me if you want to express feedback, suggest an
improvement, desire to collaborate on this free and open source
project, want to support me, or want to create something great.
Complacency and obstructionism and whining are not tolerated.
I desire to make this library the best theoretically possible,
so please, let us connect.


<pre><code>
Mirror Links

Blog - https://foundationallib.wordpress.com/

Github - https://github.com/gregoryc/foundationallib

Ruby Gem Mirror - https://rubygems.org/gems/foundational_lib

Ruby Gem Mirror - https://rubygems.org/gems/foundational_lib2

Library Instagram - https://www.instagram.com/foundationallib

Google Drive Mirrors

ZIP - https://drive.google.com/file/d/1bK2njCRsH4waTm4LP16sloPQawk7JIR5/view?usp=sharing
TAR.GZ - https://drive.google.com/file/d/1RCA1yy9R3cEqI_X9Lv0fxqh-zgNCK005/view?usp=sharing
TAR.BZ2 - https://drive.google.com/file/d/1ljdlI_fEnMS_X5WmuhI1qavhgseWlD5j/view?usp=sharing
</code></pre>


<h1>This code is in the public domain, fully.

You can do whatever you want with it.

See docs.html for API reference.

![Alt text](https://github.com/gregoryc/foundationallib/raw/main/tools/pic.png)

</h1>

<h1>Here's some examples of some things you can do easily with Foundationallib.<br><br>

<h3>Use it for scripting purposes...</h3>
</h1>

![Alt text](https://github.com/gregoryc/foundationallib/raw/main/tools/pic2.png)

<h1>Take control of the Web - in C.<br><br></h1>

![Alt text](https://github.com/gregoryc/foundationallib/raw/main/tools/pic3.png)


README

#'

readme = README + (`lynx -dump -stdin<../docs.html`.split("\nFunction Documentation", 2).reverse.join("\n").gsub(/\[\d+\]/, "").gsub(/^\s*\d+\. .*$/, "").gsub("./docs/src/foundationallib.h.", "").gsub(/^\s*Examples\s*$/, "").gsub(/\n{3,}/, "\n"))

readme = readme.gsub(/^\s*◆\s*(.+)$/, " <h2>\\1</h2>")

readme.gsub! /^\s*(Note|Returns|Warning|Parameters)\s*$/, "\n\n<h3><pre>\\1</pre></h3>\n\n"

wr "../README.md", README
wr "../DOCS_MOBILE.md", readme
