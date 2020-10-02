#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Board
{
public:
	Sprite Main_Board[8][8];

	bool Main_Board_Positions[8][8] =
	{
		0, 1, 0, 1, 0, 1, 0, 1,
		1, 0, 1, 0, 1, 0, 1, 0,
		0, 1, 0, 1, 0, 1, 0, 1,
		1, 0, 1, 0, 1, 0, 1, 0,
		0, 1, 0, 1, 0, 1, 0, 1,
		1, 0, 1, 0, 1, 0, 1, 0,
		0, 1, 0, 1, 0, 1, 0, 1,
		1, 0, 1, 0, 1, 0, 1, 0,
	};

	String File_ChessBoard_Dark;
	Texture Texture_ChessBoard_Dark;

	String File_ChessBoard_Light;
	Texture Texture_ChessBoard_Light;

	int W, H;

	Board(String file_dark, String file_light, int w, int h);

	~Board();
};

