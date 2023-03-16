CC=g++
CFLAGS=-std-c++17 -Wall -pedantic

all: test skim

.cpp:
	$(CC) -o $@ $@.cpp $(FLAGS)

test: test.cpp ../include/word.h

skim: skim.cpp

clean:
	rm test skim *~
