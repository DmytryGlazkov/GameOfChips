class GameField;

#pragma once
#include "../libs/OpenGL/glut.h"
#include <vector>
#include <iostream>

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

		CurrentChip = (new Chip())->Color(AppConfig::FirstPlayerColor);
		chips.push_back(CurrentChip);

		cells = new int*[width];
		for (int i = 0; i < width; i++)
		{
			cells[i] = new int[height];
			for (int j = 0; j < height; j++)
				cells[i][j] = 0;
		}
	}

	Chip* CurrentChip;

	bool IsChipSettedUp()
	{
		return CurrentChip->IsSetted;
	}

	bool IsWins()
	{
		int player = AppConfig::IsFirstPlayerStep ? 1 : 0;

		for (int i=0; i<AppConfig::GameFieldWidth; i++)
		{
			for (int j=0; j < AppConfig::GameFieldHeight; j++)
			{
				if (cells[i][j] == 0) continue;
				int tek = cells[i][j];
				int end;
				int u;
				end = 0;
				for (int k = j; k < j + 5; k++)
				{
					if ((k == AppConfig::GameFieldHeight) || (cells[i][k] != tek))
					{
						break;
					}
					end++;
				}
				if (end >= 4)
				{
					return true;
				}

				//Смотрим вниз и вправо от текущей клетки
				end = 0;
				u=i;
				for (int k = j; k < j + 5; k++)
				{
					if ((k == AppConfig::GameFieldHeight) || (u == AppConfig::GameFieldWidth) || (cells[u][k] != tek))
					{
						break;
					}
					end++;
					u++;
				}
				if (end >= 4)
				{
					return true;
				}

				//Смотрим вниз и влево от текущей клетки
				end = 0;
				u=i;
				for (int k = j; k > j - 4; k--)
				{
					if ((k == -1) || (u == AppConfig::GameFieldWidth) || (cells[u][k] != tek))
					{
						break;
					}
					end++;
					u++;
				}
				if (end >= 4)
				{
					return true;
				}
				end = 0;
				for (int k = i;k < i+4;k++)
				{
					if ((k == AppConfig::GameFieldWidth) || (cells[k][j] != tek))
					{
						break;
					}
					end++;
				}
				if (end == 4)
				{
					return true;
				}
			}
		}
		return 0;
	}

	void Update()
	{
		if (IsChipSettedUp())
		{
			POINT position = CurrentChip->GetPosition();
			cells[position.x][position.y] = AppConfig::IsFirstPlayerStep ? 1 : 2;

			if (!IsWins())
			{
				AppConfig::IsFirstPlayerStep = !AppConfig::IsFirstPlayerStep;

				CurrentChip = (new Chip())->Color(AppConfig::IsFirstPlayerStep ? AppConfig::FirstPlayerColor :   AppConfig::SecondPlayerColor);
				chips.push_back(CurrentChip);
			}
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
	int **cells;
};



GameField* Field = new GameField();