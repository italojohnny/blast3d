/*
 *       title: blast3d
 *        file: asteroid.hpp
 *     licence: GNU General Public License v2.0
 *      source: https://github.com/italojohnny/blast3d
 *      author: Italo Johnny
 *       email: italojohnnydosanjos@gmail.com
 * Description: ...
 *
 */
#ifndef ASTEROID_HPP
#define ASTEROID_HPP
#include <cmath>
#include <GL/glut.h>
#include <iostream>
using namespace std;

class Asteroid
{
	private:
		float r, ang1, ang2;
	public:
		Asteroid (void);
		void draws (void);
};

#endif
