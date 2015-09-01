/*
 *       title: blast3d
 *        file: interface.hpp
 *     licence: GNU General Public License v2.0
 *      source: https://github.com/italojohnny/blast3d
 *      author: Italo Johnny
 *       email: italojohnnydosanjos@gmail.com
 * Description: ...
 *
 */
#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <GL/glut.h>
#include <iostream>
using namespace std;

#include "player.hpp"

const int WIDTH  = 800;
const int HEIGHT = 600;

class Interface
{
	public:
		Interface(int &argc, char **argv);

	private:
		float my_rotate;
		Player *p1;

		void initialize (void);
		static void reshape (GLsizei, GLsizei);
		static void keyboard (unsigned char, int, int);
		static void timer (int);
		static void display (void);
};

#endif
