asteroid.o: asteroid.cpp asteroid.hpp
	g++ -c asteroid.cpp

camera.o: camera.cpp camera.hpp
	g++ -c camera.cpp

scenery.o: scenery.cpp scenery.hpp
	g++ -c scenery.cpp

player.o: player.cpp player.hpp
	g++ -c player.cpp

interface.o: interface.cpp interface.hpp
	g++ -c interface.cpp

main.o: main.cpp
	g++ -c main.cpp

all:asteroid.o camera.o scenery.o player.o interface.o main.o
	g++ main.o interface.o player.o scenery.o camera.o asteroid.o -lglut -lGLU -lGL -lm && ./a.out

clean:
	rm -f *.o *.out
