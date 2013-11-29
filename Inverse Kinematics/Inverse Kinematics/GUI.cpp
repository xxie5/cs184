#include "GUI.h"
#include <iostream>
#include <cassert>

using namespace std;
GUI::GUI(void)
{
}


GUI::~GUI(void)
{
}

void renderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear buffers
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//define the perspective by setting field of view, aspect ratio, near and far clipping plane 
	gluPerspective(90,1.0f,1.0f, 10.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//define the position of the camera, where we are looking, and the up vector
	gluLookAt(0.0, 0.0, 5.0, 0.0,0.0,0.0, 0.0, 1.0,0.0);

	//some green ground
	glBegin(GL_POLYGON);
	glColor3f(0,1,0);
	glVertex3f(-5,-5,0);
	glVertex3f(-5,-4.5,0);
	glVertex3f(5,-4.5,0);
	glVertex3f(5,-5,0);
	glEnd();


	glFlush();
	glutSwapBuffers();
}

void reshapeScene(int width, int height)
{
	assert(height>0);
	float aspectRatio = (float) width / (float) height;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, aspectRatio, 3.0, 7.0);
	//defines the perspective by setting field of view, aspect ratio, near and far clipping plane 

	glViewport(0, 0, width, height);
}




int main(int argc, char* argv[])
{
	//OpenGL stuff
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800,400);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Final project");
	glutDisplayFunc(renderScene);
	glutReshapeFunc(reshapeScene);

	glutMainLoop();

	return 0;
}

