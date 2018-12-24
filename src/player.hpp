/*
 *       title: blast3d
 *        file: player.hpp
 *     licence: GNU General Public License v2.0
 *      source: https://github.com/italojohnny/blast3d
 *      author: Italo Johnny
 *       email: italojohnnydosanjos@gmail.com
 * Description: ...
 *
 */
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <GL/glut.h>
#include <iostream>
using namespace std;

class Player
{
	private:
		float position[3];
		float rotation[3];

	public:
		Player (void);
		void draws (void);	

		void reset_location (void);
		void move (void);
		void move_up (void);
		void move_down (void);
		void move_left (void);
		void move_right (void);
};

#endif
