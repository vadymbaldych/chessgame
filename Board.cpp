#include "Board.h"

Board::Board(String file_dark, String file_light, int w, int h)
{
	File_ChessBoard_Dark = file_dark;
	File_ChessBoard_Light = file_light;
	W = w;
	H = h;

	Texture_ChessBoard_Dark.loadFromFile("Resources/Board/" + File_ChessBoard_Dark);
	Texture_ChessBoard_Light.loadFromFile("Resources/Board/" + File_ChessBoard_Light);

	/*Make chess board. Setting 
	relevant squares in the position by 
	position in array (1). 
	If found 0 - Light square (2).
	If found 1 - Dark square (3).*/
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Main_Board_Positions[i][j] == 0) //(2)
			{
				Main_Board[i][j].setTexture(Texture_ChessBoard_Light);
				Main_Board[i][j].setTextureRect(IntRect(0, 0, W, H));
				Main_Board[i][j].setPosition(j * W, i * H); //(1)
			}
			if (Main_Board_Positions[i][j] == 1) //(3)
			{
				Main_Board[i][j].setTexture(Texture_ChessBoard_Dark);
				Main_Board[i][j].setTextureRect(IntRect(0, 0, W, H));
				Main_Board[i][j].setPosition(j * W, i * H);
			}
		}
	}
}


Board::~Board()
{
}
