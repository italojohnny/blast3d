#include "asteroid.hpp"

Asteroid::Asteroid (void)
{
	r = 400;
	ang1 = ((float(rand()) / float(RAND_MAX)) * (180.0 - 1.0)) + 1.0;
	ang2 = ((float(rand()) / float(RAND_MAX)) * (360.0 - 1.0)) + 1.0;
}

void Asteroid::draws (void)
{
	glColor3f(1,1,1);
	glPointSize(1);
	glBegin(GL_POINTS);
		glVertex3f(
			r * sin(ang1) * cos(ang2),
			r * sin(ang1) * sin(ang2),
			r * cos(ang1)
		);
	glEnd();
}
