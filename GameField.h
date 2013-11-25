#pragma once
#include "libs/OpenGL/glut.h"
#include "config.h"

class GameField
{
public:
	GameField()
	{
		width = AppConfig::GameFieldWidth;
		height = AppConfig::GameFieldHeight;
	}

	void DrawField()
	{
		glPushMatrix();
	}
private:
	int width;
	int height;
};