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
		IsMoved = false;
		IsSetted = false;
	}

	Chip(int x, int y)
	{
		positionX = destinationX = currentX = x;
		positionY = destinationY = currentY = y;
	}

	int Bottom;
	bool IsSetted;

	bool IsMoved;

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
			if (IsMoved)IsSetted = true;
		}
	}

	void Draw()
	{
		glPushMatrix();
		glTranslatef(-AppConfig::FieldBorderX  + currentX, AppConfig::FieldBorderY - currentY, 0);

		glColor4f(color[0], color[1], color[2], 0.8);

		glutSolidCube(1);
		glTranslatef(-0.5, -0.5, 0.51);


		glColor3f(0, 0, 0);
		glLineWidth(1);
		glBegin(GL_LINE_LOOP);
			glVertex3f(0, 0, 0);
			glVertex3f(1, 0, 0);
			glVertex3f(1, 1, 0);
			glVertex3f(0, 1, 0);
		glEnd();

		glPopMatrix();
	}

	Chip* Move(int x, int y)
	{
		if(!IsMoved)
		{
			destinationX += x;
			if (destinationX < 0 || destinationX >= AppConfig::GameFieldWidth)
				destinationX = positionX;
			destinationY += y;
			if (destinationY < 0 || destinationY >= AppConfig::GameFieldHeight)
				destinationY = positionY;

			positionX = destinationX;
			positionY = destinationY;

		}
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
		result.x = currentX;
		result.y = currentY;
		return result;
	}

	bool IsSettedUp()
	{
		if (positionY >= AppConfig::GameFieldHeight - 1)
			return true;
		return false;
	}

	float* Color()
	{
		return color;
	}

	Chip* Color(float c[3])
	{
		color[0] = c[0];
		color[1] = c[1];
		color[2] = c[2];
		return this;
	}

	Chip* DecreaseDestination(int value)
	{
		destinationY -= value;
		return this;
	}
private:
	int positionX;
	int positionY;
	int destinationX;
	int destinationY;
	float currentX;
	float currentY;
	int speedKoef;
	float color[3];
};