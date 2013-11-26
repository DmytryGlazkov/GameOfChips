#pragma once
#include <iostream>

using namespace std;

#include "models/Chip.h"
#include "models/GameField.h"

void Keyboard(unsigned char key, int x, int y)
{
	cout << key << " " << x << " " << y <<  "\r\n";
}

void KeyboardSpecialKeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		Field->CurrentChip->Move(-1, 0);
		break;
	case GLUT_KEY_RIGHT:
		Field->CurrentChip->Move(1, 0);
		break;
	case GLUT_KEY_DOWN:
		Field->CurrentChip->Move(0, 1);
		break;
	case GLUT_KEY_UP:
		Field->CurrentChip->Move(0, -1);
		break;
	}
}