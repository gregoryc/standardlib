#!/bin/sh

sudo apt update && \
	sudo apt install ruby-dev ruby clang-format valgrind build-essential graphviz && \
	sudo gem install rouge puppeteer-ruby
exit 0

#sudo apt update && \
#	sudo dnf install ruby-dev ruby clang-format valgrind build-essential graphviz && \
#	sudo gem install rouge puppeteer-ruby

#If you want to run all the different scripts in this repository,
#you just need these


#ruby-dev ruby clang-format valgrind build-essential graphviz

#and gem intall rouge puppeteer-ruby

#and nothing else

#Of course, some scripts don't need all of these, but if you
# install these it makes for easy testing.
