#pragma once
#include "GameField.h"
void Display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	//glTranslatef(-AppConfig::GameFieldWidth / 2, -AppConfig::GameFieldHeight / 2, -10);
	glTranslatef(0, 0, -10);
	Field->DrawField();
	//glutSolidCube(1);

	glutSwapBuffers();
};