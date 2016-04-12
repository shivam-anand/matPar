CC = g++
OPTIONS = -std=c++11
PARALLEL = -fopenmp

all: one_serial one_parallel two_serial two_parallel

one_serial: one.cpp ../include/matrix.h
	$(CC) $< -o $@ $(OPTIONS)

one_parallel: one.cpp ../include/matrix.h
	$(CC) $< -o $@ $(OPTIONS) $(PARALLEL)

two_serial: two.cpp ../include/matrix.h
	$(CC) $< -o $@ $(OPTIONS)

two_parallel: two.cpp ../include/matrix.h
	$(CC) $< -o $@ $(OPTIONS) $(PARALLEL)

clean:
	rm -f out one_serial one_parallel two_serial two_parallel
