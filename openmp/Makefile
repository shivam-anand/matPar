CC = g++
OPTIONS = -std=c++11
PARALLEL = -fopenmp

.PHONY: all clean one two three

all: one two three

one: one_serial one_parallel

one_serial: one.cpp ../include/matrix.h
	$(CC) $< -o $@ $(OPTIONS)

one_parallel: one.cpp ../include/matrix.h
	$(CC) $< -o $@ $(OPTIONS) $(PARALLEL)

two: two_serial two_parallel

two_serial: two.cpp ../include/matrix.h
	$(CC) $< -o $@ $(OPTIONS)

two_parallel: two.cpp ../include/matrix.h
	$(CC) $< -o $@ $(OPTIONS) $(PARALLEL)

three: three_serial three_parallel

three_serial: three.cpp ../include/matrix.h
	$(CC) $< -o $@ $(OPTIONS)

three_parallel: three.cpp ../include/matrix.h
	$(CC) $< -o $@ $(OPTIONS) $(PARALLEL)

clean:
	rm -f out one_serial one_parallel two_serial two_parallel three_serial three_parallel
