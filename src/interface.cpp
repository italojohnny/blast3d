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
	glutKeyboardFunc(this->keyboardDown);
	glutKeyboardUpFunc(this->keyboardUp);
	glutSpecialFunc(this->skeyboardDown);
	glutSpecialUpFunc(this->skeyboardUp);
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
	estrelas = new Asteroid[MAX_ASTEROID];

	my_rotate = 0.0;
	glEnable(GL_COLOR_MATERIAL);
	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	//
	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
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
	gluLookAt(0, 0, 50, 0,0,0, 0,1,0);

}

void Interface::keyboardDown (unsigned char key, int x, int y)
{
	cout << (int)key << endl;
	_this->keystates[key] = true;
	if (_this->keystates[27] || key == 'q')
		exit(0);
}

void Interface::keyboardUp (unsigned char key, int x, int y)
{
	cout << (int)key << endl;
	_this->keystates[key] = false;
}

void Interface::skeyboardDown (int key, int x, int y)
{
	//cout << key << endl;
	if (101 == key) _this->btn_up = true;
	if (103 == key) _this->btn_down = true;
	if (100 == key) _this->btn_left = true;
	if (102 == key) _this->btn_right = true;

}

void Interface::skeyboardUp (int key, int x, int y)
{
	//cout << key << endl;
	if (101 == key) _this->btn_up = false;
	if (103 == key) _this->btn_down = false;
	if (100 == key) _this->btn_left = false;
	if (102 == key) _this->btn_right = false;
}

void Interface::timer (int interval)
{
	if (_this->my_rotate >= 360.0)
		_this->my_rotate = 0.0;
	else
		_this->my_rotate += 0.5;

	if (_this->btn_up) _this->p1->move_up();
	if (_this->btn_down) _this->p1->move_down();
	if (_this->btn_left) _this->p1->move_left();
	if (_this->btn_right) _this->p1->move_right();

	interval = 30;
	glutPostRedisplay();
	glutTimerFunc(interval, Interface::timer, 1);
}

void Interface::display (void)
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		//_this->lighting();
	glPushMatrix();

		//glRotatef(90, 1, 0, 0);
		//glRotatef(20, 0, 0, 1);

		//glRotatef(90, 1, 0, 0);glRotatef(180, 0, 1, 0);

		//glRotatef(_this->my_rotate, 0, 1, 0);glRotatef(_this->my_rotate, 1, 0, 0);glRotatef(_this->my_rotate, 0, 0, 1);
		glRotatef(_this->my_rotate, 0, 1, 0);glRotatef(15, 1, 0, 0);

		//_this->base->draws();
		for (int i=0; i < MAX_ASTEROID; i++)
			_this->estrelas[i].draws();
		_this->p1->draws();

	glPopMatrix();


	glutSwapBuffers();
}

