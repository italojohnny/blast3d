

interface.o: interface.cpp interface.hpp
	g++ -c interface.cpp

main.o: main.cpp
	g++ -c main.cpp

all: interface.o main.o
	g++ main.o interface.o -lglut -lGLU -lGL -lm && ./a.out
