/*
 *       title: blast3d
 *        file: main.cpp
 *     licence: GNU General Public License v2.0
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
	srand(time(NULL));
	
	Interface *game = new Interface(argc, argv);
	return 0;
	
}
