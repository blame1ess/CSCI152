

CPP = g++

Exec = .
Source = .

Libs =

Options = -std=c++20 -Wall -pedantic -pedantic-errors -flto -O3

# Linking:

$(Exec)/main : $(Source)/main.o $(Source)/timetable.o $(Source)/sorting.o $(Source)/string.o
	$(CPP) $(Options) -o $(Exec)/main $(Source)/main.o $(Source)/timetable.o $(Source)/sorting.o $(Source)/string.o $(Libs)

# Compiling the source files:

$(Source)/main.o : $(Source)/main.cpp $(Source)/sorting.h $(Source)/string.h $(Source)/timer.h $(Source)/timetable.h
	$(CPP) -c $(Options) $(Source)/main.cpp -o $(Source)/main.o

$(Source)/timetable.o : $(Source)/timetable.cpp $(Source)/timetable.h
	$(CPP) -c $(Options) $(Source)/timetable.cpp -o $(Source)/timetable.o

$(Source)/sorting.o : $(Source)/sorting.cpp $(Source)/sorting.h
	$(CPP) -c $(Options) $(Source)/sorting.cpp -o $(Source)/sorting.o

$(Source)/string.o : $(Source)/string.cpp $(Source)/string.h
	$(CPP) -c $(Options) $(Source)/string.cpp -o $(Source)/string.o

