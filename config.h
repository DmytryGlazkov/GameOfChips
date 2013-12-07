#pragma once
class AppConfig
{
public:
	static int Width;
	static int Height;
	static int GameFieldHeight;
	static int GameFieldWidth;
	static float ScreenBorderX;
	static float ScreenBorderY;
	static float FieldBorderX;
	static float FieldBorderY;
	static float StartZoneX;
	static float StartZoneY;

	static float FirstPlayerColor[3];
	static float SecondPlayerColor[3];

	static bool IsFirstPlayerStep;

	static bool IsWins;
};

int AppConfig::Width  = 800;
int AppConfig::Height = 600;
int AppConfig::GameFieldWidth = 7;
int AppConfig::GameFieldHeight = 6;
float AppConfig::ScreenBorderX = (float)(AppConfig::GameFieldWidth + 1) / 2;
float AppConfig::ScreenBorderY = (float)(AppConfig::GameFieldHeight + 1) / 2;
float AppConfig::FieldBorderX = (float)(AppConfig::GameFieldWidth - 1) / 2;
float AppConfig::FieldBorderY = (float)(AppConfig::GameFieldHeight - 1) / 2;

float AppConfig::FirstPlayerColor[3] = {1, 0, 0};
float AppConfig::SecondPlayerColor[3] = {0, 0, 1};

bool AppConfig::IsFirstPlayerStep = true;

bool AppConfig::IsWins = false;