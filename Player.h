#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Player
{
public:
	Sprite Figures_Steps[8][8];
	bool Figures_Steps_Positions[8][8] = //Buffer array which contain current figure steps.
	{
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
	};

	String File_Mouse;
	Texture Texture_Mouse;
	Sprite Sprite_Mouse;

	String File_Empty;
	Texture Texture_Empty;
	Sprite Sprite_Empty;

	Vector2i MousePosition;

	float CurrentFrame = 0;

	int W, H;

	Player(String file_M, int w, int h, String file_E);

	void UpdateFrame(float time, RenderWindow &window, bool check);

	~Player();
};

