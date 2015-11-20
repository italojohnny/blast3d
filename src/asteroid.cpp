#include "asteroid.hpp"

Asteroid::Asteroid (void)
{
	x = (rand() % 40) -20;
	y = (rand() % 40) -20;
	z = (rand() % 40) -20;
	cout << "hello asteroid: "<< x << endl;
}

void Asteroid::draws (void)
{

	glColor3f(1,1,1);
	glPointSize(2);
	glBegin(GL_POINTS);
		glVertex3f(x, y, z);
	glEnd();
}
