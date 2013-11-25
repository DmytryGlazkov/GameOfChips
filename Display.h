#pragma once
void Display()
{
	glClearColor(0.5f, 0.5f, 0.5f, 0.5f);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	glLoadIdentity();
	glTranslatef(0, 0, -4);
	glutSolidCube(1);
	glPopMatrix();
	glutSwapBuffers();
};