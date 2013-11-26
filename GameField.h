#pragma once
#include "libs/OpenGL/glut.h"
#include <vector>

using namespace std;

#include "config.h"
#include "Chip.h"

class GameField
{
public:
	GameField()
	{
		width = AppConfig::GameFieldWidth;
		height = AppConfig::GameFieldHeight;

		chips.push_back((new Chip()));
	}

	void DrawField()
	{
		glPushMatrix();
		glColor3f(0.5, 0.5, 0.5);
		
		glPushMatrix();

		glTranslatef(-(AppConfig::GameFieldWidth + 2) / 2, -(AppConfig::GameFieldHeight + 2) / 2, 0);

		for (float i = (float)-(AppConfig::GameFieldHeight + 2) / 2 ; i < (float)(AppConfig::GameFieldHeight + 4) / 2; i++)
		{
			glutSolidCube(1);
			glTranslatef(AppConfig::GameFieldWidth + 1, 0, 0);
			glutSolidCube(1);
			glTranslatef(-(AppConfig::GameFieldWidth + 1), 0, 0);
			glTranslatef(0, 1.1, 0);
		}
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-(AppConfig::GameFieldWidth + 2) / 2, -(AppConfig::GameFieldHeight + 2) / 2, 0);
		for (float i = -(float)(AppConfig::GameFieldWidth + 2) / 2 ; i < (float)(AppConfig::GameFieldWidth + 2) / 2; i++)
		{
			glutSolidCube(1);
			glTranslatef(0, AppConfig::GameFieldHeight + 2, 0);
			glutSolidCube(1);
			glTranslatef(0, -(AppConfig::GameFieldHeight + 2), 0);
			glTranslatef(1.1, 0, 0);
		}
		glPopMatrix();

		glColor3f(0, 0, 0);
		glPushMatrix();
		glTranslatef((float)-(AppConfig::GameFieldWidth + 2) / 2, (float)(AppConfig::GameFieldHeight + 2) / 2, 0);
		glBegin(GL_QUADS);
			glVertex3f(0, 0, 0);
			glVertex3f(AppConfig::GameFieldWidth + 1, 0, 0);
			glVertex3f(AppConfig::GameFieldWidth + 1, -1, 0);
			glVertex3f(0, -1, 0);
		glEnd();
		glPopMatrix();

		
		/*glLoadIdentity();
		glTranslatef(-(AppConfig::GameFieldWidth) / 2, 0, -10);

		glPushMatrix();
		glColor3f(0, 1, 0);
		for (int i = 0; i < AppConfig::GameFieldWidth; i++)
		{
			glutSolidCube(1);
			glTranslatef(1, 0, 0);
		}
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, -(AppConfig::GameFieldHeight) / 2, 0);
		glColor3f(1, 0, 0);
		for (int i = 0; i < AppConfig::GameFieldHeight; i++)
		{
			glutSolidCube(1);
			glTranslatef(0, 1, 0);
		}
		glPopMatrix();*/

		/*glLoadIdentity();
		glTranslatef(-(AppConfig::GameFieldWidth) / 2, (AppConfig::GameFieldHeight) / 2, -10);

		glColor3f(0, 0, 1);
		glutSolidCube(1);*/
		/*
		for (int i = 0; i <= AppConfig::GameFieldHeight; i++)
		{
			glVertex2f(0, 1 / (float)AppConfig::GameFieldHeight * i);
			glVertex2f(1, 1 / (float)AppConfig::GameFieldHeight * i);
		}*/
		for (int i = 0; i < chips.size(); i++)
		{
			chips[i]->Draw();
		}
		glPopMatrix();
	}
private:
	int width;
	int height;
	vector<Chip*> chips;
};

GameField* Field = new GameField();