CC = g++
OPTIONS = -std=c++11
PARALLEL = -fopenmp

.PHONY: all clean one two three

all: one two three

one: one_serial one_parallel

two: two_serial two_parallel

three: three_serial three_parallel

%_serial: %.cpp ../include/matrix.h
	$(CC) $< -o $@ $(OPTIONS)

%_parallel: %.cpp ../include/matrix.h
	$(CC) $< -o $@ $(OPTIONS) $(PARALLEL)

clean:
	rm -f out one_serial one_parallel two_serial two_parallel three_serial three_parallel
