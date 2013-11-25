#include "libs/OpenGL/glut.h"
#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "Display.h"
#include "Reshape.h"

int main(int argc, char** argv)
{
	glutInit (&argc, argv);
	glutInitWindowSize (AppConfig::Width, AppConfig::Height);
	glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow ("Game of Chips");

	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

	glutMainLoop();
	return 0;
}