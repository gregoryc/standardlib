#!/bin/bash
# Tries compiling on windows and unix, unix 64 and 32 bits.

set -x
set -e
function green_text() {
	# ANSI escape code for green text
	GREEN='\033[0;32m'
	NC='\033[0m' # No Color

	# Print text in green
	echo -e "${GREEN}$1${NC}"
}

function red_text() {
	# ANSI escape code for red text
	RED='\033[0;31m'
	NC='\033[0m' # No Color

	# Print text in red
	echo -e "${RED}$1${NC}"
}

function die_no_valgrind() {
	red_text "No valgrind"
	exit 1
}

# 64 win
which valgrind || die_no_valgrind
rm -f test_log.txt
touch test_log.txt

if which x86_64-w64-mingw32.shared-g++; then
	CC="x86_64-w64-mingw32.shared-g++ -DFOUNDATIONAL_LIB_THREAD_FUNCTIONS_ENABLED=0 -Wno-c++0x-compat"
	echo "NOTE: threads.h doesn't seem to be a feature of MXE (M Cross Environment for UNIX, which allows people to compile Windows applications on UNIX). So we have to skip it."
	$CC -xc++ -std=c++11 -O2 -g -Werror -Wall -Wextra -Wfatal-errors lib_and_tests.c -o lib_and_tests.exe
	$CC -xc++ -std=c++11 -g -Werror -Wall -Wextra -Wfatal-errors lib_and_tests.c -o lib_and_tests.exe
	timeout 6m tail -f test_log.txt -n 0 &
	if (wine ./lib_and_tests.exe 2>&1 | tee -a test_log.txt); then

		$CC -xc++ -std=c++11 -O2 -g -Werror -Wall -Wextra -Wfatal-errors decoupled_thorough_tests.c -o decoupled_thorough_tests

		$CC -xc++ -std=c++11 -g -Werror -Wall -Wextra -Wfatal-errors decoupled_thorough_tests.c -o decoupled_thorough_tests

		if (wine ./decoupled_thorough_tests 2>&1 | tee -a test_log.txt); then
			set -x
			set -e
			green_text 'ALL TESTS PASS!!! LIBRARY WORKS ON YOUR WINDOWS!!!!!!!!!!!!'
		else
			red_text "Tests collection 1 failed on Windows."
			exit 1
		fi

	else
		red_text "Tests collection 1 failed on Windows."
		exit 1
	fi
fi

# default (64 ? ) unix

CC="g++  -Wno-c++0x-compat"

$CC -std=c++11 -O2 -g -Werror -Wall -Wextra -Wfatal-errors lib_and_tests.c -o lib_and_tests
$CC -std=c++11 -g -Werror -Wall -Wextra -Wfatal-errors lib_and_tests.c -o lib_and_tests
timeout 6m tail -f test_log.txt -n 0 &
if (valgrind ./lib_and_tests 2>&1 | tee -a test_log.txt | grep -q 'ERROR SUMMARY: 0 errors from 0 contexts'); then

	$CC -std=c++11   -xc++ -O2 -g -Werror -Wall -Wextra -Wfatal-errors decoupled_thorough_tests.c -o decoupled_thorough_tests

	$CC -std=c++11   -xc++ -g -Werror -Wall -Wextra -Wfatal-errors decoupled_thorough_tests.c -o decoupled_thorough_tests

	if (valgrind ./decoupled_thorough_tests 2>&1 | tee -a test_log.txt | grep -q 'ERROR SUMMARY: 0 errors from 0 contexts'); then
		set -x
		set -e
		green_text 'ALL TESTS PASS!!! LIBRARY WORKS ON YOUR SYSTEM!!!!!!!!!!!!'
		green_text "$(uname -a)"
		green_text "Foundationallib appears to work on $(uname -a)"
	else
		red_text "Tests collection 1 failed."
		exit 1
	fi

else
	red_text "Tests collection 1 failed."
	exit 1
fi

# Unix 32

CC="g++  -Wno-c++0x-compat"

$CC -xc++ -std=c++11 -O2 -g -m32 -Werror -Wall -Wextra -Wfatal-errors lib_and_tests.c -o lib_and_tests32
$CC -xc++ -std=c++11    -g -m32 -Werror -Wall -Wextra -Wfatal-errors lib_and_tests.c -o lib_and_tests32
timeout 6m tail -f test_log.txt -n 0 &
if (./lib_and_tests32 2>&1 | tee -a test_log.txt); then

	$CC -std=c++11 -xc++ -O2 -g -Werror -Wall -Wextra -Wfatal-errors decoupled_thorough_tests.c -o decoupled_thorough_tests32

	$CC -xc++ -std=c++11             -g -Werror -Wall -Wextra -Wfatal-errors decoupled_thorough_tests.c -o decoupled_thorough_tests32

	if (./decoupled_thorough_tests32 2>&1 | tee -a test_log.txt); then
		set -x
		set -e
		green_text 'ALL TESTS PASS!!! LIBRARY WORKS ON YOUR SYSTEM!!!!!!!!!!!!'
		green_text "$(uname -a)"
		green_text "Foundationallib appears to work on $(uname -a)"
	else
		red_text "Tests collection 1 failed."
		exit 1
	fi

else
	red_text "Tests collection 1 failed."
	exit 1
fi
