# Compile the object and test program.

# Customize as you wish
CC = gcc

# Customize as you wish
CFLAGS = -O2 -Wall -Wextra -Werror -Wfatal-errors

all: non_inline_example

foundationallib_noninline.o: foundationallib_noninline.c
	$(CC) -c $(CFLAGS) $< -o $@

non_inline_example: foundationallib_noninline.o non_inline_example.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f foundationallib_noninline.o non_inline_example
