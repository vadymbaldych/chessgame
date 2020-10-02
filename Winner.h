#pragma once
#include <SFML/Graphics.hpp>
#include "Figures.h"
#include <iostream>

using namespace sf;
using namespace std;

class Winner
{
public:
	String File_Winner_White;
	Texture Texture_Winner_White;
	Sprite Sprite_Winner_White;

	String File_Winner_Black;
	Texture Texture_Winner_Black;
	Sprite Sprite_Winner_Black;

	int W, H;

	Winner(String file_winner_white, String file_winner_black, int w, int h);

	int CheckWinner(Figures &obj);

	~Winner();
};

