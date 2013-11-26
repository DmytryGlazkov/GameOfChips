#pragma once
#include "../libs/OpenGL/glut.h"
#include <windows.h>

#include "../config.h"

class Chip
{
public:
	Chip()
	{
		positionX = destinationX = currentX = 0;
		positionY = destinationY = currentY = -1;
		speedKoef = 5;
		destinationX = 3;
	}

	Chip(int x, int y)
	{
		positionX = destinationX = currentX = x;
		positionY = destinationY = currentY = y;
	}

	void Update()
	{
		if (abs(currentX - destinationX) > 0.01)
			currentX += (float)(destinationX - currentX) / speedKoef;
		else
		{
			currentX = destinationX;
		}
		if (abs(currentY - destinationY) > 0.01)
			currentY += (float)(destinationY - currentY) / speedKoef;
		else
		{
			currentY = destinationY;
		}
	}

	void Draw()
	{
		glPushMatrix();
		glTranslatef(-(AppConfig::GameFieldWidth) / 2  + currentX, (AppConfig::GameFieldHeight) / 2 - currentY, 0);

		glColor3f(1, 0, 1);

		glutSolidCube(1);
		glPopMatrix();
	}

	Chip* Move(int x, int y)
	{
		destinationX += x;
		if (destinationX < 0 || destinationX >= AppConfig::GameFieldWidth)
			destinationX = positionX;
		destinationY += y;
		if (destinationY < 0 || destinationY > AppConfig::GameFieldWidth)
			destinationY = positionY;

		//if (Field->CheckField(this))
		//{
			positionX = destinationX;
			positionY = destinationY;
		//}

		return this;
	}

	POINT GetDestination()
	{
		POINT result;
		result.x = destinationX;
		result.y = destinationY;
		return result;
	}

	POINT GetPosition()
	{
		POINT result;
		result.x = positionX;
		result.y = positionY;
		return result;
	}

	bool IsSettedUp()
	{
		if (positionY  == AppConfig::GameFieldHeight)
			return true;
	}
private:
	int positionX;
	int positionY;
	int destinationX;
	int destinationY;
	float currentX;
	float currentY;
	int speedKoef;
};