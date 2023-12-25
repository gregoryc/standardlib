These are custom versions that are generated.

header_and_separate_compilation_unit =>
	no inline functions in this version. And a test program.

header_and_separate_compilation_unit_all_safe_funcs =>
	Same as above, but

	popen() on windows (as popen(), not _popen()) and shellescape() and backticks() are all removed

	No “unsafe functions” are added in this version.

	This is a program that compiles, and a program that WON'T compile, because it tries to use
	shellescape()

	However, these functions are very handy for non-security intensive scripting tasks,
	which is why they are enabled by default.
