/*
 *       title: blast3d
 *        file: interface.cpp
 *     licence: GNU General Public License v2.0
 *      source: https://github.com/italojohnny/blast3d
 *      author: Italo Johnny
 *       email: italojohnnydosanjos@gmail.com
 * Description: ...
 *
 */
#include "interface.hpp"
Interface *_this;

Interface::Interface(int &argc, char **argv)
{
	char title[] = "blast3d";
	_this = this;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - WIDTH)/2, (glutGet(GLUT_SCREEN_HEIGHT) - HEIGHT)/2);
	glutCreateWindow(title);
	glutKeyboardFunc(this->keyboard);
	glutTimerFunc(1, this->timer, 1);
	glutReshapeFunc(this->reshape);
	glutDisplayFunc(this->display);
	this->initialize();
	glutMainLoop();

}

void Interface::initialize (void)
{
	glClearColor (0.0f, 0.0f, 0.0f, 1);

	p1 = new Player();
	my_rotate = 0.0;
	glEnable(GL_DEPTH_TEST);
}

void Interface::reshape (GLsizei w, GLsizei z)
{
	glutReshapeWindow(WIDTH, HEIGHT);
	glViewport(0, 0, WIDTH, HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, ((GLfloat)WIDTH / (GLfloat)HEIGHT), 0.5, 500);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 50, 100, 0,0,0, 0,1,0);

}

void Interface::keyboard (unsigned char key, int x, int y)
{
	if (key == 27) {
		exit (0);
	}
}

void Interface::timer (int interval)
{
	if (_this->my_rotate >= 360.0)
		_this->my_rotate = 0.0;
	else
		_this->my_rotate += 0.5;
	
	interval = 30;
	glutPostRedisplay();
	glutTimerFunc(interval, Interface::timer, 1);
}

void Interface::display (void)
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glPushMatrix();
		glRotatef(_this->my_rotate, 0, 1, 0);
		_this->p1->draws();
	glPopMatrix();

	glutSwapBuffers();
}

