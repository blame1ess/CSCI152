
# Automatically generated Makefile

# Tree Generator

CPP = g++

Exec = .
Source = .

Libs =

Options = -std=c++20 -Wall -pedantic -pedantic-errors

# Linking:

$(Exec)/test : $(Source)/test.o $(Source)/date.o
	$(CPP) $(Options) -o $(Exec)/test $(Source)/test.o $(Source)/date.o $(Libs)

# Compiling the source files:

$(Source)/test.o : $(Source)/test.cpp $(Source)/date.h
	$(CPP) -c $(Options) $(Source)/test.cpp -o $(Source)/test.o

$(Source)/date.o : $(Source)/date.cpp $(Source)/date.h
	$(CPP) -c $(Options) $(Source)/date.cpp -o $(Source)/date.o

