CC=g++
CFLAGS=-std-c++17 -Wall -pedantic

all: test

.cpp:
	$(CC) -o $@ $@.cpp $(FLAGS)

test: test.cpp ../include/word.h

clean:
	rm test *~
