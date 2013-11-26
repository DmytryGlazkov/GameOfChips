#pragma once
#include "Models/GameField.h"
void Display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	//glTranslatef(-AppConfig::GameFieldWidth / 2, -AppConfig::GameFieldHeight / 2, -10);
	gluLookAt(0, -5, 9 + AppConfig::GameFieldWidth/4*3, 0, 0, 0, 0, 1, 0);
	//glTranslatef(0, 0, -(6 + AppConfig::GameFieldWidth));
	Field->DrawField();
	//glutSolidCube(1);

	glutSwapBuffers();
};