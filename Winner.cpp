#include "Winner.h"

Winner::Winner(String file_winner_white, String file_winner_black, int w, int h)
{
	File_Winner_White = file_winner_white;
	File_Winner_Black = file_winner_black;
	W = w;
	H = h;

	Texture_Winner_White.loadFromFile("Resources/Winner/" + File_Winner_White);
	Sprite_Winner_White.setTexture(Texture_Winner_White);
	Sprite_Winner_White.setTextureRect(IntRect(0, 0, W, H));
	Sprite_Winner_White.setPosition(0, 0);

	Texture_Winner_Black.loadFromFile("Resources/Winner/" + File_Winner_Black);
	Sprite_Winner_Black.setTexture(Texture_Winner_Black);
	Sprite_Winner_Black.setTextureRect(IntRect(0, 0, W, H));
	Sprite_Winner_Black.setPosition(0, 0);
}

int Winner::CheckWinner(Figures& obj)
{
	bool Buffer_For_White = false;
	bool Buffer_For_Black = false;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			/*Check figures array for kings.
			If -6 in array - White wins (1).
			If 6 in array - Black wins (2).*/
			if (obj.Main_Figures_Positions[i][j] == -6)
			{
				Buffer_For_White = true; //(1)
			}
			if (obj.Main_Figures_Positions[i][j] == 6)
			{
				Buffer_For_Black = true; //(2)
			}
		}
	}

	/*Return -1 if White wins*/
	if (Buffer_For_White == true && Buffer_For_Black == false)
	{
		return -1; 
	}
	/*Return 1 if Black wins*/
	if (Buffer_For_Black == true && Buffer_For_White == false)
	{
		return 1;
	}
	/*Do nothing if nothing happen*/
	else
	{
		return 0;
	}
}

Winner::~Winner()
{
}
