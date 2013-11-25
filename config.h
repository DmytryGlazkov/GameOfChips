#pragma once
class AppConfig
{
public:
	static int Width;
	static int Height;
	static int GameFieldHeight;
	static int GameFieldWidth;
};

int AppConfig::Width  = 800;
int AppConfig::Height = 600;
int AppConfig::GameFieldWidth = 6;
int AppConfig::GameFieldHeight = 7;
