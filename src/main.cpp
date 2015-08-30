/*
 *       title: blast3d
 *        file: main.cpp
 *     licence: GNU V.2
 *      source: https://github.com/italojohnny/blast3d
 *      author: Italo Johnny
 *       email: italojohnnydosanjos@gmail.com
 * Description: ...
 *
 */
#define LINUX

#include <iostream>
#include "interface.hpp"
using namespace std;

int main (int argc, char **argv)
{
	Interface *game = new Interface(argc, argv);
	return 0;
	
}
