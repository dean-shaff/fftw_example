CC=g++
CFLAGS=-std=c++11 

FFTW3_HOME=$(HOME)/.soft/fftw-3.3.8/build
CSV_HOME=$(HOME)/personal/cpp-sandbox/csv

INCLUDES=-I $(FFTW3_HOME)/include -I $(CSV_HOME)/include 
LIBRARIES=-L $(FFTW3_HOME)/lib -lfftw3 -lm


obj=fftw_example.cpp

fftw_example: $(obj)
	$(CC) $(CFLAGS) -o $@ $^ $(INCLUDES) $(LIBRARIES)
