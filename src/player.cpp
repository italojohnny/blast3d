/*{{{*/
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
/*}}}*/
Player::Player (void)
{
	position[0] = 0.0f;
	position[1] = 0.0f;
	position[2] = 0.0f;

	rotation[0] = 0.0f;
	rotation[1] = 0.0f;
	rotation[2] = 0.0f;
}

void Player::reset_location (void)
{
	position[0] = position[1] = position[2] = 0.0f;
	rotation[0] = rotation[1] = rotation[2] = 0.0f;
}
void Player::move (void)
{}
void Player::move_up (void)
{
	(rotation[0] > 1) ? rotation[0] -= 1 : rotation[0] = 360;
}
void Player::move_down (void)
{
	(rotation[0] < 360)? rotation[0] += 1 : rotation[0] = 0;
}
void Player::move_left (void)
{
	(rotation[1] < 360)? rotation[1] += 1 : rotation[1] = 0;
}
void Player::move_right (void)
{
	(rotation[1] > 1) ? rotation[1] -= 1 : rotation[1] = 360;
}



void Player::draws (void)/*{{{*/
{
	glPushMatrix();
		glRotatef(rotation[1], 0, 1, 0);
		glRotatef(rotation[0], 1, 0, 0);
		glRotatef(rotation[2], 0, 0, 1);

		glTranslatef(position[0], position[1], position[2]);
	
	glColor3f (0.25f, 0.25f,0.25f);
	glBegin (GL_TRIANGLES);
		glVertex3f( 00.0f, 00.0f, 10.0f);glVertex3f( 03.0f, 00.0f,-6.0f);glVertex3f(-03.0f, 00.0f,-06.0f);
		glVertex3f( 00.0f, 00.0f, 10.0f);glVertex3f( 03.0f, 00.0f,-6.0f);glVertex3f( 00.0f, 03.0f,-10.0f);
		glVertex3f( 00.0f, 00.0f, 10.0f);glVertex3f(-03.0f, 00.0f,-6.0f);glVertex3f( 00.0f, 03.0f,-10.0f);
		glVertex3f( 00.0f, 03.0f,-10.0f);glVertex3f( 03.0f, 00.0f,-6.0f);glVertex3f(-03.0f, 00.0f,-06.0f);
	glEnd ();

	glColor3f (0.15f, 0.15f,0.15f);
	//glColor3f (1, 0, 0);
	glBegin(GL_TRIANGLES);
		glVertex3f(5.0f, 0.0f,-01.0f);glVertex3f(3.0f, 0.0f,-05.0f);glVertex3f(7.0f, 0.0f,-05.0f);
		glVertex3f(5.0f, 7.5f,-15.0f);glVertex3f(3.0f, 0.0f,-05.0f);glVertex3f(7.0f, 0.0f,-05.0f);
		glVertex3f(5.0f, 0.0f,-01.0f);glVertex3f(5.0f, 7.5f,-15.0f);glVertex3f(7.0f, 0.0f,-05.0f);
		glVertex3f(5.0f, 0.0f,-01.0f);glVertex3f(3.0f, 0.0f,-05.0f);glVertex3f(5.0f, 7.5f,-15.0f);
	glEnd ();
	//glColor3f (0, 1, 0);
	glBegin(GL_TRIANGLES);
		glVertex3f(5.0f, 0.0f,-01.0f);glVertex3f(3.0f, 0.0f,-05.0f);glVertex3f(7.0f, 0.0f,-05.0f);
		glVertex3f(5.0f,-7.5f,-15.0f);glVertex3f(3.0f, 0.0f,-05.0f);glVertex3f(7.0f, 0.0f,-05.0f);
		glVertex3f(5.0f, 0.0f,-01.0f);glVertex3f(5.0f,-7.5f,-15.0f);glVertex3f(7.0f, 0.0f,-05.0f);
		glVertex3f(5.0f, 0.0f,-01.0f);glVertex3f(3.0f, 0.0f,-05.0f);glVertex3f(5.0f,-7.5f,-15.0f);
	glEnd ();
	glBegin(GL_TRIANGLES);
		glVertex3f(15.0f, 0.0f,-17.0f);glVertex3f(7.0f, 0.0f,-2.0f);glVertex3f(7.0f, 1.0f,-8.0f);
		glVertex3f(15.0f, 0.0f,-17.0f);glVertex3f(7.0f, 0.0f,-2.0f);glVertex3f(7.0f,-1.0f,-8.0f);
		glVertex3f(15.0f, 0.0f,-17.0f);glVertex3f(7.0f, 1.0f,-8.0f);glVertex3f(7.0f,-1.0f,-8.0f);
		glVertex3f( 7.0f, 0.0f,-02.0f);glVertex3f(7.0f, 1.0f,-8.0f);glVertex3f(7.0f,-1.0f,-8.0f);
	glEnd();

	glColor3f (0.15f, 0.15f,0.15f);
	//glColor3f (1, 0, 0);
	glBegin(GL_TRIANGLES);
		glVertex3f(-5.0f, 0.0f,-01.0f);glVertex3f(-3.0f, 0.0f,-05.0f);glVertex3f(-7.0f, 0.0f,-05.0f);
		glVertex3f(-5.0f, 7.5f,-15.0f);glVertex3f(-3.0f, 0.0f,-05.0f);glVertex3f(-7.0f, 0.0f,-05.0f);
		glVertex3f(-5.0f, 0.0f,-01.0f);glVertex3f(-5.0f, 7.5f,-15.0f);glVertex3f(-7.0f, 0.0f,-05.0f);
		glVertex3f(-5.0f, 0.0f,-01.0f);glVertex3f(-3.0f, 0.0f,-05.0f);glVertex3f(-5.0f, 7.5f,-15.0f);
	glEnd ();
	//glColor3f (0, 1, 0);
	glBegin(GL_TRIANGLES);
		glVertex3f(-5.0f, 0.0f,-01.0f);glVertex3f(-3.0f, 0.0f,-05.0f);glVertex3f(-7.0f, 0.0f,-05.0f);
		glVertex3f(-5.0f,-7.5f,-15.0f);glVertex3f(-3.0f, 0.0f,-05.0f);glVertex3f(-7.0f, 0.0f,-05.0f);
		glVertex3f(-5.0f, 0.0f,-01.0f);glVertex3f(-5.0f,-7.5f,-15.0f);glVertex3f(-7.0f, 0.0f,-05.0f);
		glVertex3f(-5.0f, 0.0f,-01.0f);glVertex3f(-3.0f, 0.0f,-05.0f);glVertex3f(-5.0f,-7.5f,-15.0f);
	glEnd ();
	glBegin(GL_TRIANGLES);
		glVertex3f(-15.0f, 0.0f,-17.0f);glVertex3f(-7.0f, 0.0f,-2.0f);glVertex3f(-7.0f, 1.0f,-8.0f);
		glVertex3f(-15.0f, 0.0f,-17.0f);glVertex3f(-7.0f, 0.0f,-2.0f);glVertex3f(-7.0f,-1.0f,-8.0f);
		glVertex3f(-15.0f, 0.0f,-17.0f);glVertex3f(-7.0f, 1.0f,-8.0f);glVertex3f(-7.0f,-1.0f,-8.0f);
		glVertex3f( -7.0f, 0.0f,-02.0f);glVertex3f(-7.0f, 1.0f,-8.0f);glVertex3f(-7.0f,-1.0f,-8.0f);
	glEnd();

	glPopMatrix();

/*
	glColor3f(0.25, 0.5, 0.25);	
	glBegin(GL_TRIANGLES);
		glVertex3f( 15.0f, 0.0f,-20.0f);glVertex3f( 5.0f, 0.0f, -1.0f);glVertex3f( 5.0f, 2.2f, -5.0f);
		//glVertex3f( 15.0f, 0.0f,-20.0f);glVertex3f( 5.0f, 0.0f, -1.0f);glVertex3f( 5.0f,-2.2f, -5.0f);
glColor3f(1,0,0);
		glVertex3f( 15.0f, 0.0f,-20.0f);glVertex3f( 6.7, 1.8,-7.5);glVertex3f( 6.7, 0, -7.5);
	glEnd();
	glColor3f(1,1,1);
	
	glBegin(GL_LINES);
		glVertex3f(15.0f, 0.0f,-20.0f);glVertex3f( 5.0f, 0.0f, -1.0f);
		glVertex3f(15.0f, 0.0f,-20.0f);glVertex3f( 5.0f, 2.2f, -5.0f);
		glVertex3f( 5.0f, 0.0f, -1.0f);glVertex3f(5, 7.5f , -15.0f);
	glEnd();
*/
}/*}}}*/
