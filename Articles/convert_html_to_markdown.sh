#!/bin/sh

for i in *.html
do
	echo "Converting $i"
	pandoc -s "$i" -o "../Articles_MD/${i}.md"
	echo "Done Converting ${i}. Out is ../Articles_MD/${i}.md"
done
