#pragma once
#include "libs/OpenGL/glut.h"

#include "config.h"

class Chip
{
public:
	Chip()
	{
		positionX = destinationX = 0;
		positionY = destinationY = -1;
		deltaX = deltaY = 0;
	}

	Chip(int x, int y)
	{
		positionX = destinationX = x;
		positionY = destinationY = y;
		deltaX = deltaY = 0;
	}

	void Draw()
	{
		glPushMatrix();
		glTranslatef(-(AppConfig::GameFieldWidth) / 2  + positionX, (AppConfig::GameFieldHeight) / 2 - positionY, 0);

		glColor3f(1, 0, 1);

		glutSolidCube(1);
		glPopMatrix();
	}

	Chip* Move(int x, int y)
	{
		positionX += x;
		positionY += y;

		return this;
	}
private:
	int positionX;
	int positionY;
	int destinationX;
	int destinationY;
	float deltaX;
	float deltaY;
	int speedKoef;
};