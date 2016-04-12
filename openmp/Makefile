CC = g++
OPTIONS = -std=c++11
PARALLEL = -fopenmp

all: one_serial one_parallel

one_serial: one.cpp ../include/matrix.h
	$(CC) $< -o $@ $(OPTIONS)

one_parallel: one.cpp ../include/matrix.h
	$(CC) $< -o $@ $(OPTIONS) $(PARALLEL)

clean:
	rm -f one_serial one_parallel out
