CC = g++
OPTIONS = -std=c++11
PARALLEL = -fopenmp

.PHONY: all clean one two three gauss

all: one two three gauss

one: one_serial one_parallel

two: two_serial two_parallel

three: three_serial three_parallel

gauss: gauss_serial gauss_parallel

%_serial: %.cpp ../include/matrix.h
	$(CC) $< -o $@ $(OPTIONS)

%_parallel: %.cpp ../include/matrix.h
	$(CC) $< -o $@ $(OPTIONS) $(PARALLEL)

clean:
	rm -f out *_serial *_parallel
