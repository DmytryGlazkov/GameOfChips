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
};

int AppConfig::Width  = 800;
int AppConfig::Height = 600;
int AppConfig::GameFieldWidth = 18;
int AppConfig::GameFieldHeight = 7;
float AppConfig::ScreenBorderX = (float)(AppConfig::GameFieldWidth + 1) / 2;
float AppConfig::ScreenBorderY = (float)(AppConfig::GameFieldHeight + 1) / 2;
float AppConfig::FieldBorderX = (float)(AppConfig::GameFieldWidth - 1) / 2;
float AppConfig::FieldBorderY = (float)(AppConfig::GameFieldHeight - 1) / 2;