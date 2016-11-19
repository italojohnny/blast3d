#include "asteroid.hpp"

Asteroid::Asteroid (void)
{
	r = 100;
	ang1 = (180.0 - 90.0)* ((((float) rand()) / (float) 180.0)) + 90.0;
	ang2 = (360.0 - 90.0)* ((((float) rand()) / (float) 360.0)) + 90.0;
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
