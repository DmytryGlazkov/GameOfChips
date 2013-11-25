#include "libs/OpenGL/glut.h"
#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "MainLoop.h"
#include "Display.h"
#include "Reshape.h"

int main(int argc, char** argv)
{
	glutInit (&argc, argv);
	glutInitWindowSize (App::Width, App::Height);
	glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow ("Game of Chips");

	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutMainLoop();
	return 0;
}