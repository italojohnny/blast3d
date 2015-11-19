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
	base = new Scenery();

	my_rotate = 0.0;
	glEnable(GL_COLOR_MATERIAL);
	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

void Interface::lighting (void)
{
	GLfloat light_1[4] = {0.2, 0.2, 0.2, 1.0};
	GLfloat light_2[4] = {0.7, 0.7, 0.7, 1.0};
	GLfloat light_3[4] = {1.0, 1.0, 1.0, 1.0};
	GLfloat light_4[4] = {0.0,50.0,50.0, 1.0};

	GLfloat anyth_1[4] = {0.0, 0.0, 0.0, 0.0};
	GLint   anyth_2 = 60;

	glMaterialfv(GL_FRONT, GL_SPECULAR, anyth_1);
	glMateriali (GL_FRONT, GL_SHININESS, anyth_2);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_1);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_2);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_3);
	glLightfv(GL_LIGHT0, GL_POSITION, light_4);
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
	gluLookAt(0, 45, 50, 0,0,0, 0,1,0);

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
	
	
		//_this->lighting();	
	//glPushMatrix();
		
		//glRotatef(90, 1, 0, 0);glRotatef(180, 0, 1, 0);
		
		//glRotatef(90, 1, 0, 0);glRotatef(180, 0, 1, 0);
	
		//glRotatef(_this->my_rotate, 0, 1, 0);glRotatef(_this->my_rotate, 1, 0, 0);glRotatef(_this->my_rotate, 0, 0, 1);
		glRotatef(_this->my_rotate, 0, 1, 0);//glRotatef(15, 1, 0, 0);
		
		_this->base->draws();
		_this->p1->draws();
	
	//glPopMatrix();
	
	
	glutSwapBuffers();
}

