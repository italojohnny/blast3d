/*
 *       title: blast3d
 *        file: player.cpp
 *     licence: GNU General Public License v2.0
 *      source: https://github.com/italojohnny/blast3d
 *      author: Italo Johnny
 *       email: italojohnnydosanjos@gmail.com
 * Description: ...
 *
 */
#include "player.hpp"

void Player::draws (void)
{

	glColor3f (0,1,0);
	glBegin (GL_TRIANGLE_FAN);
		glVertex3f ( 00.0f, 00.0f, 10.0f);
		glVertex3f ( 00.0f, 02.5f,-05.0f);
		glVertex3f ( 02.5f, 00.0f,-05.0f);
		glVertex3f ( 00.0f,-02.5f,-05.0f);
		glVertex3f (-02.5f, 00.0f,-05.0f);
		glVertex3f ( 00.0f, 02.5f,-05.0f);
	glEnd ();

	glColor3f(1,0,0);
	glBegin (GL_TRIANGLE_FAN);
		glVertex3f ( 00.0f, 00.0f,-10.0f);
		glVertex3f ( 00.0f, 02.5f,-05.0f);
		glVertex3f ( 02.5f, 00.0f,-05.0f);
		glVertex3f ( 00.0f,-02.5f,-05.0f);
		glVertex3f (-02.5f, 00.0f,-05.0f);
		glVertex3f ( 00.0f, 02.5f,-05.0f);
	glEnd ();

	glColor3f(0,0,1);
	glBegin (GL_TRIANGLE_FAN);
		glVertex3f ( 00.0f, 00.0f, 05.0f);
		glVertex3f ( 02.5f, 00.0f,-05.0f);
		glVertex3f ( 10.0f, 00.0f,-15.0f);
	glEnd ();

	glColor3f(0,0,1);
	glBegin (GL_TRIANGLE_FAN);
		glVertex3f ( 00.0f, 00.0f, 05.0f);
		glVertex3f (-02.5f, 00.0f,-05.0f);
		glVertex3f (-10.0f, 00.0f,-15.0f);
	glEnd ();

}
