#pragma once
#include "../libs/OpenGL/glut.h"
#include <vector>

using namespace std;

#include "../config.h"
#include "Chip.h"

class GameField
{
public:
	GameField()
	{
		width = AppConfig::GameFieldWidth;
		height = AppConfig::GameFieldHeight;

		CurrentChip = new Chip();
		chips.push_back(CurrentChip);
	}

	Chip* CurrentChip;

	void Update()
	{
		if (CurrentChip->IsSettedUp())
		{
			CurrentChip = new Chip();
			chips.push_back(CurrentChip);
		}
	}

	void DrawField()
	{
		glPushMatrix();
		glColor3f(0.5, 0.5, 0.5);
		
		glPushMatrix();

		glTranslatef(-AppConfig::ScreenBorderX, -AppConfig::ScreenBorderY, 0);

		for (int i = 0 ; i < AppConfig::GameFieldHeight + 3; i++)
		{
			glutSolidCube(1);
			glTranslatef(AppConfig::GameFieldWidth + 1, 0, 0);
			glutSolidCube(1);
			glTranslatef(-(AppConfig::GameFieldWidth + 1), 0, 0);
			glTranslatef(0, 1, 0);
		}
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-AppConfig::ScreenBorderX, -AppConfig::ScreenBorderY, 0);
		for (int i = 0 ; i < AppConfig::GameFieldWidth + 2; i++)
		{
			glutSolidCube(1);
			glTranslatef(0, AppConfig::GameFieldHeight + 2, 0);
			glutSolidCube(1);
			glTranslatef(0, -(AppConfig::GameFieldHeight + 2), 0);
			glTranslatef(1, 0, 0);
		}
		glPopMatrix();
		
		glColor3f(0, 0, 0);
		glPushMatrix();
		glTranslatef((float)-AppConfig::GameFieldWidth / 2, (float)(AppConfig::GameFieldHeight + 2) / 2, 0);
		glBegin(GL_QUADS);
			glVertex3f(0, 0, 0);
			glVertex3f(AppConfig::GameFieldWidth + 1, 0, 0);
			glVertex3f(AppConfig::GameFieldWidth + 1, -1.1, 0);
			glVertex3f(0, -1.1, 0);
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

	bool CheckField(Chip* chip)
	{
		POINT destination = chip->GetDestination();
		for (int i = 0; i < chips.size(); i++)
		{
			if (chips[i]->GetPosition().x == destination.x && chips[i]->GetPosition().y == destination.y)
				return false;
		}
		return true;
	}

	void PushChip(Chip* chip)
	{
		chips.push_back(chip);
	}

	vector<Chip*> GetChips()
	{
		return chips;
	}
private:
	int width;
	int height;
	vector<Chip*> chips;
};

GameField* Field = new GameField();