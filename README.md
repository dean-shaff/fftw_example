### FFTW example 

You can find FFTW <a target="_blank" href="http://www.fftw.org/">here</a>. 

#### Building

I'm new the world of Makefiles, so figuring out how to link FFTW when installed in a 
non standard location was a bit of a pain. If you install it in the standard location 
after doing the following: 

```sh
./configure
make 
sudo make install
```

It's sufficient to do the following: `g++ -o fftw_example fftw_example.cpp -lfttw3 -lm`. 

If you install it in a nonstandard location, by doing the following:

```sh
./configure --prefix=/path/to/install/dir 
make 
make install
```

things become a little trickier. We have to link to the static library that is 
created when we build FFTW. We have to tell the compiler where to look, and we 
have to tell it where to find the FFTW header file. We can do this as follows:

```makefile
CC=g++
CFLAGS=-std=c++11
FFTW_HOME=/path/to/install/dir
INCLUDES=-I $(FFTW_HOME)/include
LIBRARIES=-L $(FFTW_HOME)/lib -lfftw3 -lm

fftw_example: fftw_example.cpp
	$(CC) $(CFLAGS) -o $@ $^ $(INCLUDES) $(LIBRARIES)
```

Notice the position of the `INCLUDES` and `LIBRARIES` variables *after* we tell 
g++ what to compile. Crazy. 
