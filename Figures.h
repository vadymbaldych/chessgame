#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>

using namespace sf;
using namespace std;

class Figures
{
public:
	Sprite Main_Figures[8][8];
	int Main_Figures_Positions[8][8] =
	{
		2, 3, 4, 6, 5, 4, 3, 2,
		1, 1, 1, 1, 1, 1, 1, 1,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		-1, -1, -1, -1, -1, -1, -1, -1,
		-2, -3, -4, -6, -5, -4, -3, -2
	};

	String D_File_Rook, D_File_Hourse, D_File_Bishop, D_File_King, D_File_Queen, D_File_Pawn;
	String L_File_Rook, L_File_Hourse, L_File_Bishop, L_File_King, L_File_Queen, L_File_Pawn;
	Texture D_Texture_Rook, D_Texture_Hourse, D_Texture_Bishop, D_Texture_King, D_Texture_Queen, D_Texture_Pawn;
	Texture L_Texture_Rook, L_Texture_Hourse, L_Texture_Bishop, L_Texture_King, L_Texture_Queen, L_Texture_Pawn;

	String File_Empty;
	Texture Texture_Empty;

	Vector2i ChoosedFigure;
	Vector2i ChoosedFigure_Buffer;

	int W, H;

	Figures(String d_file_R, String d_file_H, String d_file_B, String d_file_K, String d_file_Q,
			String l_file_R, String l_file_H, String l_file_B, String l_file_K, String l_file_Q,
			String d_file_P, String l_file_P, int w, int h , String file_E);

	void UpdateFigures();

	void DrawSteps(Player &obj, bool check);

	~Figures();
};

