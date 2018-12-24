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
#include "scenery.hpp"
#include "asteroid.hpp"

const int WIDTH  = 800;
const int HEIGHT = 600;
const int MAX_ASTEROID = 10000;
class Interface
{
	public:
		Interface(int &argc, char **argv);

	private:
		float my_rotate;
		bool keystates[256];
		bool btn_up, btn_down, btn_left, btn_right;

		Player *p1;
		Scenery *base;		
		Asteroid *estrelas;

		void initialize (void);
		void lighting (void);
		static void reshape (GLsizei, GLsizei);
		static void keyboardDown (unsigned char, int, int);
		static void keyboardUp (unsigned char, int, int);
		static void skeyboardDown (int, int, int);
		static void skeyboardUp (int, int, int);

		static void timer (int);
		static void display (void);
};

#endif
