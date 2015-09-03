#include "scenery.hpp"

Scenery::Scenery (void)
{
	cout << "hello scenery" << endl;
}

void Scenery::draws (void)
{
	GLfloat size = 20;
	glColor3f(0.0f, 0.5f, 0.0f);

	glBegin(GL_LINES);
		for (int i=(size)*(-1); i<=size; i++) {
			glVertex3f(size*(-1), 0.0f, 0.0f+i);	 glVertex3f(  size, 0.0f, 0.0f+i);
			glVertex3f(   0.0f+i, 0.0f, size*(-1)); glVertex3f(0.0f+i, 0.0f, size);
		}
	glEnd();
}
