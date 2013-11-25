#pragma once
#include "config.h"
void Reshape(int width, int height)
{
	AppConfig::Width = width;
	AppConfig::Height = height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (float)width / height, 0.1f, 100.0f);
	//gluOrtho2D(0, width, height, 0);
	glMatrixMode(GL_MODELVIEW);
};