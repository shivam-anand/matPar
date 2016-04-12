CC = g++
OPTIONS = -std=c++11

%: %.cpp
	$(CC) $< -o $@ $(OPTIONS)

.PHONY:all clean

all: matGen gaussGen

clean:
	rm -f matGen gaussGen
