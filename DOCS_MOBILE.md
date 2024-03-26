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
 <h2>append_data_to_array()</h2>

   FOUNDATIONAL_LIB_FUNC int append_data_to_array ( void **  array,
   size_t *  array_size,
   size_t *  array_current_alloc_size,
   void *  data,
   size_t  data_size
   )

   Appends a new element to the end of a dynamically allocated array and
   updates its size.

   This function adds a new element to the end of the specified array. If
   the array has already been allocated with malloc, the function resizes
   it accordingly. If the array's current allocation size is 0, a new
   array is dynamically allocated. Memory is reallocated as needed to
   accommodate the new element. The caller is responsible for freeing the
   memory allocated for the array.


<h3><pre>Parameters</pre></h3>


   array A pointer to the array of strings.
   array_size A pointer to the size_t variable representing the current
   size of the array.
   array_current_alloc_size A pointer to the size_t variable representing
   the current allocated size of the array.
   element The string element to be appended.


<h3><pre>Returns</pre></h3>


          0 on success, -1 on error.


<h3><pre>Note</pre></h3>


          The caller should free the memory allocated for the array. Make
          sure that *array_current_alloc_size is initialized to 0 or a
          higher value when calling this function.
 <h2>append_data_to_array_no_initial_alloc()</h2>

   FOUNDATIONAL_LIB_FUNC int append_data_to_array_no_initial_alloc (
   void **  array,
   size_t *  array_size,
   size_t *  array_current_alloc_size,
   void *  data,
   size_t  data_size
   )

   Appends a new element to the end of a dynamically allocated array and
   updates its size.

   This function adds a new element to the end of the specified array. If
   the array has already been allocated with malloc, the function resizes
   it accordingly. Memory is reallocated as needed to accommodate the new
   element. The caller is responsible for freeing the memory allocated for
   the array.


<h3><pre>Parameters</pre></h3>


   array A pointer to the array of strings.
   array_size A pointer to the size_t variable representing the current
   size of the array.
   array_current_alloc_size A pointer to the size_t variable representing
   the current allocated size of the array.
   element The string element to be appended.


<h3><pre>Returns</pre></h3>


          0 on success, -1 on error.


<h3><pre>Note</pre></h3>


          The caller should free the memory allocated for the array. This
          function is an optimization of append_data_to_array that doesn't
          check "if (*array_current_alloc_size == 0)" constantly. Use
          wisely. Make sure that *array_current_alloc_size is initialized
          to 0 or a higher value when calling this function.
 <h2>append_string_to_array()</h2>

   FOUNDATIONAL_LIB_FUNC int append_string_to_array ( char ***
   array,
   size_t *  array_size,
   size_t *  array_current_alloc_size,
   const char *  string
   )

   Appends a new string element to the end of a dynamically allocated
   array of strings and updates its size.

   This function adds a new string element to the end of the specified
   array of strings. If the array has already been allocated with malloc,
   the function resizes it accordingly. If the array's current allocation
   size is 0, a new array is dynamically allocated. Memory is reallocated
   as needed to accommodate the new element. The caller is responsible for
   freeing the memory allocated for the array.


<h3><pre>Parameters</pre></h3>


   array A pointer to the array of strings.
   array_size A pointer to the size_t variable representing the current
   size of the array.
   array_current_alloc_size A pointer to the size_t variable representing
   the current allocated size of the array.
   element The string element to be appended.


<h3><pre>Returns</pre></h3>


          0 on success, -1 on error.


<h3><pre>Note</pre></h3>


          The caller should free the memory allocated for the array. Make
          sure that *array_current_alloc_size is initialized to 0 or a
          higher value when calling this function.
 <h2>append_string_to_array_no_initial_alloc()</h2>

   FOUNDATIONAL_LIB_FUNC int append_string_to_array_no_initial_alloc
   ( char ***  array,
   size_t *  array_size,
   size_t *  array_current_alloc_size,
   const char *  string
   )

   Appends a new string element to the end of a dynamically allocated
   array of strings and updates its size.

   This function adds a new string element to the end of the specified
   array of strings. If the array has already been allocated with malloc,
   the function resizes it accordingly. If the array's current allocation
   size is 0, an error will occur - do not do this. Memory is reallocated
   as needed to accommodate the new element. The caller is responsible for
   freeing the memory allocated for the array.


<h3><pre>Parameters</pre></h3>


   array A pointer to the array of strings.
   array_size A pointer to the size_t variable representing the current
   size of the array.
   array_current_alloc_size A pointer to the size_t variable representing
   the current allocated size of the array.
   element The string element to be appended.


<h3><pre>Returns</pre></h3>


          0 on success, -1 on error.


<h3><pre>Note</pre></h3>


          The caller should free the memory allocated for the array. This
          function is an optimization of append_string_to_array that
          doesn't check "if (*array_current_alloc_size == 0)" constantly.
          Use wisely. Make sure that *array_current_alloc_size is
          initialized to 0 or a higher value when calling this function.
 <h2>append_string_to_file()</h2>

   FOUNDATIONAL_LIB_FUNC int append_string_to_file ( const char *
   filename,
                                                           const char *  content
                                                         )

   Appends a string to a file.

   This function appends the specified content string of a given size to
   the end of the specified file.


<h3><pre>Parameters</pre></h3>


   filename Pointer to the name of the file to which the content will be
   appended.
   content Pointer to the string content to be appended to the file.
   content_size Size of the content to be appended.


<h3><pre>Returns</pre></h3>


          Returns 0 on success and -1 on failure. The function fails if
          the file cannot be opened or if there is an error during the
          appending process.
 <h2>append_string_to_string()</h2>

   FOUNDATIONAL_LIB_FUNC int append_string_to_string ( char **
   string,
   size_t *  string_length,
   size_t *  string_alloc_size,
   const char *  string_to_get_appended,
   size_t  string_to_get_appended_length
   )

   Appends a new string to an existing string and updates its length and
   allocation size.

   This function appends the specified string to the end of the target
   string. If the target string has not been allocated yet or its current
   allocation size is insufficient, the function dynamically reallocates
   memory as needed. The caller is responsible for freeing the memory
   allocated for the target string.


<h3><pre>Parameters</pre></h3>


   string A pointer to the target string.
   string_length A pointer to the size_t variable representing the current
   length of the target string.
   string_alloc_size A pointer to the size_t variable representing the
   current allocated size of the target string.
   string_to_get_appended The string to be appended.
   string_to_get_appended_length A pointer to the size_t variable
   representing the length of the string to be appended.


<h3><pre>Returns</pre></h3>


          0 on success, -1 on error.
 <h2>array_total_string_length()</h2>

   FOUNDATIONAL_LIB_FUNC size_t array_total_string_length ( char **
   array,
                                                                  size_t  count
                                                                )

   Calculates the total length of strings in an array.

   This function computes the cumulative length of strings in the provided
   array of strings. It does not include any additional memory needed for
   null terminators.


<h3><pre>Parameters</pre></h3>


          array An array of strings.
          count The number of elements in the array.


<h3><pre>Returns</pre></h3>


          The total length of strings in the array.
 <h2>arraydup()</h2>

   FOUNDATIONAL_LIB_FUNC void* arraydup ( const void *  array,
                                                size_t        num_mem,
                                                size_t        size
                                              )

   Duplicates an array of elements at a shallow level.

   This function creates a new array by duplicating the elements of the
   input array up to one level deep.


<h3><pre>Parameters</pre></h3>


          array   Pointer to the source array.
          num_mem Number of elements in the source array.
          size    Size (in bytes) of each element in the array.


<h3><pre>Returns</pre></h3>


          A pointer to the newly created array or NULL if allocation
          fails. It is the caller's responsibility to free the allocated
          memory.
 <h2>backticks()</h2>

   FOUNDATIONAL_LIB_FUNC char* backticks ( const char *  command,
                                                 size_t *      size
                                               )

   Executes a command and reads its output into a string.

   This function executes the specified command using popen and reads the
   output into a dynamically allocated string. The size of the string is
   stored in the variable pointed to by the 'size' parameter. The caller
   is responsible for freeing the memory allocated for the returned string
   using free().


<h3><pre>Parameters</pre></h3>


   command Pointer to the command to be executed.
   size Pointer to a variable where the size of the read string will be
   stored.


<h3><pre>Returns</pre></h3>


          Pointer to the dynamically allocated string containing the
          command output. Returns NULL if there is an error or the command
          output is empty. The caller is responsible for freeing the
          memory using free().


<h3><pre>Note</pre></h3>


          Caution: This function may introduce security vulnerabilities.
          Consider using alternative methods such as execvp() for safer
          command execution in a controlled environment.
 <h2>common_prefix_length()</h2>

   FOUNDATIONAL_LIB_FUNC size_t common_prefix_length ( const char *
   str1,
                                                             const char *  str2
                                                           )

   Finds the length of the common prefix of two strings.

   This function determines the length of the common prefix between two
   strings.


<h3><pre>Parameters</pre></h3>


          str1 Pointer to the first string.
          str2 Pointer to the second string.


<h3><pre>Returns</pre></h3>


          Length of the common prefix.
 <h2>common_suffix_length()</h2>

   FOUNDATIONAL_LIB_FUNC size_t common_suffix_length ( const char *
   str1,
                                                             const char *  str2
                                                           )

   Finds the length of the common suffix of two strings.

   This function determines the length of the common suffix between two
   strings.


<h3><pre>Parameters</pre></h3>


          str1 Pointer to the first string.
          str2 Pointer to the second string.


<h3><pre>Returns</pre></h3>


          Length of the common suffix.
 <h2>concatenate_five_strings()</h2>

   FOUNDATIONAL_LIB_FUNC char* concatenate_five_strings ( const char
   *  str1,
   const char *  str2,
   const char *  str3,
   const char *  str4,
   const char *  str5
   )

   Concatenates five strings into a new dynamically allocated array.

   This function concatenates the given five strings into a new
   dynamically allocated character array. The caller is responsible for
   freeing the memory allocated for the result using the free() function.


<h3><pre>Parameters</pre></h3>


          str1 The first string to be concatenated.
          str2 The second string to be concatenated.
          str3 The third string to be concatenated.
          str4 The fourth string to be concatenated.
          str5 The fifth string to be concatenated.


<h3><pre>Returns</pre></h3>


          Returns a pointer to the newly allocated character array
          containing the concatenated strings. If the allocation fails,
          returns NULL. The caller must free the memory when done using
          free().
 <h2>concatenate_four_strings()</h2>

   FOUNDATIONAL_LIB_FUNC char* concatenate_four_strings ( const char
   *  str1,
   const char *  str2,
   const char *  str3,
   const char *  str4
   )

   Concatenates four strings into a new dynamically allocated array.

   This function concatenates the given four strings into a new
   dynamically allocated character array. The caller is responsible for
   freeing the memory allocated for the result using the free() function.


<h3><pre>Parameters</pre></h3>


          str1 The first string to be concatenated.
          str2 The second string to be concatenated.
          str3 The third string to be concatenated.
          str4 The fourth string to be concatenated.


<h3><pre>Returns</pre></h3>


          Returns a pointer to the newly allocated character array
          containing the concatenated strings. If the allocation fails,
          returns NULL. The caller must free the memory when done using
          free().
 <h2>concatenate_string_array()</h2>

   FOUNDATIONAL_LIB_FUNC char* concatenate_string_array ( const char
   **  strings,
   size_t  num_strings
   )

   Concatenates an array of strings into a single string.

   This function takes an array of strings and concatenates them into a
   single string. The resulting string is dynamically allocated and the
   caller is responsible for freeing the memory using free().


<h3><pre>Parameters</pre></h3>


      strings     An array of C-style strings (const char**) to be concatenated.
      num_strings The number of strings in the array.


<h3><pre>Returns</pre></h3>


          A dynamically allocated string containing the concatenated
          result. The caller is responsible for freeing the memory using
          free().


<h3><pre>Warning</pre></h3>


          The caller is responsible for freeing the memory of the returned
          string using free() to prevent memory leaks.
 <h2>concatenate_strings()</h2>

   FOUNDATIONAL_LIB_FUNC char* concatenate_strings ( const char *
   str1,
                                                           const char *  str2
                                                         )

   Concatenates two strings.

   This function concatenates the contents of the two given strings and
   returns a dynamically allocated string containing the result. The
   caller is responsible for freeing the memory allocated for the returned
   string using free().


<h3><pre>Parameters</pre></h3>


          str1 Pointer to the first null-terminated string.
          str2 Pointer to the second null-terminated string.


<h3><pre>Returns</pre></h3>


          Pointer to the dynamically allocated string containing the
          concatenated result. Returns NULL if there is an allocation
          error. The caller is responsible for freeing the memory using
          free().
 <h2>concatenate_three_strings()</h2>

   FOUNDATIONAL_LIB_FUNC char* concatenate_three_strings ( const
   char *  str1,
   const char *  str2,
   const char *  str3
   )

   Concatenates three strings into a new dynamically allocated array.

   This function concatenates the given three strings into a new
   dynamically allocated character array. The caller is responsible for
   freeing the memory allocated for the result using the free() function.


<h3><pre>Parameters</pre></h3>


          str1 The first string to be concatenated.
          str2 The second string to be concatenated.
          str3 The third string to be concatenated.


<h3><pre>Returns</pre></h3>


          Returns a pointer to the newly allocated character array
          containing the concatenated strings. If the allocation fails,
          returns NULL. The caller must free the memory when done using
          free().
 <h2>copy_file()</h2>

  FOUNDATIONAL_LIB_FUNC int copy_file ( const char *
   source_filename,
                                              const char *  destination_filename
                                            )

   Copies a file from source to destination.

   This function copies the content of the source file to the destination
   file.


<h3><pre>Parameters</pre></h3>


          source_filename      Pointer to the name of the source file.
          destination_filename Pointer to the name of the destination file.


<h3><pre>Returns</pre></h3>


          Returns 0 on success and -1 on error. The function fails if the
          source file cannot be opened, the destination file cannot be
          created or written to, or if there is an error during the
          copying process.
 <h2>count_occurrences_of_adjacent_data_in_array()</h2>

   FOUNDATIONAL_LIB_FUNC size_t
   count_occurrences_of_adjacent_data_in_array ( const void *
   array_of_adjacent_values,
   size_t  array_length,
   const void *  memory,
   size_t  memory_length
   )

   Counts the occurrences of a block of memory in an array of memory
   blocks.

   This function iterates through the given array of memory blocks and
   counts how many times the specified memory block appears in the array.


<h3><pre>Parameters</pre></h3>


          array_of_adjacent_values The array of memory blocks to search.
          array_length             The number of elements in the array.
          memory                   The memory block to count occurrences of.
          memory_length            The size of the memory block.


<h3><pre>Returns</pre></h3>


          The count of occurrences of the specified memory block in the
          array.
 <h2>count_occurrences_of_data_in_array()</h2>

   FOUNDATIONAL_LIB_FUNC size_t count_occurrences_of_data_in_array (
   const void **  array_of_pointers,
   size_t  array_length,
   const void *  memory,
   size_t  memory_length
   )

   Counts the occurrences of a block of memory in an array of memory
   blocks.

   This function iterates through the given array of memory blocks and
   counts how many times the specified memory block appears in the array.


<h3><pre>Parameters</pre></h3>


          array_of_pointers The array of memory blocks to search.
          array_length      The number of elements in the array.
          memory            The memory block to count occurrences of.
          memory_length     The size of the memory block.


<h3><pre>Returns</pre></h3>


          The count of occurrences of the specified memory block in the
          array.
 <h2>count_occurrences_of_string_in_array()</h2>

   FOUNDATIONAL_LIB_FUNC size_t count_occurrences_of_string_in_array
   ( const char **  array,
   const char *  string,
   size_t  array_length
   )

   Counts the occurrences of a string in an array of strings.

   This function iterates through the given array of strings and counts
   how many times the specified string appears in the array.


<h3><pre>Parameters</pre></h3>


          array        The array of strings to search.
          string       The string to count occurrences of.
          array_length The number of elements in the array.


<h3><pre>Returns</pre></h3>


          The count of occurrences of the specified string in the array.
 <h2>count_occurrences_of_substr()</h2>

   FOUNDATIONAL_LIB_FUNC size_t count_occurrences_of_substr ( const
   char *  str,
   const char *  substring
   )

   Counts the occurrences of a specified substring within a given string.

   This function takes a source string and a target substring as input and
   returns the number of times the substring appears in the source string.
   It performs a case-sensitive search and provides an accurate count of
   occurrences.


<h3><pre>Parameters</pre></h3>


          str       The source string in which occurrences are counted.
          substring The target substring whose occurrences are being counted.


<h3><pre>Returns</pre></h3>


          The number of times the specified substring appears in the
          source string.
 <h2>count_occurrences_of_substr_len()</h2>

   FOUNDATIONAL_LIB_FUNC size_t count_occurrences_of_substr_len (
   const char *  string,
   size_t  string_length,
   const char *  substring,
   size_t  substring_length
   )

   Counts the occurrences of a specified substring within a given string.

   This function takes a source string and a target substring as input and
   returns the number of times the substring appears in the source string.
   It performs a case-sensitive search and provides an accurate count of
   occurrences.


<h3><pre>Parameters</pre></h3>


      str              The source string in which occurrences are counted.
      substring        The target substring whose occurrences are being counted.
      substring_length The length of the substring.


<h3><pre>Returns</pre></h3>


          The number of times the specified substring appears in the
          source string.


<h3><pre>Note</pre></h3>


          It is undefined behavior how this function works if a NUL
          terminator is present in the array.
 <h2>dict_add()</h2>

   FOUNDATIONAL_LIB_FUNC int dict_add ( struct Dict *  dict,
                                              const char *         key,
                                              void *               value
                                            )

   Adds a key-value pair to the dictionary.

   This function adds a new key-value pair to the provided dictionary. It
   associates them in the dictionary.


<h3><pre>Parameters</pre></h3>


          dict  A pointer to the dictionary instance.
          key   The key to be added.
          value A pointer to the value to be associated with the key.


<h3><pre>Returns</pre></h3>


          Returns -1 on error, 0 on success.
 <h2>dict_del_key()</h2>

   FOUNDATIONAL_LIB_FUNC void dict_del_key ( struct Dict *
   dict,
                                                   const char *         key
                                                 )

   Deletes a key-value pair from the dictionary based on the provided key.

   This function removes the key-value pair associated with the specified
   key from the provided dictionary. If the key is not found, the
   dictionary remains unchanged.


<h3><pre>Parameters</pre></h3>


          dict A pointer to the dictionary instance.
          key  The key for which the associated key-value pair is to be deleted.
 <h2>dict_del_keys()</h2>

   static void dict_del_keys ( char **  keys )
   inlinestatic

   Deallocates memory associated with an array of keys.

   This function serves as the destructor for an array of Dict keys,
   freeing the memory allocated for the array. It is functionally
   identical to just calling free().


<h3><pre>Parameters</pre></h3>


          keys A pointer to the array of keys to be deallocated.
 <h2>dict_del_values()</h2>

   static void dict_del_values ( void **  values )
   inlinestatic

   Deallocates memory associated with an array of values.

   This function serves as the destructor for an array of Dict
   values, freeing the memory allocated for the array. It is functionally
   identical to just calling free().


<h3><pre>Parameters</pre></h3>


          keys A pointer to the array of keys to be deallocated.
 <h2>dict_destructor()</h2>

   FOUNDATIONAL_LIB_FUNC void dict_destructor ( struct Dict *
   dict                                             )

   Deallocates memory associated with a dictionary, freeing resources.

   This function is the destructor for the provided dictionary, freeing
   the memory allocated for the hash table and its elements. It is
   important to call this function to prevent memory leaks when a
   dictionary is no longer needed.


<h3><pre>Parameters</pre></h3>


          dict A pointer to the dictionary instance to be deallocated.
 <h2>dict_get()</h2>

   FOUNDATIONAL_LIB_FUNC void* dict_get ( struct Dict *  dict,
                                                const char *         key
                                              )

   Retrieves the value associated with the specified key from the
   dictionary.

   This function retrieves the value associated with the provided key from
   the dictionary. If the key is not found, it returns NULL. Note that
   this function does not differentiate between a NULL value and the key
   not being present in the dictionary. If such differentiation is needed,
   use dict_get_check(dict, key, &key_is_in_dict), instead


<h3><pre>Parameters</pre></h3>


          dict A pointer to the dictionary instance.
          key  The key for which the associated value is to be retrieved.


<h3><pre>Returns</pre></h3>


          Returns a pointer to the value associated with the key, or NULL
          if the key is not found.
 <h2>dict_get_check()</h2>

   FOUNDATIONAL_LIB_FUNC void* dict_get_check ( struct Dict *
   dict,
   const char *  key,
   int *  key_is_in_dict
   )

   Retrieves the value associated with the specified key from the
   dictionary.

   This function retrieves the value associated with the provided key from
   the dictionary. If the key is found, it sets key_is_in_dict to 1 (true)
   and returns a pointer to the associated value. If the key is not
   present, it sets key_is_in_dict to 0 (false) and returns NULL.


<h3><pre>Parameters</pre></h3>


   dict A pointer to the dictionary instance.
   key The key for which the associated value is to be retrieved.
   key_is_in_dict A pointer to an integer that is set to 1 if the key is
   in the dictionary, and 0 if the key is not found.


<h3><pre>Returns</pre></h3>


          Returns a pointer to the value associated with the key if
          present, or NULL if the key is not found.
 <h2>dict_hash()</h2>

   FOUNDATIONAL_LIB_FUNC size_t dict_hash ( const char *  key,
                                                  size_t        capacity
                                                )

   Hashes a null-terminated string using the djb2 algorithm.

   The djb2 hash function is a simple and effective algorithm for hashing
   strings. It iterates over each character in the input string, combining
   the current hash value with the ASCII value of the character using the
   formula hash = (hash << 5) + hash + c. The algorithm is known for its
   simplicity, good distribution properties, and reduced likelihood of
   collisions.


<h3><pre>Parameters</pre></h3>


   key Pointer to the null-terminated character array (string) used as the
   key.
   capacity Capacity of the hash table.


<h3><pre>Returns</pre></h3>


          The computed hash value within the specified capacity.
 <h2>dict_iter()</h2>

   FOUNDATIONAL_LIB_FUNC void dict_iter ( struct Dict *  dict,
   void(*)(char *key, void *value)  callback
   )

   Iterates through the key-value pairs in the dictionary, applying a
   callback function.

   This function iterates through the key-value pairs in the provided
   dictionary and applies the specified callback function to each pair.
   The callback function takes a key and a value as parameters and is
   applied for each element in the dictionary.


<h3><pre>Parameters</pre></h3>


   dict A pointer to the dictionary instance.
   callback A function pointer to the callback function taking a key and a
   value as parameters.
 <h2>dict_reserve_more()</h2>

   FOUNDATIONAL_LIB_FUNC int dict_reserve_more ( struct Dict
   *  dict,
   size_t  number_of_new_elements_max_one_is_expecting
   )

   Reserves additional space in a Dictionary for anticipated new elements.

   This function reserves additional space in the provided dictionary's
   internal hash table to accommodate an anticipated number of new
   elements. The reservation helps avoid frequent resizes, optimizing
   performance when a known number of new elements is expected. Calling
   this function will trigger a resize and rehash of the dictionary, but
   it will only happen (ideally) once, if you accurately predict the
   future size of the dictionary.


<h3><pre>Parameters</pre></h3>


   dict A pointer to the Dict instance for which space is to be
   reserved.
   number_of_new_elements_max_one_is_expecting The anticipated number of
   new elements (above the current capacity).


<h3><pre>Returns</pre></h3>


          Returns 0 on success, -1 on failure.
 <h2>dict_resize()</h2>

   FOUNDATIONAL_LIB_FUNC int dict_resize ( struct Dict *  dict
   )

   Resizes the hash table of the dictionary to optimize performance.

   This function adjusts the size of the hash table in the provided
   dictionary to enhance performance. The new capacity is determined using
   a reallocation algorithm specified by the
   FOUNDATIONAL_LIB_REALLOC_REALLOCATION_ALGORITHM macro. The function
   reallocates memory for the hash table, rehashes all existing key-value
   pairs, and updates the dictionary's capacity accordingly.


<h3><pre>Parameters</pre></h3>


          dict A pointer to the dictionary instance to be resized.


<h3><pre>Returns</pre></h3>


          Returns 0 on success, -1 on failure.
 <h2>dict_size()</h2>

        FOUNDATIONAL_LIB_FUNC size_t dict_size ( struct Dict *
   dict )

   Returns the number of key-value pairs in the dictionary.

   This function returns the current size, representing the number of
   key-value pairs, in the provided dictionary.


<h3><pre>Parameters</pre></h3>


          dict A pointer to the dictionary instance.


<h3><pre>Returns</pre></h3>


          Returns the number of key-value pairs in the dictionary.
 <h2>dict_to_array()</h2>

   FOUNDATIONAL_LIB_FUNC int dict_to_array ( struct Dict *
   dict,
   char ***  keys,
   void ***  values,
   size_t *  size_of_keys_and_values
   )

   Converts the key-value pairs from the dictionary into separate arrays
   for keys and values.

   This function converts the key-value pairs from the provided dictionary
   into separate arrays for keys and values. The resulting arrays are
   allocated dynamically and should be freed by the caller when no longer
   needed. The size_of_keys_and_values parameter is set to the number of
   key-value pairs in the dictionary.


<h3><pre>Parameters</pre></h3>


   dict A pointer to the dictionary instance.
   keys A pointer to store the dynamically allocated array of keys.
   values A pointer to store the dynamically allocated array of values.
   size_of_keys_and_values A pointer to store the size of the resulting
   arrays.


<h3><pre>Returns</pre></h3>


          Returns -1 on error, 0 on success.


<h3><pre>Note</pre></h3>


          The caller is responsible for freeing the memory allocated for
          keys and values arrays using dict_del_keys() and
          dict_del_values() (or just free() - these have the same
          effect) when they are no longer needed.
 <h2>dict_to_string()</h2>

   FOUNDATIONAL_LIB_FUNC char* dict_to_string ( struct Dict *
   dict,
   int  pointer_or_string
   )

   Converts a dictionary to a string representation.

   This function converts the provided dictionary to a string
   representation. The resulting string can either contain pointers to the
   key-value pairs (pointer format) or the actual key-value pairs as
   strings (string format). The choice is determined by the
   pointer_or_string parameter, where 0 represents the pointer format and
   1 represents the string format.


<h3><pre>Parameters</pre></h3>


   dict A pointer to the dictionary instance.
   pointer_or_string Determines the format of the resulting string (0 =
   pointer, 1 = string).


<h3><pre>Returns</pre></h3>


          Returns a dynamically allocated string representing the
          dictionary.


<h3><pre>Note</pre></h3>


          The caller is responsible for freeing the memory allocated for
          the resulting string using free() when it is no longer needed.
 <h2>dup_format()</h2>

   FOUNDATIONAL_LIB_FUNC char* dup_format ( const char *  format,
                                                                ...
                                                )

   Duplicates a formatted string.

   This function duplicates a formatted string created using
   FOUNDATIONAL_LIB_PRINTF-style formatting. It returns a dynamically
   allocated string containing the formatted result. The caller is
   responsible for freeing the memory allocated for the returned string
   using free().


<h3><pre>Parameters</pre></h3>


          format Pointer to the null-terminated format string.
          ...    Variable arguments to be formatted into the string.


<h3><pre>Returns</pre></h3>


          Pointer to the dynamically allocated string containing the
          formatted result. Returns NULL if there is an allocation error.
          The caller is responsible for freeing the memory using free().
 <h2>ends_with()</h2>

   static int ends_with ( const char *  str,
                          const char *  suffix
                        )
   inlinestatic

   Checks whether a given string ends with a specified suffix.

   This function compares the provided string with the specified suffix to
   determine if the string ends with the given suffix. It calculates the
   lengths of both the string and the suffix and performs a comparison. If
   the suffix is longer than the string, the function returns 0;
   otherwise, it checks for equality in the suffix portion at the end of
   the string.


<h3><pre>Parameters</pre></h3>


          str    The input string to be checked.
          suffix The suffix to check for at the end of the string.


<h3><pre>Returns</pre></h3>


          Returns 1 if the string ends with the specified suffix;
          otherwise, returns 0.
 <h2>equal_array_of_char_ptrs()</h2>

   static int equal_array_of_char_ptrs ( const char **  array,
                                         const char **  array2,
                                         size_t         size
                                       )
   inlinestatic

   Checks if two arrays of pointers to characters are equal.

   This function compares each element of two arrays of pointers to
   characters to determine if they are equal. Returns 1 if the arrays of
   pointers are identical, and 0 otherwise.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the first array of pointers to characters.
          array2 Pointer to the second array of pointers to characters.
          size   Size of the arrays to compare.


<h3><pre>Returns</pre></h3>


          1 if arrays of pointers are equal, 0 otherwise.
 <h2>equal_array_of_chars()</h2>

   static int equal_array_of_chars ( const char *  array,
                                     const char *  array2,
                                     size_t        size
                                   )
   inlinestatic

   Checks if two arrays of characters are equal.

   This function compares each element of two arrays of characters to
   determine if they are equal. Returns 1 if the arrays are identical, and
   0 otherwise.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the first array of characters.
          array2 Pointer to the second array of characters.
          size   Size of the arrays to compare.


<h3><pre>Returns</pre></h3>


          1 if arrays are equal, 0 otherwise.
 <h2>equal_array_of_double_ptrs()</h2>

   static int equal_array_of_double_ptrs ( const double **  array,
                                           const double **  array2,
                                           size_t           size
                                         )
   inlinestatic

   Compares arrays of double pointers for equality.

   This function compares two arrays of double pointers element-wise to
   check if they are equal.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the first array of double pointers.
          array2 Pointer to the second array of double pointers.
          size   Size of the arrays.


<h3><pre>Returns</pre></h3>


          An integer value: 1 if arrays are equal, 0 otherwise.
 <h2>equal_array_of_doubles()</h2>

   static int equal_array_of_doubles ( const double *  array,
                                       const double *  array2,
                                       size_t          size
                                     )
   inlinestatic

   Checks if two arrays of doubles are equal.

   This function compares two arrays of doubles element-wise to determine
   if they are equal.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the first array.
          array2 Pointer to the second array.
          size   Size of the arrays.


<h3><pre>Returns</pre></h3>


          An integer value: 1 if arrays are equal, 0 otherwise.
 <h2>equal_array_of_float_ptrs()</h2>

   static int equal_array_of_float_ptrs ( const float **  array,
                                          const float **  array2,
                                          size_t          size
                                        )
   inlinestatic

   Checks if two arrays of pointers to float values are equal.

   This function compares each element of two arrays of pointers to float
   values to determine if they are equal. Returns 1 if the arrays of
   pointers are identical, and 0 otherwise.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the first array of pointers to float values.
          array2 Pointer to the second array of pointers to float values.
          size   Size of the arrays to compare.


<h3><pre>Returns</pre></h3>


          1 if arrays of pointers are equal, 0 otherwise.
 <h2>equal_array_of_floats()</h2>

   static int equal_array_of_floats ( const float *  array,
                                      const float *  array2,
                                      size_t         size
                                    )
   inlinestatic

   Checks if two arrays of float values are equal.

   This function compares each element of two arrays of float values to
   determine if they are equal. Returns 1 if the arrays are identical, and
   0 otherwise.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the first array of float values.
          array2 Pointer to the second array of float values.
          size   Size of the arrays to compare.


<h3><pre>Returns</pre></h3>


          1 if arrays are equal, 0 otherwise.
 <h2>equal_array_of_int_ptrs()</h2>

   static int equal_array_of_int_ptrs ( const int **  array,
                                        const int **  array2,
                                        size_t        size
                                      )
   inlinestatic

   Checks if two arrays of pointers to integers are equal.

   This function compares each element of two arrays of pointers to
   integers to determine if they are equal. Returns 1 if the arrays of
   pointers are identical, and 0 otherwise.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the first array of pointers to integers.
          array2 Pointer to the second array of pointers to integers.
          size   Size of the arrays to compare.


<h3><pre>Returns</pre></h3>


          1 if arrays of pointers are equal, 0 otherwise.
 <h2>equal_array_of_ints()</h2>

   static int equal_array_of_ints ( const int *  array,
                                    const int *  array2,
                                    size_t       size
                                  )
   inlinestatic

   Checks if two arrays of integers are equal.

   This function compares each element of two arrays of integers to
   determine if they are equal. Returns 1 if the arrays are identical, and
   0 otherwise.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the first array of integers.
          array2 Pointer to the second array of integers.
          size   Size of the arrays to compare.


<h3><pre>Returns</pre></h3>


          1 if arrays are equal, 0 otherwise.
 <h2>equal_array_of_long_long_ptrs()</h2>

   static int equal_array_of_long_long_ptrs ( const long long **  array,
                                              const long long **  array2,
                                              size_t              size
                                            )
   inlinestatic

   Checks if two arrays of pointers to long long integers are equal.

   This function compares each element of two arrays of pointers to long
   long integers to determine if they are equal. Returns 1 if the arrays
   of pointers are identical, and 0 otherwise.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the first array of pointers to long long integers.
          array2 Pointer to the second array of pointers to long long integers.
          size   Size of the arrays to compare.


<h3><pre>Returns</pre></h3>


          1 if arrays of pointers are equal, 0 otherwise.
 <h2>equal_array_of_long_longs()</h2>

   static int equal_array_of_long_longs ( const long long *  array,
                                          const long long *  array2,
                                          size_t             size
                                        )
   inlinestatic

   Checks if two arrays of long long integers are equal.

   This function compares each element of two arrays of long long integers
   to determine if they are equal. Returns 1 if the arrays are identical,
   and 0 otherwise.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the first array of long long integers.
          array2 Pointer to the second array of long long integers.
          size   Size of the arrays to compare.


<h3><pre>Returns</pre></h3>


          1 if arrays are equal, 0 otherwise.
 <h2>equal_array_of_long_ptrs()</h2>

   static int equal_array_of_long_ptrs ( const long **  array,
                                         const long **  array2,
                                         size_t         size
                                       )
   inlinestatic

   Checks if two arrays of pointers to long integers are equal.

   This function compares each element of two arrays of pointers to long
   integers to determine if they are equal. Returns 1 if the arrays of
   pointers are identical, and 0 otherwise.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the first array of pointers to long integers.
          array2 Pointer to the second array of pointers to long integers.
          size   Size of the arrays to compare.


<h3><pre>Returns</pre></h3>


          1 if arrays of pointers are equal, 0 otherwise.
 <h2>equal_array_of_longs()</h2>

   static int equal_array_of_longs ( const long *  array,
                                     const long *  array2,
                                     size_t        size
                                   )
   inlinestatic

   Checks if two arrays of long integers are equal.

   This function compares each element of two arrays of long integers to
   determine if they are equal. Returns 1 if the arrays are identical, and
   0 otherwise.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the first array of long integers.
          array2 Pointer to the second array of long integers.
          size   Size of the arrays to compare.


<h3><pre>Returns</pre></h3>


          1 if arrays are equal, 0 otherwise.
 <h2>equal_array_of_short_ptrs()</h2>

   static int equal_array_of_short_ptrs ( const short **  array,
                                          const short **  array2,
                                          size_t          size
                                        )
   inlinestatic

   Checks if two arrays of pointers to short integers are equal.

   This function compares each element of two arrays of pointers to short
   integers to determine if they are equal. Returns 1 if the arrays of
   pointers are identical, and 0 otherwise.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the first array of pointers to short integers.
          array2 Pointer to the second array of pointers to short integers.
          size   Size of the arrays to compare.


<h3><pre>Returns</pre></h3>


          1 if arrays of pointers are equal, 0 otherwise.
 <h2>equal_array_of_shorts()</h2>

   static int equal_array_of_shorts ( const short *  array,
                                      const short *  array2,
                                      size_t         size
                                    )
   inlinestatic

   Checks if two arrays of short integers are equal.

   This function compares each element of two arrays of short integers to
   determine if they are equal. Returns 1 if the arrays are identical, and
   0 otherwise.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the first array of short integers.
          array2 Pointer to the second array of short integers.
          size   Size of the arrays to compare.


<h3><pre>Returns</pre></h3>


          1 if arrays are equal, 0 otherwise.
 <h2>equal_array_of_size_t_ptrs()</h2>

   static int equal_array_of_size_t_ptrs ( const size_t **  array,
                                           const size_t **  array2,
                                           size_t           size
                                         )
   inlinestatic

   Compares arrays of size_t pointers for equality.

   This function compares two arrays of size_t pointers element-wise to
   check if they are equal.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the first array of size_t pointers.
          array2 Pointer to the second array of size_t pointers.
          size   Size of the arrays.


<h3><pre>Returns</pre></h3>


          An integer value: 1 if arrays are equal, 0 otherwise.
 <h2>equal_array_of_size_ts()</h2>

   static int equal_array_of_size_ts ( const size_t *  array,
                                       const size_t *  array2,
                                       size_t          size
                                     )
   inlinestatic

   Checks if two arrays of size_t values are equal.

   This function compares two arrays of size_t values element-wise to
   determine if they are equal.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the first array of size_t values.
          array2 Pointer to the second array of size_t values.
          size   Size of the arrays.


<h3><pre>Returns</pre></h3>


          An integer value: 1 if arrays are equal, 0 otherwise.
 <h2>equal_array_of_uchar_ptrs()</h2>

   static int equal_array_of_uchar_ptrs ( const unsigned char **  array,
                                          const unsigned char **  array2,
                                          size_t                  size
                                        )
   inlinestatic

   Checks if two arrays of pointers to unsigned characters are equal.

   This function compares each element of two arrays of pointers to
   unsigned characters to determine if they are equal. Returns 1 if the
   arrays of pointers are identical, and 0 otherwise.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the first array of pointers to unsigned characters.
          array2 Pointer to the second array of pointers to unsigned characters.
          size   Size of the arrays to compare.


<h3><pre>Returns</pre></h3>


          1 if arrays of pointers are equal, 0 otherwise.
 <h2>equal_array_of_uchars()</h2>

   static int equal_array_of_uchars ( const unsigned char *  array,
                                      const unsigned char *  array2,
                                      size_t                 size
                                    )
   inlinestatic

   Checks if two arrays of unsigned characters are equal.

   This function compares each element of two arrays of unsigned
   characters to determine if they are equal. Returns 1 if the arrays are
   identical, and 0 otherwise.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the first array of unsigned characters.
          array2 Pointer to the second array of unsigned characters.
          size   Size of the arrays to compare.


<h3><pre>Returns</pre></h3>


          1 if arrays are equal, 0 otherwise.
 <h2>equal_array_of_uint_ptrs()</h2>

   static int equal_array_of_uint_ptrs ( const unsigned int **  array,
                                         const unsigned int **  array2,
                                         size_t                 size
                                       )
   inlinestatic

   Checks if two arrays of pointers to unsigned integers are equal.

   This function compares each element of two arrays of pointers to
   unsigned integers to determine if they are equal. Returns 1 if the
   arrays of pointers are identical, and 0 otherwise.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the first array of pointers to unsigned integers.
          array2 Pointer to the second array of pointers to unsigned integers.
          size   Size of the arrays to compare.


<h3><pre>Returns</pre></h3>


          1 if arrays of pointers are equal, 0 otherwise.
 <h2>equal_array_of_uints()</h2>

   static int equal_array_of_uints ( const unsigned int *  array,
                                     const unsigned int *  array2,
                                     size_t                size
                                   )
   inlinestatic

   Checks if two arrays of unsigned integers are equal.

   This function compares each element of two arrays of unsigned integers
   to determine if they are equal. Returns 1 if the arrays are identical,
   and 0 otherwise.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the first array of unsigned integers.
          array2 Pointer to the second array of unsigned integers.
          size   Size of the arrays to compare.


<h3><pre>Returns</pre></h3>


          1 if arrays are equal, 0 otherwise.
 <h2>equal_array_of_ulong_long_ptrs()</h2>

   static int equal_array_of_ulong_long_ptrs ( const unsigned long long
   **  array,
   const unsigned long long **  array2,
   size_t  size
   )
   inlinestatic

   Checks if two arrays of pointers to unsigned long long integers are
   equal.

   This function compares each element of two arrays of pointers to
   unsigned long long integers to determine if they are equal. Returns 1
   if the arrays of pointers are identical, and 0 otherwise.


<h3><pre>Parameters</pre></h3>


   array Pointer to the first array of pointers to unsigned long long
   integers.
   array2 Pointer to the second array of pointers to unsigned long long
   integers.
   size Size of the arrays to compare.


<h3><pre>Returns</pre></h3>


          1 if arrays of pointers are equal, 0 otherwise.
 <h2>equal_array_of_ulong_longs()</h2>

   static int equal_array_of_ulong_longs ( const unsigned long long *
   array,
                                           const unsigned long long *  array2,
                                           size_t                      size
                                         )
   inlinestatic

   Checks if two arrays of unsigned long long integers are equal.

   This function compares each element of two arrays of unsigned long long
   integers to determine if they are equal. Returns 1 if the arrays are
   identical, and 0 otherwise.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the first array of unsigned long long integers.
          array2 Pointer to the second array of unsigned long long integers.
          size   Size of the arrays to compare.


<h3><pre>Returns</pre></h3>


          1 if arrays are equal, 0 otherwise.
 <h2>equal_array_of_ulong_ptrs()</h2>

   static int equal_array_of_ulong_ptrs ( const unsigned long **  array,
                                          const unsigned long **  array2,
                                          size_t                  size
                                        )
   inlinestatic

   Checks if two arrays of pointers to unsigned long integers are equal.

   This function compares each element of two arrays of pointers to
   unsigned long integers to determine if they are equal. Returns 1 if the
   arrays of pointers are identical, and 0 otherwise.


<h3><pre>Parameters</pre></h3>


   array Pointer to the first array of pointers to unsigned long integers.
   array2 Pointer to the second array of pointers to unsigned long
   integers.
   size Size of the arrays to compare.


<h3><pre>Returns</pre></h3>


          1 if arrays of pointers are equal, 0 otherwise.
 <h2>equal_array_of_ulongs()</h2>

   static int equal_array_of_ulongs ( const unsigned long *  array,
                                      const unsigned long *  array2,
                                      size_t                 size
                                    )
   inlinestatic

   Checks if two arrays of unsigned long integers are equal.

   This function compares each element of two arrays of unsigned long
   integers to determine if they are equal. Returns 1 if the arrays are
   identical, and 0 otherwise.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the first array of unsigned long integers.
          array2 Pointer to the second array of unsigned long integers.
          size   Size of the arrays to compare.


<h3><pre>Returns</pre></h3>


          1 if arrays are equal, 0 otherwise.
 <h2>equal_array_of_ushort_ptrs()</h2>

   static int equal_array_of_ushort_ptrs ( const unsigned short **  array,
                                           const unsigned short **  array2,
                                           size_t                   size
                                         )
   inlinestatic

   Checks if two arrays of pointers to unsigned short integers are equal.

   This function compares each element of two arrays of pointers to
   unsigned short integers to determine if they are equal. Returns 1 if
   the arrays of pointers are identical, and 0 otherwise.


<h3><pre>Parameters</pre></h3>


   array Pointer to the first array of pointers to unsigned short
   integers.
   array2 Pointer to the second array of pointers to unsigned short
   integers.
   size Size of the arrays to compare.


<h3><pre>Returns</pre></h3>


          1 if arrays of pointers are equal, 0 otherwise.
 <h2>equal_array_of_ushorts()</h2>

   static int equal_array_of_ushorts ( const unsigned short *  array,
                                       const unsigned short *  array2,
                                       size_t                  size
                                     )
   inlinestatic

   Checks if two arrays of unsigned short integers are equal.

   This function compares each element of two arrays of unsigned short
   integers to determine if they are equal. Returns 1 if the arrays are
   identical, and 0 otherwise.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the first array of unsigned short integers.
          array2 Pointer to the second array of unsigned short integers.
          size   Size of the arrays to compare.


<h3><pre>Returns</pre></h3>


          1 if arrays are equal, 0 otherwise.
 <h2>equal_strings()</h2>

   static int equal_strings ( const char *  first,
                              const char *  second
                            )
   inlinestatic

   Compares two strings for equality.

   This function compares two strings for equality.


<h3><pre>Parameters</pre></h3>


          first  The first string to compare.
          second The second string to compare.


<h3><pre>Returns</pre></h3>


          Returns 1 if the strings are equal, 0 otherwise.
 <h2>file_exists()</h2>

   FOUNDATIONAL_LIB_FUNC int file_exists ( const char *  filename )

   Checks if a file exists.

   This function checks if the specified file exists in the file system.


<h3><pre>Parameters</pre></h3>


          filename Pointer to the name of the file to be checked for existence.


<h3><pre>Returns</pre></h3>


          Returns 1 if the file exists, and 0 otherwise.
 <h2>file_is_directory()</h2>

            FOUNDATIONAL_LIB_FUNC int file_is_directory ( const char *
   filename )

   Checks if a file is a directory.

   This function checks if the specified file is a directory in the file
   system.


<h3><pre>Parameters</pre></h3>


          filename Pointer to the name of the file to be checked.


<h3><pre>Returns</pre></h3>


          Returns 1 if the file is a directory, and 0 otherwise.
 <h2>file_is_executable()</h2>

            FOUNDATIONAL_LIB_FUNC int file_is_executable ( const char *
   filename )

   Checks if a file is executable.

   This function checks if the specified file is executable by the current
   process.


<h3><pre>Parameters</pre></h3>


   filename Pointer to the name of the file to be checked for
   executability.


<h3><pre>Returns</pre></h3>


          Returns 1 if the file is executable, and 0 otherwise.
 <h2>file_is_readable()</h2>

            FOUNDATIONAL_LIB_FUNC int file_is_readable ( const char *
   filename )

   Checks if a file is readable.

   This function checks if the specified file is readable by the current
   process.


<h3><pre>Parameters</pre></h3>


         filename Pointer to the name of the file to be checked for readability.


<h3><pre>Returns</pre></h3>


          Returns 1 if the file is readable, and 0 otherwise.
 <h2>file_is_regular()</h2>

            FOUNDATIONAL_LIB_FUNC int file_is_regular ( const char *
   filename )

   Checks if a file is a regular file.

   This function checks if the specified file is a regular file in the
   file system.


<h3><pre>Parameters</pre></h3>


          filename Pointer to the name of the file to be checked.


<h3><pre>Returns</pre></h3>


          Returns 1 if the file is a regular file, and 0 otherwise.
 <h2>file_is_writable()</h2>

            FOUNDATIONAL_LIB_FUNC int file_is_writable ( const char *
   filename )

   Checks if a file is writable.

   This function checks if the specified file is writable by the current
   process.


<h3><pre>Parameters</pre></h3>


         filename Pointer to the name of the file to be checked for writability.


<h3><pre>Returns</pre></h3>


          Returns 1 if the file is writable, and 0 otherwise.
 <h2>filter_data()</h2>

   FOUNDATIONAL_LIB_FUNC size_t filter_data ( void *          source,
                                                    size_t          source_size,
                                                    size_t          elem_size,
                                                    void *          destination,
                                                    size_t          dest_size,
                                                    int(*)(void *)  condition
                                                  )

   Filters elements of an array (void* version) based on a specified
   condition.

   This function applies a user-defined condition to filter elements from
   the source array with support for generic data types using void
   pointers. The filtered elements are stored in the destination array.


<h3><pre>Parameters</pre></h3>


   source Pointer to the source array to be filtered.
   source_size Size of the source array.
   elem_size Size of each element in bytes.
   destination Pointer to the destination array to store filtered
   elements.
   dest_size Size of the destination array.
   condition Pointer to the condition function. The function should take a
   void pointer as input, which points to an individual element in the
   source array, and return an integer (boolean) indicating whether the
   element satisfies the condition.


<h3><pre>Returns</pre></h3>


          The number of elements that satisfy the condition and are stored
          in the destination array.


<h3><pre>Note</pre></h3>


          The destination array should have sufficient space to
          accommodate filtered elements.
          The user-defined condition function should be provided as a
          pointer.

   // Example condition function: check if the integer element is even
   int is_even_condition(void *element) {
   return (*(int *)element % 2 == 0);
   }
   // Example usage:
   int my_array[] = {1, 2, 3, 4, 5};
   int filtered_array; // Assuming the worst case where all elements
   satisfy the condition size_t num_filtered = filter_data(my_array,
   5, sizeof(int),
   filtered_array, 5, is_even_condition);
   // After the call, filtered_array will contain {2, 4}, and num_filtered
   will be 2
   filter_data
   FOUNDATIONAL_LIB_FUNC size_t filter_data(void *source, size_t
   source_size, size_t elem_size, void *destination, size_t dest_size,
   int(*condition)(void *))
   Filters elements of an array (void* version) based on a specified
   condition.
   Definition: foundationallib.h:8540
 <h2>filter_filesystem_files_as_strings()</h2>

   FOUNDATIONAL_LIB_FUNC int filter_filesystem_files_as_strings (
   const char *  directory,
   int(*)(const char *filename)  filter_function
   )

   Applies a filter operation on files in the specified directory.

   This function iterates through the files in the given directory and
   applies the provided filter function to each file. The filter function
   should return 1 to keep the file or 0 to delete it. The overall result
   of the filter operation is returned by this function.


<h3><pre>Parameters</pre></h3>


   directory The path to the directory containing the files to be
   filtered.
   filter_function A pointer to the filter function that takes a filename
   as a parameter and returns 1 to keep the file or 0 to delete it.


<h3><pre>Returns</pre></h3>


          Returns -1 on error, 0 on non-error.
 <h2>filter_ints()</h2>

   FOUNDATIONAL_LIB_FUNC int filter_ints ( int *        source,
                                                 size_t       source_size,
                                                 int *        destination,
                                                 int(*)(int)  condition
                                               )

   Filters elements of an integer array based on a specified condition.

   This function applies a user-defined condition to filter elements from
   the source integer array and stores the filtered elements in the
   destination array.


<h3><pre>Parameters</pre></h3>


   source Pointer to the source integer array to be filtered.
   source_size Size of the source array.
   destination Pointer to the destination array to store filtered
   elements.
   condition Pointer to the condition function. The function should take
   an integer as input and return a boolean (int) indicating whether the
   element satisfies the condition.


<h3><pre>Returns</pre></h3>


          The number of elements that satisfy the condition and are stored
          in the destination array.


<h3><pre>Note</pre></h3>


          The destination array should have sufficient space to
          accommodate filtered elements.
          The user-defined condition function should be provided as a
          pointer.

   // Example condition function: check if the element is even
   int is_even_condition(int x) {
   return (x % 2 == 0);
   }
   // Example usage:
   int my_array[] = {1, 2, 3, 4, 5};
   int filtered_array; // Assuming the worst case where all elements
   satisfy the condition size_t num_filtered = filter_ints(my_array,
   5,
   filtered_array, is_even_condition);
   // After the call, filtered_array will contain {2, 4}, and num_filtered
   will be 2
   filter_ints
   FOUNDATIONAL_LIB_FUNC int filter_ints(int *source, size_t source_size,
   int *destination, int(*condition)(int))
   Filters elements of an integer array based on a specified condition.
   Definition: foundationallib.h:8383
 <h2>find_first_of()</h2>

   FOUNDATIONAL_LIB_FUNC ssize_t find_first_of ( const char *  str,
                                                       const char *  char_set
                                                     )

   Finds the first occurrence of any character from a set in a string.

   Searches the given null-terminated string for the first occurrence of
   any character from the specified character set. Returns the index of
   the first matching character if found; otherwise, returns -1.


<h3><pre>Parameters</pre></h3>


          str      The input string to search within.
          char_set The set of characters to look for in the string.


<h3><pre>Returns</pre></h3>


          The index of the first matching character, or -1 if not found.
 <h2>find_last_of()</h2>

   FOUNDATIONAL_LIB_FUNC ssize_t find_last_of ( const char *  str,
                                                      const char *  char_set
                                                    )

   Finds the last occurrence of any character from a specified set within
   a given string.

   This function takes a string (str) and a character set (char_set) as
   input and searches for the last occurrence of any character from the
   specified set within the string.


<h3><pre>Parameters</pre></h3>


          str      The input string to be searched.
          char_set The set of characters to look for in the string.


<h3><pre>Returns</pre></h3>


          Returns the index of the last occurrence if found; otherwise,
          returns -1.
 <h2>find_max_int_in_array()</h2>

   FOUNDATIONAL_LIB_FUNC int find_max_int_in_array ( const int *
   array,
                                                           size_t       size
                                                         )

   Finds the maximum element in an array of integers.

   This function determines the maximum element in the given array of
   integers.


<h3><pre>Parameters</pre></h3>


          array Pointer to the array of integers.
          size  Size of the array.


<h3><pre>Returns</pre></h3>


          Maximum element in the array.
 <h2>find_min_int_in_array()</h2>

   FOUNDATIONAL_LIB_FUNC int find_min_int_in_array ( const int *
   array,
                                                           size_t       size
                                                         )

   Finds the minimum element in an array of integers.

   This function determines the minimum element in the given array of
   integers.


<h3><pre>Parameters</pre></h3>


          array Pointer to the array of integers.
          size  Size of the array.


<h3><pre>Returns</pre></h3>


          Minimum element in the array.
 <h2>FOUNDATIONAL_LIB_cmp_char_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_char_ptrs ( const
   void *  a,
   const void *  b
   )

   Compare function for sorting pointers to chars.

   This function is used as a comparison function for qsort to sort an
   array of pointers to chars in ascending order.


<h3><pre>Parameters</pre></h3>


          a Pointer to the first element (pointer to char) to be compared.
          b Pointer to the second element (pointer to char) to be compared.


<h3><pre>Returns</pre></h3>


          Integer less than, equal to, or greater than zero if the first
          element is found to be less than, equal to, or greater than the
          second element.
 <h2>FOUNDATIONAL_LIB_cmp_chars()</h2>

   FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_chars ( const void
   *  a,
   const void *  b
   )

   Compare function for sorting chars.

   This function is used as a comparison function for qsort to sort an
   array of chars in ascending order.


<h3><pre>Parameters</pre></h3>


          a Pointer to the first element (char) to be compared.
          b Pointer to the second element (char) to be compared.


<h3><pre>Returns</pre></h3>


          Integer less than, equal to, or greater than zero if the first
          element is found to be less than, equal to, or greater than the
          second element.
 <h2>FOUNDATIONAL_LIB_cmp_double_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_double_ptrs (
   const void *  a,
   const void *  b
   )

   Compare function for sorting pointers to doubles.

   This function is used as a comparison function for qsort to sort an
   array of pointers to doubles in ascending order.


<h3><pre>Parameters</pre></h3>


          a Pointer to the first element (pointer to double) to be compared.
          b Pointer to the second element (pointer to double) to be compared.


<h3><pre>Returns</pre></h3>


          Integer less than, equal to, or greater than zero if the first
          element is found to be less than, equal to, or greater than the
          second element.
 <h2>FOUNDATIONAL_LIB_cmp_doubles()</h2>

   FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_doubles ( const
   void *  a,
   const void *  b
   )

   Compare function for sorting doubles.

   This function is used as a comparison function for qsort to sort an
   array of doubles in ascending order.


<h3><pre>Parameters</pre></h3>


          a Pointer to the first element (double) to be compared.
          b Pointer to the second element (double) to be compared.


<h3><pre>Returns</pre></h3>


          Integer less than, equal to, or greater than zero if the first
          element is found to be less than, equal to, or greater than the
          second element.
 <h2>FOUNDATIONAL_LIB_cmp_float_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_float_ptrs ( const
   void *  a,
   const void *  b
   )

   Compare function for sorting pointers to floats.

   This function is used as a comparison function for qsort to sort an
   array of pointers to floats in ascending order.


<h3><pre>Parameters</pre></h3>


          a Pointer to the first element (pointer to float) to be compared.
          b Pointer to the second element (pointer to float) to be compared.


<h3><pre>Returns</pre></h3>


          Integer less than, equal to, or greater than zero if the first
          element is found to be less than, equal to, or greater than the
          second element.
 <h2>FOUNDATIONAL_LIB_cmp_floats()</h2>

   FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_floats ( const
   void *  a,
   const void *  b
   )

   Compare function for sorting floats.

   This function is used as a comparison function for qsort to sort an
   array of floats in ascending order.


<h3><pre>Parameters</pre></h3>


          a Pointer to the first element (float) to be compared.
          b Pointer to the second element (float) to be compared.


<h3><pre>Returns</pre></h3>


          Integer less than, equal to, or greater than zero if the first
          element is found to be less than, equal to, or greater than the
          second element.
 <h2>FOUNDATIONAL_LIB_cmp_int_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_int_ptrs ( const
   void *  a,
   const void *  b
   )

   Compare two pointers to integers for foundational library.

   This function is designed for use with sorting algorithms that require
   a comparison function, such as qsort. It compares two pointers to
   integers pointed to by a and b.


<h3><pre>Parameters</pre></h3>


          a Pointer to the first pointer to integer.
          b Pointer to the second pointer to integer.


<h3><pre>Returns</pre></h3>


          An integer less than, equal to, or greater than zero if the
          first pointer to integer is found to be less than, equal to, or
          greater than the second pointer to integer, respectively.
 <h2>FOUNDATIONAL_LIB_cmp_ints()</h2>

   FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_ints ( const void
   *  a,
   const void *  b
   )

   Compare two integers for foundational library.

   This function is designed for use with sorting algorithms that require
   a comparison function, such as qsort. It compares two integers pointed
   to by a and b.


<h3><pre>Parameters</pre></h3>


          a Pointer to the first integer.
          b Pointer to the second integer.


<h3><pre>Returns</pre></h3>


          An integer less than, equal to, or greater than zero if the
          first integer is found to be less than, equal to, or greater
          than the second integer, respectively.
 <h2>FOUNDATIONAL_LIB_cmp_long_long_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_long_long_ptrs (
   const void *  a,
   const void *  b
   )

   Compare function for sorting pointers to long longs.

   This function is used as a comparison function for qsort to sort an
   array of pointers to long longs in ascending order.


<h3><pre>Parameters</pre></h3>


          a Pointer to the first element (pointer to long long) to be compared.
          b Pointer to the second element (pointer to long long) to be compared.


<h3><pre>Returns</pre></h3>


          Integer less than, equal to, or greater than zero if the first
          element is found to be less than, equal to, or greater than the
          second element.
 <h2>FOUNDATIONAL_LIB_cmp_long_longs()</h2>

   FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_long_longs ( const
   void *  a,
   const void *  b
   )

   Compare function for sorting long longs.

   This function is used as a comparison function for qsort to sort an
   array of long longs in ascending order.


<h3><pre>Parameters</pre></h3>


          a Pointer to the first element (long long) to be compared.
          b Pointer to the second element (long long) to be compared.


<h3><pre>Returns</pre></h3>


          Integer less than, equal to, or greater than zero if the first
          element is found to be less than, equal to, or greater than the
          second element.
 <h2>FOUNDATIONAL_LIB_cmp_long_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_long_ptrs ( const
   void *  a,
   const void *  b
   )

   Compare function for sorting pointers to longs.

   This function is used as a comparison function for qsort to sort an
   array of pointers to longs in ascending order.


<h3><pre>Parameters</pre></h3>


          a Pointer to the first element (pointer to long) to be compared.
          b Pointer to the second element (pointer to long) to be compared.


<h3><pre>Returns</pre></h3>


          Integer less than, equal to, or greater than zero if the first
          element is found to be less than, equal to, or greater than the
          second element.
 <h2>FOUNDATIONAL_LIB_cmp_longs()</h2>

   FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_longs ( const void
   *  a,
   const void *  b
   )

   Compare function for sorting pointers to unsigned longs.

   This function is used as a comparison function for qsort to sort an
   array of pointers to unsigned longs in ascending order.


<h3><pre>Parameters</pre></h3>


   a Pointer to the first element (pointer to unsigned long) to be
   compared.
   b Pointer to the second element (pointer to unsigned long) to be
   compared.


<h3><pre>Returns</pre></h3>


          Integer less than, equal to, or greater than zero if the first
          element is found to be less than, equal to, or greater than the
          second element.
 <h2>FOUNDATIONAL_LIB_cmp_short_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_short_ptrs ( const
   void *  a,
   const void *  b
   )

   Compare function for sorting pointers to shorts.

   This function is used as a comparison function for qsort to sort an
   array of pointers to shorts in ascending order.


<h3><pre>Parameters</pre></h3>


          a Pointer to the first element (pointer to short) to be compared.
          b Pointer to the second element (pointer to short) to be compared.


<h3><pre>Returns</pre></h3>


          Integer less than, equal to, or greater than zero if the first
          element is found to be less than, equal to, or greater than the
          second element.
 <h2>FOUNDATIONAL_LIB_cmp_shorts()</h2>

   FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_shorts ( const
   void *  a,
   const void *  b
   )

   Compare function for sorting shorts.

   This function is used as a comparison function for qsort to sort an
   array of shorts in ascending order.


<h3><pre>Parameters</pre></h3>


          a Pointer to the first element (short) to be compared.
          b Pointer to the second element (short) to be compared.


<h3><pre>Returns</pre></h3>


          Integer less than, equal to, or greater than zero if the first
          element is found to be less than, equal to, or greater than the
          second element.
 <h2>FOUNDATIONAL_LIB_cmp_size_t_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_size_t_ptrs (
   const void *  a,
   const void *  b
   )

   Compare function for sorting pointers to size_t values.

   This function is used as a comparison function for qsort to sort an
   array of pointers to size_t values in ascending order.


<h3><pre>Parameters</pre></h3>


          a Pointer to the first element (pointer to size_t) to be compared.
          b Pointer to the second element (pointer to size_t) to be compared.


<h3><pre>Returns</pre></h3>


          Integer less than, equal to, or greater than zero if the first
          element is found to be less than, equal to, or greater than the
          second element.
 <h2>FOUNDATIONAL_LIB_cmp_size_ts()</h2>

   FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_size_ts ( const
   void *  a,
   const void *  b
   )

   Compare function for sorting size_t values.

   This function is used as a comparison function for qsort to sort an
   array of size_t values in ascending order.


<h3><pre>Parameters</pre></h3>


          a Pointer to the first element (size_t) to be compared.
          b Pointer to the second element (size_t) to be compared.


<h3><pre>Returns</pre></h3>


          Integer less than, equal to, or greater than zero if the first
          element is found to be less than, equal to, or greater than the
          second element.
 <h2>FOUNDATIONAL_LIB_cmp_uchar_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_uchar_ptrs ( const
   void *  a,
   const void *  b
   )

   Compare function for sorting pointers to unsigned chars.

   This function is used as a comparison function for qsort to sort an
   array of pointers to unsigned chars in ascending order.


<h3><pre>Parameters</pre></h3>


   a Pointer to the first element (pointer to unsigned char) to be
   compared.
   b Pointer to the second element (pointer to unsigned char) to be
   compared.


<h3><pre>Returns</pre></h3>


          Integer less than, equal to, or greater than zero if the first
          element is found to be less than, equal to, or greater than the
          second element.
 <h2>FOUNDATIONAL_LIB_cmp_uchars()</h2>

   FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_uchars ( const
   void *  a,
   const void *  b
   )

   Compare function for sorting unsigned chars.

   This function is used as a comparison function for qsort to sort an
   array of unsigned chars in ascending order.


<h3><pre>Parameters</pre></h3>


          a Pointer to the first element to be compared.
          b Pointer to the second element to be compared.


<h3><pre>Returns</pre></h3>


          Integer less than, equal to, or greater than zero if the first
          element is found to be less than, equal to, or greater than the
          second element.
 <h2>FOUNDATIONAL_LIB_cmp_uint_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_uint_ptrs ( const
   void *  a,
   const void *  b
   )

   Compare two pointers to unsigned integers for foundational library.

   This function is designed for use with sorting algorithms that require
   a comparison function, such as qsort. It compares two pointers to
   unsigned integers pointed to by a and b.


<h3><pre>Parameters</pre></h3>


          a Pointer to the first pointer to unsigned integer.
          b Pointer to the second pointer to unsigned integer.


<h3><pre>Returns</pre></h3>


          An integer less than, equal to, or greater than zero if the
          first pointer to unsigned integer is found to be less than,
          equal to, or greater than the second pointer to unsigned
          integer, respectively.
 <h2>FOUNDATIONAL_LIB_cmp_uints()</h2>

   FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_uints ( const void
   *  a,
   const void *  b
   )

   Compare two unsigned integers for foundational library.

   This function is designed for use with sorting algorithms that require
   a comparison function, such as qsort. It compares two unsigned integers
   pointed to by a and b.


<h3><pre>Parameters</pre></h3>


          a Pointer to the first unsigned integer.
          b Pointer to the second unsigned integer.


<h3><pre>Returns</pre></h3>


          An integer less than, equal to, or greater than zero if the
          first unsigned integer is found to be less than, equal to, or
          greater than the second unsigned integer, respectively.
 <h2>FOUNDATIONAL_LIB_cmp_ulong_long_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_ulong_long_ptrs (
   const void *  a,
   const void *  b
   )

   Compare function for sorting pointers to unsigned long longs.

   This function is used as a comparison function for qsort to sort an
   array of pointers to unsigned long longs in ascending order.


<h3><pre>Parameters</pre></h3>


   a Pointer to the first element (pointer to unsigned long long) to be
   compared.
   b Pointer to the second element (pointer to unsigned long long) to be
   compared.


<h3><pre>Returns</pre></h3>


          Integer less than, equal to, or greater than zero if the first
          element is found to be less than, equal to, or greater than the
          second element.
 <h2>FOUNDATIONAL_LIB_cmp_ulong_longs()</h2>

   FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_ulong_longs (
   const void *  a,
   const void *  b
   )

   Compare function for sorting unsigned long longs.

   This function is used as a comparison function for qsort to sort an
   array of unsigned long longs in ascending order.


<h3><pre>Parameters</pre></h3>


          a Pointer to the first element (unsigned long long) to be compared.
          b Pointer to the second element (unsigned long long) to be compared.


<h3><pre>Returns</pre></h3>


          Integer less than, equal to, or greater than zero if the first
          element is found to be less than, equal to, or greater than the
          second element.
 <h2>FOUNDATIONAL_LIB_cmp_ulong_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_ulong_ptrs ( const
   void *  a,
   const void *  b
   )

   Compare function for sorting pointers to unsigned longs.

   This function is used as a comparison function for qsort to sort an
   array of pointers to unsigned longs in ascending order.


<h3><pre>Parameters</pre></h3>


   a Pointer to the first element (pointer to unsigned long) to be
   compared.
   b Pointer to the second element (pointer to unsigned long) to be
   compared.


<h3><pre>Returns</pre></h3>


          Integer less than, equal to, or greater than zero if the first
          element is found to be less than, equal to, or greater than the
          second element.
 <h2>FOUNDATIONAL_LIB_cmp_ulongs()</h2>

   FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_ulongs ( const
   void *  a,
   const void *  b
   )

   Compare function for sorting unsigned longs.

   This function is used as a comparison function for qsort to sort an
   array of unsigned longs in ascending order.


<h3><pre>Parameters</pre></h3>


          a Pointer to the first element (unsigned long) to be compared.
          b Pointer to the second element (unsigned long) to be compared.


<h3><pre>Returns</pre></h3>


          Integer less than, equal to, or greater than zero if the first
          element is found to be less than, equal to, or greater than the
          second element.
 <h2>FOUNDATIONAL_LIB_cmp_ushort_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_ushort_ptrs (
   const void *  a,
   const void *  b
   )

   Compare function for sorting pointers to unsigned shorts.

   This function is used as a comparison function for qsort to sort an
   array of pointers to unsigned shorts in ascending order.


<h3><pre>Parameters</pre></h3>


   a Pointer to the first element (pointer to unsigned short) to be
   compared.
   b Pointer to the second element (pointer to unsigned short) to be
   compared.


<h3><pre>Returns</pre></h3>


          Integer less than, equal to, or greater than zero if the first
          element is found to be less than, equal to, or greater than the
          second element.
 <h2>FOUNDATIONAL_LIB_cmp_ushorts()</h2>

   FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmp_ushorts ( const
   void *  a,
   const void *  b
   )

   Compare function for sorting unsigned shorts.

   This function is used as a comparison function for qsort to sort an
   array of unsigned shorts in ascending order.


<h3><pre>Parameters</pre></h3>


          a Pointer to the first element (unsigned short) to be compared.
          b Pointer to the second element (unsigned short) to be compared.


<h3><pre>Returns</pre></h3>


          Integer less than, equal to, or greater than zero if the first
          element is found to be less than, equal to, or greater than the
          second element.
 <h2>FOUNDATIONAL_LIB_cmpstringp()</h2>

   FOUNDATIONAL_LIB_FUNC int FOUNDATIONAL_LIB_cmpstringp ( const
   void *  p1,
   const void *  p2
   )

   Compare two strings pointed to by pointers for foundational library.

   This function is designed for use with sorting algorithms that require
   a comparison function, such as qsort. It compares two strings pointed
   to by p1 and p2.


<h3><pre>Parameters</pre></h3>


          p1 Pointer to the first string.
          p2 Pointer to the second string.


<h3><pre>Returns</pre></h3>


          An integer less than, equal to, or greater than zero if the
          first string is found to be less than, equal to, or greater than
          the second string, respectively.
 <h2>FOUNDATIONAL_LIB_list_comprehension_worker()</h2>

   FOUNDATIONAL_LIB_FUNC int
   FOUNDATIONAL_LIB_list_comprehension_worker ( void *  data )
 <h2>FOUNDATIONAL_LIB_REALLOC_REALLOCATION_ALGORITHM()</h2>

   static size_t FOUNDATIONAL_LIB_REALLOC_REALLOCATION_ALGORITHM ( size_t
   siz                                                           )
   inlinestatic
 <h2>FOUNDATIONAL_LIB_safe_add_2()</h2>

   static FOUNDATIONAL_LIB_CONST size_t FOUNDATIONAL_LIB_safe_add_2 (
   size_t  a,
   size_t  b
   )
   inlinestatic

   Safely add 2 numbers to avoid unsigned integer overflows and security
   and stability issues. We never, NEVER want any of those things. Ever.
 <h2>FOUNDATIONAL_LIB_safe_add_2_ptr()</h2>

   static size_t FOUNDATIONAL_LIB_safe_add_2_ptr ( size_t    a,
                                                   size_t    b,
                                                   size_t *  ptr
                                                 )
   inlinestatic

   Safely add 2 numbers to avoid unsigned integer overflows and security
   and stability issues. We never, NEVER want any of those things. Ever.
 <h2>FOUNDATIONAL_LIB_safe_add_3()</h2>

   static FOUNDATIONAL_LIB_CONST size_t FOUNDATIONAL_LIB_safe_add_3 (
   size_t  a,
   size_t  b,
   size_t  c
   )
   inlinestatic

   Safely add 3 numbers to avoid unsigned integer overflows and security
   and stability issues. We never, NEVER want any of those things. Ever.
 <h2>FOUNDATIONAL_LIB_safe_add_3_ptr()</h2>

   static int FOUNDATIONAL_LIB_safe_add_3_ptr ( size_t    a,
                                                size_t    b,
                                                size_t    c,
                                                size_t *  ptr
                                              )
   inlinestatic

   Safely add 3 numbers to avoid unsigned integer overflows and security
   and stability issues. We never, NEVER want any of those things. Ever.
 <h2>FOUNDATIONAL_LIB_safe_mul()</h2>

   static size_t FOUNDATIONAL_LIB_safe_mul ( size_t  a,
                                             size_t  b
                                           )
   inlinestatic

   Safely multiply 2 numbers to avoid unsigned integer overflows and
   security and stability issues. We never, NEVER want any of those
   things. Ever.
 <h2>FOUNDATIONAL_LIB_safe_mul_ptr()</h2>

   static size_t FOUNDATIONAL_LIB_safe_mul_ptr ( size_t    a,
                                                 size_t    b,
                                                 size_t *  ptr
                                               )
   inlinestatic

   Safely multiply 2 numbers to avoid unsigned integer overflows and
   security and stability issues. We never, NEVER want any of those
   things. Ever.
 <h2>FOUNDATIONAL_LIB_STATIC_ASSERT_MSG()</h2>

   FOUNDATIONAL_LIB_STATIC_ASSERT_MSG ( (sizeof(size_t)<=8
   &&FOUNDATIONAL_LIB_SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATO
   R >=21)  ,
   "Increase SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATOR to more than
   21"
   )
 <h2>free_array()</h2>

   static void free_array ( void **  array,
                            size_t   len
                          )
   inlinestatic

   Frees a dynamic array and its elements up to one level deep.

   This function releases the memory allocated for the array and its
   elements, assuming a two-dimensional structure with one level of
   indirection.


<h3><pre>Parameters</pre></h3>


          array The pointer to the dynamic array.
          len   The length of the array.
 <h2>free_string_array()</h2>

   static void free_string_array ( char **  array,
                                   size_t   len
                                 )
   inlinestatic

   Frees a dynamic string array and its elements up to one level deep.

   This function releases the memory allocated for the string array and
   its elements, assuming a two-dimensional structure with one level of
   indirection.


<h3><pre>Parameters</pre></h3>


          array The pointer to the array of strings
          len   The length of the array.
 <h2>frozen_dict_del_keys()</h2>

   static void frozen_dict_del_keys ( char **  keys )
   inlinestatic

   Deletes keys from a frozen dictionary.

   This function deletes keys from a frozen dictionary.


<h3><pre>Parameters</pre></h3>


          keys The keys to delete.
 <h2>frozen_dict_del_values()</h2>

   static void frozen_dict_del_values ( void **  values )
   inlinestatic

   Deletes values from a frozen dictionary.

   This function deletes values from a frozen dictionary.


<h3><pre>Parameters</pre></h3>


          values The values to delete.
 <h2>frozen_dict_destructor()</h2>

   FOUNDATIONAL_LIB_FUNC void frozen_dict_destructor ( struct
   FrozenDict *  dict )

   Deallocates memory associated with a frozen dictionary, freeing
   resources.

   This function serves as the destructor for the provided frozen
   dictionary, freeing the memory allocated for the immutable hash table
   and its elements. It is important to call this function to prevent
   memory leaks when a frozen dictionary is no longer needed.


<h3><pre>Parameters</pre></h3>


          dict A pointer to the frozen dictionary instance to be deallocated.
 <h2>frozen_dict_get()</h2>

   FOUNDATIONAL_LIB_FUNC void* frozen_dict_get ( struct
   FrozenDict *  dict,
   const char *  key
   )

   Retrieves the value associated with the specified key from the frozen
   dictionary.

   This function retrieves the value associated with the provided key from
   the immutable frozen dictionary. If the key is found, it returns a
   pointer to the associated value; otherwise, it returns NULL.


<h3><pre>Parameters</pre></h3>


          dict A pointer to the frozen dictionary instance.
          key  The key for which the associated value is to be retrieved.


<h3><pre>Returns</pre></h3>


          Returns a pointer to the value associated with the key if
          present, or NULL if the key is not found.
 <h2>frozen_dict_get_check()</h2>

   FOUNDATIONAL_LIB_FUNC void* frozen_dict_get_check ( struct
   FrozenDict *  dict,
   const char *  key,
   int *  key_is_in_dict
   )

   Retrieves the value associated with the specified key from the frozen
   dictionary.

   This function retrieves the value associated with the provided key from
   the immutable frozen dictionary. If the key is found, it returns a
   pointer to the associated value and sets key_is_in_dict to 1 (true);
   otherwise, it returns NULL and sets key_is_in_dict to 0 (false).


<h3><pre>Parameters</pre></h3>


   dict A pointer to the frozen dictionary instance.
   key The key for which the associated value is to be retrieved.
   key_is_in_dict A pointer to an integer that is set to 1 if the key is
   in the dictionary, and 0 if the key is not found.


<h3><pre>Returns</pre></h3>


          Returns a pointer to the value associated with the key if
          present, or NULL if the key is not found.
 <h2>frozen_dict_iter()</h2>

   FOUNDATIONAL_LIB_FUNC void frozen_dict_iter ( struct
   FrozenDict *  frozen_dict,
   void(*)(char *key, void *value)  callback
   )

   Iterates through the key-value pairs in the FrozenDict, applying
   a callback function.

   This function iterates through the key-value pairs in the provided
   FrozenDict and applies the specified callback function to each
   pair. The callback function takes a key and a value as parameters and
   is applied for each element in the FrozenDict.


<h3><pre>Parameters</pre></h3>


   dict A pointer to the FrozenDict instance.
   callback A function pointer to the callback function taking a key and a
   value as parameters.
 <h2>frozen_dict_new_instance()</h2>

   FOUNDATIONAL_LIB_FUNC struct FrozenDict*
   frozen_dict_new_instance ( size_t  num_pairs,
     ...
   )

   Creates a new instance of a frozen dictionary.

   This function creates a new instance of a frozen dictionary, which is
   an immutable hash table containing the specified key-value pairs. The
   key-value pairs are provided as variable arguments with the format
   (const char *key, void *value).


<h3><pre>Parameters</pre></h3>


          num_pairs The number of key-value pairs provided as arguments.
          ...       Variable arguments representing key-value pairs.


<h3><pre>Returns</pre></h3>


          Returns a pointer to the newly created frozen dictionary
          instance.
 <h2>frozen_dict_size()</h2>

   FOUNDATIONAL_LIB_FUNC size_t frozen_dict_size ( struct
   FrozenDict *  dict )

   Returns the number of key-value pairs in the frozen dictionary.

   This function returns the current size, representing the number of
   key-value pairs, in the provided frozen dictionary.


<h3><pre>Parameters</pre></h3>


          dict A pointer to the frozen dictionary instance.


<h3><pre>Returns</pre></h3>


          Returns the number of key-value pairs in the frozen dictionary.
 <h2>frozen_dict_to_array()</h2>

   FOUNDATIONAL_LIB_FUNC size_t frozen_dict_to_array ( struct
   FrozenDict *  dict,
   char ***  keys,
   void ***  values,
   size_t *  size_of_keys_and_values
   )

   Converts the key-value pairs from the frozen dictionary into separate
   arrays for keys and values.

   This function converts the key-value pairs from the provided frozen
   dictionary into separate arrays for keys and values. The resulting
   arrays are allocated dynamically and should be freed by the caller when
   no longer needed. The size_of_keys_and_values parameter is set to the
   number of key-value pairs in the frozen dictionary.


<h3><pre>Parameters</pre></h3>


   dict A pointer to the frozen dictionary instance.
   keys A pointer to store the dynamically allocated array of keys.
   values A pointer to store the dynamically allocated array of values.
   size_of_keys_and_values A pointer to store the size of the resulting
   arrays.


<h3><pre>Returns</pre></h3>


          Returns -1 on error, 0 on success.


<h3><pre>Note</pre></h3>


          The caller is responsible for freeing the memory allocated for
          keys and values arrays using dict_del_keys() and
          dict_del_values() (or just free() - these have the same
          effect) when they are no longer needed.
 <h2>frozen_dict_to_string()</h2>

   FOUNDATIONAL_LIB_FUNC char* frozen_dict_to_string ( struct
   FrozenDict *  dict,
   int  pointer_or_string
   )

   Converts a FrozenDict (frozen dictionary) to a string
   representation.

   This function converts the provided frozen dictionary to a string
   representation. The resulting string can either contain pointers to the
   key-value pairs (pointer format) or the actual key-value pairs as
   strings (string format). The choice is determined by the
   pointer_or_string parameter, where 0 represents the pointer format and
   1 represents the string format.


<h3><pre>Parameters</pre></h3>


   dict A pointer to the frozen dictionary instance.
   pointer_or_string Determines the format of the resulting string (0 =
   pointer, 1 = string).


<h3><pre>Returns</pre></h3>


          Returns a dynamically allocated string representing the frozen
          dictionary.


<h3><pre>Note</pre></h3>


          The caller is responsible for freeing the memory allocated for
          the resulting string using free() when it is no longer needed.
 <h2>frozen_set_del_keys()</h2>

   FOUNDATIONAL_LIB_FUNC void frozen_set_del_keys ( char **  keys )

   Deletes keys from a FrozenSet.

   This function deletes keys from a FrozenSet data structure and
   frees the memory allocated for the keys.


<h3><pre>Parameters</pre></h3>


          keys The keys to delete and free.
 <h2>frozen_set_destructor()</h2>

   FOUNDATIONAL_LIB_FUNC void frozen_set_destructor ( struct
   FrozenSet *  frozen_set )

   The destructor for a Frozen Set.

   This function sets the destructor for a Set data structure.


<h3><pre>Parameters</pre></h3>


          dict The Frozen Set data structure.
 <h2>frozen_set_in()</h2>

   FOUNDATIONAL_LIB_FUNC int frozen_set_in ( struct FrozenSet
   *  set,
   const char *  key
   )

   Checks if a key is in a FrozenSet.

   This function checks if a key is present in a FrozenSet data
   structure.


<h3><pre>Parameters</pre></h3>


          set The FrozenSet data structure.
          key The key to check.


<h3><pre>Returns</pre></h3>


          Returns 1 if the key is present, 0 otherwise.
 <h2>frozen_set_iter()</h2>

 FOUNDATIONAL_LIB_FUNC void frozen_set_iter ( struct Set *
   set,
                                                    void(*)(char *key)  callback
                                                  )

   Iterates over a Set and applies a callback to each key.

   This function iterates over a Set data structure and applies a
   callback function to each key. The callback function should take a
   single parameter, a pointer to a char representing the key.


<h3><pre>Parameters</pre></h3>


          set      The Set data structure.
          callback The callback function to apply to each key.
 <h2>frozen_set_new_instance()</h2>

   FOUNDATIONAL_LIB_FUNC struct FrozenSet*
   frozen_set_new_instance ( size_t  num_args,
     ...
   )

   Creates a new instance of a FrozenSet.

   This function creates a new instance of a FrozenSet data
   structure.


<h3><pre>Parameters</pre></h3>


          num_args The number of arguments provided.
          ...      The variable arguments representing keys.


<h3><pre>Returns</pre></h3>


          Returns a pointer to the new FrozenSet instance.
 <h2>frozen_set_size()</h2>

   FOUNDATIONAL_LIB_FUNC size_t frozen_set_size ( struct
   FrozenSet *  set )

   Returns the size of a FrozenSet.

   This function returns the size of a FrozenSet data structure.


<h3><pre>Parameters</pre></h3>


          set The FrozenSet data structure.


<h3><pre>Returns</pre></h3>


          Returns the size of the FrozenSet.
 <h2>frozen_set_to_array()</h2>

   FOUNDATIONAL_LIB_FUNC int frozen_set_to_array ( struct
   FrozenSet *  set,
   char ***  keys,
   size_t *  size_of_keys
   )

   Converts a FrozenSet to an array of keys.

   This function converts a FrozenSet data structure to an array of
   keys.


<h3><pre>Parameters</pre></h3>


          set          The FrozenSet data structure.
          keys         A pointer to the array of keys.
          size_of_keys A pointer to the size of the array.


<h3><pre>Returns</pre></h3>


          Returns 1 on success, 0 on failure.
 <h2>frozen_set_to_string()</h2>

   FOUNDATIONAL_LIB_FUNC char* frozen_set_to_string ( struct
   FrozenSet *  frozen_set )

   Converts a frozen set to a string representation.

   This function converts the provided frozen set to a string
   representation.


<h3><pre>Parameters</pre></h3>


          set A pointer to the frozen set instance.


<h3><pre>Returns</pre></h3>


          Returns a dynamically allocated string representing the frozen
          set.


<h3><pre>Note</pre></h3>


          The caller is responsible for freeing the memory allocated for
          the resulting string using free() when it is no longer needed.
 <h2>generate_range()</h2>

   FOUNDATIONAL_LIB_FUNC size_t* generate_range ( size_t    start,
                                                        size_t    end,
                                                        size_t    step,
                                                        size_t *  range_size
                                                      )

   Generates a range of integers.

   This function creates an array of integers within the specified range
   and step.


<h3><pre>Parameters</pre></h3>


          start      Starting value of the range.
          end        Ending value of the range.
          step       Step size between consecutive elements.
          range_size Pointer to store the size of the generated range.


<h3><pre>Returns</pre></h3>


          Pointer to the dynamically allocated array of integers
          representing the range. The caller is responsible for freeing
          the allocated memory.
 <h2>get_file_size()</h2>

   FOUNDATIONAL_LIB_FUNC int get_file_size ( const char *  filename,
                                                   size_t *      size
                                                 )

   Gets the size of a file.

   This function retrieves the size of the specified file and stores it in
   the variable pointed to by the 'size' parameter.


<h3><pre>Parameters</pre></h3>


       filename Pointer to the name of the file to get the size.
       size     Pointer to a variable where the size of the file will be stored.


<h3><pre>Returns</pre></h3>


          Returns 0 on success and -1 on error. The function fails if the
          file cannot be opened or if there is an error during the size
          retrieval.
 <h2>index_of_char()</h2>

   static ssize_t index_of_char ( const char *  str,
                                  char          chr
                                )
   inlinestatic

   Finds the index of the first occurrence of a specified character in a
   string.

   This function searches for the first occurrence of the given target
   character in the provided string and returns its index. If the
   character is not found, it returns -1.


<h3><pre>Parameters</pre></h3>


          str The null-terminated string to search.
          chr The character to locate within the string.


<h3><pre>Returns</pre></h3>


          The index of the target character in the string, or -1 if not
          found.
 <h2>int_to_string()</h2>

   FOUNDATIONAL_LIB_FUNC char* int_to_string ( long long int  number
   )

   Converts an integer to its string representation.

   This function takes an integer as input and returns a dynamically
   allocated character array containing its string representation.


<h3><pre>Parameters</pre></h3>


          number The integer to be converted.


<h3><pre>Returns</pre></h3>


          A pointer to the dynamically allocated string representation.
 <h2>int_to_string_with_buffer()</h2>

   FOUNDATIONAL_LIB_FUNC void int_to_string_with_buffer ( long long
   int  number,
   char *  buffer
   )

   Converts an integer to its string representation.

   This function takes an integer as input and returns a dynamically
   allocated character array containing its string representation.


<h3><pre>Parameters</pre></h3>


          number The integer to be converted.


<h3><pre>Returns</pre></h3>


          A pointer to the dynamically allocated string representation.
 <h2>ints_are_sorted_ascending()</h2>

   FOUNDATIONAL_LIB_FUNC int ints_are_sorted_ascending ( const int
   *  array,
   size_t  size
   )

   Checks if an array of integers is sorted in ascending order.

   This function examines the given array of integers to determine if it
   is sorted in ascending order.


<h3><pre>Parameters</pre></h3>


          array Pointer to the array of integers.
          size  Size of the array.


<h3><pre>Returns</pre></h3>


          1 if the array is sorted in ascending order, 0 otherwise.
 <h2>ints_are_sorted_descending()</h2>

   FOUNDATIONAL_LIB_FUNC int ints_are_sorted_descending ( const int
   *  array,
   size_t  size
   )

   Checks if an array of integers is sorted in descending order.

   This function examines the given array of integers to determine if it
   is sorted in descending order.


<h3><pre>Parameters</pre></h3>


          array Pointer to the array of integers.
          size  Size of the array.


<h3><pre>Returns</pre></h3>


          1 if the array is sorted in descending order, 0 otherwise.
 <h2>is_array_digit()</h2>

   FOUNDATIONAL_LIB_FUNC int is_array_digit ( const char **  array,
                                                    size_t         size
                                                  )

   Check if a string array contains only digits.

   This function determines whether all strings in the given array consist
   solely of digit characters ('0' to '9').


<h3><pre>Parameters</pre></h3>


          array Pointer to the array of strings to be checked.
          size  Number of elements in the array.


<h3><pre>Returns</pre></h3>


          Returns 1 (true) if all strings contain only digits, 0 (false)
          otherwise.


<h3><pre>Note</pre></h3>


          The function considers an empty or NULL array as containing only
          digits.
          If the array contains NULL pointers, they are treated as empty
          strings.


<h3><pre>Warning</pre></h3>


          This function assumes that the input strings are
          null-terminated. Use caution when using this function with
          non-null-terminated strings.

   Example usage:
   const char *myArray[] = {"123", "456", "789"};
   if (is_array_digit(myArray, 3)) {
   // All strings in the array are composed of digits.
   } else {
   // At least one string in the array contains non-digit characters.
   }
   is_array_digit
   FOUNDATIONAL_LIB_FUNC int is_array_digit(const char **array, size_t
   size)
   Check if a string array contains only digits.
   Definition: foundationallib.h:9489
 <h2>is_array_lower()</h2>

   FOUNDATIONAL_LIB_FUNC int is_array_lower ( const char **  array,
                                                    size_t         size
                                                  )

   Checks if a string array contains only lowercase characters.

   This function examines each string in the given array to determine if
   it contains only lowercase characters. The comparison is
   case-sensitive.


<h3><pre>Parameters</pre></h3>


          array Pointer to an array of strings.
          size  The number of elements in the array.


<h3><pre>Returns</pre></h3>


          Returns 1 if all strings in the array are composed of lowercase
          characters only. Returns 0 otherwise.
 <h2>is_array_upper()</h2>

   FOUNDATIONAL_LIB_FUNC int is_array_upper ( const char **  array,
                                                    size_t         size
                                                  )

   Checks if a string array contains only uppercase characters.

   This function examines each string in the given array to determine if
   it contains only uppercase characters. The comparison is
   case-sensitive.


<h3><pre>Parameters</pre></h3>


          array Pointer to an array of strings.
          size  The number of elements in the array.


<h3><pre>Returns</pre></h3>


          Returns 1 if all strings in the array are composed of uppercase
          characters only. Returns 0 otherwise.
 <h2>is_string_alpha()</h2>

     FOUNDATIONAL_LIB_FUNC int is_string_alpha ( const char *  string
   )

   Check if all characters in a string are alphanumeric.

   This function takes a null-terminated string as input and checks if all
   characters in the string are alphanumeric (either letters or digits).


<h3><pre>Parameters</pre></h3>


          str The input string to be checked for alphanumeric characters.


<h3><pre>Returns</pre></h3>


          Returns 1 (true) if all characters in the string are
          alphanumeric, 0 (false) otherwise. Returns 1 for an empty string
          as there are no non-alphanumeric characters to check.
 <h2>is_string_alphanumeric()</h2>

       FOUNDATIONAL_LIB_FUNC int is_string_alphanumeric ( const char *
   str )

   Determines whether a given string consists solely of alphanumeric
   characters.

   This function examines each character in the input string and verifies
   if it is an alphanumeric character. Alphanumeric characters include
   both letters (A-Z, a-z) and digits (0-9). The function returns a
   non-zero value if the string contains only alphanumeric characters;
   otherwise, it returns 0.


<h3><pre>Parameters</pre></h3>


          str Pointer to the input string to be checked.


<h3><pre>Returns</pre></h3>


          An integer indicating whether the string is alphanumeric
          (non-zero) or not (0).
 <h2>is_string_digit()</h2>

     FOUNDATIONAL_LIB_FUNC int is_string_digit ( const char *  string
   )

   Check if all characters in a string are digits.

   This function takes a null-terminated string as input and checks if all
   characters in the string are numeric digits (0-9).


<h3><pre>Parameters</pre></h3>


          str The input string to be checked for digit characters.


<h3><pre>Returns</pre></h3>


          Returns 1 (true) if all characters in the string are digits, 0
          (false) otherwise. Returns 1 for an empty string as there are no
          non-digit characters to check.
 <h2>is_string_lower()</h2>

     FOUNDATIONAL_LIB_FUNC int is_string_lower ( const char *  string
   )

   Check if all characters in a string are lowercase.

   This function takes a null-terminated string as input and checks if all
   characters in the string are lowercase letters.


<h3><pre>Parameters</pre></h3>


          str The input string to be checked for uppercase characters.


<h3><pre>Returns</pre></h3>


          Returns 1 (true) if all characters in the string are uppercase,
          0 (false) otherwise. Returns 1 for an empty string as there are
          no lowercase characters to check.
 <h2>is_string_numeric()</h2>

   FOUNDATIONAL_LIB_FUNC int is_string_numeric ( const char *  str )

   Checks if the provided string consists solely of numeric characters.

   This function iterates through each character in the given string,
   verifying whether it is a numeric digit. If a non-numeric character is
   encountered, the function concludes that the string contains characters
   other than digits and returns 0. Otherwise, if all characters are
   numeric, the function returns 1.


<h3><pre>Parameters</pre></h3>


          str Pointer to the input string to be checked.


<h3><pre>Returns</pre></h3>


          1 if the string contains only numeric characters, 0 otherwise.
 <h2>is_string_printable()</h2>

          FOUNDATIONAL_LIB_FUNC int is_string_printable ( const char *
   string )

   Check if all characters in a string are printable.

   This function determines whether all characters in the given string are
   printable. Printable characters are those that can be displayed or
   printed and include alphanumeric characters, punctuation, and
   whitespace, excluding control characters.


<h3><pre>Parameters</pre></h3>


          str Pointer to the null-terminated string to be checked.


<h3><pre>Returns</pre></h3>


          Returns 1 (true) if all characters are printable, 0 (false)
          otherwise.


<h3><pre>Note</pre></h3>


          The function considers a string with an empty or NULL pointer as
          printable.


<h3><pre>Warning</pre></h3>


          This function does not handle wide characters or multi-byte
          character encodings. It assumes a single-byte character encoding
          or UTF-8 with one byte per character. Use caution when using
          this function with multi-byte character strings.
 <h2>is_string_space()</h2>

     FOUNDATIONAL_LIB_FUNC int is_string_space ( const char *  string
   )

   Check if all characters in a string are spaces.

   This function takes a null-terminated string as input and checks if all
   characters in the string are whitespace characters, such as spaces or
   tabs.


<h3><pre>Parameters</pre></h3>


          str The input string to be checked for space characters.


<h3><pre>Returns</pre></h3>


          Returns 1 (true) if all characters in the string are spaces, 0
          (false) otherwise. Returns 1 for an empty string as there are no
          non-space characters to check.
 <h2>is_string_upper()</h2>

     FOUNDATIONAL_LIB_FUNC int is_string_upper ( const char *  string
   )

   Check if all characters in a string are uppercase.

   This function takes a null-terminated string as input and checks if all
   characters in the string are uppercase letters.


<h3><pre>Parameters</pre></h3>


          str The input string to be checked for uppercase characters.


<h3><pre>Returns</pre></h3>


          Returns 1 (true) if all characters in the string are uppercase,
          0 (false) otherwise. Returns 1 for an empty string as there are
          no lowercase characters to check.
 <h2>is_string_valid_integer()</h2>

   FOUNDATIONAL_LIB_FUNC int is_string_valid_integer ( const char *
   str                                                     )

   Checks if a string is a valid integer.

   This function examines the given string to determine if it represents a
   valid integer.


<h3><pre>Parameters</pre></h3>


          str Pointer to the string to be checked.


<h3><pre>Returns</pre></h3>


          1 if the string is a valid integer, 0 otherwise.
 <h2>is_valid_utf8()</h2>

   FOUNDATIONAL_LIB_FUNC int is_valid_utf8 ( const char *  str,
                                                   size_t        len
                                                 )

   Checks if a string is a valid UTF-8 sequence.

   This function checks if a string is a valid UTF-8 sequence.


<h3><pre>Parameters</pre></h3>


          str The string to check.
          len The length of the string.


<h3><pre>Returns</pre></h3>


          Returns 1 if the string is valid UTF-8, 0 otherwise.
 <h2>join()</h2>

   FOUNDATIONAL_LIB_FUNC char* join ( const char **  array,
                                            size_t         count,
                                            const char *   delimiter
                                          )

   Joins an array of strings into a single string using a specified
   delimiter.

   This function takes an array of strings, a count of elements in the
   array, and a delimiter. It concatenates the strings with the delimiter
   in between, creating a new dynamically allocated string. The caller is
   responsible for freeing the memory allocated for the resulting string.


<h3><pre>Parameters</pre></h3>


          array     An array of strings to be joined.
          count     The number of elements in the array.
          delimiter The string used as a delimiter between joined elements.


<h3><pre>Returns</pre></h3>


          A new string representing the joined elements, or NULL in case
          of errors. The caller should free the memory allocated for the
          resulting string.
 <h2>last_index_of_char()</h2>

   static ssize_t last_index_of_char ( const char *  str,
                                       char          chr
                                     )
   inlinestatic

   Finds the index of the last occurrence of a specified character in a
   given string.

   This function scans the provided string from the end to the beginning,
   searching for the last occurrence of the specified target character. If
   found, it returns the index of that occurrence; otherwise, it returns a
   special value indicating that the character was not found in the
   string.


<h3><pre>Parameters</pre></h3>


          str The input string to be searched.
          chr The character to be found within the string.


<h3><pre>Returns</pre></h3>


          The index of the last occurrence of the target character, or -1
          if not found.
 <h2>list_comprehension()</h2>

   FOUNDATIONAL_LIB_FUNC void* list_comprehension ( const void *
   input_array,
   size_t  array_size,
   size_t  elem_size,
   void(*)(void *value)  transform_func,
   int(*)(void *value)  filter_func,
   size_t *  result_size
   )

   Perform a list comprehension operation.

   This function applies a transformation function and a filter function
   to each element of the input array, creating a new array as a result.


<h3><pre>Parameters</pre></h3>


   input_array Pointer to the input array.
   array_size Size of the input array.
   elem_size Size of each element in the array.
   transform_func Pointer to the transformation function applied to each
   element.
   filter_func Pointer to the filter function determining inclusion in the
   result.
   result_size Pointer to store the size of the resulting array.


<h3><pre>Returns</pre></h3>


          Pointer to the dynamically allocated result array. Make sure to
          free() after.

   The list_comprehension function performs a list comprehension operation
   on the input array. It applies the provided transformation and filter
   functions to each element of the array, creating a new array containing
   only the elements that pass the filter condition.

   The transformation function is applied to each element to derive a
   modified value, and the filter function determines whether an element
   should be included in the result array.


<h3><pre>Note</pre></h3>


          The input_array is expected to contain homogeneous elements, and
          the transform_func and filter_func should be designed
          accordingly.


<h3><pre>Warning</pre></h3>


          The resulting array is dynamically allocated and should be freed
          by the caller using the free() function to avoid memory leaks.

   See also
          list_comprehension_multithreaded for a version of this
          function optimized for multi-threaded execution.


<h3><pre>Parameters</pre></h3>


   example_usage Example Usage:

   // Example Usage 1: Transform each element to its square and filter out
   even

   numbers size_t input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; size_t input_size
   =

   sizeof(input) / sizeof(input);

   // Transformation function: Square each element

   void square_transform(void *value) {

   size_t *num = (size_t *)value;

   *num = (*num) * (*num);

   }

   // Filter function: Include only odd numbers

   int odd_filter(void *value) {

   size_t *num = (size_t *)value;

   return (*num) % 2 != 0;

   }

   size_t result_size;

   size_t *result = (size_t *)list_comprehension(input, input_size,

   sizeof(size_t), square_transform, odd_filter, &result_size);

   // Use the result array

   free(result);

   list_comprehension

   FOUNDATIONAL_LIB_FUNC void * list_comprehension(const void
   *input_array, size_t array_size, size_t elem_size,
   void(*transform_func)(void *value), int(*filter_func)(void *value),
   size_t *result_size)

   Perform a list comprehension operation.

   Definition: foundationallib.h:8656

   // Example Usage 2: Transform each string to uppercase and filter out
   those

   starting with 'a' const char *words[] = {"apple", "banana", "orange",

   "grape", "kiwi"}; size_t words_size = sizeof(words) / sizeof(words);

   // Transformation function: Convert string to uppercase

   void uppercase_transform(void *value) {

   char **str = (char **)value;

   for (int i = 0; (*str)[i]; ++i) {

   (*str)[i] = toupper((*str)[i]);

   }

   }

   // Filter function: Exclude strings starting with 'a'

   int exclude_a_filter(void *value) {

   char **str = (char **)value;

   return (*str) != 'a' && (*str) != 'A';

   }

   size_t result_size;

   char **result = (char **)list_comprehension(words, words_size,
   sizeof(char

   *), uppercase_transform, exclude_a_filter, &result_size);

   // Use the result array

   free(result);
 <h2>list_comprehension_multithreaded()</h2>

   FOUNDATIONAL_LIB_FUNC void* list_comprehension_multithreaded (
   const void *  input_array,
   size_t  array_size,
   size_t  elem_size,
   void(*)(void *value)  transform_func,
   int(*)(void *value)  filter_func,
   size_t *  result_size,
   size_t  thread_count
   )

   Perform a list comprehension operation in a multithreaded fashion.

   This function applies a transformation function and a filter function
   to each element of the input array, creating a new array as a result.


<h3><pre>Parameters</pre></h3>


   input_array Pointer to the input array.
   array_size Size of the input array.
   elem_size Size of each element in the array.
   transform_func Pointer to the transformation function applied to each
   element.
   filter_func Pointer to the filter function determining inclusion in the
   result.
   result_size Pointer to store the size of the resulting array.
   thread_count Number of threads to use for parallel processing.


<h3><pre>Returns</pre></h3>


          Pointer to the dynamically allocated result array. Make sure to
          free() after.
 <h2>list_files_with_pattern()</h2>

   FOUNDATIONAL_LIB_FUNC char** list_files_with_pattern ( const char
   *  directory,
   const char *  pattern,
   size_t *  len
   )

   Lists files in a directory using a wildcard pattern.

   This function retrieves the list of files in the specified directory
   that match the specified wildcard pattern. The function returns an
   array of strings containing the file names. The length of the array is
   stored in the variable pointed to by the 'len' parameter. The caller is
   responsible for freeing the memory allocated for the returned array and
   each string within it using free() or simply using free_array().


<h3><pre>Parameters</pre></h3>


   directory Pointer to the name of the directory to list files from.
   pattern Pointer to the wildcard pattern for filtering files.
   len Pointer to a variable where the length of the file list array will
   be stored.


<h3><pre>Returns</pre></h3>


          Pointer to the dynamically allocated array of strings containing
          the file names. Returns NULL if there is an error or if no files
          match the pattern. The caller is responsible for freeing the
          memory using free().
 <h2>longest_common_prefix()</h2>

   FOUNDATIONAL_LIB_FUNC char* longest_common_prefix ( const char
   **  strings,
   size_t  count
   )

   Finds the longest common prefix among an array of strings.

   This function takes an array of strings and determines the longest
   common prefix shared by all strings. The input array 'strings' and its
   count 'count' are used to perform the comparison.


<h3><pre>Parameters</pre></h3>


   strings An array of C-style strings for which the common prefix is to
   be found.
   count The number of strings in the 'strings' array.


<h3><pre>Returns</pre></h3>


          A pointer to the longest common prefix string. If no common
          prefix is found, the function returns NULL.
 <h2>longest_common_suffix()</h2>

   FOUNDATIONAL_LIB_FUNC char* longest_common_suffix ( const char
   **  strings,
   size_t  count
   )

   Finds the longest common suffix among an array of strings.

   This function takes an array of strings and determines the longest
   common suffix shared by all the strings. The result is dynamically
   allocated, and the caller is responsible for freeing the memory when
   done using the returned string.


<h3><pre>Parameters</pre></h3>


          strings An array of strings to find the common suffix from.
          count   The number of strings in the array.


<h3><pre>Returns</pre></h3>


          A dynamically allocated string representing the longest common
          suffix. It is the caller's responsibility to free this memory
          using free().
 <h2>map()</h2>

   FOUNDATIONAL_LIB_FUNC void map ( void *           array,
                                          size_t           size,
                                          size_t           elem_size,
                                          void(*)(void *)  transform
                                        )

   Applies a transformation to each element of an array (void* version).

   This function applies a user-defined transformation to each element of
   the input array with support for generic data types using void
   pointers.


<h3><pre>Parameters</pre></h3>


   array Pointer to the array to be transformed.
   size Size of the array.
   elem_size Size of each element in bytes.
   transform Pointer to the transformation function. The function should
   take a void pointer as input, which points to an individual element in
   the array.


<h3><pre>Note</pre></h3>


          The input array is modified in place.
          The user-defined transformation function should be provided as a
          pointer.

   // Example transformation function: increment an integer element
   void increment_transform(void *element) {
   (*(int *)element)++;
   }
   // Example usage:
   int my_array[] = {1, 2, 3, 4, 5};
   map(my_array, 5, sizeof(int), increment_transform);
   // After the call, my_array will be {2, 3, 4, 5, 6}
   map
   FOUNDATIONAL_LIB_FUNC void map(void *array, size_t size, size_t
   elem_size, void(*transform)(void *))
   Applies a transformation to each element of an array (void* version).
   Definition: foundationallib.h:8430
 <h2>map_filesystem_files_as_strings()</h2>

   FOUNDATIONAL_LIB_FUNC int map_filesystem_files_as_strings ( const
   char *  directory,
   char *(*)(const char *file_string_data, size_t string_size)
   map_function
   )

   Applies a map operation on files in a directory, working with strings.

   This function applies the given map function to each file in the
   specified directory, treating the file content as a string. The map
   function is expected to take the file string data and its size as its
   input and return a dynamically allocated string which then will
   afterwards be written back to the corresponding file, in effect
   "mapping" all the files in the directory to a given function's result -
   establishing a level of easy power over the filesystem that is
   difficult in C. The caller is responsible for freeing the memory
   allocated by the map function.


<h3><pre>Parameters</pre></h3>


   directory The path to the directory containing files to be processed.
   map_function The map function to be applied to each file's string data.
   It should have the signature: char *(*map_function)(const char
   *file_string_data, size_t string_size). The map function should return
   a dynamically allocated string.


<h3><pre>Returns</pre></h3>


          Returns 0 on success (non-error) or -1 on error.
 <h2>map_ints()</h2>

   FOUNDATIONAL_LIB_FUNC void map_ints ( int *        array,
                                               size_t       size,
                                               int(*)(int)  transform
                                             )

   Applies a transformation to each element of an integer array.

   This function applies a user-defined transformation to each element of
   the input integer array and stores the results back in the array.


<h3><pre>Parameters</pre></h3>


   array Pointer to the integer array to be transformed.
   size Size of the array.
   transform Pointer to the transformation function. The function should
   take an integer as input and return an integer as the transformed
   result.


<h3><pre>Note</pre></h3>


          The input array is modified in place.
          The user-defined transformation function should be provided as a
          pointer.

   // Example transformation function: square the input
   int square_transform(int x) {
   return x * x;
   }
   // Example usage:
   int my_array[] = {1, 2, 3, 4, 5};
   map_ints(my_array, 5, square_transform);
   // After the call, my_array will be {1, 4, 9, 16, 25}
   map_ints
   FOUNDATIONAL_LIB_FUNC void map_ints(int *array, size_t size,
   int(*transform)(int))
   Applies a transformation to each element of an integer array.
   Definition: foundationallib.h:8290
 <h2>memmem()</h2>

   void* memmem ( const void *  haystack,
                  size_t        haystacklen,
                  const void *  needle,
                  size_t        needlelen
                )
 <h2>memory_has_subchunk()</h2>

   FOUNDATIONAL_LIB_FUNC int memory_has_subchunk ( void *  memory,
                                                         size_t  memory_length,
                                                         void *  subchunk,
                                                         size_t  subchunk_length
                                                       )

   Checks if a subchunk exists within a given memory block.

   This function examines the specified memory block to determine if a
   subchunk with the specified content and length is present.


<h3><pre>Parameters</pre></h3>


  memory          Pointer to the start of the memory block to search.
  memory_length   Length of the memory block in bytes.
  subchunk        Pointer to the subchunk to search for within the memory block.
  subchunk_length Length of the subchunk in bytes.


<h3><pre>Returns</pre></h3>


          Returns 1 (true) if the subchunk is found, 0 (false) otherwise.


<h3><pre>Note</pre></h3>


          This function assumes that the provided memory and subchunk
          pointers are valid and that the lengths are non-negative. It is
          the responsibility of the caller to ensure the correctness of
          the inputs to prevent undefined behavior.
 <h2>memory_locate()</h2>

   FOUNDATIONAL_LIB_FUNC void* memory_locate ( const void *
   haystack,
                                                     size_t        haystack_len,
                                                     const void *  needle,
                                                     size_t        needle_len
                                                   )
 <h2>prepend_string_to_array()</h2>

   FOUNDATIONAL_LIB_FUNC int prepend_string_to_array ( char ***
   array,
   size_t *  array_size,
   size_t *  array_current_alloc_size,
   char *  string
   )

   Prepends a new string element to the beginning of a dynamically
   allocated array of strings and updates its size.

   This function adds a new string element to the beginning of the
   specified array of strings. If the array has already been allocated
   with malloc, the function resizes it accordingly. If the array's
   current allocation size is 0, a new array is dynamically allocated.
   Memory is reallocated as needed to accommodate the new element, and
   existing elements are shifted to make room for the prepended element.
   The caller is responsible for freeing the memory allocated for the
   array.


<h3><pre>Parameters</pre></h3>


   array A pointer to the array of strings.
   array_size A pointer to the size_t variable representing the current
   size of the array.
   array_current_alloc_size A pointer to the size_t variable representing
   the current allocated size of the array.
   element The string element to be prepended.


<h3><pre>Returns</pre></h3>


          0 on success, -1 on error.


<h3><pre>Note</pre></h3>


          The caller should free the memory allocated for the array. Make
          sure that *array_current_alloc_size is initialized to 0 or a
          higher value when calling this function.
 <h2>prepend_string_to_array_no_initial_alloc()</h2>

   FOUNDATIONAL_LIB_FUNC int
   prepend_string_to_array_no_initial_alloc ( char ***  array,
   size_t *  array_size,
   size_t *  array_current_alloc_size,
   char *  string
   )

   Prepends a new string element to the beginning of a dynamically
   allocated array of strings and updates its size.

   This function adds a new string element to the beginning of the
   specified array of strings. If the array has already been allocated
   with malloc, the function resizes it accordingly. If the array's
   current allocation size is 0, an error will occur - do not do this.
   Memory is reallocated as needed to accommodate the new element, and
   existing elements are shifted to make room for the prepended element.
   The caller is responsible for freeing the memory allocated for the
   array.


<h3><pre>Parameters</pre></h3>


   array A pointer to the array of strings.
   array_size A pointer to the size_t variable representing the current
   size of the array.
   array_current_alloc_size A pointer to the size_t variable representing
   the current allocated size of the array.
   element The string element to be prepended.


<h3><pre>Returns</pre></h3>


          0 on success, -1 on error.


<h3><pre>Note</pre></h3>


          The caller should free the memory allocated for the array. This
          function is an optimization of prepend_string_to_array that
          doesn't check "if (*array_current_alloc_size == 0)" constantly.
          Use wisely. Make sure that *array_current_alloc_size is
          initialized to 0 or a higher value when calling this function.
 <h2>print_char()</h2>

   FOUNDATIONAL_LIB_FUNC void print_char ( const char  value )

   Prints a character value to the standard output.


<h3><pre>Parameters</pre></h3>


          value The character value to be printed.
 <h2>print_char_array_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_char_array_to_stream ( const
   char *  array,
   size_t  size,
   FILE *  stream
   )

   Prints the elements of a char array to a specified stream.

   This function takes a pointer to a char array, its size, and a FILE
   stream as parameters. It prints each element of the array to the
   specified stream.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the char array.
          size   Size of the array.
          stream FILE stream to which the elements are printed.
 <h2>print_char_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_char_to_stream ( const char
   value,
                                                           FILE *      stream
                                                         )

   Prints a character value to the specified stream.


<h3><pre>Parameters</pre></h3>


          value  The character value to be printed.
          stream The file stream where the output will be directed.
 <h2>print_double()</h2>

   FOUNDATIONAL_LIB_FUNC void print_double ( const double  value )

   Prints a double-precision floating-point value to the standard output.


<h3><pre>Parameters</pre></h3>


          value The double value to be printed.
 <h2>print_double_array()</h2>

   FOUNDATIONAL_LIB_FUNC void print_double_array ( const double *
   array,
                                                         size_t          size
                                                       )

   Prints the elements of a double array.

   This function takes a pointer to a double array and its size as
   parameters. It prints each element of the array to the standard output.


<h3><pre>Parameters</pre></h3>


          array Pointer to the double array.
          size  Size of the array.
 <h2>print_double_array_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_double_array_to_stream ( const
   double *  array,
   size_t  size,
   FILE *  stream
   )

   Outputs elements of a double array to a stream.

   This function takes an array of double values and a specified size,
   then writes each element to the provided file stream. Useful for
   displaying or logging double arrays in a human-readable format.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the double array.
          size   Size of the array.
          stream File stream to which the array elements will be written.
 <h2>print_double_ptr_array()</h2>

   FOUNDATIONAL_LIB_FUNC void print_double_ptr_array ( const double
   **  array,
   size_t  size
   )

   Prints the elements of a double array through a pointer.

   This function takes a pointer to a pointer to a double array and the
   size of the array as parameters. It prints each element of the array to
   the standard output.


<h3><pre>Parameters</pre></h3>


          array Pointer to a pointer to the double array.
          size  Size of the array.
 <h2>print_double_ptr_array_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_double_ptr_array_to_stream (
   const double **  array,
   size_t  size,
   FILE *  stream
   )

   Outputs elements of an array of pointers to double to a stream.

   This function takes an array of pointers to double values and a
   specified size, then writes each referenced double element to the
   provided file stream. Useful for displaying or logging arrays of
   pointers to double values.


<h3><pre>Parameters</pre></h3>


   array Pointer to the array of pointers to double.
   size Size of the array.
   stream File stream to which the referenced double elements will be
   written.
 <h2>print_double_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_double_to_stream ( const double
   value,
                                                             FILE *       stream
                                                           )

   Prints a double-precision floating-point value to the specified stream.


<h3><pre>Parameters</pre></h3>


          value  The double value to be printed.
          stream The file stream where the output will be directed.
 <h2>print_float()</h2>

   FOUNDATIONAL_LIB_FUNC void print_float ( const float  value )

   Prints a single-precision floating-point value to the standard output.


<h3><pre>Parameters</pre></h3>


          value The float value to be printed.
 <h2>print_float_array()</h2>

   FOUNDATIONAL_LIB_FUNC void print_float_array ( const float *
   array,
                                                        size_t         size
                                                      )

   Prints the elements of a float array.

   This function takes a pointer to a float array and its size as
   parameters. It prints each element of the array to the standard output.


<h3><pre>Parameters</pre></h3>


          array Pointer to the float array.
          size  Size of the array.
 <h2>print_float_array_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_float_array_to_stream ( const
   float *  array,
   size_t  size,
   FILE *  stream
   )

   Outputs elements of a float array to a stream.

   This function takes an array of float values and a specified size, then
   writes each element to the provided file stream. Useful for displaying
   or logging float arrays in a human-readable format.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the float array.
          size   Size of the array.
          stream File stream to which the array elements will be written.
 <h2>print_float_ptr_array()</h2>

   FOUNDATIONAL_LIB_FUNC void print_float_ptr_array ( const float
   **  array,
   size_t  size
   )

   Prints the elements of a float array through a pointer.

   This function takes a pointer to a pointer to a float array and the
   size of the array as parameters. It prints each element of the array to
   the standard output.


<h3><pre>Parameters</pre></h3>


          array Pointer to a pointer to the float array.
          size  Size of the array.
 <h2>print_float_ptr_array_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_float_ptr_array_to_stream (
   const float **  array,
   size_t  size,
   FILE *  stream
   )

   Outputs elements of an array of pointers to float to a stream.

   This function takes an array of pointers to float values and a
   specified size, then writes each referenced float element to the
   provided file stream. Useful for displaying or logging arrays of
   pointers to float values.


<h3><pre>Parameters</pre></h3>


   array Pointer to the array of pointers to float.
   size Size of the array.
   stream File stream to which the referenced float elements will be
   written.
 <h2>print_float_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_float_to_stream ( const float
   value,
                                                            FILE *       stream
                                                          )

   Prints a single-precision floating-point value to the specified stream.


<h3><pre>Parameters</pre></h3>


          value  The float value to be printed.
          stream The file stream where the output will be directed.
 <h2>print_int()</h2>

   FOUNDATIONAL_LIB_FUNC void print_int ( const int  value )

   Prints an integer value to the standard output.


<h3><pre>Parameters</pre></h3>


          value The integer value to be printed.
 <h2>print_int_array()</h2>

   FOUNDATIONAL_LIB_FUNC void print_int_array ( const int *  array,
                                                      size_t       size
                                                    )

   Prints the elements of an int array.

   This function takes a pointer to an integer array and its size as
   input, and prints each element of the array. Useful for debugging and
   displaying the contents of an int array.


<h3><pre>Parameters</pre></h3>


          array Pointer to the integer array.
          size  Size of the array.
 <h2>print_int_array_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_int_array_to_stream ( const int
   *  array,
   size_t  size,
   FILE *  stream
   )

   Prints the elements of an int array to a specified stream.

   This function takes a pointer to an int array, its size, and a FILE
   stream as parameters. It prints each element of the array to the
   specified stream.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the int array.
          size   Size of the array.
          stream FILE stream to which the elements are printed.
 <h2>print_int_ptr_array()</h2>

   FOUNDATIONAL_LIB_FUNC void print_int_ptr_array ( const int **
   array,
                                                          size_t        size
                                                        )

   Prints the elements of an array of int pointers.

   This function takes a pointer to an array of pointers to integers and
   its size as input. It prints each element of the array, treating them
   as pointers to int arrays. Useful for debugging and displaying the
   contents of an array of int pointers.


<h3><pre>Parameters</pre></h3>


          array Pointer to the array of pointers to integers.
          size  Size of the array.
 <h2>print_int_ptr_array_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_int_ptr_array_to_stream ( const
   int **  array,
   size_t  size,
   FILE *  stream
   )

   Prints the elements of an int array through a pointer to a specified
   stream.

   This function takes a pointer to a pointer to an int array, the size of
   the array, and a FILE stream as parameters. It prints each element of
   the array to the specified stream.


<h3><pre>Parameters</pre></h3>


          array  Pointer to a pointer to the int array.
          size   Size of the array.
          stream FILE stream to which the elements are printed.
 <h2>print_int_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_int_to_stream ( const int
   value,
                                                          FILE *     stream
                                                        )

   Prints an integer value to the specified stream.


<h3><pre>Parameters</pre></h3>


          value  The integer value to be printed.
          stream The file stream where the output will be directed.
 <h2>print_long()</h2>

   FOUNDATIONAL_LIB_FUNC void print_long ( const long  value )

   Prints a long integer value to the standard output.


<h3><pre>Parameters</pre></h3>


          value The long integer value to be printed.
 <h2>print_long_array()</h2>

   FOUNDATIONAL_LIB_FUNC void print_long_array ( const long *
   array,
                                                       size_t        size
                                                     )

   Prints the elements of a long array.

   This function takes a pointer to a long array and the size of the array
   as input parameters. It prints each element of the array to the
   standard output.


<h3><pre>Parameters</pre></h3>


          array Pointer to the long array.
          size  Size of the array.
 <h2>print_long_array_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_long_array_to_stream ( const
   long *  array,
   size_t  size,
   FILE *  stream
   )

   Prints the elements of a long array to a specified stream.

   This function takes a pointer to a long array, its size, and a FILE
   stream as parameters. It prints each element of the array to the
   specified stream.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the long array.
          size   Size of the array.
          stream FILE stream to which the elements are printed.
 <h2>print_long_long()</h2>

         FOUNDATIONAL_LIB_FUNC void print_long_long ( const long long
   value )

   Prints a long long integer value to the standard output.


<h3><pre>Parameters</pre></h3>


          value The long long integer value to be printed.
 <h2>print_long_long_array()</h2>

   FOUNDATIONAL_LIB_FUNC void print_long_long_array ( const long
   long *  array,
   size_t  size
   )

   Prints the elements of a long long array.

   This function takes a pointer to a long long array and its size as
   parameters. It prints each element of the array to the standard output.


<h3><pre>Parameters</pre></h3>


          array Pointer to the long long array.
          size  Size of the array.
 <h2>print_long_long_array_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_long_long_array_to_stream (
   const long long *  array,
   size_t  size,
   FILE *  stream
   )

   Outputs elements of a long_long array to a stream.

   This function takes an array of long long integers and a specified
   size, then writes each element to the provided file stream. Useful for
   displaying or logging long_long arrays in a human-readable format.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the long long array.
          size   Size of the array.
          stream File stream to which the array elements will be written.
 <h2>print_long_long_ptr_array()</h2>

   FOUNDATIONAL_LIB_FUNC void print_long_long_ptr_array ( const long
   long **  array,
   size_t  size
   )

   Prints the elements of a long long array through a pointer.

   This function takes a pointer to a pointer to a long long array and the
   size of the array as parameters. It prints each element of the array to
   the standard output.


<h3><pre>Parameters</pre></h3>


          array Pointer to a pointer to the long long array.
          size  Size of the array.
 <h2>print_long_long_ptr_array_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_long_long_ptr_array_to_stream (
   const long long **  array,
   size_t  size,
   FILE *  stream
   )

   Outputs elements of an array of pointers to long long to a stream.

   This function takes an array of pointers to long long integers and a
   specified size, then writes each referenced long long element to the
   provided file stream. Useful for displaying or logging arrays of
   pointers to long long integers.


<h3><pre>Parameters</pre></h3>


   array Pointer to the array of pointers to long long.
   size Size of the array.
   stream File stream to which the referenced long long elements will be
   written.
 <h2>print_long_long_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_long_long_to_stream ( const long
   long  value,
   FILE *  stream
   )

   Prints a long long integer value to the specified stream.


<h3><pre>Parameters</pre></h3>


          value  The long long integer value to be printed.
          stream The file stream where the output will be directed.
 <h2>print_long_ptr_array()</h2>

   FOUNDATIONAL_LIB_FUNC void print_long_ptr_array ( const long **
   array,
                                                           size_t         size
                                                         )

   Prints the elements of a long array.

   This function takes a pointer to a long array and its size as
   parameters. It prints each element of the array to the standard output.


<h3><pre>Parameters</pre></h3>


          array Pointer to the long array.
          size  Size of the array.
 <h2>print_long_ptr_array_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_long_ptr_array_to_stream ( const
   long **  array,
   size_t  size,
   FILE *  stream
   )

   Prints the elements of a long array through a pointer to a specified
   stream.

   This function takes a pointer to a pointer to a long array, the size of
   the array, and a FILE stream as parameters. It prints each element of
   the array to the specified stream.


<h3><pre>Parameters</pre></h3>


          array  Pointer to a pointer to the long array.
          size   Size of the array.
          stream FILE stream to which the elements are printed.
 <h2>print_long_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_long_to_stream ( const long
   value,
                                                           FILE *      stream
                                                         )

   Prints a long integer value to the specified stream.


<h3><pre>Parameters</pre></h3>


          value  The long integer value to be printed.
          stream The file stream where the output will be directed.
 <h2>print_short()</h2>

   FOUNDATIONAL_LIB_FUNC void print_short ( const short  value )

   Prints a short integer value to the standard output.


<h3><pre>Parameters</pre></h3>


          value The short integer value to be printed.
 <h2>print_short_array()</h2>

   FOUNDATIONAL_LIB_FUNC void print_short_array ( const short *
   array,
                                                        size_t         size
                                                      )

   Prints the contents of an array of short integers.

   This function takes a pointer to an array of short integers and its
   size as input parameters, and then prints the contents of the array.
   The size parameter indicates the number of elements in the array.


<h3><pre>Parameters</pre></h3>


          array Pointer to the array of short integers to be printed.
          size  Size of the array.
 <h2>print_short_array_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_short_array_to_stream ( const
   short *  array,
   size_t  size,
   FILE *  stream
   )

   Prints the elements of a short array to a specified stream.

   This function takes a pointer to a short array, its size, and a FILE
   stream as parameters. It prints each element of the array to the
   specified stream.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the short array.
          size   Size of the array.
          stream FILE stream to which the elements are printed.
 <h2>print_short_ptr_array()</h2>

   FOUNDATIONAL_LIB_FUNC void print_short_ptr_array ( const short
   **  array,
   size_t  size
   )

   Prints an array of pointers to short integers.

   This function takes a pointer to an array of pointers to short integers
   and its size as input parameters, and then prints the contents of each
   pointed array. The size parameter indicates the number of pointers in
   the array.


<h3><pre>Parameters</pre></h3>


         array Pointer to the array of pointers to short integers to be printed.
         size  Size of the array (number of pointers).
 <h2>print_short_ptr_array_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_short_ptr_array_to_stream (
   const short **  array,
   size_t  size,
   FILE *  stream
   )

   Prints the elements of a short array through a pointer to a specified
   stream.

   This function takes a pointer to a pointer to a short array, the size
   of the array, and a FILE stream as parameters. It prints each element
   of the array to the specified stream.


<h3><pre>Parameters</pre></h3>


          array  Pointer to a pointer to the short array.
          size   Size of the array.
          stream FILE stream to which the elements are printed.
 <h2>print_short_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_short_to_stream ( const short
   value,
                                                            FILE *       stream
                                                          )

   Prints a short integer value to the specified stream.


<h3><pre>Parameters</pre></h3>


          value  The short integer value to be printed.
          stream The file stream where the output will be directed.
 <h2>print_size_t()</h2>

   FOUNDATIONAL_LIB_FUNC void print_size_t ( const size_t  value )

   Prints a size_t value to the standard output.


<h3><pre>Parameters</pre></h3>


          value The size_t value to be printed.
 <h2>print_size_t_array()</h2>

   FOUNDATIONAL_LIB_FUNC void print_size_t_array ( const size_t *
   array,
                                                         size_t          size
                                                       )

   Prints the elements of a size_t array.

   This function takes a pointer to a size_t array and its size as
   parameters. It prints each element of the array to the standard output.


<h3><pre>Parameters</pre></h3>


          array Pointer to the size_t array.
          size  Size of the array.
 <h2>print_size_t_array_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_size_t_array_to_stream ( const
   size_t *  array,
   size_t  size,
   FILE *  stream
   )

   Outputs elements of a size_t array to a stream.

   This function takes an array of size_t values and a specified size,
   then writes each element to the provided file stream. Useful for
   displaying or logging size_t arrays in a human-readable format.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the size_t array.
          size   Size of the array.
          stream File stream to which the array elements will be written.
 <h2>print_size_t_ptr_array()</h2>

   FOUNDATIONAL_LIB_FUNC void print_size_t_ptr_array ( const size_t
   **  array,
   size_t  size
   )

   Prints the elements of a size_t array through a pointer.

   This function takes a pointer to a pointer to a size_t array and the
   size of the array as parameters. It prints each element of the array to
   the standard output.


<h3><pre>Parameters</pre></h3>


          array Pointer to a pointer to the size_t array.
          size  Size of the array.
 <h2>print_size_t_ptr_array_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_size_t_ptr_array_to_stream (
   const size_t **  array,
   size_t  size,
   FILE *  stream
   )

   Outputs elements of an array of pointers to size_t to a stream.

   This function takes an array of pointers to size_t values and a
   specified size, then writes each referenced size_t element to the
   provided file stream. Useful for displaying or logging arrays of
   pointers to size_t values.


<h3><pre>Parameters</pre></h3>


   array Pointer to the array of pointers to size_t.
   size Size of the array.
   stream File stream to which the referenced size_t elements will be
   written.
 <h2>print_size_t_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_size_t_to_stream ( const size_t
   value,
                                                             FILE *       stream
                                                           )

   Prints a size_t value to the specified stream.


<h3><pre>Parameters</pre></h3>


          value  The size_t value to be printed.
          stream The file stream where the output will be directed.
 <h2>print_string()</h2>

   FOUNDATIONAL_LIB_FUNC void print_string ( char *  value )

   Prints a string value to the standard output.


<h3><pre>Parameters</pre></h3>


          value The string to be printed.
 <h2>print_string_array()</h2>

   FOUNDATIONAL_LIB_FUNC void print_string_array ( char **  array,
                                                         size_t   size
                                                       )

   Prints an array of strings.

   This function takes a pointer to an array of strings and its size as
   input parameters, and then prints each string in the array. It assumes
   that the array is an array of null-terminated strings. The size
   parameter indicates the number of strings in the array.


<h3><pre>Parameters</pre></h3>


          array Pointer to the array of strings to be printed.
          size  Size of the array (number of strings).
 <h2>print_string_array_array()</h2>

   FOUNDATIONAL_LIB_FUNC void print_string_array_array ( char ***
   array,
                                                               size_t    size
                                                             )

   Prints an array of arrays of strings.

   This function takes a pointer to an array of arrays of strings and its
   size as input parameters, and then prints each string in each inner
   array. It assumes that the inner arrays are arrays of null-terminated
   strings. The size parameter indicates the number of arrays in the outer
   array.


<h3><pre>Parameters</pre></h3>


          array Pointer to the array of arrays of strings to be printed.
          size  Size of the outer array (number of arrays).
 <h2>print_string_array_array_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_string_array_array_to_stream (
   char ***  array,
   size_t  size,
   FILE *  stream
   )

   Prints the elements of an array of string arrays to a specified stream.

   This function takes a pointer to a pointer to a pointer to a char array
   (string), the size of the array, and a FILE stream as parameters. It
   prints each element of the array of string arrays to the specified
   stream.


<h3><pre>Parameters</pre></h3>


          array  Pointer to a pointer to a pointer to the char array (string).
          size   Size of the array.
          stream FILE stream to which the elements (strings) are printed.
 <h2>print_string_array_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_string_array_to_stream ( char
   **  array,
   size_t  size,
   FILE *  stream
   )

   Prints the elements of a string array to a specified stream.

   This function takes a pointer to a pointer to a char array (string),
   the size of the array, and a FILE stream as parameters. It prints each
   element of the array (string) to the specified stream.


<h3><pre>Parameters</pre></h3>


          array  Pointer to a pointer to the char array (string).
          size   Size of the array.
          stream FILE stream to which the elements (strings) are printed.
 <h2>print_string_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_string_to_stream ( char *
   value,
                                                             FILE *  stream
                                                           )

   Prints a string value to the specified stream.


<h3><pre>Parameters</pre></h3>


          value  The string to be printed.
          stream The file stream where the output will be directed.
 <h2>print_uchar()</h2>

         FOUNDATIONAL_LIB_FUNC void print_uchar ( const unsigned char
   value )

   Prints an unsigned char value to the standard output.


<h3><pre>Parameters</pre></h3>


          value The unsigned char value to be printed.
 <h2>print_uchar_array_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_uchar_array_to_stream ( const
   unsigned char *  array,
   size_t  size,
   FILE *  stream
   )

   Prints the elements of an unsigned char array to a specified stream.

   This function takes a pointer to an unsigned char array, its size, and
   a FILE stream as parameters. It prints each element of the array to the
   specified stream.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the unsigned char array.
          size   Size of the array.
          stream FILE stream to which the elements are printed.
 <h2>print_uchar_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_uchar_to_stream ( const unsigned
   char  value,
   FILE *  stream
   )

   Prints an unsigned char value to the specified stream.


<h3><pre>Parameters</pre></h3>


          value  The unsigned char value to be printed.
          stream The file stream where the output will be directed.
 <h2>print_uint()</h2>

   FOUNDATIONAL_LIB_FUNC void print_uint ( const unsigned int  value
   )

   Prints an unsigned int value to the standard output.


<h3><pre>Parameters</pre></h3>


          value The unsigned int value to be printed.
 <h2>print_uint_array()</h2>

   FOUNDATIONAL_LIB_FUNC void print_uint_array ( const unsigned long
   long *  array,
   size_t  size
   )

   Prints the elements of a uint array.

   This function takes a pointer to an unsigned integer array and its size
   as input, and prints each element of the array. It is useful for
   debugging and displaying the contents of a uint array.


<h3><pre>Parameters</pre></h3>


          array Pointer to the unsigned integer array.
          size  Size of the array.
 <h2>print_uint_array_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_uint_array_to_stream ( const
   unsigned int *  array,
   size_t  size,
   FILE *  stream
   )

   Prints the elements of an unsigned int array to a specified stream.

   This function takes a pointer to an unsigned int array, its size, and a
   FILE stream as parameters. It prints each element of the array to the
   specified stream.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the unsigned int array.
          size   Size of the array.
          stream FILE stream to which the elements are printed.
 <h2>print_uint_ptr_array()</h2>

   FOUNDATIONAL_LIB_FUNC void print_uint_ptr_array ( const unsigned
   int **  array,
   size_t  size
   )

   Prints the elements of an array of uint pointers.

   This function takes a pointer to an array of pointers to unsigned
   integers and its size as input. It prints each element of the array,
   treating them as pointers to uint arrays. Useful for debugging and
   displaying the contents of an array of uint pointers.


<h3><pre>Parameters</pre></h3>


          array Pointer to the array of pointers to unsigned integers.
          size  Size of the array.
 <h2>print_uint_ptr_array_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_uint_ptr_array_to_stream ( const
   unsigned int **  array,
   size_t  size,
   FILE *  stream
   )

   Prints the elements of an unsigned int array through a pointer to a
   specified stream.

   This function takes a pointer to a pointer to an unsigned int array,
   the size of the array, and a FILE stream as parameters. It prints each
   element of the array to the specified stream.


<h3><pre>Parameters</pre></h3>


          array  Pointer to a pointer to the unsigned int array.
          size   Size of the array.
          stream FILE stream to which the elements are printed.
 <h2>print_uint_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_uint_to_stream ( const unsigned
   int  value,
   FILE *  stream
   )

   Prints an unsigned int value to the specified stream.


<h3><pre>Parameters</pre></h3>


          value  The unsigned int value to be printed.
          stream The file stream where the output will be directed.
 <h2>print_ulong()</h2>

         FOUNDATIONAL_LIB_FUNC void print_ulong ( const unsigned long
   value )

   Prints an unsigned long value to the standard output.


<h3><pre>Parameters</pre></h3>


          value The unsigned long value to be printed.
 <h2>print_ulong_array()</h2>

   FOUNDATIONAL_LIB_FUNC void print_ulong_array ( const unsigned
   long *  array,
   size_t  size
   )

   Prints the contents of an array of unsigned long integers.

   This function takes a pointer to an array of unsigned long integers and
   its size as input parameters, and then prints the contents of the
   array. The size parameter indicates the number of elements in the
   array.


<h3><pre>Parameters</pre></h3>


          array Pointer to the array of unsigned long integers to be printed.
          size  Size of the array.
 <h2>print_ulong_array_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_ulong_array_to_stream ( const
   unsigned long *  array,
   size_t  size,
   FILE *  stream
   )

   Prints the elements of an unsigned long array to a specified stream.

   This function takes a pointer to an unsigned long array, its size, and
   a FILE stream as parameters. It prints each element of the array to the
   specified stream.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the unsigned long array.
          size   Size of the array.
          stream FILE stream to which the elements are printed.
 <h2>print_ulong_long()</h2>

   FOUNDATIONAL_LIB_FUNC void print_ulong_long ( const unsigned long
   long  value )

   Prints an unsigned long long value to the standard output.


<h3><pre>Parameters</pre></h3>


          value The unsigned long long value to be printed.
 <h2>print_ulong_long_array()</h2>

   FOUNDATIONAL_LIB_FUNC void print_ulong_long_array ( const
   unsigned long long *  array,
   size_t  size
   )

   Prints the elements of an unsigned long long array.

   This function takes a pointer to an unsigned long long array and its
   size as parameters. It prints each element of the array to the standard
   output.


<h3><pre>Parameters</pre></h3>


          array Pointer to the unsigned long long array.
          size  Size of the array.
 <h2>print_ulong_long_array_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_ulong_long_array_to_stream (
   const unsigned long long *  array,
   size_t  size,
   FILE *  stream
   )

   Prints the elements of an unsigned long long array to a specified
   stream.

   This function takes a pointer to an unsigned long long array, its size,
   and a FILE stream as parameters. It prints each element of the array to
   the specified stream.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the unsigned long long array.
          size   Size of the array.
          stream FILE stream to which the elements are printed.
 <h2>print_ulong_long_ptr_array()</h2>

   FOUNDATIONAL_LIB_FUNC void print_ulong_long_ptr_array ( const
   unsigned long long **  array,
   size_t  size
   )

   Prints the elements of an unsigned long long array through a pointer.

   This function takes a pointer to a pointer to an unsigned long long
   array and the size of the array as parameters. It prints each element
   of the array to the standard output.


<h3><pre>Parameters</pre></h3>


          array Pointer to a pointer to the unsigned long long array.
          size  Size of the array.
 <h2>print_ulong_long_ptr_array_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_ulong_long_ptr_array_to_stream (
   const unsigned long long **  array,
   size_t  size,
   FILE *  stream
   )

   Prints the elements of an unsigned long long array through a pointer to
   a specified stream.

   This function takes a pointer to a pointer to an unsigned long long
   array, the size of the array, and a FILE stream as parameters. It
   prints each element of the array to the specified stream.


<h3><pre>Parameters</pre></h3>


          array  Pointer to a pointer to the unsigned long long array.
          size   Size of the array.
          stream FILE stream to which the elements are printed.
 <h2>print_ulong_long_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_ulong_long_to_stream ( const
   unsigned long long  value,
   FILE *  stream
   )

   Prints an unsigned long long value to the specified stream.


<h3><pre>Parameters</pre></h3>


          value  The unsigned long long value to be printed.
          stream The file stream where the output will be directed.
 <h2>print_ulong_ptr_array()</h2>

   FOUNDATIONAL_LIB_FUNC void print_ulong_ptr_array ( const unsigned
   long **  array,
   size_t  size
   )

   Prints an array of pointers to unsigned long integers.

   This function takes a pointer to an array of pointers to unsigned long
   integers and its size as input parameters, and then prints the contents
   of each pointed array. The size parameter indicates the number of
   pointers in the array.


<h3><pre>Parameters</pre></h3>


   array Pointer to the array of pointers to unsigned long integers to be
   printed.
   size Size of the array (number of pointers).
 <h2>print_ulong_ptr_array_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_ulong_ptr_array_to_stream (
   const unsigned long **  array,
   size_t  size,
   FILE *  stream
   )

   Prints the elements of an unsigned long array through a pointer to a
   specified stream.

   This function takes a pointer to a pointer to an unsigned long array,
   the size of the array, and a FILE stream as parameters. It prints each
   element of the array to the specified stream.


<h3><pre>Parameters</pre></h3>


          array  Pointer to a pointer to the unsigned long array.
          size   Size of the array.
          stream FILE stream to which the elements are printed.
 <h2>print_ulong_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_ulong_to_stream ( const unsigned
   long  value,
   FILE *  stream
   )

   Prints an unsigned long value to the specified stream.


<h3><pre>Parameters</pre></h3>


          value  The unsigned long value to be printed.
          stream The file stream where the output will be directed.
 <h2>print_ushort()</h2>

         FOUNDATIONAL_LIB_FUNC void print_ushort ( const unsigned short
   value )

   Print an unsigned short value.


<h3><pre>Parameters</pre></h3>


          value Unsigned short value to be printed.
 <h2>print_ushort_array()</h2>

   FOUNDATIONAL_LIB_FUNC void print_ushort_array ( const unsigned
   short *  array,
   size_t  size
   )

   Prints the contents of an array of unsigned short integers.

   This function takes a pointer to an array of unsigned short integers
   and its size as input parameters, and then prints the contents of the
   array. The size parameter indicates the number of elements in the
   array.


<h3><pre>Parameters</pre></h3>


          array Pointer to the array of unsigned short integers to be printed.
          size  Size of the array.
 <h2>print_ushort_array_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_ushort_array_to_stream ( const
   unsigned short *  array,
   size_t  size,
   FILE *  stream
   )

   Prints the elements of an unsigned short array to a specified stream.

   This function takes a pointer to an unsigned short array, its size, and
   a FILE stream as parameters. It prints each element of the array to the
   specified stream.


<h3><pre>Parameters</pre></h3>


          array  Pointer to the unsigned short array.
          size   Size of the array.
          stream FILE stream to which the elements are printed.
 <h2>print_ushort_ptr_array()</h2>

   FOUNDATIONAL_LIB_FUNC void print_ushort_ptr_array ( const
   unsigned short **  array,
   size_t  size
   )

   Prints an array of pointers to unsigned short integers.

   This function takes a pointer to an array of pointers to unsigned short
   integers and its size as input parameters, and then prints the contents
   of each pointed array. The size parameter indicates the number of
   pointers in the array.


<h3><pre>Parameters</pre></h3>


   array Pointer to the array of pointers to unsigned short integers to be
   printed.
   size Size of the array (number of pointers).
 <h2>print_ushort_ptr_array_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_ushort_ptr_array_to_stream (
   const unsigned short **  array,
   size_t  size,
   FILE *  stream
   )

   Prints the elements of an unsigned short array through a pointer to a
   specified stream.

   This function takes a pointer to a pointer to an unsigned short array,
   the size of the array, and a FILE stream as parameters. It prints each
   element of the array to the specified stream.


<h3><pre>Parameters</pre></h3>


          array  Pointer to a pointer to the unsigned short array.
          size   Size of the array.
          stream FILE stream to which the elements are printed.
 <h2>print_ushort_to_stream()</h2>

   FOUNDATIONAL_LIB_FUNC void print_ushort_to_stream ( const
   unsigned short  value,
   FILE *  stream
   )

   Print an unsigned short value to a stream.


<h3><pre>Parameters</pre></h3>


          value  Unsigned short value to be printed.
          stream FILE stream where the output will be printed.
 <h2>rand_number_from_range_inclusive_signed()</h2>

   FOUNDATIONAL_LIB_FUNC long
   rand_number_from_range_inclusive_signed ( signed long  min,
   signed long  max
   )

   Generates a random signed number within a specified range (inclusive).

   This function generates a random signed number within a specified range
   (inclusive).


<h3><pre>Parameters</pre></h3>


          min The minimum value of the range.
          max The maximum value of the range.


<h3><pre>Returns</pre></h3>


          Returns the generated random number.
 <h2>rand_number_from_range_inclusive_unsigned()</h2>

   FOUNDATIONAL_LIB_FUNC unsigned long
   rand_number_from_range_inclusive_unsigned ( unsigned long  min,
   unsigned long  max
   )

   Generates a random unsigned number within a specified range
   (inclusive).

   This function generates a random unsigned number within a specified
   range (inclusive).


<h3><pre>Parameters</pre></h3>


          min The minimum value of the range.
          max The maximum value of the range.


<h3><pre>Returns</pre></h3>


          Returns the generated random number.
 <h2>read_file_into_array()</h2>

   FOUNDATIONAL_LIB_FUNC char** read_file_into_array ( const char *
   filename,
   const char *  delim,
   size_t *  num_lines
   )

   Reads the contents of a file into an array of strings.

   This function reads the contents of the specified file into a
   dynamically allocated array of strings, using the specified delimiter.
   The size of the array is stored in the variable pointed to by the
   'num_lines' parameter. The caller is responsible for freeing the memory
   allocated for the array and its strings using free().


<h3><pre>Parameters</pre></h3>


   filename Pointer to the name of the file to be read.
   delim The delimiter used to split the file content into lines.
   num_lines Pointer to a variable where the number of lines in the file
   will be stored.


<h3><pre>Returns</pre></h3>


          Pointer to the dynamically allocated array of strings. Returns
          NULL if there is an error or the file is empty. The caller is
          responsible for freeing the memory using free().


<h3><pre>Note</pre></h3>


          This function reads a file into an array of character arrays.
          Don't use this with binary data. The result CAN contain '\0' but
          you won't know how long each string is.
 <h2>read_file_into_string()</h2>

   FOUNDATIONAL_LIB_FUNC char* read_file_into_string ( const char *
   filename,
                                                             size_t *     size
                                                           )

   Reads the contents of a file into a string.

   This function reads the contents of the specified file into a
   dynamically allocated string and returns a pointer to the created
   string. The size of the string is stored in the variable pointed to by
   the 'size' parameter. The caller is responsible for freeing the memory
   allocated for the returned string using free().


<h3><pre>Parameters</pre></h3>


   filename Pointer to the name of the file to be read.
   size Pointer to a variable where the size of the read string will be
   stored.


<h3><pre>Returns</pre></h3>


          Pointer to the dynamically allocated string containing the file
          contents. Returns NULL if there is an error or the file is
          empty. The caller is responsible for freeing the memory using
          free().
 <h2>read_files_into_array()</h2>

   FOUNDATIONAL_LIB_FUNC int read_files_into_array ( const char **
   files_to_open,
   size_t  num_files,
   char ***  outputs,
   size_t **  lens,
   int  aggressive_stop_on_error
   )

   Reads content from multiple files into an array.

   This function reads the content of multiple files specified by an array
   of file paths and stores the content and corresponding lengths in
   output arrays.


<h3><pre>Parameters</pre></h3>


   files_to_open An array of file paths to be opened and read.
   num_files The number of files in the files_to_open array.
   outputs A pointer to an array that will store the content of each file.
   The content will be stored as an array of null-terminated strings.
   lens A pointer to an array that will store the length of each file's
   content.
   aggressive_stop_on_error If set to 1, the function will stop reading
   files if an error occurs while reading a file. If set to 0, the
   function will continue reading other files even if an error occurs.


<h3><pre>Returns</pre></h3>


          Returns 0 on success, -1 on failure. If aggressive_stop_on_error
          is set to 1, the function will return -1 as soon as an error is
          encountered; otherwise, it will attempt to read all files before
          returning.


<h3><pre>Note</pre></h3>


          The outputs array is dynamically allocated and should be freed
          by the caller after use to prevent memory leaks.
          The lens array is dynamically allocated and contains the lengths
          of the corresponding file contents in the outputs array.
          If an error occurs while reading a file, the content for that
          file in the outputs array will be set to NULL, and its length in
          the lens array will be 0.
          It is the responsibility of the caller to free the memory
          allocated for outputs and lens arrays after use.
 <h2>reduce()</h2>

   FOUNDATIONAL_LIB_FUNC void reduce ( void *                   array,
                                             size_t                   size,
                                             size_t                   elem_size,
                                             void *                   result,
                                             void(*)(void *, void *)  operation
                                           )

   Performs a reduction on an array (void* version) using a binary
   operation.

   This function applies a user-defined binary operation to reduce the
   elements of the input array with support for generic data types using
   void pointers.


<h3><pre>Parameters</pre></h3>


   array Pointer to the array to be reduced.
   size Size of the array.
   elem_size Size of each element in bytes.
   result Pointer to the memory location to store the result of the
   reduction.
   operation Pointer to the binary operation function. The function should
   take two void pointers as input, which point to individual elements in
   the array, and update the result.


<h3><pre>Note</pre></h3>


          The reduction operation is performed from left to right.
          The user-defined binary operation function should be provided as
          a pointer.

   // Example binary operation function: sum two integer elements
   void sum_operation(void *element1, void *element2) {
   (*(int *)element1) += (*(int *)element2);
   }
   // Example usage:
   int my_array[] = {1, 2, 3, 4, 5};
   int result = 0;
   reduce(my_array, 5, sizeof(int), &result, sum_operation);
   // After the call, result will be the sum of elements: 1 + 2 + 3 + 4 +
   5 =
   15
   reduce
   FOUNDATIONAL_LIB_FUNC void reduce(void *array, size_t size, size_t
   elem_size, void *result, void(*operation)(void *, void *))
   Performs a reduction on an array (void* version) using a binary
   operation.
   Definition: foundationallib.h:8476
 <h2>reduce_filesystem_files_as_strings()</h2>

   FOUNDATIONAL_LIB_FUNC char* reduce_filesystem_files_as_strings (
   const char *  directory,
   const char *  out_file,
   char *(*)(char *value1,...)  reduce_function
   )

   Applies a reduce operation on files in the specified directory, and
   outputs the result as a string.

   This function iterates through the files in the given directory and
   applies the provided reduce function to each file. The reduce function
   takes variable arguments (char pointers) and produces a result that is
   then concatenated. The final result is returned as a dynamically
   allocated string. The caller is responsible for freeing the memory
   allocated for the result.


<h3><pre>Parameters</pre></h3>


   directory The path to the directory containing the files to be
   processed.
   out_file The path to the output file where the final result will be
   stored.
   reduce_function A pointer to the reduce function that takes variable
   arguments (char pointers) and produces a result to be concatenated.


<h3><pre>Returns</pre></h3>


          Returns a dynamically allocated string containing the result of
          the reduce operation. The caller is responsible for freeing the
          memory allocated for the result.
 <h2>reduce_ints()</h2>

   FOUNDATIONAL_LIB_FUNC int reduce_ints ( int *             array,
                                                 size_t            size,
                                                 int(*)(int, int)  operation
                                               )

   Performs a reduction on an integer array using a binary operation.

   This function applies a user-defined binary operation to reduce the
   elements of the input integer array to a single result.


<h3><pre>Parameters</pre></h3>


   array Pointer to the integer array to be reduced.
   size Size of the array.
   operation Pointer to the binary operation function. The function should
   take two integers as input and return an integer as the result of the
   binary operation.


<h3><pre>Returns</pre></h3>


          The result of the reduction operation.


<h3><pre>Note</pre></h3>


          The reduction operation is performed from left to right.
          The user-defined binary operation function should be provided as
          a pointer.

   // Example binary operation function: addition
   int add_operation(int x, int y) {
   return x + y;
   }
   // Example usage:
   int my_array[] = {1, 2, 3, 4, 5};
   int result = reduce_ints(my_array, 5, add_operation);
   // After the call, result will be the sum of elements: 1 + 2 + 3 + 4 +
   5 =
   15
   reduce_ints
   FOUNDATIONAL_LIB_FUNC int reduce_ints(int *array, size_t size,
   int(*operation)(int, int))
   Performs a reduction on an integer array using a binary operation.
   Definition: foundationallib.h:8332
 <h2>reject_array()</h2>

   FOUNDATIONAL_LIB_FUNC void* reject_array ( const void *  source,
   size_t  source_size,
   size_t  elem_size,
   int(*)(const void *)  condition,
   size_t *  result_size
   )

   Filters elements from an array based on a specified condition.

   This function creates a new array by rejecting elements from the source
   array that do not satisfy the given condition.


<h3><pre>Parameters</pre></h3>


   source Pointer to the source array.
   source_size Size of the source array.
   elem_size Size of each element in the array.
   condition Pointer to the condition function. The function should return
   a non-zero value for elements to be rejected.
   result_size Pointer to a variable to store the size of the resulting
   array.


<h3><pre>Returns</pre></h3>


          Pointer to the newly allocated array containing filtered
          elements. It is the responsibility of the caller to free the
          memory when done.
 <h2>remove_file()</h2>

   FOUNDATIONAL_LIB_FUNC int remove_file ( const char *  filename )

   Removes a file.

   This function removes (deletes) the specified file from the file
   system.


<h3><pre>Parameters</pre></h3>


          filename Pointer to the name of the file to be removed.


<h3><pre>Returns</pre></h3>


          Returns 0 on success and -1 on error. The function fails if the
          file cannot be removed or if there is an error during the
          removal process.
 <h2>replace_all()</h2>

   FOUNDATIONAL_LIB_FUNC char* replace_all ( const char *  source,
                                                   const char *  find,
                                                   const char *  replace
                                                 )

   Replaces all occurrences of a specified substring in a given string.

   This function takes an input string and replaces all occurrences of a
   specified old substring with a new substring. The result is a modified
   string with all instances of the old substring replaced by the new
   substring.


<h3><pre>Parameters</pre></h3>


         str           The input string in which replacements will be performed.
         old_substring The substring to be replaced.
         new_substring The substring that replaces the old substring.


<h3><pre>Returns</pre></h3>


          Returns a dynamically allocated string containing the modified
          result. The caller is responsible for freeing the memory when no
          longer needed.
 <h2>replace_all_with_callback()</h2>

   FOUNDATIONAL_LIB_FUNC char* replace_all_with_callback ( const
   char *  str,
   const char *  old_substring,
   char *(*)(const char *, void *)  callback,
   void *  data_for_callback
   )

   Replaces all occurrences of a substring in a string using a callback
   function.

   This function searches for all occurrences of the specified substring
   in the given string and replaces them by invoking a callback function.
   The callback function is responsible for providing the replacement for
   each occurrence.


<h3><pre>Parameters</pre></h3>


   str The input string to be processed.
   old_substring The substring to be replaced.
   callback A callback function that receives the matched substring and
   user data, and returns a dynamically allocated replacement string.
   data_for_callback User data to be passed to the callback function.


<h3><pre>Returns</pre></h3>


          A dynamically allocated string containing the result of the
          replacements. The caller is responsible for freeing the memory
          allocated for this string.


<h3><pre>Note</pre></h3>


          The returned string must be freed by the caller using free()
          when it is no longer needed.
 <h2>replace_all_with_lens()</h2>

   FOUNDATIONAL_LIB_FUNC int replace_all_with_lens ( const char *
   source,
   size_t  source_len,
   const char *  find,
   size_t  find_len,
   const char *  replace,
   size_t  replace_len,
   char **  output,
   size_t *  new_len,
   int *  should_free_after_use,
   size_t  matches_max,
   size_t *  num_matches
   )

   Performs string replacement with specified lengths.

   This function replaces occurrences of the 'find' substring with the
   'replace' substring within the 'source' string. It operates on strings
   with explicitly provided lengths to handle cases where null characters
   may be present in the strings. It's designed to be more efficient than
   other string replace functions but takes more arguments.

   'output' is aliased to the original value, if so, there was no text
   replacement, and no new memory was allocated. As such, there is no new
   memory that needs to be freed().


<h3><pre>Parameters</pre></h3>


   source The original string to search and modify.
   find The substring to be replaced.
   replace The substring to replace 'find' with.
   source_len The length of the 'source' string.
   find_len The length of the 'find' substring.
   replace_len The length of the 'replace' substring.
   output A pointer to the new string resulting from the replacements. The
   caller is responsible for freeing the memory allocated for 'output'.

   If should_free_after_use is non-zero, a new dynamically allocated array
   with the replacements made. If should_free_after_use is zero, output
   aliases source, and they refer to the same memory.


<h3><pre>Parameters</pre></h3>


   should_free_after_use A pointer to a int indicating whether
   num_matches A pointer to a variable to store the number of replacements
   made.
   matches_max A pointer to the maximum number of replacements to make. If
   zero, there is no maximum.


<h3><pre>Returns</pre></h3>


          Returns 0 on success, -1 on failure.


<h3><pre>Note</pre></h3>


          This function is designed for performance but requires careful
          memory management. Ensure that the caller frees the memory
          allocated for 'new_text' only when appropriate.
          For efficiency, null terminated strings are not checked. As
          such, the blocks of memory that are being replaced CAN contain
          null bytes. Internally, memmem() / memory_locate()
          is used to locate memory. See benchark_lib.c to see just how
          much FASTER this function can make things. It is likely
          optimized with platform specific code, making searches as fast
          as possible. It is much better to not have to constantly check
          for a null byte in every byte.

   This function is just about the most powerful and most efficient memory
   replacement that you will find anywhere.
 <h2>replace_count()</h2>

   FOUNDATIONAL_LIB_FUNC char* replace_count ( const char *  source,
                                                     const char *  find,
                                                     const char *  replace,
                                                     const size_t  matches_max
                                                   )

   Replaces the first N occurrences of a specified substring in a given
   string.

   This function takes an input string and replaces the first N occurences
   of a specified old substring with a new substring. The result is a
   modified string with all instances of the old substring replaced by the
   new substring.


<h3><pre>Parameters</pre></h3>


         str           The input string in which replacements will be performed.
         old_substring The substring to be replaced.
         new_substring The substring that replaces the old substring.


<h3><pre>Returns</pre></h3>


          Returns a dynamically allocated string containing the modified
          result. The caller is responsible for freeing the memory when no
          longer needed.
 <h2>replace_first()</h2>

   FOUNDATIONAL_LIB_FUNC char* replace_first ( const char *  source,
                                                     const char *  find,
                                                     const char *  replace
                                                   )

   Replaces the first occurrence of a specified substring in a given
   string.

   This function takes an input string and replaces the first occurence of
   a specified old substring with a new substring. The result is a
   modified string with all instances of the old substring replaced by the
   new substring.


<h3><pre>Parameters</pre></h3>


         str           The input string in which replacements will be performed.
         old_substring The substring to be replaced.
         new_substring The substring that replaces the old substring.


<h3><pre>Returns</pre></h3>


          Returns a dynamically allocated string containing the modified
          result. The caller is responsible for freeing the memory when no
          longer needed.
 <h2>replace_memory()</h2>

   FOUNDATIONAL_LIB_FUNC int replace_memory ( void *  source,
   size_t  source_len,
   void *  find,
   size_t  find_len,
   void *  replace,
   size_t  replace_len,
   void **  output,
   size_t *  output_length_without_nullt,
   int *  should_free_after_use,
   size_t  matches_max,
   size_t *  num_matches_found,
   int  should_nullt
   )

   Performs memory replacement with specified lengths.

   This function replaces occurrences of the 'find' memory unit with the
   'replace' memory unit within the 'source' memory unit. It operates on
   memory blocks.

   'output' is aliased to the original value, if so, there was no text
   replacement, and no new memory was allocated. As such, there is no new
   memory that needs to be freed().


<h3><pre>Parameters</pre></h3>


   source The original block to search.
   find The block to be replaced.
   replace The block to replace 'find' with.
   source_len The length of the 'source' block.
   find_len The length of the 'find' block.
   replace_len The length of the 'replace' block.
   output A pointer to the new string resulting from the replacements. The
   caller is responsible for freeing the memory allocated for 'output'.

   If should_free_after_use is non-zero, a new dynamically allocated array
   with the replacements made. If should_free_after_use is zero, output
   aliases source, and they refer to the same memory.


<h3><pre>Parameters</pre></h3>


   should_free_after_use A pointer to a int indicating whether one should
   free the memory after using the function.
   num_matches A pointer to a variable to store the number of replacements
   made.
   matches_max A pointer to the maximum number of replacements to make. If
   zero, there is no maximum.


<h3><pre>Returns</pre></h3>


          Returns 0 on success, -1 on failure.


<h3><pre>Note</pre></h3>


          This function is designed for performance but requires careful
          memory management. Ensure that the caller frees the memory
          allocated for 'new_text' if appropriate and checks the return
          value.
          For efficiency, null terminated strings are not checked. As
          such, the blocks of memory that are being replaced CAN contain
          null bytes.

  This function is just about the most powerful and most efficient memory replac
ement that you will find anywhere.

  It seems impementations of memmem() and FOUNDATIONAL_LIB_STRSTR() can vary spe
ed-wise depending on machine. On one of my machines, memmem() was MUCH faster
  whereas on my other machine, FOUNDATIONAL_LIB_STRSTR() was faster (strangely).
 We should reimplement these functions in assembly, or use a library to have
  IDEAL version of these.
 <h2>replicate()</h2>

   FOUNDATIONAL_LIB_FUNC void* replicate ( const void *  source,
                                                 size_t        source_size,
                                                 size_t        elem_size,
                                                 size_t        repetitions
                                               )

   Replicates an array a specified number of times.

   This function creates a new array by replicating the elements of the
   source array a given number of times.


<h3><pre>Parameters</pre></h3>


          source      Pointer to the source array.
          source_size Size of the source array.
          elem_size   Size of each element in the array.
          repetitions Number of times to replicate the array.


<h3><pre>Returns</pre></h3>


          Pointer to the newly allocated array containing replicated
          elements or NULL on error. It is the responsibility of the
          caller to free the memory when done.
 <h2>reverse_int_array_in_place()</h2>

   FOUNDATIONAL_LIB_FUNC void reverse_int_array_in_place ( int *
   array,
                                                                 size_t  size
                                                               )

   Reverses an array of integers in place.

   This function takes an array of integers and reverses its order in
   place.


<h3><pre>Parameters</pre></h3>


          array Pointer to the array of integers to be reversed.
          size  Size of the array.
 <h2>reverse_string()</h2>

   FOUNDATIONAL_LIB_FUNC char* reverse_string ( const char *  str )

   Reverses a given string.

   This function takes a string as input and reverses its order. It
   allocates memory for the reversed string, and the caller is responsible
   for freeing the memory.


<h3><pre>Parameters</pre></h3>


          str The input string to be reversed.


<h3><pre>Returns</pre></h3>


          A new dynamically allocated string representing the reversed
          input string, or NULL in case of memory allocation failure. The
          caller should free the memory allocated for the reversed string.
 <h2>reverse_string_in_place()</h2>

     FOUNDATIONAL_LIB_FUNC void reverse_string_in_place ( char *  str
   )

   Reverses a string in place.

   This function takes a null-terminated string and reverses its contents
   in place.


<h3><pre>Parameters</pre></h3>


          str Pointer to the null-terminated string to be reversed.
 <h2>sample_strings()</h2>

   FOUNDATIONAL_LIB_FUNC const char* sample_strings ( const char **
   strings,
                                                            size_t        size
                                                          )

   Selects a random string from an array of strings without dynamic memory
   allocation.

   This function selects a random string from an array of strings without
   dynamically allocating memory.


<h3><pre>Parameters</pre></h3>


          strings An array of strings.
          size    The size of the array.


<h3><pre>Returns</pre></h3>


          Returns a pointer to the selected string.
 <h2>select_array()</h2>

   FOUNDATIONAL_LIB_FUNC void* select_array ( const void *  source,
   size_t  source_size,
   size_t  elem_size,
   int(*)(const void *)  condition,
   size_t *  result_size
   )

   Filters elements from an array based on a specified condition.

   This function creates a new array by selecting elements from the source
   array that satisfy the given condition.


<h3><pre>Parameters</pre></h3>


   source Pointer to the source array.
   source_size Size of the source array.
   elem_size Size of each element in the array.
   condition Pointer to the condition function. The function should return
   a non-zero value for elements to be selected.
   result_size Pointer to a variable to store the size of the resulting
   array.


<h3><pre>Returns</pre></h3>


          Pointer to the newly allocated array containing selected
          elements. It is the responsibility of the caller to free the
          memory when done.
 <h2>set_add()</h2>

   FOUNDATIONAL_LIB_FUNC int set_add ( struct Set *  set,
                                             const char *        key
                                           )

   Adds a key pair to the set.

   This function adds a new key-value pair to the provided set. It
   associates them in the setionary.


<h3><pre>Parameters</pre></h3>


          set A pointer to the setionary instance.
          key The key to be added.


<h3><pre>Returns</pre></h3>


          Returns -1 on error, 0 on success.
 <h2>set_del_key()</h2>

   FOUNDATIONAL_LIB_FUNC void set_del_key ( struct Set *  set,
                                                  const char *        key
                                                )

   Deletes a key from a Set.

   This function deletes a key from a Set data structure.


<h3><pre>Parameters</pre></h3>


          set The Set data structure.
          key The key to delete.
 <h2>set_del_keys()</h2>

   FOUNDATIONAL_LIB_FUNC void set_del_keys ( char **  keys )

   Deletes keys from a Set.

   This function deletes keys from a Set data structure.


<h3><pre>Parameters</pre></h3>


          keys The keys to delete.
 <h2>set_destructor()</h2>

       FOUNDATIONAL_LIB_FUNC void set_destructor ( struct Set *
   set )

   The destructor for a Set.

   This function sets the destructor for a Set data structure.


<h3><pre>Parameters</pre></h3>


          set The Set data structure.
 <h2>set_hash()</h2>

   FOUNDATIONAL_LIB_FUNC size_t set_hash ( const char *  key,
                                                 size_t        capacity
                                               )

   Hashes a null-terminated string using the djb2 algorithm.

   The djb2 hash function is a simple and effective algorithm for hashing
   strings. It iterates over each character in the input string, combining
   the current hash value with the ASCII value of the character using the
   formula hash = (hash << 5) + hash + c. The algorithm is known for its
   simplicity, good distribution properties, and reduced likelihood of
   collisions.


<h3><pre>Parameters</pre></h3>


   key Pointer to the null-terminated character array (string) used as the
   key.
   capacity Capacity of the hash table.


<h3><pre>Returns</pre></h3>


          The computed hash value within the specified capacity.
 <h2>set_in()</h2>

   FOUNDATIONAL_LIB_FUNC int set_in ( struct Set *  set,
                                            const char *        key
                                          )

   Checks if a key is in a Set.

   This function checks if a key is present in a Set.


<h3><pre>Parameters</pre></h3>


          set The Set data structure.
          key The key to check.


<h3><pre>Returns</pre></h3>


          Returns 1 if the key is present, 0 otherwise.
 <h2>set_iter()</h2>

   FOUNDATIONAL_LIB_FUNC void set_iter ( struct Set *  set,
                                               void(*)(char *key)  callback
                                             )

   Iterates over a Set and applies a callback to each key.

   This function iterates over a Set data structure and applies a
   callback to each key.


<h3><pre>Parameters</pre></h3>


          set      The Set data structure.
          callback The callback function to apply to each key.
 <h2>set_new_instance()</h2>

     FOUNDATIONAL_LIB_FUNC struct Set* set_new_instance ( void
   )

   Creates a new instance of a Set.

   This function creates a new instance of a Set data structure.


<h3><pre>Returns</pre></h3>


          Returns a pointer to the new Set instance.
 <h2>set_reserve_more()</h2>

   FOUNDATIONAL_LIB_FUNC int set_reserve_more ( struct Set *
   set,
   size_t  number_of_new_elements_max_one_is_expecting
   )

   Reserves additional space in a Set for anticipated new elements.

   This function reserves additional space in the provided Set's
   internal hash table to accommodate an anticipated number of new
   elements. The reservation helps avoid frequent resizes, optimizing
   performance when a known number of new elements is expected. Calling
   this function will trigger a resize and rehash of the Set, but it
   will only happen (ideally) once, if you accurately predict the future
   size of the Set.


<h3><pre>Parameters</pre></h3>


   set A pointer to the Set instance for which space is to be
   reserved.
   number_of_new_elements_max_one_is_expecting The anticipated number of
   new elements (above the current capacity).


<h3><pre>Returns</pre></h3>


          Returns 0 on success, -1 on failure.
 <h2>set_resize()</h2>

   FOUNDATIONAL_LIB_FUNC int set_resize ( struct Set *  set )

   Resizes a Set data structure.

   This function resizes a Set data structure.


<h3><pre>Parameters</pre></h3>


          dict The Set data structure to resize.


<h3><pre>Returns</pre></h3>


          Returns 1 on success, 0 on failure.
 <h2>set_size()</h2>

   FOUNDATIONAL_LIB_FUNC size_t set_size ( struct Set *  set )

   Returns the size of a Set.

   This function returns the size of a Set data structure.


<h3><pre>Parameters</pre></h3>


          set The Set data structure.


<h3><pre>Returns</pre></h3>


          Returns the size of the Set.
 <h2>set_to_array()</h2>

 FOUNDATIONAL_LIB_FUNC int set_to_array ( struct Set *  set,
                                                char ***            keys,
                                                size_t *            size_of_keys
                                              )

   Converts a Set to an array of keys.

   This function converts a Set data structure to an array of keys.
   The resulting array is allocated dynamically and needs to be freed by
   the caller using FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE.


<h3><pre>Parameters</pre></h3>


          set          The Set data structure.
          keys         A pointer to the array of keys (output parameter).
          size_of_keys A pointer to the size of the array (output parameter).
 <h2>set_to_string()</h2>

       FOUNDATIONAL_LIB_FUNC char* set_to_string ( struct Set *
   set )

   Convert a set to a string representation
 <h2>shellescape()</h2>

   FOUNDATIONAL_LIB_FUNC char* shellescape ( const char *  input )

   Escapes special characters in a given string for shell usage.

   This function takes a string as input and escapes special characters
   commonly used in shell commands. The resulting escaped string is
   dynamically allocated, and the caller is responsible for freeing the
   memory.


<h3><pre>Parameters</pre></h3>


          input The input string to be escaped.


<h3><pre>Returns</pre></h3>


          A new dynamically allocated string with escaped special
          characters, or NULL in case of memory allocation failure. The
          caller should free the memory allocated for the escaped string.


<h3><pre>Note</pre></h3>


          Caution: Avoid using the escaped string with system() or similar
          functions as they may introduce security vulnerabilities.
          Consider using alternative methods such as execvp() for safer
          command execution in a controlled environment.
 <h2>shuffle_strings_in_place()</h2>

   FOUNDATIONAL_LIB_FUNC int shuffle_strings_in_place ( char **
   strings,
                                                              size_t   size
                                                            )

   Shuffles an array of strings in place.

   This function shuffles an array of strings in place.


<h3><pre>Parameters</pre></h3>


          strings An array of strings.
          size    The size of the array.


<h3><pre>Returns</pre></h3>


          Returns 1 on success, 0 on failure.
 <h2>sort_char_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC void sort_char_ptrs ( char **  char_ptrs,
                                                     size_t   size
                                                   )

   Sorts an array of pointers to chars in ascending order.

   This function uses the qsort algorithm to sort the given array of
   pointers to chars.


<h3><pre>Parameters</pre></h3>


          char_ptrs Pointer to the array of pointers to chars to be sorted.
          size      Number of elements in the array.
 <h2>sort_chars()</h2>

   FOUNDATIONAL_LIB_FUNC void sort_chars ( char *  chars,
                                                 size_t  size
                                               )

   Sorts an array of chars in ascending order.

   This function uses the qsort algorithm to sort the given array of
   chars.


<h3><pre>Parameters</pre></h3>


          chars Pointer to the array of chars to be sorted.
          size  Number of elements in the array.
 <h2>sort_double_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC void sort_double_ptrs ( double **
   double_ptrs,
                                                       size_t     size
                                                     )

   Sorts an array of pointers to doubles in ascending order.

   This function uses the qsort algorithm to sort the given array of
   pointers to doubles.


<h3><pre>Parameters</pre></h3>


          double_ptrs Pointer to the array of pointers to doubles to be sorted.
          size        Number of elements in the array.
 <h2>sort_doubles()</h2>

   FOUNDATIONAL_LIB_FUNC void sort_doubles ( double *  doubles,
                                                   size_t    size
                                                 )

   Sorts an array of doubles in ascending order.

   This function uses the qsort algorithm to sort the given array of
   doubles.


<h3><pre>Parameters</pre></h3>


          doubles Pointer to the array of doubles to be sorted.
          size    Number of elements in the array.
 <h2>sort_float_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC void sort_float_ptrs ( float **
   float_ptrs,
                                                      size_t    size
                                                    )

   Sorts an array of pointers to floats in ascending order.

   This function uses the qsort algorithm to sort the given array of
   pointers to floats.


<h3><pre>Parameters</pre></h3>


          float_ptrs Pointer to the array of pointers to floats to be sorted.
          size       Number of elements in the array.
 <h2>sort_floats()</h2>

   FOUNDATIONAL_LIB_FUNC void sort_floats ( float *  floats,
                                                  size_t   size
                                                )

   Sorts an array of floats in ascending order.

   This function uses the qsort algorithm to sort the given array of
   floats.


<h3><pre>Parameters</pre></h3>


          floats Pointer to the array of floats to be sorted.
          size   Number of elements in the array.
 <h2>sort_int_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC void sort_int_ptrs ( int **  int_ptrs,
                                                    size_t  size
                                                  )

   Sort an array of pointers to integers for foundational library.

   This function uses a sorting algorithm to arrange the pointers to
   integers pointed to by int_ptrs based on their values in ascending
   order.


<h3><pre>Parameters</pre></h3>


          int_ptrs Pointer to the array of pointers to integers.
          size     Size of the array of pointers.
 <h2>sort_ints()</h2>

   FOUNDATIONAL_LIB_FUNC void sort_ints ( int *   ints,
                                                size_t  size
                                              )

   Sort an array of integers for foundational library.

   This function uses a sorting algorithm to arrange the elements in the
   array pointed to by ints in ascending order.


<h3><pre>Parameters</pre></h3>


          ints Pointer to the array of integers.
          size Size of the array.
 <h2>sort_long_long_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC void sort_long_long_ptrs ( long long **
   long_long_ptrs,
                                                          size_t        size
                                                        )

   Sorts an array of pointers to long longs in ascending order.

   This function uses the qsort algorithm to sort the given array of
   pointers to long longs.


<h3><pre>Parameters</pre></h3>


   long_long_ptrs Pointer to the array of pointers to long longs to be
   sorted.
   size Number of elements in the array.
 <h2>sort_long_longs()</h2>

   FOUNDATIONAL_LIB_FUNC void sort_long_longs ( long long *
   long_longs,
                                                      size_t       size
                                                    )

   Sorts an array of long longs in ascending order.

   This function uses the qsort algorithm to sort the given array of long
   longs.


<h3><pre>Parameters</pre></h3>


          long_longs Pointer to the array of long longs to be sorted.
          size       Number of elements in the array.
 <h2>sort_long_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC void sort_long_ptrs ( long **  long_ptrs,
                                                     size_t   size
                                                   )

   Sorts an array of pointers to longs in ascending order.

   This function uses the qsort algorithm to sort the given array of
   pointers to longs.


<h3><pre>Parameters</pre></h3>


          long_ptrs Pointer to the array of pointers to longs to be sorted.
          size      Number of elements in the array.
 <h2>sort_longs()</h2>

   FOUNDATIONAL_LIB_FUNC void sort_longs ( long *  longs,
                                                 size_t  size
                                               )

   Sorts an array of pointers to unsigned longs in ascending order.

   This function uses the qsort algorithm to sort the given array of
   pointers to unsigned longs.


<h3><pre>Parameters</pre></h3>


   ulong_ptrs Pointer to the array of pointers to unsigned longs to be
   sorted.
   size Number of elements in the array.
 <h2>sort_short_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC void sort_short_ptrs ( short **
   short_ptrs,
                                                      size_t    size
                                                    )

   Sorts an array of pointers to shorts in ascending order.

   This function uses the qsort algorithm to sort the given array of
   pointers to shorts.


<h3><pre>Parameters</pre></h3>


          short_ptrs Pointer to the array of pointers to shorts to be sorted.
          size       Number of elements in the array.
 <h2>sort_shorts()</h2>

   FOUNDATIONAL_LIB_FUNC void sort_shorts ( short *  shorts,
                                                  size_t   size
                                                )

   Sorts an array of shorts in ascending order.

   This function uses the qsort algorithm to sort the given array of
   shorts.


<h3><pre>Parameters</pre></h3>


          shorts Pointer to the array of shorts to be sorted.
          size   Number of elements in the array.
 <h2>sort_size_t_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC void sort_size_t_ptrs ( size_t **
   size_t_ptrs,
                                                       size_t     size
                                                     )

   Sorts an array of pointers to size_t values in ascending order.

   This function uses the qsort algorithm to sort the given array of
   pointers to size_t values.


<h3><pre>Parameters</pre></h3>


   size_t_ptrs Pointer to the array of pointers to size_t values to be
   sorted.
   size Number of elements in the array.
 <h2>sort_size_ts()</h2>

   FOUNDATIONAL_LIB_FUNC void sort_size_ts ( size_t *  size_ts,
                                                   size_t    size
                                                 )

   Sorts an array of size_t values in ascending order.

   This function uses the qsort algorithm to sort the given array of
   size_t values.


<h3><pre>Parameters</pre></h3>


          size_ts Pointer to the array of size_t values to be sorted.
          size    Number of elements in the array.
 <h2>sort_strings()</h2>

   FOUNDATIONAL_LIB_FUNC void sort_strings ( char **  strings,
                                                   size_t   size
                                                 )

   Sorts an array of strings.


<h3><pre>Parameters</pre></h3>


          strings Pointer to the array of strings to be sorted.
          size    Size of the array.
 <h2>sort_uchar_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC void sort_uchar_ptrs ( unsigned char **
   uchar_ptrs,
                                                      size_t            size
                                                    )

   Sorts an array of pointers to unsigned chars in ascending order.

   This function uses the qsort algorithm to sort the given array of
   pointers to unsigned chars.


<h3><pre>Parameters</pre></h3>


   uchar_ptrs Pointer to the array of pointers to unsigned chars to be
   sorted.
   size Number of elements in the array.
 <h2>sort_uchars()</h2>

   FOUNDATIONAL_LIB_FUNC void sort_uchars ( unsigned char *  uchars,
                                                  size_t           size
                                                )

   Sorts an array of unsigned chars in ascending order.

   This function uses the qsort algorithm to sort the given array of
   unsigned chars.


<h3><pre>Parameters</pre></h3>


          uchars Pointer to the array of unsigned chars to be sorted.
          size   Number of elements in the array.
 <h2>sort_uint_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC void sort_uint_ptrs ( unsigned int **
   uint_ptrs,
                                                     size_t           size
                                                   )

   Sort an array of pointers to unsigned integers for foundational
   library.

   This function uses a sorting algorithm to arrange the pointers to
   unsigned integers pointed to by uint_ptrs based on their values in
   ascending order.


<h3><pre>Parameters</pre></h3>


          uint_ptrs Pointer to the array of pointers to unsigned integers.
          size      Size of the array of pointers.
 <h2>sort_uints()</h2>

   FOUNDATIONAL_LIB_FUNC void sort_uints ( unsigned int *  uints,
                                                 size_t          size
                                               )

   Sort an array of unsigned integers for foundational library.

   This function uses a sorting algorithm to arrange the elements in the
   array pointed to by uints in ascending order.


<h3><pre>Parameters</pre></h3>


          uints Pointer to the array of unsigned integers.
          size  Size of the array.
 <h2>sort_ulong_long_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC void sort_ulong_long_ptrs ( unsigned long
   long **  ulong_long_ptrs,
   size_t  size
   )

   Sorts an array of pointers to unsigned long longs in ascending order.

   This function uses the qsort algorithm to sort the given array of
   pointers to unsigned long longs.


<h3><pre>Parameters</pre></h3>


   ulong_long_ptrs Pointer to the array of pointers to unsigned long longs
   to be sorted.
   size Number of elements in the array.
 <h2>sort_ulong_longs()</h2>

   FOUNDATIONAL_LIB_FUNC void sort_ulong_longs ( unsigned long long
   *  ulong_longs,
   size_t  size
   )

   Sorts an array of unsigned long longs in ascending order.

   This function uses the qsort algorithm to sort the given array of
   unsigned long longs.


<h3><pre>Parameters</pre></h3>


          ulong_longs Pointer to the array of unsigned long longs to be sorted.
          size        Number of elements in the array.
 <h2>sort_ulong_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC void sort_ulong_ptrs ( unsigned long **
   ulong_ptrs,
                                                      size_t            size
                                                    )

   Sorts an array of pointers to unsigned longs in ascending order.

   This function uses the qsort algorithm to sort the given array of
   pointers to unsigned longs.


<h3><pre>Parameters</pre></h3>


   ulong_ptrs Pointer to the array of pointers to unsigned longs to be
   sorted.
   size Number of elements in the array.
 <h2>sort_ulongs()</h2>

   FOUNDATIONAL_LIB_FUNC void sort_ulongs ( unsigned long *  ulongs,
                                                  size_t           size
                                                )

   Sorts an array of unsigned longs in ascending order.

   This function uses the qsort algorithm to sort the given array of
   unsigned longs.


<h3><pre>Parameters</pre></h3>


          ulongs Pointer to the array of unsigned longs to be sorted.
          size   Number of elements in the array.
 <h2>sort_ushort_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC void sort_ushort_ptrs ( unsigned short **
   ushort_ptrs,
                                                       size_t             size
                                                     )

   Sorts an array of pointers to unsigned shorts in ascending order.

   This function uses the qsort algorithm to sort the given array of
   pointers to unsigned shorts.


<h3><pre>Parameters</pre></h3>


   ushort_ptrs Pointer to the array of pointers to unsigned shorts to be
   sorted.
   size Number of elements in the array.
 <h2>sort_ushorts()</h2>

   FOUNDATIONAL_LIB_FUNC void sort_ushorts ( unsigned short *
   ushorts,
                                                   size_t            size
                                                 )

   Sorts an array of unsigned shorts in ascending order.

   This function uses the qsort algorithm to sort the given array of
   unsigned shorts.


<h3><pre>Parameters</pre></h3>


          ushorts Pointer to the array of unsigned shorts to be sorted.
          size    Number of elements in the array.
 <h2>sorted_char_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC char** sorted_char_ptrs ( char **
   char_ptrs,
                                                         size_t   size
                                                       )

   Creates a new array containing sorted pointers to chars.

   This function takes an array of pointers to chars, creates a new array,
   and returns it after sorting the original array in ascending order. The
   caller is responsible for freeing the memory allocated for the returned
   array using free().


<h3><pre>Parameters</pre></h3>


          char_ptrs Pointer to the array of pointers to chars to be sorted.
          size      Number of elements in the array.


<h3><pre>Returns</pre></h3>


          Pointer to the newly created and sorted array of pointers to
          chars. The caller is responsible for freeing the memory using
          free().
 <h2>sorted_chars()</h2>

   FOUNDATIONAL_LIB_FUNC char* sorted_chars ( char *  chars,
                                                    size_t  size
                                                  )

   Creates a new array containing sorted chars.

   This function takes an array of chars, creates a new array, and returns
   it after sorting the original array in ascending order. The caller is
   responsible for freeing the memory allocated for the returned array
   using free().


<h3><pre>Parameters</pre></h3>


          chars Pointer to the array of chars to be sorted.
          size  Number of elements in the array.


<h3><pre>Returns</pre></h3>


          Pointer to the newly created and sorted array of chars. The
          caller is responsible for freeing the memory using free().
 <h2>sorted_double_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC double** sorted_double_ptrs ( double **
   double_ptrs,
                                                             size_t     size
                                                           )

   Creates a new array containing sorted pointers to doubles.

   This function takes an array of pointers to doubles, creates a new
   array, and returns it after sorting the original array in ascending
   order. The caller is responsible for freeing the memory allocated for
   the returned array using free().


<h3><pre>Parameters</pre></h3>


          double_ptrs Pointer to the array of pointers to doubles to be sorted.
          size        Number of elements in the array.


<h3><pre>Returns</pre></h3>


          Pointer to the newly created and sorted array of pointers to
          doubles. The caller is responsible for freeing the memory using
          free().
 <h2>sorted_doubles()</h2>

   FOUNDATIONAL_LIB_FUNC double* sorted_doubles ( double *  doubles,
                                                        size_t    size
                                                      )

   Creates a new array containing sorted doubles.

   This function takes an array of doubles, creates a new array, and
   returns it after sorting the original array in ascending order. The
   caller is responsible for freeing the memory allocated for the returned
   array using free().


<h3><pre>Parameters</pre></h3>


          doubles Pointer to the array of doubles to be sorted.
          size    Number of elements in the array.


<h3><pre>Returns</pre></h3>


          Pointer to the newly created and sorted array of doubles. The
          caller is responsible for freeing the memory using free().
 <h2>sorted_float_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC float** sorted_float_ptrs ( float **
   float_ptrs,
                                                           size_t    size
                                                         )

   Creates a new array containing sorted pointers to floats.

   This function takes an array of pointers to floats, creates a new
   array, and returns it after sorting the original array in ascending
   order. The caller is responsible for freeing the memory allocated for
   the returned array using free().


<h3><pre>Parameters</pre></h3>


          float_ptrs Pointer to the array of pointers to floats to be sorted.
          size       Number of elements in the array.


<h3><pre>Returns</pre></h3>


          Pointer to the newly created and sorted array of pointers to
          floats. The caller is responsible for freeing the memory using
          free().
 <h2>sorted_floats()</h2>

   FOUNDATIONAL_LIB_FUNC float* sorted_floats ( float *  floats,
                                                      size_t   size
                                                    )

   Creates a new array containing sorted floats.

   This function takes an array of floats, creates a new array, and
   returns it after sorting the original array in ascending order. The
   caller is responsible for freeing the memory allocated for the returned
   array using free().


<h3><pre>Parameters</pre></h3>


          floats Pointer to the array of floats to be sorted.
          size   Number of elements in the array.


<h3><pre>Returns</pre></h3>


          Pointer to the newly created and sorted array of floats. The
          caller is responsible for freeing the memory using free().
 <h2>sorted_int_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC int** sorted_int_ptrs ( int **  int_ptrs,
                                                       size_t  size
                                                     )

   Get a sorted copy of an array of pointers to integers for foundational
   library.

   This function creates a sorted copy of the array of pointers to
   integers pointed to by int_ptrs and returns a pointer to the sorted
   array of pointers. The original array of pointers remains unchanged.


<h3><pre>Parameters</pre></h3>


          int_ptrs Pointer to the array of pointers to integers.
          size     Size of the array of pointers.


<h3><pre>Returns</pre></h3>


          A pointer to the sorted array of pointers to integers.


<h3><pre>Note</pre></h3>


          The caller is responsible for freeing the memory allocated for
          the sorted array of pointers using free().
 <h2>sorted_ints()</h2>

   FOUNDATIONAL_LIB_FUNC int* sorted_ints ( int *   ints,
                                                  size_t  size
                                                )

   Get a sorted copy of an array of integers for foundational library.

   This function creates a sorted copy of the array pointed to by ints and
   returns a pointer to the sorted array. The original array remains
   unchanged.


<h3><pre>Parameters</pre></h3>


          ints Pointer to the array of integers.
          size Size of the array.


<h3><pre>Returns</pre></h3>


          A pointer to the sorted array of integers. Note: The caller is
          responsible for freeing the memory allocated for the sorted
          array using the appropriate deallocation function, such as
          free().
 <h2>sorted_long_long_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC long long** sorted_long_long_ptrs ( long
   long **  long_long_ptrs,
   size_t  size
   )

   Creates a new array containing sorted pointers to long longs.

   This function takes an array of pointers to long longs, creates a new
   array, and returns it after sorting the original array in ascending
   order. The caller is responsible for freeing the memory allocated for
   the returned array using free().


<h3><pre>Parameters</pre></h3>


   long_long_ptrs Pointer to the array of pointers to long longs to be
   sorted.
   size Number of elements in the array.


<h3><pre>Returns</pre></h3>


          Pointer to the newly created and sorted array of pointers to
          long longs. The caller is responsible for freeing the memory
          using free().
 <h2>sorted_long_longs()</h2>

   FOUNDATIONAL_LIB_FUNC long long* sorted_long_longs ( long long *
   long_longs,
                                                              size_t      size
                                                            )

   Creates a new array containing sorted long longs.

   This function takes an array of long longs, creates a new array, and
   returns it after sorting the original array in ascending order. The
   caller is responsible for freeing the memory allocated for the returned
   array using free().


<h3><pre>Parameters</pre></h3>


          long_longs Pointer to the array of long longs to be sorted.
          size       Number of elements in the array.


<h3><pre>Returns</pre></h3>


          Pointer to the newly created and sorted array of long longs. The
          caller is responsible for freeing the memory using free().
 <h2>sorted_long_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC long** sorted_long_ptrs ( long **
   long_ptrs,
                                                         size_t   size
                                                       )

   Creates a new array containing sorted pointers to longs.

   This function takes an array of pointers to longs, creates a new array,
   and returns it after sorting the original array in ascending order. The
   caller is responsible for freeing the memory allocated for the returned
   array using free().


<h3><pre>Parameters</pre></h3>


          long_ptrs Pointer to the array of pointers to longs to be sorted.
          size      Number of elements in the array.


<h3><pre>Returns</pre></h3>


          Pointer to the newly created and sorted array of pointers to
          longs. The caller is responsible for freeing the memory using
          free().
 <h2>sorted_longs()</h2>

   FOUNDATIONAL_LIB_FUNC long* sorted_longs ( long *  longs,
                                                    size_t  size
                                                  )

   Creates a new array containing sorted pointers to unsigned longs.

   This function takes an array of pointers to unsigned longs, creates a
   new array, and returns it after sorting the original array in ascending
   order. The caller is responsible for freeing the memory allocated for
   the returned array using free().


<h3><pre>Parameters</pre></h3>


   ulong_ptrs Pointer to the array of pointers to unsigned longs to be
   sorted.
   size Number of elements in the array.


<h3><pre>Returns</pre></h3>


          Pointer to the newly created and sorted array of pointers to
          unsigned longs. The caller is responsible for freeing the memory
          using free().
 <h2>sorted_short_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC short** sorted_short_ptrs ( short **
   short_ptrs,
                                                           size_t    size
                                                         )

   Creates a new array containing sorted pointers to shorts.

   This function takes an array of pointers to shorts, creates a new
   array, and returns it after sorting the original array in ascending
   order. The caller is responsible for freeing the memory allocated for
   the returned array using free().


<h3><pre>Parameters</pre></h3>


          short_ptrs Pointer to the array of pointers to shorts to be sorted.
          size       Number of elements in the array.


<h3><pre>Returns</pre></h3>


          Pointer to the newly created and sorted array of pointers to
          shorts. The caller is responsible for freeing the memory using
          free().
 <h2>sorted_shorts()</h2>

   FOUNDATIONAL_LIB_FUNC short* sorted_shorts ( short *  shorts,
                                                      size_t   size
                                                    )

   Creates a new array containing sorted shorts.

   This function takes an array of shorts, creates a new array, and
   returns it after sorting the original array in ascending order. The
   caller is responsible for freeing the memory allocated for the returned
   array using free().


<h3><pre>Parameters</pre></h3>


          shorts Pointer to the array of shorts to be sorted.
          size   Number of elements in the array.


<h3><pre>Returns</pre></h3>


          Pointer to the newly created and sorted array of shorts. The
          caller is responsible for freeing the memory using free().
 <h2>sorted_size_t_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC size_t** sorted_size_t_ptrs ( size_t **
   size_t_ptrs,
                                                             size_t     size
                                                           )

   Creates a new array containing sorted pointers to size_t values.

   This function takes an array of pointers to size_t values, creates a
   new array, and returns it after sorting the original array in ascending
   order. The caller is responsible for freeing the memory allocated for
   the returned array using free().


<h3><pre>Parameters</pre></h3>


   size_t_ptrs Pointer to the array of pointers to size_t values to be
   sorted.
   size Number of elements in the array.


<h3><pre>Returns</pre></h3>


          Pointer to the newly created and sorted array of pointers to
          size_t values. The caller is responsible for freeing the memory
          using free().
 <h2>sorted_size_ts()</h2>

   FOUNDATIONAL_LIB_FUNC size_t* sorted_size_ts ( size_t *  size_ts,
                                                        size_t    size
                                                      )

   Creates a new array containing sorted size_t values.

   This function takes an array of size_t values, creates a new array, and
   returns it after sorting the original array in ascending order. The
   caller is responsible for freeing the memory allocated for the returned
   array using free().


<h3><pre>Parameters</pre></h3>


          size_ts Pointer to the array of size_t values to be sorted.
          size    Number of elements in the array.


<h3><pre>Returns</pre></h3>


          Pointer to the newly created and sorted array of size_t values.
          The caller is responsible for freeing the memory using free().
 <h2>sorted_strings()</h2>

   FOUNDATIONAL_LIB_FUNC char** sorted_strings ( char **  strings,
                                                       size_t   size
                                                     )

   Creates a new array of strings sorted in ascending order.

   This function takes an array of strings and returns a new array
   containing the strings sorted in ascending order. The original array
   remains unchanged.


<h3><pre>Parameters</pre></h3>


          strings Pointer to the array of strings to be sorted.
          size    Size of the array.


<h3><pre>Returns</pre></h3>


          Pointer to the dynamically allocated array of strings sorted in
          ascending order. The caller is responsible for freeing the
          allocated memory.
 <h2>sorted_uchar_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC unsigned char** sorted_uchar_ptrs (
   unsigned char **  uchar_ptrs,
   size_t  size
   )

   Creates a new array containing sorted pointers to unsigned chars.

   This function takes an array of pointers to unsigned chars, creates a
   new array, and returns it after sorting the original array in ascending
   order. The caller is responsible for freeing the memory allocated for
   the returned array using free().


<h3><pre>Parameters</pre></h3>


   uchar_ptrs Pointer to the array of pointers to unsigned chars to be
   sorted.
   size Number of elements in the array.


<h3><pre>Returns</pre></h3>


          Pointer to the newly created and sorted array of pointers to
          unsigned chars. The caller is responsible for freeing the memory
          using free().
 <h2>sorted_uchars()</h2>

   FOUNDATIONAL_LIB_FUNC unsigned char* sorted_uchars ( unsigned
   char *  uchars,
   size_t  size
   )

   Creates a new array containing sorted unsigned chars.

   This function takes an array of unsigned chars, creates a new array,
   and returns it after sorting the original array in ascending order. The
   caller is responsible for freeing the memory allocated for the returned
   array using free().


<h3><pre>Parameters</pre></h3>


          uchars Pointer to the array of unsigned chars to be sorted.
          size   Number of elements in the array.


<h3><pre>Returns</pre></h3>


          Pointer to the newly created and sorted array of unsigned chars.
          The caller is responsible for freeing the memory using free().
 <h2>sorted_uint_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC unsigned int** sorted_uint_ptrs ( unsigned
   int **  uint_ptrs,
   size_t  size
   )

   Get a sorted copy of an array of pointers to unsigned integers for
   foundational library.

   This function creates a sorted copy of the array of pointers to
   unsigned integers pointed to by uint_ptrs and returns a pointer to the
   sorted array of pointers. The original array of pointers remains
   unchanged.


<h3><pre>Parameters</pre></h3>


          uint_ptrs Pointer to the array of pointers to unsigned integers.
          size      Size of the array of pointers.


<h3><pre>Returns</pre></h3>


          A pointer to the sorted array of pointers to unsigned integers.


<h3><pre>Note</pre></h3>


          The caller is responsible for freeing the memory allocated for
          the sorted array of pointers using free().
 <h2>sorted_uints()</h2>

   FOUNDATIONAL_LIB_FUNC unsigned int* sorted_uints ( unsigned int
   *  uints,
   size_t  size
   )

   Get a sorted copy of an array of unsigned integers for foundational
   library.

   This function creates a sorted copy of the array pointed to by uints
   and returns a pointer to the sorted array. The original array remains
   unchanged.


<h3><pre>Parameters</pre></h3>


          uints Pointer to the array of unsigned integers.
          size  Size of the array.


<h3><pre>Returns</pre></h3>


          A pointer to the sorted array of unsigned integers.


<h3><pre>Note</pre></h3>


          The caller is responsible for freeing the memory allocated for
          the sorted array using the free() function.
 <h2>sorted_ulong_long_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC unsigned long long** sorted_ulong_long_ptrs
   ( unsigned long long **  ulong_long_ptrs,
   size_t  size
   )

   Creates a new array containing sorted pointers to unsigned long longs.

   This function takes an array of pointers to unsigned long longs,
   creates a new array, and returns it after sorting the original array in
   ascending order. The caller is responsible for freeing the memory
   allocated for the returned array using free().


<h3><pre>Parameters</pre></h3>


   ulong_long_ptrs Pointer to the array of pointers to unsigned long longs
   to be sorted.
   size Number of elements in the array.


<h3><pre>Returns</pre></h3>


          Pointer to the newly created and sorted array of pointers to
          unsigned long longs. The caller is responsible for freeing the
          memory using free().
 <h2>sorted_ulong_longs()</h2>

   FOUNDATIONAL_LIB_FUNC unsigned long long* sorted_ulong_longs (
   unsigned long long *  ulong_longs,
   size_t  size
   )

   Creates a new array containing sorted unsigned long longs.

   This function takes an array of unsigned long longs, creates a new
   array, and returns it after sorting the original array in ascending
   order. The caller is responsible for freeing the memory allocated for
   the returned array using free().


<h3><pre>Parameters</pre></h3>


          ulong_longs Pointer to the array of unsigned long longs to be sorted.
          size        Number of elements in the array.


<h3><pre>Returns</pre></h3>


          Pointer to the newly created and sorted array of unsigned long
          longs. The caller is responsible for freeing the memory using
          free().
 <h2>sorted_ulong_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC unsigned long** sorted_ulong_ptrs (
   unsigned long **  ulong_ptrs,
   size_t  size
   )

   Creates a new array containing sorted pointers to unsigned longs.

   This function takes an array of pointers to unsigned longs, creates a
   new array, and returns it after sorting the original array in ascending
   order. The caller is responsible for freeing the memory allocated for
   the returned array using free().


<h3><pre>Parameters</pre></h3>


   ulong_ptrs Pointer to the array of pointers to unsigned longs to be
   sorted.
   size Number of elements in the array.


<h3><pre>Returns</pre></h3>


          Pointer to the newly created and sorted array of pointers to
          unsigned longs. The caller is responsible for freeing the memory
          using free().
 <h2>sorted_ulongs()</h2>

   FOUNDATIONAL_LIB_FUNC unsigned long* sorted_ulongs ( unsigned
   long *  ulongs,
   size_t  size
   )

   Creates a new array containing sorted unsigned longs.

   This function takes an array of unsigned longs, creates a new array,
   and returns it after sorting the original array in ascending order. The
   caller is responsible for freeing the memory allocated for the returned
   array using free().


<h3><pre>Parameters</pre></h3>


          ulongs Pointer to the array of unsigned longs to be sorted.
          size   Number of elements in the array.


<h3><pre>Returns</pre></h3>


          Pointer to the newly created and sorted array of unsigned longs.
          The caller is responsible for freeing the memory using free().
 <h2>sorted_ushort_ptrs()</h2>

   FOUNDATIONAL_LIB_FUNC unsigned short** sorted_ushort_ptrs (
   unsigned short **  ushort_ptrs,
   size_t  size
   )

   Creates a new array containing sorted pointers to unsigned shorts.

   This function takes an array of pointers to unsigned shorts, creates a
   new array, and returns it after sorting the original array in ascending
   order. The caller is responsible for freeing the memory allocated for
   the returned array using free().


<h3><pre>Parameters</pre></h3>


   ushort_ptrs Pointer to the array of pointers to unsigned shorts to be
   sorted.
   size Number of elements in the array.


<h3><pre>Returns</pre></h3>


          Pointer to the newly created and sorted array of pointers to
          unsigned shorts. The caller is responsible for freeing the
          memory using free().
 <h2>sorted_ushorts()</h2>

   FOUNDATIONAL_LIB_FUNC unsigned short* sorted_ushorts ( unsigned
   short *  ushorts,
   size_t  size
   )

   Creates a new array containing sorted unsigned shorts.

   This function takes an array of unsigned shorts, creates a new array,
   and returns it after sorting the original array in ascending order. The
   caller is responsible for freeing the memory allocated for the returned
   array using free().


<h3><pre>Parameters</pre></h3>


          ushorts Pointer to the array of unsigned shorts to be sorted.
          size    Number of elements in the array.


<h3><pre>Returns</pre></h3>


          Pointer to the newly created and sorted array of unsigned
          shorts. The caller is responsible for freeing the memory using
          free().
 <h2>split()</h2>

   FOUNDATIONAL_LIB_FUNC char** split ( const char *  str,
                                              size_t *      output_size,
                                              const char *  delim,
                                              size_t        max_times,
                                              int           keep_delim_in_result
                                            )

   Splits a given string into an array based on a specified delimiter.

   This function takes a string as input and splits it into an array of
   strings, using the provided delimiter. Delimiters are included in the
   result if keep_delim_in_result is true. Memory is dynamically allocated
   for the array of strings, and the caller is responsible for freeing
   this memory.


<h3><pre>Parameters</pre></h3>


   str The input string to be split.
   output_size A pointer to a size_t variable to store the number of
   tokens.
   delim The delimiter string for splitting the input string.
   max_times Maximum number of times to split the string (0 for
   unlimited).
   keep_delim_in_result A boolean indicating whether to keep delimiters in
   the result.


<h3><pre>Returns</pre></h3>


          An array of strings representing the tokens, or NULL in case of
          errors. The caller should free the memory allocated for the
          array and its elements.
 <h2>starts_with()</h2>

   static int starts_with ( const char *  str,
                            const char *  prefix
                          )
   inlinestatic

   Checks if a string starts with a specified prefix.

   This function compares the beginning of a string with a specified
   prefix.


<h3><pre>Parameters</pre></h3>


          str    The input string to be checked.
          prefix The prefix to check for at the beginning of the input string.


<h3><pre>Returns</pre></h3>


          1 if the input string starts with the given prefix, 0 otherwise.
 <h2>str_to_double()</h2>

   static double str_to_double ( const char *  string )
   inlinestatic

   Converts a string to a double-precision floating-point number.

   Parses the given null-terminated string to extract a numerical value
   and returns it as a double-precision floating-point number.


<h3><pre>Parameters</pre></h3>


          str The input string to be converted.


<h3><pre>Returns</pre></h3>


          The resulting double-precision floating-point number.
 <h2>string_array_uniq()</h2>

  FOUNDATIONAL_LIB_FUNC int string_array_uniq ( const char **
   array,
                                                      size_t         size,
                                                      char ***       output,
                                                      size_t *       output_size
                                                    )

   Remove duplicate strings from a string array.

   This function takes an array of strings, removes duplicate entries, and
   returns the result in a dynamically allocated array. The input array
   remains unchanged.


<h3><pre>Parameters</pre></h3>


   array The input string array.
   size The size of the input array.
   output A pointer to the location where the result array will be stored.
   The caller is responsible for freeing the memory allocated for the
   result.
   output_size A pointer to the location where the size of the result
   array will be stored.


<h3><pre>Returns</pre></h3>


          -1 if an error occurs (e.g., invalid input or memory allocation
          failure), 0 if the operation is successful, and the result array
          is dynamically allocated.


<h3><pre>Note</pre></h3>


          The caller is responsible for freeing the memory allocated for
          the result array.

   const char *input_array[] = {"apple", "orange", "banana", "apple",
   "grape"};
   char **result_array;
   size_t result_size;
   int status = string_array_uniq(input_array, 5, &result_array,
   &result_size);
   if (!status) {
   // Successfully obtained the unique string array.
   // Use result_array and result_size as needed.
   // Don't forget to free(result_array) when done.
   } else {
   // Handle the error.
   }
   string_array_uniq
   FOUNDATIONAL_LIB_FUNC int string_array_uniq(const char **array, size_t
   size, char ***output, size_t *output_size)
   Remove duplicate strings from a string array.
   Definition: foundationallib.h:9605
 <h2>string_array_uniq_adjacent()</h2>

   FOUNDATIONAL_LIB_FUNC int string_array_uniq_adjacent ( const char
   **  first_array,
   size_t  size,
   char ***  new_array,
   size_t *  new_size
   )

   Remove adjacent duplicate strings from a string array.

   This function takes an array of strings, removes duplicates that are
   adjacent to each other, and returns the result in a dynamically
   allocated array. The input array remains unchanged.


<h3><pre>Parameters</pre></h3>


   first_array The input string array.
   size The size of the input array.
   new_array A pointer to the location where the result array will be
   stored. The caller is responsible for freeing the memory allocated for
   the result.
   new_size A pointer to the location where the size of the result array
   will be stored.


<h3><pre>Returns</pre></h3>


          -1 if an error occurs (e.g., invalid input or memory allocation
          failure), 0 if the operation is successful, and the result array
          is malloced.


<h3><pre>Note</pre></h3>


          The caller is responsible for freeing the memory allocated for
          the result array.

   const char *input_array[] = {"apple", "orange", "orange", "banana",
   "banana", "apple", "grape"};
   char **result_array;
   size_t result_size;
   int status = string_array_uniq_adjacent(input_array, 7,
   &result_array, &result_size);
   if (!status) {
   // Successfully obtained the string array with adjacent duplicates
   removed.
   // Use result_array and result_size as needed.
   // Don't forget to free(result_array) when done.
   } else {
   // Handle the error.
   }
   string_array_uniq_adjacent
   FOUNDATIONAL_LIB_FUNC int string_array_uniq_adjacent(const char
   **first_array, size_t size, char ***new_array, size_t *new_size)
   Remove adjacent duplicate strings from a string array.
   Definition: foundationallib.h:9705
 <h2>string_has_substr()</h2>

   FOUNDATIONAL_LIB_FUNC int string_has_substr ( const char *
   string,
   size_t  string_length,
   const char *  substring,
   size_t  substring_length
   )

   Checks if a substring exists within a given string.

   This function examines the specified string to determine if a substring
   with the specified content and length is present.


<h3><pre>Parameters</pre></h3>


      string           Pointer to the start of the string to search.
      string_length    Length of the string in characters.
      substring        Pointer to the substring to search for within the string.
      substring_length Length of the substring in characters.


<h3><pre>Returns</pre></h3>


          Returns 1 (true) if the substring is found, 0 (false) otherwise.


<h3><pre>Note</pre></h3>


          This function assumes that the provided string and substring
          pointers are valid and that the lengths are non-negative. It is
          the responsibility of the caller to ensure the correctness of
          the inputs to prevent undefined behavior.
          The function uses character-based lengths for strings, not
          byte-based. Ensure that the string and substring lengths
          represent the number of characters, not the number of bytes.
 <h2>string_to_int()</h2>

   FOUNDATIONAL_LIB_FUNC int string_to_int ( const char *  str )

   Converts a string to an integer.

   This function converts a string representation of an integer to an
   actual integer value.


<h3><pre>Parameters</pre></h3>


          str Pointer to the string to be converted.


<h3><pre>Returns</pre></h3>


          Integer value representing the converted string. If the string
          is not a valid integer representation, the behavior is
          undefined.
 <h2>string_to_json()</h2>

                FOUNDATIONAL_LIB_FUNC char* string_to_json ( const char *
   input_string )

   Converts a given input string to its JSON representation.

   This function iterates through each character of the input string,
   escaping special characters like double quotes and backslashes to
   create a valid JSON string.


<h3><pre>Parameters</pre></h3>


          input_string The input string to be converted to JSON format.


<h3><pre>Returns</pre></h3>


          A pointer to the newly created JSON string, or NULL if memory
          allocation fails. The caller is responsible for freeing the
          allocated memory.
 <h2>string_to_lowercase()</h2>

     FOUNDATIONAL_LIB_FUNC char* string_to_lowercase ( char *  string
   )

   Convert a string to lowercase.

   This function takes a null-terminated string as input and converts all
   its characters to lowercase. The resulting lowercase string is
   allocated dynamically and returned. It is the caller's responsibility
   to free the memory allocated for the new string.


<h3><pre>Parameters</pre></h3>


          str The input string to be converted to lowercase.


<h3><pre>Returns</pre></h3>


          A pointer to the newly allocated lowercase string, or NULL if
          memory allocation fails. Make sure to free the memory using
          free() when done with the returned string.
 <h2>string_to_title_case()</h2>

       FOUNDATIONAL_LIB_FUNC char* string_to_title_case ( const char *
   str )

   Converts a string to title case.

   This function converts the input string to title case, allocating
   memory for the new string. The caller is responsible for freeing the
   allocated memory.


<h3><pre>Parameters</pre></h3>


          str Pointer to the input string.


<h3><pre>Returns</pre></h3>


          Pointer to the new title case string or NULL if allocation
          fails. The caller must free the allocated memory.
 <h2>string_to_uppercase()</h2>

     FOUNDATIONAL_LIB_FUNC char* string_to_uppercase ( char *  string
   )

   Convert a string to uppercase.

   This function takes a null-terminated string as input and converts all
   its characters to uppercase. The resulting uppercase string is
   allocated dynamically and returned. It is the caller's responsibility
   to free the memory allocated for the new string.


<h3><pre>Parameters</pre></h3>


          str The input string to be converted to uppercase.


<h3><pre>Returns</pre></h3>


          A pointer to the newly allocated uppercase string, or NULL if
          memory allocation fails. Make sure to free the memory using
          free() when done with the returned string.
 <h2>strip()</h2>

   FOUNDATIONAL_LIB_FUNC char* strip ( const char *  str )

   Trims leading and trailing whitespace from a given string.

   This function takes a string as input and removes any leading and
   trailing whitespace characters, returning a new dynamically allocated
   string with the trimmed content. It is the caller's responsibility to
   free the memory allocated for the new string.


<h3><pre>Parameters</pre></h3>


          str The input string to be trimmed.


<h3><pre>Returns</pre></h3>


          A pointer to the trimmed string or NULL if memory allocation
          fails. The caller should free the returned pointer when done
          using it.
 <h2>sum_of_int_array()</h2>

   FOUNDATIONAL_LIB_FUNC int sum_of_int_array ( const int *  array,
                                                      size_t       size
                                                    )

   Calculates the sum of elements in an array of integers.

   This function computes the sum of elements in the given array of
   integers.


<h3><pre>Parameters</pre></h3>


          array Pointer to the array of integers.
          size  Size of the array.


<h3><pre>Returns</pre></h3>


          Sum of elements in the array.
 <h2>uint_to_string()</h2>

   FOUNDATIONAL_LIB_FUNC char* uint_to_string ( size_t  number )

   Converts an integer to its string representation.

   This function takes an unsigned integer (size_t) as input and returns a
   dynamically allocated character array containing its string
   representation.


<h3><pre>Parameters</pre></h3>


          number The integer to be converted.


<h3><pre>Returns</pre></h3>


          A pointer to the dynamically allocated string representation.
 <h2>utoa()</h2>

   FOUNDATIONAL_LIB_FUNC void utoa ( size_t  unsigned_value,
                                           char *  output
                                         )
 <h2>write_file()</h2>

   FOUNDATIONAL_LIB_FUNC int write_file ( const char *  filename,
                                                const char *  content
                                              )

   Writes a string to a file.

   This function writes the specified content string to the specified
   file.


<h3><pre>Parameters</pre></h3>


          filename Pointer to the name of the file to be written.
          content  Pointer to the string content to be written to the file.
          mode     Pointer to the mode of the file to be written to.


<h3><pre>Returns</pre></h3>


          Returns 0 on success and -1 on failure. The function fails if
          the file cannot be opened or if there is an error during the
          writing process.
 <h2>write_to_file_with_mode()</h2>

   FOUNDATIONAL_LIB_FUNC int write_to_file_with_mode ( const char *
   filename,
   const char *  content,
   size_t  content_length,
   const char *  mode
   )

   Writes a string or data to a file with a specified mode.

   This function writes the specified content string to the specified
   file.


<h3><pre>Parameters</pre></h3>


         filename       Pointer to the name of the file to be written.
         content        Pointer to the string content to be written to the file.
         content_length The length of the data to be written.
         mode           Pointer to the mode of the file to be written to.


<h3><pre>Returns</pre></h3>


          Returns 0 on success and -1 on failure. The function fails if
          the file cannot be opened or if there is an error during the
          writing process.

Variable Documentation
 <h2>FOUNDATIONAL_LIB_aggressive_die</h2>

   FOUNDATIONAL_LIB_AGGRESSIVE_DIE_TYPE
   FOUNDATIONAL_LIB_aggressive_die = 1

   Global variable to control aggressive die behavior.

   When set to true, the functions in the foundational library kill the
   program on error; when set to false, they fail silently. This variable,
   aggressive_die, is the only global declared, utilizing 1 byte of
   overhead. It provides a centralized control over the error-handling
   behavior of the library functions.

   Default die behavior is true, which is suitable for scenarios like
   scripting.

     * src
     * foundationallib.h
     * Generated by doxygen 1.9.1

References

   Visible links:
   Hidden links:
   Logo
   Foundationallib  1.0q
   A complete Foundationallib for C

   IFRAME: MSearchResults

   Data Structures | Macros | Typedefs | Functions |
   Variables
   foundationallib.h File Reference
   #include <stdint.h>
   #include <ctype.h>
   #include <stdarg.h>
   #include <stdio.h>
   #include <stdlib.h>
   #include <string.h>
   #include <errno.h>
   #include <unistd.h>
   #include <sys/stat.h>
   #include <dirent.h>
   #include <fnmatch.h>
   #include <threads.h>
   Include dependency graph for foundationallib.h:

   IFRAME: foundationallib_8h__incl.svg

   This browser is not able to show SVG: try Firefox, Chrome, Safari, or
   Opera instead.

   Go to the source code of this file.

Data Structures

   struct   SetKey

   struct   Dict

   struct   Set

   struct   DictKeyValue

   struct   FrozenDict

   struct   FrozenSet

   struct   ThreadData

Macros

   #define  FOUNDATIONAL_LIB_AGGRESSIVE_DIE_TYPE   unsigned char
     Type of the aggressive die variable. More...

   #define  FOUNDATIONAL_LIB_USE_STATIC_ASSERTS_FOR_SAFETY   1
     Disable this section if you are maybe getting compilation errors
   (-DFOUNDATIONAL_LIB_USE_STATIC_ASSERTS_FOR_SAFETY=0). Or you can try
   using a modern compiler C11, C++11, though this is not necessary.
   Foundationallib should work with all C and C++ compilers. More...

   #define  FOUNDATIONAL_LIB_Static_assert   _Static_assert

   #define  FOUNDATIONAL_LIB_STATIC_ASSERT_MSG(true_cond,
   failure_message)   FOUNDATIONAL_LIB_Static_assert((true_cond),
   failure_message)

   #define
   FOUNDATIONAL_LIB_STATIC_ASSERT(true_cond)   FOUNDATIONAL_LIB_St
   atic_assert((true_cond), "(" #true_cond ") failed")

   #define
   FOUNDATIONAL_LIB_SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATOR
   21 /* length of "18446744073709551615" plus 1 == 21 */

   #define  FOUNDATIONAL_LIB_UNSAFE_FUNCTIONS_ENABLED   1

   #define  FOUNDATIONAL_LIB_VA_LIST   va_list

   #define  FOUNDATIONAL_LIB_VA_START   va_start

   #define  FOUNDATIONAL_LIB_VA_ARG   va_arg

   #define  FOUNDATIONAL_LIB_VA_END   va_end

   #define  FOUNDATIONAL_LIB_PRINTF   printf

   #define  FOUNDATIONAL_LIB_SPRINTF   sprintf

   #define  FOUNDATIONAL_LIB_VSNPRINTF   vsnprintf

   #define  FOUNDATIONAL_LIB_FPRINTF   fprintf

   #define  FOUNDATIONAL_LIB_MEMCPY   memcpy

   #define  FOUNDATIONAL_LIB_STRLEN   strlen

   #define  FOUNDATIONAL_LIB_STRCMP   strcmp

   #define  FOUNDATIONAL_LIB_MEMCMP   memcmp

   #define  FOUNDATIONAL_LIB_MEMMOVE   memmove

   #define  FOUNDATIONAL_LIB_FPUTS   fputs

   #define  FOUNDATIONAL_LIB_PUTCHAR   putchar

   #define  FOUNDATIONAL_LIB_FPUTC   fputc

   #define  FOUNDATIONAL_LIB_STRPBRK   strpbrk

   #define  FOUNDATIONAL_LIB_STRCHR   strchr

   #define  FOUNDATIONAL_LIB_MEMCHR   memchr

   #define  FOUNDATIONAL_LIB_STRSTR   strstr

   #define  FOUNDATIONAL_LIB_ISSPACE   isspace

   #define  FOUNDATIONAL_LIB_ISALPHA   isalpha

   #define  FOUNDATIONAL_LIB_ISALNUM   isalnum

   #define  FOUNDATIONAL_LIB_ISDIGIT   isdigit

   #define  FOUNDATIONAL_LIB_ISPRINT   isprint

   #define  FOUNDATIONAL_LIB_ISUPPER   isupper

   #define  FOUNDATIONAL_LIB_ISLOWER   islower

   #define  define   FOUNDATIONAL_LIB_PRINTF /* not defined */

   #define  define   /* not defined */

   #define  define   FOUNDATIONAL_LIB_CONST /* not defined */

   #define  endif   /* if WIN32 */

   #define
   FOUNDATIONAL_LIB_FROZEN_INITIALIZATION_SIZE_MULTIPLIER   3

   #define  FOUNDATIONAL_LIB_INITIAL_STRING_ARRAY_ALLOC_COUNT   0

   #define
   FOUNDATIONAL_LIB_INITIAL_STRING_ARRAY_ALLOC_SIZE   (sizeof(char *)
   * 1)

   #define  FOUNDATIONAL_LIB_LIKELY(x)   (x)

   #define  FOUNDATIONAL_LIB_UNLIKELY(x)   (x)

   #define  FOUNDATIONAL_LIB_ASSERT_ARGUMENT_CHECKING   0 /*
   Argument NULL checks. Disabled by default. */

   #define  FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED(x)   /*
   */

   #define  FOUNDATIONAL_LIB_safe_increment(variable,
   label_if_fails)

   #define  FOUNDATIONAL_LIB_LOW_MEMORY_USAGE   12

   #define  FOUNDATIONAL_LIB_ALLOCATOR_DIV_AMOUNT   2

   #define  FOUNDATIONAL_LIB_COPY_SIZE_AMOUNT   4096

   #define  FOUNDATIONAL_LIB_POPEN_INITIAL_ALLOC_SIZE   4096

   #define  FOUNDATIONAL_LIB_ATOI   atoi

   #define  FOUNDATIONAL_LIB_POPEN   popen

   #define  FOUNDATIONAL_LIB_PCLOSE   pclose

   #define  FOUNDATIONAL_LIB_FERROR   ferror

   #define  FOUNDATIONAL_LIB_FSEEKO   fseeko

   #define  FOUNDATIONAL_LIB_FTELLO   ftello

   #define  FOUNDATIONAL_LIB_FREAD   fread

   #define  FOUNDATIONAL_LIB_FWRITE   fwrite

   #define  FOUNDATIONAL_LIB_FOPEN   fopen

   #define  FOUNDATIONAL_LIB_FCLOSE   fclose

   #define  FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC   malloc

   #define  FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_REALLOC   realloc

   #define  FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_CALLOC   calloc

   #define  FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE   free

   #define  FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_STRDUP   strdup

   #define  FOUNDATIONAL_LIB_NETWORK_FUNCTIONS_ENABLED   0
     Networking functions, disabled by default. More...

   #define  FOUNDATIONAL_LIB_HASH_INITIAL_CAPACITY   16
     Initial capacity for hash tables (dict, frozendict, set, frozenset).
   More...

   #define  FOUNDATIONAL_LIB_HASH_LOAD_FACTOR_THRESHOLD   0.75
     Load factor threshold for hash tables in the foundational library.
   More...

   #define  FOUNDATIONAL_LIB_FUNC   static inline

   #define  FOUNDATIONAL_LIB_THREAD_FUNCTIONS_ENABLED   1
     Enable or disable foundational library thread functions. More...

   #define  FOUNDATIONAL_LIB_set_aggressive_die(mode)
     Macro to set the aggressive die mode. More...

   #define
   FOUNDATIONAL_LIB_get_aggressive_die()   FOUNDATIONAL_LIB_aggr
   essive_die
     Macro to get the current aggressive die mode. More...

   #define  FOUNDATIONAL_LIB_die_aggressively_if_enabled()
     Macro to die aggressively if enabled. More...

   #define
   FOUNDATIONAL_LIB_INITIAL_DATA_ARRAY_ALLOC_SIZE   FOUNDATIONAL
   _LIB_INITIAL_STRING_ARRAY_ALLOC_SIZE

   #define  FOUNDATIONAL_LIB_DIR_SEPARATOR   '/'

Typedefs

   typedef struct FrozenSet  FrozenSet

   typedef struct Set  Set

   typedef struct Dict  Dict

   typedef struct FrozenDict  FrozenDict

Functions

   void *  memmem (const void *haystack, size_t haystacklen, const
   void *needle, size_t needlelen)

     FOUNDATIONAL_LIB_STATIC_ASSERT_MSG ((sizeof(size_t)<=8
   &&FOUNDATIONAL_LIB_SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATOR
   >=21), "Increase SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATOR to
   more than 21")

   static size_t  FOUNDATIONAL_LIB_safe_mul (size_t a, size_t b)
     Safely multiply 2 numbers to avoid unsigned integer overflows and
   security and stability issues. We never, NEVER want any of those
   things. Ever. More...

   static size_t  FOUNDATIONAL_LIB_safe_mul_ptr (size_t a, size_t b,
   size_t *ptr)
     Safely multiply 2 numbers to avoid unsigned integer overflows and
   security and stability issues. We never, NEVER want any of those
   things. Ever. More...

   static FOUNDATIONAL_LIB_CONST size_t  FOUNDATIONAL_LIB_safe_add_2
   (size_t a, size_t b)
     Safely add 2 numbers to avoid unsigned integer overflows and security
   and stability issues. We never, NEVER want any of those things. Ever.
   More...

   static FOUNDATIONAL_LIB_CONST size_t  FOUNDATIONAL_LIB_safe_add_3
   (size_t a, size_t b, size_t c)
     Safely add 3 numbers to avoid unsigned integer overflows and security
   and stability issues. We never, NEVER want any of those things. Ever.
   More...

   static size_t  FOUNDATIONAL_LIB_safe_add_2_ptr (size_t a, size_t
   b, size_t *ptr)
     Safely add 2 numbers to avoid unsigned integer overflows and security
   and stability issues. We never, NEVER want any of those things. Ever.
   More...

   static int  FOUNDATIONAL_LIB_safe_add_3_ptr (size_t a, size_t b,
   size_t c, size_t *ptr)
     Safely add 3 numbers to avoid unsigned integer overflows and security
   and stability issues. We never, NEVER want any of those things. Ever.
   More...

   static size_t  FOUNDATIONAL_LIB_REALLOC_REALLOCATION_ALGORITHM
   (size_t siz)

   static void  free_array (void **array, size_t len)
     Frees a dynamic array and its elements up to one level deep.
   More...

   static void  free_string_array (char **array, size_t len)
     Frees a dynamic string array and its elements up to one level deep.
   More...

   FOUNDATIONAL_LIB_FUNC char *  int_to_string (long long int
   number)
     Converts an integer to its string representation. More...

   FOUNDATIONAL_LIB_FUNC void  int_to_string_with_buffer (long
   long int number, char *buffer)
     Converts an integer to its string representation. More...

   FOUNDATIONAL_LIB_FUNC void  utoa (size_t unsigned_value, char
   *output)

   FOUNDATIONAL_LIB_FUNC char *  uint_to_string (size_t number)
     Converts an integer to its string representation. More...

   FOUNDATIONAL_LIB_FUNC void  print_uint_array (const unsigned
   long long *array, size_t size)
     Prints the elements of a uint array. More...

   FOUNDATIONAL_LIB_FUNC void  print_uint_ptr_array (const
   unsigned int **array, size_t size)
     Prints the elements of an array of uint pointers. More...

   FOUNDATIONAL_LIB_FUNC void  print_int_array (const int
   *array, size_t size)
     Prints the elements of an int array. More...

   FOUNDATIONAL_LIB_FUNC void  print_int_ptr_array (const int
   **array, size_t size)
     Prints the elements of an array of int pointers. More...

   FOUNDATIONAL_LIB_FUNC void  print_string_array (char **array,
   size_t size)
     Prints an array of strings. More...

   FOUNDATIONAL_LIB_FUNC void  print_string_array_array (char
   ***array, size_t size)
     Prints an array of arrays of strings. More...

   FOUNDATIONAL_LIB_FUNC void  print_ushort_array (const
   unsigned short *array, size_t size)
     Prints the contents of an array of unsigned short integers.
   More...

   FOUNDATIONAL_LIB_FUNC void  print_ushort_ptr_array (const
   unsigned short **array, size_t size)
     Prints an array of pointers to unsigned short integers. More...

   FOUNDATIONAL_LIB_FUNC void  print_short_array (const short
   *array, size_t size)
     Prints the contents of an array of short integers. More...

   FOUNDATIONAL_LIB_FUNC void  print_short_ptr_array (const
   short **array, size_t size)
     Prints an array of pointers to short integers. More...

   FOUNDATIONAL_LIB_FUNC void  print_ulong_array (const unsigned
   long *array, size_t size)
     Prints the contents of an array of unsigned long integers.
   More...

   FOUNDATIONAL_LIB_FUNC void  print_ulong_ptr_array (const
   unsigned long **array, size_t size)
     Prints an array of pointers to unsigned long integers. More...

   FOUNDATIONAL_LIB_FUNC void  print_long_array (const long
   *array, size_t size)
     Prints the elements of a long array. More...

   FOUNDATIONAL_LIB_FUNC void  print_long_ptr_array (const long
   **array, size_t size)
     Prints the elements of a long array. More...

   FOUNDATIONAL_LIB_FUNC void  print_ulong_long_array (const
   unsigned long long *array, size_t size)
     Prints the elements of an unsigned long long array. More...

   FOUNDATIONAL_LIB_FUNC void  print_ulong_long_ptr_array (const
   unsigned long long **array, size_t size)
     Prints the elements of an unsigned long long array through a pointer.
   More...

   FOUNDATIONAL_LIB_FUNC void  print_long_long_array (const long
   long *array, size_t size)
     Prints the elements of a long long array. More...

   FOUNDATIONAL_LIB_FUNC void  print_long_long_ptr_array (const
   long long **array, size_t size)
     Prints the elements of a long long array through a pointer.
   More...

   FOUNDATIONAL_LIB_FUNC void  print_float_array (const float
   *array, size_t size)
     Prints the elements of a float array. More...

   FOUNDATIONAL_LIB_FUNC void  print_float_ptr_array (const
   float **array, size_t size)
     Prints the elements of a float array through a pointer. More...

   FOUNDATIONAL_LIB_FUNC void  print_double_array (const double
   *array, size_t size)
     Prints the elements of a double array. More...

   FOUNDATIONAL_LIB_FUNC void  print_double_ptr_array (const
   double **array, size_t size)
     Prints the elements of a double array through a pointer. More...

   FOUNDATIONAL_LIB_FUNC void  print_size_t_array (const size_t
   *array, size_t size)
     Prints the elements of a size_t array. More...

   FOUNDATIONAL_LIB_FUNC void  print_size_t_ptr_array (const
   size_t **array, size_t size)
     Prints the elements of a size_t array through a pointer. More...

   FOUNDATIONAL_LIB_FUNC void  print_uint_array_to_stream (const
   unsigned int *array, size_t size, FILE *stream)
     Prints the elements of an unsigned int array to a specified stream.
   More...

   FOUNDATIONAL_LIB_FUNC void  print_uint_ptr_array_to_stream
   (const unsigned int **array, size_t size, FILE *stream)
     Prints the elements of an unsigned int array through a pointer to a
   specified stream. More...

   FOUNDATIONAL_LIB_FUNC void  print_int_array_to_stream (const
   int *array, size_t size, FILE *stream)
     Prints the elements of an int array to a specified stream.
   More...

   FOUNDATIONAL_LIB_FUNC void  print_int_ptr_array_to_stream
   (const int **array, size_t size, FILE *stream)
     Prints the elements of an int array through a pointer to a specified
   stream. More...

   FOUNDATIONAL_LIB_FUNC void  print_uchar_array_to_stream
   (const unsigned char *array, size_t size, FILE *stream)
     Prints the elements of an unsigned char array to a specified stream.
   More...

   FOUNDATIONAL_LIB_FUNC void  print_char_array_to_stream (const
   char *array, size_t size, FILE *stream)
     Prints the elements of a char array to a specified stream.
   More...

   FOUNDATIONAL_LIB_FUNC void  print_string_array_to_stream
   (char **array, size_t size, FILE *stream)
     Prints the elements of a string array to a specified stream.
   More...

   FOUNDATIONAL_LIB_FUNC void
   print_string_array_array_to_stream (char ***array, size_t size,
   FILE *stream)
     Prints the elements of an array of string arrays to a specified
   stream. More...

   FOUNDATIONAL_LIB_FUNC void  print_ushort_array_to_stream
   (const unsigned short *array, size_t size, FILE *stream)
     Prints the elements of an unsigned short array to a specified stream.
   More...

   FOUNDATIONAL_LIB_FUNC void  print_ushort_ptr_array_to_stream
   (const unsigned short **array, size_t size, FILE *stream)
     Prints the elements of an unsigned short array through a pointer to a
   specified stream. More...

   FOUNDATIONAL_LIB_FUNC void  print_short_array_to_stream
   (const short *array, size_t size, FILE *stream)
     Prints the elements of a short array to a specified stream.
   More...

   FOUNDATIONAL_LIB_FUNC void  print_short_ptr_array_to_stream
   (const short **array, size_t size, FILE *stream)
     Prints the elements of a short array through a pointer to a specified
   stream. More...

   FOUNDATIONAL_LIB_FUNC void  print_ulong_array_to_stream
   (const unsigned long *array, size_t size, FILE *stream)
     Prints the elements of an unsigned long array to a specified stream.
   More...

   FOUNDATIONAL_LIB_FUNC void  print_ulong_ptr_array_to_stream
   (const unsigned long **array, size_t size, FILE *stream)
     Prints the elements of an unsigned long array through a pointer to a
   specified stream. More...

   FOUNDATIONAL_LIB_FUNC void  print_long_array_to_stream (const
   long *array, size_t size, FILE *stream)
     Prints the elements of a long array to a specified stream.
   More...

   FOUNDATIONAL_LIB_FUNC void  print_long_ptr_array_to_stream
   (const long **array, size_t size, FILE *stream)
     Prints the elements of a long array through a pointer to a specified
   stream. More...

   FOUNDATIONAL_LIB_FUNC void  print_ulong_long_array_to_stream
   (const unsigned long long *array, size_t size, FILE *stream)
     Prints the elements of an unsigned long long array to a specified
   stream. More...

   FOUNDATIONAL_LIB_FUNC void
   print_ulong_long_ptr_array_to_stream (const unsigned long long
   **array, size_t size, FILE *stream)
     Prints the elements of an unsigned long long array through a pointer
   to a specified stream. More...

   FOUNDATIONAL_LIB_FUNC void  print_long_long_array_to_stream
   (const long long *array, size_t size, FILE *stream)
     Outputs elements of a long_long array to a stream. More...

   FOUNDATIONAL_LIB_FUNC void
   print_long_long_ptr_array_to_stream (const long long **array,
   size_t size, FILE *stream)
     Outputs elements of an array of pointers to long long to a stream.
   More...

   FOUNDATIONAL_LIB_FUNC void  print_float_array_to_stream
   (const float *array, size_t size, FILE *stream)
     Outputs elements of a float array to a stream. More...

   FOUNDATIONAL_LIB_FUNC void  print_float_ptr_array_to_stream
   (const float **array, size_t size, FILE *stream)
     Outputs elements of an array of pointers to float to a stream.
   More...

   FOUNDATIONAL_LIB_FUNC void  print_double_array_to_stream
   (const double *array, size_t size, FILE *stream)
     Outputs elements of a double array to a stream. More...

   FOUNDATIONAL_LIB_FUNC void  print_double_ptr_array_to_stream
   (const double **array, size_t size, FILE *stream)
     Outputs elements of an array of pointers to double to a stream.
   More...

   FOUNDATIONAL_LIB_FUNC void  print_size_t_array_to_stream
   (const size_t *array, size_t size, FILE *stream)
     Outputs elements of a size_t array to a stream. More...

   FOUNDATIONAL_LIB_FUNC void  print_size_t_ptr_array_to_stream
   (const size_t **array, size_t size, FILE *stream)
     Outputs elements of an array of pointers to size_t to a stream.
   More...

   FOUNDATIONAL_LIB_FUNC void *  arraydup (const void *array,
   size_t num_mem, size_t size)
     Duplicates an array of elements at a shallow level. More...

   static int  equal_strings (const char *first, const char *second)
     Compares two strings for equality. More...

   static int  equal_array_of_uints (const unsigned int *array, const
   unsigned int *array2, size_t size)
     Checks if two arrays of unsigned integers are equal. More...

   static int  equal_array_of_uint_ptrs (const unsigned int **array,
   const unsigned int **array2, size_t size)
     Checks if two arrays of pointers to unsigned integers are equal.
   More...

   static int  equal_array_of_ints (const int *array, const int
   *array2, size_t size)
     Checks if two arrays of integers are equal. More...

   static int  equal_array_of_int_ptrs (const int **array, const int
   **array2, size_t size)
     Checks if two arrays of pointers to integers are equal. More...

   static int  equal_array_of_uchars (const unsigned char *array,
   const unsigned char *array2, size_t size)
     Checks if two arrays of unsigned characters are equal. More...

   static int  equal_array_of_uchar_ptrs (const unsigned char
   **array, const unsigned char **array2, size_t size)
     Checks if two arrays of pointers to unsigned characters are equal.
   More...

   static int  equal_array_of_chars (const char *array, const char
   *array2, size_t size)
     Checks if two arrays of characters are equal. More...

   static int  equal_array_of_char_ptrs (const char **array, const
   char **array2, size_t size)
     Checks if two arrays of pointers to characters are equal.
   More...

   static int  equal_array_of_ushorts (const unsigned short *array,
   const unsigned short *array2, size_t size)
     Checks if two arrays of unsigned short integers are equal.
   More...

   static int  equal_array_of_ushort_ptrs (const unsigned short
   **array, const unsigned short **array2, size_t size)
     Checks if two arrays of pointers to unsigned short integers are
   equal. More...

   static int  equal_array_of_shorts (const short *array, const short
   *array2, size_t size)
     Checks if two arrays of short integers are equal. More...

   static int  equal_array_of_short_ptrs (const short **array, const
   short **array2, size_t size)
     Checks if two arrays of pointers to short integers are equal.
   More...

   static int  equal_array_of_ulongs (const unsigned long *array,
   const unsigned long *array2, size_t size)
     Checks if two arrays of unsigned long integers are equal.
   More...

   static int  equal_array_of_ulong_ptrs (const unsigned long
   **array, const unsigned long **array2, size_t size)
     Checks if two arrays of pointers to unsigned long integers are equal.
   More...

   static int  equal_array_of_longs (const long *array, const long
   *array2, size_t size)
     Checks if two arrays of long integers are equal. More...

   static int  equal_array_of_long_ptrs (const long **array, const
   long **array2, size_t size)
     Checks if two arrays of pointers to long integers are equal.
   More...

   static int  equal_array_of_ulong_longs (const unsigned long long
   *array, const unsigned long long *array2, size_t size)
     Checks if two arrays of unsigned long long integers are equal.
   More...

   static int  equal_array_of_ulong_long_ptrs (const unsigned long
   long **array, const unsigned long long **array2, size_t size)
     Checks if two arrays of pointers to unsigned long long integers are
   equal. More...

   static int  equal_array_of_long_longs (const long long *array,
   const long long *array2, size_t size)
     Checks if two arrays of long long integers are equal. More...

   static int  equal_array_of_long_long_ptrs (const long long
   **array, const long long **array2, size_t size)
     Checks if two arrays of pointers to long long integers are equal.
   More...

   static int  equal_array_of_floats (const float *array, const float
   *array2, size_t size)
     Checks if two arrays of float values are equal. More...

   static int  equal_array_of_float_ptrs (const float **array, const
   float **array2, size_t size)
     Checks if two arrays of pointers to float values are equal.
   More...

   static int  equal_array_of_doubles (const double *array, const
   double *array2, size_t size)
     Checks if two arrays of doubles are equal. More...

   static int  equal_array_of_double_ptrs (const double **array,
   const double **array2, size_t size)
     Compares arrays of double pointers for equality. More...

   static int  equal_array_of_size_ts (const size_t *array, const
   size_t *array2, size_t size)
     Checks if two arrays of size_t values are equal. More...

   static int  equal_array_of_size_t_ptrs (const size_t **array,
   const size_t **array2, size_t size)
     Compares arrays of size_t pointers for equality. More...

   FOUNDATIONAL_LIB_FUNC char *  string_to_json (const char
   *input_string)
     Converts a given input string to its JSON representation.
   More...

   FOUNDATIONAL_LIB_FUNC char *  strip (const char *str)
     Trims leading and trailing whitespace from a given string.
   More...

   FOUNDATIONAL_LIB_FUNC char **  split (const char *str, size_t
   *output_size, const char *delim, size_t max_times, int
   keep_delim_in_result)
     Splits a given string into an array based on a specified delimiter.
   More...

   FOUNDATIONAL_LIB_FUNC char *  join (const char **array,
   size_t count, const char *delimiter)
     Joins an array of strings into a single string using a specified
   delimiter. More...

   FOUNDATIONAL_LIB_FUNC int  append_string_to_string (char
   **string, size_t *string_length, size_t *string_alloc_size, const char
   *string_to_get_appended, size_t string_to_get_appended_length)
     Appends a new string to an existing string and updates its length and
   allocation size. More...

   FOUNDATIONAL_LIB_FUNC int  append_data_to_array (void
   **array, size_t *array_size, size_t *array_current_alloc_size, void
   *data, size_t data_size)
     Appends a new element to the end of a dynamically allocated array and
   updates its size. More...

   FOUNDATIONAL_LIB_FUNC int
   append_data_to_array_no_initial_alloc (void **array, size_t
   *array_size, size_t *array_current_alloc_size, void *data, size_t
   data_size)
     Appends a new element to the end of a dynamically allocated array and
   updates its size. More...

   FOUNDATIONAL_LIB_FUNC int  append_string_to_array (char
   ***array, size_t *array_size, size_t *array_current_alloc_size, const
   char *string)
     Appends a new string element to the end of a dynamically allocated
   array of strings and updates its size. More...

   FOUNDATIONAL_LIB_FUNC int
   append_string_to_array_no_initial_alloc (char ***array, size_t
   *array_size, size_t *array_current_alloc_size, const char *string)
     Appends a new string element to the end of a dynamically allocated
   array of strings and updates its size. More...

   FOUNDATIONAL_LIB_FUNC int  prepend_string_to_array (char
   ***array, size_t *array_size, size_t *array_current_alloc_size, char
   *string)
     Prepends a new string element to the beginning of a dynamically
   allocated array of strings and updates its size. More...

   FOUNDATIONAL_LIB_FUNC int
   prepend_string_to_array_no_initial_alloc (char ***array, size_t
   *array_size, size_t *array_current_alloc_size, char *string)
     Prepends a new string element to the beginning of a dynamically
   allocated array of strings and updates its size. More...

   FOUNDATIONAL_LIB_FUNC size_t  array_total_string_length (char
   **array, size_t count)
     Calculates the total length of strings in an array. More...

   FOUNDATIONAL_LIB_FUNC char *  shellescape (const char *input)
     Escapes special characters in a given string for shell usage.
   More...

   FOUNDATIONAL_LIB_FUNC char *  reverse_string (const char
   *str)
     Reverses a given string. More...

   static int  starts_with (const char *str, const char *prefix)

   static int  ends_with (const char *str, const char *suffix)
     Checks whether a given string ends with a specified suffix.
   More...

   FOUNDATIONAL_LIB_FUNC void *  memory_locate (const void
   *haystack, size_t haystack_len, const void *needle, size_t needle_len)

   FOUNDATIONAL_LIB_FUNC size_t  count_occurrences_of_substr
   (const char *str, const char *substring)
     Counts the occurrences of a specified substring within a given
   string. More...

   FOUNDATIONAL_LIB_FUNC int  string_has_substr (const char
   *string, size_t string_length, const char *substring, size_t
   substring_length)
     Checks if a substring exists within a given string. More...

   FOUNDATIONAL_LIB_FUNC int  memory_has_subchunk (void *memory,
   size_t memory_length, void *subchunk, size_t subchunk_length)
     Checks if a subchunk exists within a given memory block. More...

   FOUNDATIONAL_LIB_FUNC size_t  count_occurrences_of_substr_len
   (const char *string, size_t string_length, const char *substring,
   size_t substring_length)
     Counts the occurrences of a specified substring within a given
   string. More...

   static ssize_t  index_of_char (const char *str, char chr)
     Finds the index of the first occurrence of a specified character in a
   string. More...

   static ssize_t  last_index_of_char (const char *str, char chr)
     Finds the index of the last occurrence of a specified character in a
   given string. More...

   FOUNDATIONAL_LIB_FUNC int  is_string_numeric (const char
   *str)
     Checks if the provided string consists solely of numeric characters.
   More...

   FOUNDATIONAL_LIB_FUNC int  is_string_alphanumeric (const char
   *str)
     Determines whether a given string consists solely of alphanumeric
   characters. More...

   FOUNDATIONAL_LIB_FUNC char *  longest_common_prefix (const
   char **strings, size_t count)
     Finds the longest common prefix among an array of strings.
   More...

   FOUNDATIONAL_LIB_FUNC char *  longest_common_suffix (const
   char **strings, size_t count)
     Finds the longest common suffix among an array of strings.
   More...

   static double  str_to_double (const char *string)
     Converts a string to a double-precision floating-point number.
   More...

   FOUNDATIONAL_LIB_FUNC ssize_t  find_first_of (const char
   *str, const char *char_set)
     Finds the first occurrence of any character from a set in a string.
   More...

   FOUNDATIONAL_LIB_FUNC ssize_t  find_last_of (const char *str,
   const char *char_set)
     Finds the last occurrence of any character from a specified set
   within a given string. More...

   FOUNDATIONAL_LIB_FUNC void  reverse_string_in_place (char
   *str)
     Reverses a string in place. More...

   FOUNDATIONAL_LIB_FUNC int  is_string_valid_integer (const
   char *str)
     Checks if a string is a valid integer. More...

   FOUNDATIONAL_LIB_FUNC size_t  common_prefix_length (const
   char *str1, const char *str2)
     Finds the length of the common prefix of two strings. More...

   FOUNDATIONAL_LIB_FUNC size_t  common_suffix_length (const
   char *str1, const char *str2)
     Finds the length of the common suffix of two strings. More...

   FOUNDATIONAL_LIB_FUNC char *  string_to_title_case (const
   char *str)
     Converts a string to title case. More...

   FOUNDATIONAL_LIB_FUNC int  find_max_int_in_array (const int
   *array, size_t size)
     Finds the maximum element in an array of integers. More...

   FOUNDATIONAL_LIB_FUNC int  find_min_int_in_array (const int
   *array, size_t size)
     Finds the minimum element in an array of integers. More...

   FOUNDATIONAL_LIB_FUNC int  sum_of_int_array (const int
   *array, size_t size)
     Calculates the sum of elements in an array of integers. More...

   FOUNDATIONAL_LIB_FUNC void  reverse_int_array_in_place (int
   *array, size_t size)
     Reverses an array of integers in place. More...

   FOUNDATIONAL_LIB_FUNC int  ints_are_sorted_ascending (const
   int *array, size_t size)
     Checks if an array of integers is sorted in ascending order.
   More...

   FOUNDATIONAL_LIB_FUNC int  ints_are_sorted_descending (const
   int *array, size_t size)
     Checks if an array of integers is sorted in descending order.
   More...

   FOUNDATIONAL_LIB_FUNC size_t *  generate_range (size_t start,
   size_t end, size_t step, size_t *range_size)
     Generates a range of integers. More...

   FOUNDATIONAL_LIB_FUNC int  FOUNDATIONAL_LIB_cmpstringp (const
   void *p1, const void *p2)

   FOUNDATIONAL_LIB_FUNC void  sort_strings (char **strings,
   size_t size)
     Sorts an array of strings. More...

   FOUNDATIONAL_LIB_FUNC char **  sorted_strings (char
   **strings, size_t size)
     Creates a new array of strings sorted in ascending order.
   More...

   FOUNDATIONAL_LIB_FUNC int  FOUNDATIONAL_LIB_cmp_uints (const
   void *a, const void *b)

   FOUNDATIONAL_LIB_FUNC void  sort_uints (unsigned int *uints,
   size_t size)

   FOUNDATIONAL_LIB_FUNC unsigned int *  sorted_uints (unsigned
   int *uints, size_t size)

   FOUNDATIONAL_LIB_FUNC int  FOUNDATIONAL_LIB_cmp_uint_ptrs
   (const void *a, const void *b)

   FOUNDATIONAL_LIB_FUNC void  sort_uint_ptrs (unsigned int
   **uint_ptrs, size_t size)

   FOUNDATIONAL_LIB_FUNC unsigned int **  sorted_uint_ptrs
   (unsigned int **uint_ptrs, size_t size)

   FOUNDATIONAL_LIB_FUNC int  FOUNDATIONAL_LIB_cmp_ints (const
   void *a, const void *b)

   FOUNDATIONAL_LIB_FUNC void  sort_ints (int *ints, size_t
   size)

   FOUNDATIONAL_LIB_FUNC int *  sorted_ints (int *ints, size_t
   size)

   FOUNDATIONAL_LIB_FUNC int  FOUNDATIONAL_LIB_cmp_int_ptrs
   (const void *a, const void *b)

   FOUNDATIONAL_LIB_FUNC void  sort_int_ptrs (int **int_ptrs,
   size_t size)

   FOUNDATIONAL_LIB_FUNC int **  sorted_int_ptrs (int
   **int_ptrs, size_t size)

   FOUNDATIONAL_LIB_FUNC int  FOUNDATIONAL_LIB_cmp_uchars (const
   void *a, const void *b)
     Compare function for sorting unsigned chars. More...

   FOUNDATIONAL_LIB_FUNC void  sort_uchars (unsigned char
   *uchars, size_t size)
     Sorts an array of unsigned chars in ascending order. More...

   FOUNDATIONAL_LIB_FUNC unsigned char *  sorted_uchars
   (unsigned char *uchars, size_t size)
     Creates a new array containing sorted unsigned chars. More...

   FOUNDATIONAL_LIB_FUNC int  FOUNDATIONAL_LIB_cmp_uchar_ptrs
   (const void *a, const void *b)
     Compare function for sorting pointers to unsigned chars. More...

   FOUNDATIONAL_LIB_FUNC void  sort_uchar_ptrs (unsigned char
   **uchar_ptrs, size_t size)
     Sorts an array of pointers to unsigned chars in ascending order.
   More...

   FOUNDATIONAL_LIB_FUNC unsigned char **  sorted_uchar_ptrs
   (unsigned char **uchar_ptrs, size_t size)
     Creates a new array containing sorted pointers to unsigned chars.
   More...

   FOUNDATIONAL_LIB_FUNC int  FOUNDATIONAL_LIB_cmp_chars (const
   void *a, const void *b)
     Compare function for sorting chars. More...

   FOUNDATIONAL_LIB_FUNC void  sort_chars (char *chars, size_t
   size)
     Sorts an array of chars in ascending order. More...

   FOUNDATIONAL_LIB_FUNC char *  sorted_chars (char *chars,
   size_t size)
     Creates a new array containing sorted chars. More...

   FOUNDATIONAL_LIB_FUNC int  FOUNDATIONAL_LIB_cmp_char_ptrs
   (const void *a, const void *b)
     Compare function for sorting pointers to chars. More...

   FOUNDATIONAL_LIB_FUNC void  sort_char_ptrs (char **char_ptrs,
   size_t size)
     Sorts an array of pointers to chars in ascending order. More...

   FOUNDATIONAL_LIB_FUNC char **  sorted_char_ptrs (char
   **char_ptrs, size_t size)
     Creates a new array containing sorted pointers to chars. More...

   FOUNDATIONAL_LIB_FUNC int  FOUNDATIONAL_LIB_cmp_ushorts
   (const void *a, const void *b)
     Compare function for sorting unsigned shorts. More...

   FOUNDATIONAL_LIB_FUNC void  sort_ushorts (unsigned short
   *ushorts, size_t size)
     Sorts an array of unsigned shorts in ascending order. More...

   FOUNDATIONAL_LIB_FUNC unsigned short *  sorted_ushorts
   (unsigned short *ushorts, size_t size)
     Creates a new array containing sorted unsigned shorts. More...

   FOUNDATIONAL_LIB_FUNC int  FOUNDATIONAL_LIB_cmp_ushort_ptrs
   (const void *a, const void *b)
     Compare function for sorting pointers to unsigned shorts.
   More...

   FOUNDATIONAL_LIB_FUNC void  sort_ushort_ptrs (unsigned short
   **ushort_ptrs, size_t size)
     Sorts an array of pointers to unsigned shorts in ascending order.
   More...

   FOUNDATIONAL_LIB_FUNC unsigned short **  sorted_ushort_ptrs
   (unsigned short **ushort_ptrs, size_t size)
     Creates a new array containing sorted pointers to unsigned shorts.
   More...

   FOUNDATIONAL_LIB_FUNC int  FOUNDATIONAL_LIB_cmp_shorts (const
   void *a, const void *b)
     Compare function for sorting shorts. More...

   FOUNDATIONAL_LIB_FUNC void  sort_shorts (short *shorts,
   size_t size)
     Sorts an array of shorts in ascending order. More...

   FOUNDATIONAL_LIB_FUNC short *  sorted_shorts (short *shorts,
   size_t size)
     Creates a new array containing sorted shorts. More...

   FOUNDATIONAL_LIB_FUNC int  FOUNDATIONAL_LIB_cmp_short_ptrs
   (const void *a, const void *b)
     Compare function for sorting pointers to shorts. More...

   FOUNDATIONAL_LIB_FUNC void  sort_short_ptrs (short
   **short_ptrs, size_t size)
     Sorts an array of pointers to shorts in ascending order. More...

   FOUNDATIONAL_LIB_FUNC short **  sorted_short_ptrs (short
   **short_ptrs, size_t size)
     Creates a new array containing sorted pointers to shorts.
   More...

   FOUNDATIONAL_LIB_FUNC int  FOUNDATIONAL_LIB_cmp_ulongs (const
   void *a, const void *b)
     Compare function for sorting unsigned longs. More...

   FOUNDATIONAL_LIB_FUNC void  sort_ulongs (unsigned long
   *ulongs, size_t size)
     Sorts an array of unsigned longs in ascending order. More...

   FOUNDATIONAL_LIB_FUNC unsigned long *  sorted_ulongs
   (unsigned long *ulongs, size_t size)
     Creates a new array containing sorted unsigned longs. More...

   FOUNDATIONAL_LIB_FUNC int  FOUNDATIONAL_LIB_cmp_ulong_ptrs
   (const void *a, const void *b)
     Compare function for sorting pointers to unsigned longs. More...

   FOUNDATIONAL_LIB_FUNC void  sort_ulong_ptrs (unsigned long
   **ulong_ptrs, size_t size)
     Sorts an array of pointers to unsigned longs in ascending order.
   More...

   FOUNDATIONAL_LIB_FUNC unsigned long **  sorted_ulong_ptrs
   (unsigned long **ulong_ptrs, size_t size)
     Creates a new array containing sorted pointers to unsigned longs.
   More...

   FOUNDATIONAL_LIB_FUNC int  FOUNDATIONAL_LIB_cmp_longs (const
   void *a, const void *b)
     Compare function for sorting pointers to unsigned longs. More...

   FOUNDATIONAL_LIB_FUNC void  sort_longs (long *longs, size_t
   size)
     Sorts an array of pointers to unsigned longs in ascending order.
   More...

   FOUNDATIONAL_LIB_FUNC long *  sorted_longs (long *longs,
   size_t size)
     Creates a new array containing sorted pointers to unsigned longs.
   More...

   FOUNDATIONAL_LIB_FUNC int  FOUNDATIONAL_LIB_cmp_long_ptrs
   (const void *a, const void *b)
     Compare function for sorting pointers to longs. More...

   FOUNDATIONAL_LIB_FUNC void  sort_long_ptrs (long **long_ptrs,
   size_t size)
     Sorts an array of pointers to longs in ascending order. More...

   FOUNDATIONAL_LIB_FUNC long **  sorted_long_ptrs (long
   **long_ptrs, size_t size)
     Creates a new array containing sorted pointers to longs. More...

   FOUNDATIONAL_LIB_FUNC int  FOUNDATIONAL_LIB_cmp_ulong_longs
   (const void *a, const void *b)
     Compare function for sorting unsigned long longs. More...

   FOUNDATIONAL_LIB_FUNC void  sort_ulong_longs (unsigned long
   long *ulong_longs, size_t size)
     Sorts an array of unsigned long longs in ascending order.
   More...

   FOUNDATIONAL_LIB_FUNC unsigned long long *
   sorted_ulong_longs (unsigned long long *ulong_longs, size_t size)
     Creates a new array containing sorted unsigned long longs.
   More...

   FOUNDATIONAL_LIB_FUNC int
   FOUNDATIONAL_LIB_cmp_ulong_long_ptrs (const void *a, const void
   *b)
     Compare function for sorting pointers to unsigned long longs.
   More...

   FOUNDATIONAL_LIB_FUNC void  sort_ulong_long_ptrs (unsigned
   long long **ulong_long_ptrs, size_t size)
     Sorts an array of pointers to unsigned long longs in ascending order.
   More...

   FOUNDATIONAL_LIB_FUNC unsigned long long **
   sorted_ulong_long_ptrs (unsigned long long **ulong_long_ptrs,
   size_t size)
     Creates a new array containing sorted pointers to unsigned long
   longs. More...

   FOUNDATIONAL_LIB_FUNC int  FOUNDATIONAL_LIB_cmp_long_longs
   (const void *a, const void *b)
     Compare function for sorting long longs. More...

   FOUNDATIONAL_LIB_FUNC void  sort_long_longs (long long
   *long_longs, size_t size)
     Sorts an array of long longs in ascending order. More...

   FOUNDATIONAL_LIB_FUNC long long *  sorted_long_longs (long
   long *long_longs, size_t size)
     Creates a new array containing sorted long longs. More...

   FOUNDATIONAL_LIB_FUNC int
   FOUNDATIONAL_LIB_cmp_long_long_ptrs (const void *a, const void *b)
     Compare function for sorting pointers to long longs. More...

   FOUNDATIONAL_LIB_FUNC void  sort_long_long_ptrs (long long
   **long_long_ptrs, size_t size)
     Sorts an array of pointers to long longs in ascending order.
   More...

   FOUNDATIONAL_LIB_FUNC long long **  sorted_long_long_ptrs
   (long long **long_long_ptrs, size_t size)
     Creates a new array containing sorted pointers to long longs.
   More...

   FOUNDATIONAL_LIB_FUNC int  FOUNDATIONAL_LIB_cmp_floats (const
   void *a, const void *b)
     Compare function for sorting floats. More...

   FOUNDATIONAL_LIB_FUNC void  sort_floats (float *floats,
   size_t size)
     Sorts an array of floats in ascending order. More...

   FOUNDATIONAL_LIB_FUNC float *  sorted_floats (float *floats,
   size_t size)
     Creates a new array containing sorted floats. More...

   FOUNDATIONAL_LIB_FUNC int  FOUNDATIONAL_LIB_cmp_float_ptrs
   (const void *a, const void *b)
     Compare function for sorting pointers to floats. More...

   FOUNDATIONAL_LIB_FUNC void  sort_float_ptrs (float
   **float_ptrs, size_t size)
     Sorts an array of pointers to floats in ascending order. More...

   FOUNDATIONAL_LIB_FUNC float **  sorted_float_ptrs (float
   **float_ptrs, size_t size)
     Creates a new array containing sorted pointers to floats.
   More...

   FOUNDATIONAL_LIB_FUNC int  FOUNDATIONAL_LIB_cmp_doubles
   (const void *a, const void *b)
     Compare function for sorting doubles. More...

   FOUNDATIONAL_LIB_FUNC void  sort_doubles (double *doubles,
   size_t size)
     Sorts an array of doubles in ascending order. More...

   FOUNDATIONAL_LIB_FUNC double *  sorted_doubles (double
   *doubles, size_t size)
     Creates a new array containing sorted doubles. More...

   FOUNDATIONAL_LIB_FUNC int  FOUNDATIONAL_LIB_cmp_double_ptrs
   (const void *a, const void *b)
     Compare function for sorting pointers to doubles. More...

   FOUNDATIONAL_LIB_FUNC void  sort_double_ptrs (double
   **double_ptrs, size_t size)
     Sorts an array of pointers to doubles in ascending order.
   More...

   FOUNDATIONAL_LIB_FUNC double **  sorted_double_ptrs (double
   **double_ptrs, size_t size)
     Creates a new array containing sorted pointers to doubles.
   More...

   FOUNDATIONAL_LIB_FUNC int  FOUNDATIONAL_LIB_cmp_size_ts
   (const void *a, const void *b)
     Compare function for sorting size_t values. More...

   FOUNDATIONAL_LIB_FUNC void  sort_size_ts (size_t *size_ts,
   size_t size)
     Sorts an array of size_t values in ascending order. More...

   FOUNDATIONAL_LIB_FUNC size_t *  sorted_size_ts (size_t
   *size_ts, size_t size)
     Creates a new array containing sorted size_t values. More...

   FOUNDATIONAL_LIB_FUNC int  FOUNDATIONAL_LIB_cmp_size_t_ptrs
   (const void *a, const void *b)
     Compare function for sorting pointers to size_t values. More...

   FOUNDATIONAL_LIB_FUNC void  sort_size_t_ptrs (size_t
   **size_t_ptrs, size_t size)
     Sorts an array of pointers to size_t values in ascending order.
   More...

   FOUNDATIONAL_LIB_FUNC size_t **  sorted_size_t_ptrs (size_t
   **size_t_ptrs, size_t size)
     Creates a new array containing sorted pointers to size_t values.
   More...

   FOUNDATIONAL_LIB_FUNC int  string_to_int (const char *str)
     Converts a string to an integer. More...

   FOUNDATIONAL_LIB_FUNC char *  read_file_into_string (const
   char *filename, size_t *size)
     Reads the contents of a file into a string. More...

   FOUNDATIONAL_LIB_FUNC int  write_to_file_with_mode (const
   char *filename, const char *content, size_t content_length, const char
   *mode)
     Writes a string or data to a file with a specified mode. More...

   FOUNDATIONAL_LIB_FUNC int  write_file (const char *filename,
   const char *content)
     Writes a string to a file. More...

   FOUNDATIONAL_LIB_FUNC int  append_string_to_file (const char
   *filename, const char *content)
     Appends a string to a file. More...

   FOUNDATIONAL_LIB_FUNC int  file_exists (const char *filename)
     Checks if a file exists. More...

   FOUNDATIONAL_LIB_FUNC int  file_is_regular (const char
   *filename)
     Checks if a file is a regular file. More...

   FOUNDATIONAL_LIB_FUNC int  file_is_directory (const char
   *filename)
     Checks if a file is a directory. More...

   FOUNDATIONAL_LIB_FUNC int  file_is_readable (const char
   *filename)
     Checks if a file is readable. More...

   FOUNDATIONAL_LIB_FUNC int  file_is_writable (const char
   *filename)
     Checks if a file is writable. More...

   FOUNDATIONAL_LIB_FUNC int  file_is_executable (const char
   *filename)
     Checks if a file is executable. More...

   FOUNDATIONAL_LIB_FUNC int  get_file_size (const char
   *filename, size_t *size)
     Gets the size of a file. More...

   FOUNDATIONAL_LIB_FUNC int  remove_file (const char *filename)
     Removes a file. More...

   FOUNDATIONAL_LIB_FUNC int  copy_file (const char
   *source_filename, const char *destination_filename)
     Copies a file from source to destination. More...

   FOUNDATIONAL_LIB_FUNC char **  list_files_with_pattern (const
   char *directory, const char *pattern, size_t *len)
     Lists files in a directory using a wildcard pattern. More...

   FOUNDATIONAL_LIB_FUNC char *  concatenate_string_array (const
   char **strings, size_t num_strings)
     Concatenates an array of strings into a single string. More...

   FOUNDATIONAL_LIB_FUNC char *  concatenate_strings (const char
   *str1, const char *str2)
     Concatenates two strings. More...

   FOUNDATIONAL_LIB_FUNC int  replace_memory (void *source,
   size_t source_len, void *find, size_t find_len, void *replace, size_t
   replace_len, void **output, size_t *output_length_without_nullt, int
   *should_free_after_use, size_t matches_max, size_t *num_matches_found,
   int should_nullt)
     Performs memory replacement with specified lengths. More...

   FOUNDATIONAL_LIB_FUNC int  replace_all_with_lens (const char
   *source, size_t source_len, const char *find, size_t find_len, const
   char *replace, size_t replace_len, char **output, size_t *new_len, int
   *should_free_after_use, size_t matches_max, size_t *num_matches)
     Performs string replacement with specified lengths. More...

   FOUNDATIONAL_LIB_FUNC char *  replace_all (const char
   *source, const char *find, const char *replace)
     Replaces all occurrences of a specified substring in a given string.
   More...

   FOUNDATIONAL_LIB_FUNC char *  replace_first (const char
   *source, const char *find, const char *replace)
     Replaces the first occurrence of a specified substring in a given
   string. More...

   FOUNDATIONAL_LIB_FUNC char *  replace_count (const char
   *source, const char *find, const char *replace, const size_t
   matches_max)
     Replaces the first N occurrences of a specified substring in a given
   string. More...

   FOUNDATIONAL_LIB_FUNC char *  replace_all_with_callback
   (const char *str, const char *old_substring, char *(*callback)(const
   char *, void *), void *data_for_callback)
     Replaces all occurrences of a substring in a string using a callback
   function. More...

   FOUNDATIONAL_LIB_FUNC char *  dup_format (const char
   *format,...)
     Duplicates a formatted string. More...

   FOUNDATIONAL_LIB_FUNC void  map_ints (int *array, size_t
   size, int(*transform)(int))
     Applies a transformation to each element of an integer array.
   More...

   FOUNDATIONAL_LIB_FUNC int  reduce_ints (int *array, size_t
   size, int(*operation)(int, int))
     Performs a reduction on an integer array using a binary operation.
   More...

   FOUNDATIONAL_LIB_FUNC int  filter_ints (int *source, size_t
   source_size, int *destination, int(*condition)(int))
     Filters elements of an integer array based on a specified condition.
   More...

   FOUNDATIONAL_LIB_FUNC void  map (void *array, size_t size,
   size_t elem_size, void(*transform)(void *))
     Applies a transformation to each element of an array (void* version).
   More...

   FOUNDATIONAL_LIB_FUNC void  reduce (void *array, size_t size,
   size_t elem_size, void *result, void(*operation)(void *, void *))
     Performs a reduction on an array (void* version) using a binary
   operation. More...

   FOUNDATIONAL_LIB_FUNC size_t  filter_data (void *source,
   size_t source_size, size_t elem_size, void *destination, size_t
   dest_size, int(*condition)(void *))
     Filters elements of an array (void* version) based on a specified
   condition. More...

   FOUNDATIONAL_LIB_FUNC void *  list_comprehension (const void
   *input_array, size_t array_size, size_t elem_size,
   void(*transform_func)(void *value), int(*filter_func)(void *value),
   size_t *result_size)
     Perform a list comprehension operation. More...

   FOUNDATIONAL_LIB_FUNC int
   FOUNDATIONAL_LIB_list_comprehension_worker (void *data)

   FOUNDATIONAL_LIB_FUNC void *
   list_comprehension_multithreaded (const void *input_array, size_t
   array_size, size_t elem_size, void(*transform_func)(void *value),
   int(*filter_func)(void *value), size_t *result_size, size_t
   thread_count)

   FOUNDATIONAL_LIB_FUNC void *  reject_array (const void
   *source, size_t source_size, size_t elem_size, int(*condition)(const
   void *), size_t *result_size)

   FOUNDATIONAL_LIB_FUNC void *  select_array (const void
   *source, size_t source_size, size_t elem_size, int(*condition)(const
   void *), size_t *result_size)

   FOUNDATIONAL_LIB_FUNC void *  replicate (const void *source,
   size_t source_size, size_t elem_size, size_t repetitions)

   FOUNDATIONAL_LIB_FUNC char *  string_to_lowercase (char
   *string)
     Convert a string to lowercase. More...

   FOUNDATIONAL_LIB_FUNC char *  string_to_uppercase (char
   *string)
     Convert a string to uppercase. More...

   FOUNDATIONAL_LIB_FUNC int  is_string_upper (const char
   *string)
     Check if all characters in a string are uppercase. More...

   FOUNDATIONAL_LIB_FUNC int  is_string_lower (const char
   *string)
     Check if all characters in a string are lowercase. More...

   FOUNDATIONAL_LIB_FUNC int  is_string_alpha (const char
   *string)
     Check if all characters in a string are alphanumeric. More...

   FOUNDATIONAL_LIB_FUNC int  is_string_digit (const char
   *string)
     Check if all characters in a string are digits. More...

   FOUNDATIONAL_LIB_FUNC int  is_string_space (const char
   *string)
     Check if all characters in a string are spaces. More...

   FOUNDATIONAL_LIB_FUNC int  is_string_printable (const char
   *string)
     Check if all characters in a string are printable. More...

   FOUNDATIONAL_LIB_FUNC int  is_array_digit (const char
   **array, size_t size)
     Check if a string array contains only digits. More...

   FOUNDATIONAL_LIB_FUNC int  is_array_upper (const char
   **array, size_t size)
     Checks if a string array contains only uppercase characters.
   More...

   FOUNDATIONAL_LIB_FUNC int  is_array_lower (const char
   **array, size_t size)
     Checks if a string array contains only lowercase characters.
   More...

   FOUNDATIONAL_LIB_FUNC int  string_array_uniq (const char
   **array, size_t size, char ***output, size_t *output_size)
     Remove duplicate strings from a string array. More...

   FOUNDATIONAL_LIB_FUNC int  string_array_uniq_adjacent (const
   char **first_array, size_t size, char ***new_array, size_t *new_size)
     Remove adjacent duplicate strings from a string array. More...

   FOUNDATIONAL_LIB_FUNC char *  concatenate_three_strings
   (const char *str1, const char *str2, const char *str3)
     Concatenates three strings into a new dynamically allocated array.
   More...

   FOUNDATIONAL_LIB_FUNC char *  concatenate_four_strings (const
   char *str1, const char *str2, const char *str3, const char *str4)
     Concatenates four strings into a new dynamically allocated array.
   More...

   FOUNDATIONAL_LIB_FUNC char *  concatenate_five_strings (const
   char *str1, const char *str2, const char *str3, const char *str4, const
   char *str5)
     Concatenates five strings into a new dynamically allocated array.
   More...

   FOUNDATIONAL_LIB_FUNC int  map_filesystem_files_as_strings
   (const char *directory, char *(*map_function)(const char
   *file_string_data, size_t string_size))
     Applies a map operation on files in a directory, working with
   strings. More...

   FOUNDATIONAL_LIB_FUNC int  filter_filesystem_files_as_strings
   (const char *directory, int(*filter_function)(const char *filename))
     Applies a filter operation on files in the specified directory.
   More...

   FOUNDATIONAL_LIB_FUNC char *
   reduce_filesystem_files_as_strings (const char *directory, const
   char *out_file, char *(*reduce_function)(char *value1,...))
     Applies a reduce operation on files in the specified directory, and
   outputs the result as a string. More...

   FOUNDATIONAL_LIB_FUNC void  dict_destructor (struct Dict
   *dict)
     Deallocates memory associated with a dictionary, freeing resources.
   More...

   FOUNDATIONAL_LIB_FUNC size_t  dict_hash (const char *key,
   size_t capacity)
     Hashes a null-terminated string using the djb2 algorithm.
   More...

   FOUNDATIONAL_LIB_FUNC int  dict_reserve_more (struct
   Dict *dict, size_t number_of_new_elements_max_one_is_expecting)
     Reserves additional space in a Dictionary for anticipated new
   elements. More...

   FOUNDATIONAL_LIB_FUNC int  dict_resize (struct Dict
   *dict)
     Resizes the hash table of the dictionary to optimize performance.
   More...

   FOUNDATIONAL_LIB_FUNC void  dict_del_key (struct Dict
   *dict, const char *key)
     Deletes a key-value pair from the dictionary based on the provided
   key. More...

   FOUNDATIONAL_LIB_FUNC int  dict_add (struct Dict *dict,
   const char *key, void *value)
     Adds a key-value pair to the dictionary. More...

   FOUNDATIONAL_LIB_FUNC void *  dict_get (struct Dict
   *dict, const char *key)
     Retrieves the value associated with the specified key from the
   dictionary. More...

   FOUNDATIONAL_LIB_FUNC void *  dict_get_check (struct
   Dict *dict, const char *key, int *key_is_in_dict)
     Retrieves the value associated with the specified key from the
   dictionary. More...

   FOUNDATIONAL_LIB_FUNC void  frozen_dict_destructor (struct
   FrozenDict *dict)
     Deallocates memory associated with a frozen dictionary, freeing
   resources. More...

   FOUNDATIONAL_LIB_FUNC struct FrozenDict *
   frozen_dict_new_instance (size_t num_pairs,...)
     Creates a new instance of a frozen dictionary. More...

   FOUNDATIONAL_LIB_FUNC void *  frozen_dict_get (struct
   FrozenDict *dict, const char *key)
     Retrieves the value associated with the specified key from the frozen
   dictionary. More...

   FOUNDATIONAL_LIB_FUNC void *  frozen_dict_get_check (struct
   FrozenDict *dict, const char *key, int *key_is_in_dict)
     Retrieves the value associated with the specified key from the frozen
   dictionary. More...

   FOUNDATIONAL_LIB_FUNC void  dict_iter (struct Dict
   *dict, void(*callback)(char *key, void *value))
     Iterates through the key-value pairs in the dictionary, applying a
   callback function. More...

   FOUNDATIONAL_LIB_FUNC void  frozen_dict_iter (struct
   FrozenDict *frozen_dict, void(*callback)(char *key, void *value))
     Iterates through the key-value pairs in the FrozenDict, applying
   a callback function. More...

   FOUNDATIONAL_LIB_FUNC size_t  dict_size (struct Dict
   *dict)
     Returns the number of key-value pairs in the dictionary. More...

   FOUNDATIONAL_LIB_FUNC size_t  frozen_dict_size (struct
   FrozenDict *dict)
     Returns the number of key-value pairs in the frozen dictionary.
   More...

   FOUNDATIONAL_LIB_FUNC int  dict_to_array (struct Dict
   *dict, char ***keys, void ***values, size_t *size_of_keys_and_values)
     Converts the key-value pairs from the dictionary into separate arrays
   for keys and values. More...

   FOUNDATIONAL_LIB_FUNC size_t  frozen_dict_to_array (struct
   FrozenDict *dict, char ***keys, void ***values, size_t
   *size_of_keys_and_values)
     Converts the key-value pairs from the frozen dictionary into separate
   arrays for keys and values. More...

   static void  dict_del_keys (char **keys)
     Deallocates memory associated with an array of keys. More...

   static void  dict_del_values (void **values)
     Deallocates memory associated with an array of values. More...

   FOUNDATIONAL_LIB_FUNC char *  dict_to_string (struct
   Dict *dict, int pointer_or_string)
     Converts a dictionary to a string representation. More...

   FOUNDATIONAL_LIB_FUNC char *  frozen_dict_to_string (struct
   FrozenDict *dict, int pointer_or_string)
     Converts a FrozenDict (frozen dictionary) to a string
   representation. More...

   static void  frozen_dict_del_keys (char **keys)
     Deletes keys from a frozen dictionary. More...

   static void  frozen_dict_del_values (void **values)
     Deletes values from a frozen dictionary. More...

   FOUNDATIONAL_LIB_FUNC void  set_destructor (struct
   Set *set)
     The destructor for a Set. More...

   FOUNDATIONAL_LIB_FUNC struct Set *  set_new_instance
   (void)
     Creates a new instance of a Set. More...

   FOUNDATIONAL_LIB_FUNC size_t  set_hash (const char *key,
   size_t capacity)
     Hashes a null-terminated string using the djb2 algorithm.
   More...

   FOUNDATIONAL_LIB_FUNC int  set_resize (struct Set
   *set)
     Resizes a Set data structure. More...

   FOUNDATIONAL_LIB_FUNC void  set_del_key (struct Set
   *set, const char *key)
     Deletes a key from a Set. More...

   FOUNDATIONAL_LIB_FUNC int  set_add (struct Set *set,
   const char *key)
     Adds a key pair to the set. More...

   FOUNDATIONAL_LIB_FUNC int  set_reserve_more (struct
   Set *set, size_t number_of_new_elements_max_one_is_expecting)
     Reserves additional space in a Set for anticipated new
   elements. More...

   FOUNDATIONAL_LIB_FUNC int  set_in (struct Set *set,
   const char *key)
     Checks if a key is in a Set. More...

   FOUNDATIONAL_LIB_FUNC void  frozen_set_destructor (struct
   FrozenSet *frozen_set)
     The destructor for a Frozen Set. More...

   FOUNDATIONAL_LIB_FUNC struct FrozenSet *
   frozen_set_new_instance (size_t num_args,...)
     Creates a new instance of a FrozenSet. More...

   FOUNDATIONAL_LIB_FUNC int  frozen_set_in (struct
   FrozenSet *set, const char *key)
     Checks if a key is in a FrozenSet. More...

   FOUNDATIONAL_LIB_FUNC void  set_iter (struct Set
   *set, void(*callback)(char *key))
     Iterates over a Set and applies a callback to each key.
   More...

   FOUNDATIONAL_LIB_FUNC size_t  set_size (struct Set
   *set)
     Returns the size of a Set. More...

   FOUNDATIONAL_LIB_FUNC size_t  frozen_set_size (struct
   FrozenSet *set)
     Returns the size of a FrozenSet. More...

   FOUNDATIONAL_LIB_FUNC int  set_to_array (struct Set
   *set, char ***keys, size_t *size_of_keys)
     Converts a Set to an array of keys. More...

   FOUNDATIONAL_LIB_FUNC int  frozen_set_to_array (struct
   FrozenSet *set, char ***keys, size_t *size_of_keys)
     Converts a FrozenSet to an array of keys. More...

   FOUNDATIONAL_LIB_FUNC void  set_del_keys (char **keys)
     Deletes keys from a Set. More...

   FOUNDATIONAL_LIB_FUNC char *  set_to_string (struct
   Set *set)

   FOUNDATIONAL_LIB_FUNC char *  frozen_set_to_string (struct
   FrozenSet *frozen_set)
     Converts a frozen set to a string representation. More...

   FOUNDATIONAL_LIB_FUNC void  frozen_set_del_keys (char
   **keys)
     Deletes keys from a FrozenSet. More...

   FOUNDATIONAL_LIB_FUNC void  frozen_set_iter (struct
   Set *set, void(*callback)(char *key))
     Iterates over a Set and applies a callback to each key.
   More...

   FOUNDATIONAL_LIB_FUNC int  is_valid_utf8 (const char *str,
   size_t len)
     Checks if a string is a valid UTF-8 sequence. More...

   FOUNDATIONAL_LIB_FUNC const char *  sample_strings (const
   char **strings, size_t size)
     Selects a random string from an array of strings without dynamic
   memory allocation. More...

   FOUNDATIONAL_LIB_FUNC int  shuffle_strings_in_place (char
   **strings, size_t size)
     Shuffles an array of strings in place. More...

   FOUNDATIONAL_LIB_FUNC long
   rand_number_from_range_inclusive_signed (signed long min, signed
   long max)
     Generates a random signed number within a specified range
   (inclusive). More...

   FOUNDATIONAL_LIB_FUNC unsigned long
   rand_number_from_range_inclusive_unsigned (unsigned long min,
   unsigned long max)
     Generates a random unsigned number within a specified range
   (inclusive). More...

   FOUNDATIONAL_LIB_FUNC char *  backticks (const char
   *command, size_t *size)
     Executes a command and reads its output into a string. More...

   FOUNDATIONAL_LIB_FUNC char **  read_file_into_array (const
   char *filename, const char *delim, size_t *num_lines)
     Reads the contents of a file into an array of strings. More...

   FOUNDATIONAL_LIB_FUNC void  print_char (const char value)
     Prints a character value to the standard output. More...

   FOUNDATIONAL_LIB_FUNC void  print_char_to_stream (const
   char value, FILE *stream)
     Prints a character value to the specified stream. More...

   FOUNDATIONAL_LIB_FUNC void  print_double (const double
   value)
     Prints a double-precision floating-point value to the standard
   output. More...

   FOUNDATIONAL_LIB_FUNC void  print_double_to_stream (const
   double value, FILE *stream)
     Prints a double-precision floating-point value to the specified
   stream. More...

   FOUNDATIONAL_LIB_FUNC void  print_float (const float value)
     Prints a single-precision floating-point value to the standard
   output. More...

   FOUNDATIONAL_LIB_FUNC void  print_float_to_stream (const
   float value, FILE *stream)
     Prints a single-precision floating-point value to the specified
   stream. More...

   FOUNDATIONAL_LIB_FUNC void  print_int (const int value)
     Prints an integer value to the standard output. More...

   FOUNDATIONAL_LIB_FUNC void  print_int_to_stream (const int
   value, FILE *stream)
     Prints an integer value to the specified stream. More...

   FOUNDATIONAL_LIB_FUNC void  print_long (const long value)
     Prints a long integer value to the standard output. More...

   FOUNDATIONAL_LIB_FUNC void  print_long_to_stream (const
   long value, FILE *stream)
     Prints a long integer value to the specified stream. More...

   FOUNDATIONAL_LIB_FUNC void  print_long_long (const long
   long value)
     Prints a long long integer value to the standard output.
   More...

   FOUNDATIONAL_LIB_FUNC void  print_long_long_to_stream
   (const long long value, FILE *stream)
     Prints a long long integer value to the specified stream.
   More...

   FOUNDATIONAL_LIB_FUNC void  print_short (const short value)
     Prints a short integer value to the standard output. More...

   FOUNDATIONAL_LIB_FUNC void  print_short_to_stream (const
   short value, FILE *stream)
     Prints a short integer value to the specified stream. More...

   FOUNDATIONAL_LIB_FUNC void  print_size_t (const size_t
   value)
     Prints a size_t value to the standard output. More...

   FOUNDATIONAL_LIB_FUNC void  print_size_t_to_stream (const
   size_t value, FILE *stream)
     Prints a size_t value to the specified stream. More...

   FOUNDATIONAL_LIB_FUNC void  print_string (char *value)
     Prints a string value to the standard output. More...

   FOUNDATIONAL_LIB_FUNC void  print_string_to_stream (char
   *value, FILE *stream)
     Prints a string value to the specified stream. More...

   FOUNDATIONAL_LIB_FUNC void  print_uchar (const unsigned
   char value)
     Prints an unsigned char value to the standard output. More...

   FOUNDATIONAL_LIB_FUNC void  print_uchar_to_stream (const
   unsigned char value, FILE *stream)
     Prints an unsigned char value to the specified stream. More...

   FOUNDATIONAL_LIB_FUNC void  print_uint (const unsigned int
   value)
     Prints an unsigned int value to the standard output. More...

   FOUNDATIONAL_LIB_FUNC void  print_uint_to_stream (const
   unsigned int value, FILE *stream)
     Prints an unsigned int value to the specified stream. More...

   FOUNDATIONAL_LIB_FUNC void  print_ulong (const unsigned
   long value)
     Prints an unsigned long value to the standard output. More...

   FOUNDATIONAL_LIB_FUNC void  print_ulong_to_stream (const
   unsigned long value, FILE *stream)
     Prints an unsigned long value to the specified stream. More...

   FOUNDATIONAL_LIB_FUNC void  print_ulong_long (const
   unsigned long long value)
     Prints an unsigned long long value to the standard output.
   More...

   FOUNDATIONAL_LIB_FUNC void  print_ulong_long_to_stream
   (const unsigned long long value, FILE *stream)
     Prints an unsigned long long value to the specified stream.
   More...

   FOUNDATIONAL_LIB_FUNC void  print_ushort (const unsigned
   short value)
     Print an unsigned short value. More...

   FOUNDATIONAL_LIB_FUNC void  print_ushort_to_stream (const
   unsigned short value, FILE *stream)
     Print an unsigned short value to a stream. More...

   FOUNDATIONAL_LIB_FUNC size_t
   count_occurrences_of_string_in_array (const char **array, const
   char *string, size_t array_length)
     Counts the occurrences of a string in an array of strings.
   More...

   FOUNDATIONAL_LIB_FUNC size_t
   count_occurrences_of_adjacent_data_in_array (const void
   *array_of_adjacent_values, size_t array_length, const void *memory,
   size_t memory_length)
     Counts the occurrences of a block of memory in an array of memory
   blocks. More...

   FOUNDATIONAL_LIB_FUNC size_t
   count_occurrences_of_data_in_array (const void
   **array_of_pointers, size_t array_length, const void *memory, size_t
   memory_length)
     Counts the occurrences of a block of memory in an array of memory
   blocks. More...

   FOUNDATIONAL_LIB_FUNC int  read_files_into_array (const
   char **files_to_open, size_t num_files, char ***outputs, size_t **lens,
   int aggressive_stop_on_error)
     Reads content from multiple files into an array. More...

Variables

   FOUNDATIONAL_LIB_AGGRESSIVE_DIE_TYPE
   FOUNDATIONAL_LIB_aggressive_die = 1
     Global variable to control aggressive die behavior. More...

Macro Definition Documentation
 <h2>define [1/3]</h2>

   #define define   FOUNDATIONAL_LIB_PRINTF /* not defined */
 <h2>define [2/3]</h2>

   #define define   /* not defined */
 <h2>define [3/3]</h2>

   #define define   FOUNDATIONAL_LIB_CONST /* not defined */
 <h2>endif</h2>

   #define endif   /* if WIN32 */
 <h2>FOUNDATIONAL_LIB_AGGRESSIVE_DIE_TYPE</h2>

   #define FOUNDATIONAL_LIB_AGGRESSIVE_DIE_TYPE   unsigned char

   Type of the aggressive die variable.

   This macro defines the type of the aggressive die variable, which uses
   1 byte of overhead by default. It can be configured as static or
   nonstatic based on user preference.
 <h2>FOUNDATIONAL_LIB_ALLOCATOR_DIV_AMOUNT</h2>

   #define FOUNDATIONAL_LIB_ALLOCATOR_DIV_AMOUNT   2
 <h2>FOUNDATIONAL_LIB_ASSERT_ARGUMENT_CHECKING</h2>

   #define FOUNDATIONAL_LIB_ASSERT_ARGUMENT_CHECKING   0 /* Argument
   NULL checks. Disabled by default. */
 <h2>FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED</h2>

   #define FOUNDATIONAL_LIB_ASSERT_ARGUMENT_IF_ENABLED (   x )    /*
   */
 <h2>FOUNDATIONAL_LIB_ATOI</h2>

   #define FOUNDATIONAL_LIB_ATOI   atoi
 <h2>FOUNDATIONAL_LIB_COPY_SIZE_AMOUNT</h2>

   #define FOUNDATIONAL_LIB_COPY_SIZE_AMOUNT   4096
 <h2>FOUNDATIONAL_LIB_die_aggressively_if_enabled</h2>

   #define FOUNDATIONAL_LIB_die_aggressively_if_enabled ( )
   Value:
   if
   (FOUNDATIONAL_LIB_UNLIKELY(FOUNDATIONAL_LIB_aggressive_die)
   ) \
   { \
   FOUNDATIONAL_LIB_FPRINTF(stderr, "Error: %s: %s.\n", __func__,
   strerror(errno)); \
   exit(EXIT_FAILURE); /* Use default exit, only place in library this is
   used, adjust as needed. */ \
   }
   FOUNDATIONAL_LIB_aggressive_die
   FOUNDATIONAL_LIB_AGGRESSIVE_DIE_TYPE FOUNDATIONAL_LIB_aggressive_die
   Global variable to control aggressive die behavior.
   Definition: foundationallib.h:859
   FOUNDATIONAL_LIB_UNLIKELY
   #define FOUNDATIONAL_LIB_UNLIKELY(x)
   Definition: foundationallib.h:429

   Macro to die aggressively if enabled.

   This macro, when used, checks if aggressive die is enabled. If enabled,
   it prints an error message including the function name and the error
   description, then terminates the program with EXIT_FAILURE.
 <h2>FOUNDATIONAL_LIB_DIR_SEPARATOR</h2>

   #define FOUNDATIONAL_LIB_DIR_SEPARATOR   '/'
 <h2>FOUNDATIONAL_LIB_FCLOSE</h2>

   #define FOUNDATIONAL_LIB_FCLOSE   fclose
 <h2>FOUNDATIONAL_LIB_FERROR</h2>

   #define FOUNDATIONAL_LIB_FERROR   ferror
 <h2>FOUNDATIONAL_LIB_FOPEN</h2>

   #define FOUNDATIONAL_LIB_FOPEN   fopen
 <h2>FOUNDATIONAL_LIB_FPRINTF</h2>

   #define FOUNDATIONAL_LIB_FPRINTF   fprintf
 <h2>FOUNDATIONAL_LIB_FPUTC</h2>

   #define FOUNDATIONAL_LIB_FPUTC   fputc
 <h2>FOUNDATIONAL_LIB_FPUTS</h2>

   #define FOUNDATIONAL_LIB_FPUTS   fputs
 <h2>FOUNDATIONAL_LIB_FREAD</h2>

   #define FOUNDATIONAL_LIB_FREAD   fread
 <h2>FOUNDATIONAL_LIB_FROZEN_INITIALIZATION_SIZE_MULTIPLIER</h2>

   #define
   FOUNDATIONAL_LIB_FROZEN_INITIALIZATION_SIZE_MULTIPLIER   3
 <h2>FOUNDATIONAL_LIB_FSEEKO</h2>

   #define FOUNDATIONAL_LIB_FSEEKO   fseeko
 <h2>FOUNDATIONAL_LIB_FTELLO</h2>

   #define FOUNDATIONAL_LIB_FTELLO   ftello
 <h2>FOUNDATIONAL_LIB_FUNC</h2>

   #define FOUNDATIONAL_LIB_FUNC   static inline
 <h2>FOUNDATIONAL_LIB_FWRITE</h2>

   #define FOUNDATIONAL_LIB_FWRITE   fwrite
 <h2>FOUNDATIONAL_LIB_get_aggressive_die</h2>

   #define FOUNDATIONAL_LIB_get_aggressive_die ( )
   FOUNDATIONAL_LIB_aggressive_die

   Macro to get the current aggressive die mode.

   This macro retrieves the current aggressive die mode, providing insight
   into the error-handling behavior.
 <h2>FOUNDATIONAL_LIB_HASH_INITIAL_CAPACITY</h2>

   #define FOUNDATIONAL_LIB_HASH_INITIAL_CAPACITY   16

   Initial capacity for hash tables (dict, frozendict, set, frozenset).

   This macro defines the initial capacity for hash tables used in dict,
   frozendict, set, and frozenset in the foundational library. It sets the
   default size when these hash-based data structures are created.
 <h2>FOUNDATIONAL_LIB_HASH_LOAD_FACTOR_THRESHOLD</h2>

   #define FOUNDATIONAL_LIB_HASH_LOAD_FACTOR_THRESHOLD   0.75

   Load factor threshold for hash tables in the foundational library.

   This macro defines the load factor threshold for hash tables as
   FOUNDATIONAL_LIB_HASH_LOAD_FACTOR_THRESHOLD if not already defined. It
   represents the maximum load factor before a hash table triggers
   resizing to maintain performance and prevent excessive collisions.
 <h2>FOUNDATIONAL_LIB_INITIAL_DATA_ARRAY_ALLOC_SIZE</h2>

   #define
   FOUNDATIONAL_LIB_INITIAL_DATA_ARRAY_ALLOC_SIZE   FOUNDATIONAL_LIB
   _INITIAL_STRING_ARRAY_ALLOC_SIZE
 <h2>FOUNDATIONAL_LIB_INITIAL_STRING_ARRAY_ALLOC_COUNT</h2>

   #define FOUNDATIONAL_LIB_INITIAL_STRING_ARRAY_ALLOC_COUNT   0
 <h2>FOUNDATIONAL_LIB_INITIAL_STRING_ARRAY_ALLOC_SIZE</h2>

   #define
   FOUNDATIONAL_LIB_INITIAL_STRING_ARRAY_ALLOC_SIZE   (sizeof(char *) * 1)
 <h2>FOUNDATIONAL_LIB_ISALNUM</h2>

   #define FOUNDATIONAL_LIB_ISALNUM   isalnum
 <h2>FOUNDATIONAL_LIB_ISALPHA</h2>

   #define FOUNDATIONAL_LIB_ISALPHA   isalpha
 <h2>FOUNDATIONAL_LIB_ISDIGIT</h2>

   #define FOUNDATIONAL_LIB_ISDIGIT   isdigit
 <h2>FOUNDATIONAL_LIB_ISLOWER</h2>

   #define FOUNDATIONAL_LIB_ISLOWER   islower
 <h2>FOUNDATIONAL_LIB_ISPRINT</h2>

   #define FOUNDATIONAL_LIB_ISPRINT   isprint
 <h2>FOUNDATIONAL_LIB_ISSPACE</h2>

   #define FOUNDATIONAL_LIB_ISSPACE   isspace
 <h2>FOUNDATIONAL_LIB_ISUPPER</h2>

   #define FOUNDATIONAL_LIB_ISUPPER   isupper
 <h2>FOUNDATIONAL_LIB_LIKELY</h2>

   #define FOUNDATIONAL_LIB_LIKELY (   x )    (x)
 <h2>FOUNDATIONAL_LIB_LOW_MEMORY_USAGE</h2>

   #define FOUNDATIONAL_LIB_LOW_MEMORY_USAGE   12
 <h2>FOUNDATIONAL_LIB_MEMCHR</h2>

   #define FOUNDATIONAL_LIB_MEMCHR   memchr
 <h2>FOUNDATIONAL_LIB_MEMCMP</h2>

   #define FOUNDATIONAL_LIB_MEMCMP   memcmp
 <h2>FOUNDATIONAL_LIB_MEMCPY</h2>

   #define FOUNDATIONAL_LIB_MEMCPY   memcpy
 <h2>FOUNDATIONAL_LIB_MEMMOVE</h2>

   #define FOUNDATIONAL_LIB_MEMMOVE   memmove
 <h2>FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_CALLOC</h2>

   #define FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_CALLOC   calloc
 <h2>FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE</h2>

   #define FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_FREE   free
 <h2>FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC</h2>

   #define FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_MALLOC   malloc
 <h2>FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_REALLOC</h2>

   #define FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_REALLOC   realloc
 <h2>FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_STRDUP</h2>

   #define FOUNDATIONAL_LIB_MEMORY_ALLOCATOR_STRDUP   strdup
 <h2>FOUNDATIONAL_LIB_NETWORK_FUNCTIONS_ENABLED</h2>

   #define FOUNDATIONAL_LIB_NETWORK_FUNCTIONS_ENABLED   0

   Networking functions, disabled by default.
 <h2>FOUNDATIONAL_LIB_PCLOSE</h2>

   #define FOUNDATIONAL_LIB_PCLOSE   pclose
 <h2>FOUNDATIONAL_LIB_POPEN</h2>

   #define FOUNDATIONAL_LIB_POPEN   popen
 <h2>FOUNDATIONAL_LIB_POPEN_INITIAL_ALLOC_SIZE</h2>

   #define FOUNDATIONAL_LIB_POPEN_INITIAL_ALLOC_SIZE   4096
 <h2>FOUNDATIONAL_LIB_PRINTF</h2>

   #define FOUNDATIONAL_LIB_PRINTF   printf
 <h2>FOUNDATIONAL_LIB_PUTCHAR</h2>

   #define FOUNDATIONAL_LIB_PUTCHAR   putchar
 <h2>FOUNDATIONAL_LIB_safe_increment</h2>

   #define FOUNDATIONAL_LIB_safe_increment (   variable,
                                                     label_if_fails
                                                 )
   Value:
   if
   (FOUNDATIONAL_LIB_UNLIKELY(FOUNDATIONAL_LIB_safe_add_2_ptr(
   (variable), 1, &(variable)) == 0)) \
   goto label_if_fails;
   FOUNDATIONAL_LIB_safe_add_2_ptr
   static size_t FOUNDATIONAL_LIB_safe_add_2_ptr(size_t a, size_t b,
   size_t *ptr)
   Safely add 2 numbers to avoid unsigned integer overflows and security
   and stability issues....
   Definition: foundationallib.h:600
 <h2>FOUNDATIONAL_LIB_set_aggressive_die</h2>

   #define FOUNDATIONAL_LIB_set_aggressive_die (   mode )
   Value:
   { \
   FOUNDATIONAL_LIB_aggressive_die = (mode); \
   }

   Macro to set the aggressive die mode.

   This macro sets the aggressive die mode based on the specified
   parameter (mode). It allows dynamic control over the aggressive die
   behavior.
 <h2>FOUNDATIONAL_LIB_SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATOR</h2>

   #define
   FOUNDATIONAL_LIB_SIZE_STRING_OF_NUMBER_SIZE_PLUS_ZERO_TERMINATOR   21
   /* length of "18446744073709551615" plus 1 == 21 */
 <h2>FOUNDATIONAL_LIB_SPRINTF</h2>

   #define FOUNDATIONAL_LIB_SPRINTF   sprintf
 <h2>FOUNDATIONAL_LIB_Static_assert</h2>

   #define FOUNDATIONAL_LIB_Static_assert   _Static_assert
 <h2>FOUNDATIONAL_LIB_STATIC_ASSERT</h2>

   #define FOUNDATIONAL_LIB_STATIC_ASSERT (   true_cond )
   FOUNDATIONAL_LIB_Static_assert((true_cond), "(" #true_cond ")
   failed")
 <h2>FOUNDATIONAL_LIB_STATIC_ASSERT_MSG</h2>

   #define FOUNDATIONAL_LIB_STATIC_ASSERT_MSG (   true_cond,
     failure_message
   )    FOUNDATIONAL_LIB_Static_assert((true_cond), failure_message)
 <h2>FOUNDATIONAL_LIB_STRCHR</h2>

   #define FOUNDATIONAL_LIB_STRCHR   strchr
 <h2>FOUNDATIONAL_LIB_STRCMP</h2>

   #define FOUNDATIONAL_LIB_STRCMP   strcmp
 <h2>FOUNDATIONAL_LIB_STRLEN</h2>

   #define FOUNDATIONAL_LIB_STRLEN   strlen
 <h2>FOUNDATIONAL_LIB_STRPBRK</h2>

   #define FOUNDATIONAL_LIB_STRPBRK   strpbrk
 <h2>FOUNDATIONAL_LIB_STRSTR</h2>

   #define FOUNDATIONAL_LIB_STRSTR   strstr
 <h2>FOUNDATIONAL_LIB_THREAD_FUNCTIONS_ENABLED</h2>

   #define FOUNDATIONAL_LIB_THREAD_FUNCTIONS_ENABLED   1

   Enable or disable foundational library thread functions.

   If not already defined, this macro enables foundational library thread
   functions by default. Users can toggle it to control the behavior of
   the library's thread-related functions.
 <h2>FOUNDATIONAL_LIB_UNLIKELY</h2>

   #define FOUNDATIONAL_LIB_UNLIKELY (   x )    (x)
 <h2>FOUNDATIONAL_LIB_UNSAFE_FUNCTIONS_ENABLED</h2>

   #define FOUNDATIONAL_LIB_UNSAFE_FUNCTIONS_ENABLED   1
 <h2>FOUNDATIONAL_LIB_USE_STATIC_ASSERTS_FOR_SAFETY</h2>

   #define FOUNDATIONAL_LIB_USE_STATIC_ASSERTS_FOR_SAFETY   1

   Disable this section if you are maybe getting compilation errors
   (-DFOUNDATIONAL_LIB_USE_STATIC_ASSERTS_FOR_SAFETY=0). Or you can try
   using a modern compiler C11, C++11, though this is not necessary.
   Foundationallib should work with all C and C++ compilers.
 <h2>FOUNDATIONAL_LIB_VA_ARG</h2>

   #define FOUNDATIONAL_LIB_VA_ARG   va_arg
 <h2>FOUNDATIONAL_LIB_VA_END</h2>

   #define FOUNDATIONAL_LIB_VA_END   va_end
 <h2>FOUNDATIONAL_LIB_VA_LIST</h2>

   #define FOUNDATIONAL_LIB_VA_LIST   va_list
 <h2>FOUNDATIONAL_LIB_VA_START</h2>

   #define FOUNDATIONAL_LIB_VA_START   va_start
 <h2>FOUNDATIONAL_LIB_VSNPRINTF</h2>

   #define FOUNDATIONAL_LIB_VSNPRINTF   vsnprintf

Typedef Documentation
 <h2>Dict</h2>

   typedef struct Dict Dict
 <h2>FrozenDict</h2>

   typedef struct FrozenDict FrozenDict
 <h2>FrozenSet</h2>

   typedef struct FrozenSet FrozenSet
 <h2>Set</h2>

   typedef struct Set Set
