#!/bin/bash

# This is for the 3rd test suite.

# It is not 100% necessary.
# Many of these tests won't work yet because this is a work-in-progress test suite.

cd src
for i in $(ls *.c | shuf)
do
	echo Compile $i
	gcc $i -o $i.prog
echo Run $i
	./$i.prog || (echo Open editor...; read; "$EDITOR" "$i"; exec $0)
done
