#pragma once
#include <iostream>

#include "models/Chip.h"
#include "models/GameField.h"

void Timer(int id)
{
	vector<Chip*> chips = Field->GetChips();

	for (int i = 0; i < chips.size(); i++)
	{
		chips[i]->Update();
	}

	Field->Update();

	glutTimerFunc(1000 / 24, Timer, 0);
}