player.o: player.cpp player.hpp
	g++ -c player.cpp

interface.o: interface.cpp interface.hpp
	g++ -c interface.cpp

main.o: main.cpp
	g++ -c main.cpp

all: player.o interface.o main.o
	g++ main.o interface.o player.o -lglut -lGLU -lGL -lm && ./a.out
