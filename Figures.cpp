#include "Figures.h"

Figures::Figures(String d_file_R, String d_file_H, String d_file_B, String d_file_K, String d_file_Q,
				 String l_file_R, String l_file_H, String l_file_B, String l_file_K, String l_file_Q,
				 String d_file_P, String l_file_P, int w, int h, String file_E)
{
	D_File_Rook = d_file_R;
	D_File_Hourse = d_file_H;
	D_File_Bishop = d_file_B;
	D_File_King = d_file_K;
	D_File_Queen = d_file_Q;
	D_File_Pawn = d_file_P;

	L_File_Rook = l_file_R;
	L_File_Hourse = l_file_H;
	L_File_Bishop = l_file_B;
	L_File_King = l_file_K;
	L_File_Queen = l_file_Q;
	L_File_Pawn = l_file_P;

	D_Texture_Rook.loadFromFile("Resources/Figures/" + D_File_Rook);
	D_Texture_Hourse.loadFromFile("Resources/Figures/" + D_File_Hourse);
	D_Texture_Bishop.loadFromFile("Resources/Figures/" + D_File_Bishop);
	D_Texture_King.loadFromFile("Resources/Figures/" + D_File_King);
	D_Texture_Queen.loadFromFile("Resources/Figures/" + D_File_Queen);
	D_Texture_Pawn.loadFromFile("Resources/Figures/" + D_File_Pawn);
	
	L_Texture_Rook.loadFromFile("Resources/Figures/" + L_File_Rook);
	L_Texture_Hourse.loadFromFile("Resources/Figures/" + L_File_Hourse);
	L_Texture_Bishop.loadFromFile("Resources/Figures/" + L_File_Bishop);
	L_Texture_King.loadFromFile("Resources/Figures/" + L_File_King);
	L_Texture_Queen.loadFromFile("Resources/Figures/" + L_File_Queen);
	L_Texture_Pawn.loadFromFile("Resources/Figures/" + L_File_Pawn);

	W = w;
	H = h;

	File_Empty = file_E;
	Texture_Empty.loadFromFile("Resources/Figures/" + File_Empty);
}

void Figures::UpdateFigures()
{
	/*Check array with figures for figures,
	then give their sprites relevant texture.
	j*W i*W setting figure on the board by position
	in array (1)*/
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)	
		{
			if (Main_Figures_Positions[i][j] == 2)
			{
				Main_Figures[i][j].setTexture(D_Texture_Rook);
				Main_Figures[i][j].setTextureRect(IntRect(0, 0, W, H)); 
				Main_Figures[i][j].setPosition(j * W, i * H); //(1)
			}
			if (Main_Figures_Positions[i][j] == 3)
			{
				Main_Figures[i][j].setTexture(D_Texture_Hourse);
				Main_Figures[i][j].setTextureRect(IntRect(0, 0, W, H));
				Main_Figures[i][j].setPosition(j * W, i * H);
			}
			if (Main_Figures_Positions[i][j] == 4)
			{
				Main_Figures[i][j].setTexture(D_Texture_Bishop);
				Main_Figures[i][j].setTextureRect(IntRect(0, 0, W, H));
				Main_Figures[i][j].setPosition(j * W, i * H);
			}
			if (Main_Figures_Positions[i][j] == 6)
			{

				Main_Figures[i][j].setTexture(D_Texture_King);
				Main_Figures[i][j].setTextureRect(IntRect(0, 0, W, H));
				Main_Figures[i][j].setPosition(j * W, i * H);
			}
			if (Main_Figures_Positions[i][j] == 5)
			{
				Main_Figures[i][j].setTexture(D_Texture_Queen);
				Main_Figures[i][j].setTextureRect(IntRect(0, 0, W, H));
				Main_Figures[i][j].setPosition(j * W, i * H);
			}
			if (Main_Figures_Positions[i][j] == 1)
			{
				Main_Figures[i][j].setTexture(D_Texture_Pawn);
				Main_Figures[i][j].setTextureRect(IntRect(0, 0, W, H));
				Main_Figures[i][j].setPosition(j * W, i * H);
			}
			//-----------------------------------------
			if (Main_Figures_Positions[i][j] == -2)
			{
				Main_Figures[i][j].setTexture(L_Texture_Rook);
				Main_Figures[i][j].setTextureRect(IntRect(0, 0, W, H));
				Main_Figures[i][j].setPosition(j * W, i * H);
			}
			if (Main_Figures_Positions[i][j] == -3)
			{
				Main_Figures[i][j].setTexture(L_Texture_Hourse);
				Main_Figures[i][j].setTextureRect(IntRect(0, 0, W, H));
				Main_Figures[i][j].setPosition(j * W, i * H);
			}
			if (Main_Figures_Positions[i][j] == -4)
			{
				Main_Figures[i][j].setTexture(L_Texture_Bishop);
				Main_Figures[i][j].setTextureRect(IntRect(0, 0, W, H));
				Main_Figures[i][j].setPosition(j * W, i * H);
			}
			if (Main_Figures_Positions[i][j] == -6)
			{
				Main_Figures[i][j].setTexture(L_Texture_King);
				Main_Figures[i][j].setTextureRect(IntRect(0, 0, W, H));
				Main_Figures[i][j].setPosition(j * W, i * H);
			}
			if (Main_Figures_Positions[i][j] == -5)
			{

				Main_Figures[i][j].setTexture(L_Texture_Queen);
				Main_Figures[i][j].setTextureRect(IntRect(0, 0, W, H));
				Main_Figures[i][j].setPosition(j * W, i * H);
			}
			if (Main_Figures_Positions[i][j] == -1)
			{
				Main_Figures[i][j].setTexture(L_Texture_Pawn);
				Main_Figures[i][j].setTextureRect(IntRect(0, 0, W, H));
				Main_Figures[i][j].setPosition(j * W, i * H);
			}
			//-----------------------------------------
			if (Main_Figures_Positions[i][j] == 0)
			{
				Main_Figures[i][j].setTexture(Texture_Empty);
				Main_Figures[i][j].setTextureRect(IntRect(0, 0, W, H));
				Main_Figures[i][j].setPosition(j * W, i * H);
			}
		}
	}
}

void Figures::DrawSteps(Player &obj, bool check)
{
	/*Left click*/
	if (check == false)
	{
		/*

		BALCK FIGURES
		
		*/
		if (Main_Figures_Positions[ChoosedFigure.y][ChoosedFigure.x] == 2) //Standart BLACK ROOK step.
		{
			//Up
			for (int i = ChoosedFigure.y; i >= 0; i--)
			{
				if (i - 1 >= 0)
				{
					if (Main_Figures_Positions[i - 1][ChoosedFigure.x] <= 0)
					{
						obj.Figures_Steps_Positions[i - 1][ChoosedFigure.x] = 1;
					}
					if (Main_Figures_Positions[i - 1][ChoosedFigure.x] != 0)
					{
						break;
					}
				}
			}
			//Down
			for (int i = ChoosedFigure.y; i < 8; i++)
			{
				if (i + 1 < 8)
				{
					if (Main_Figures_Positions[i + 1][ChoosedFigure.x] <= 0)
					{
						obj.Figures_Steps_Positions[i + 1][ChoosedFigure.x] = 1;
					}
					if (Main_Figures_Positions[i + 1][ChoosedFigure.x] != 0)
					{
						break;
					}
				}
			}
			//Left
			for (int i = ChoosedFigure.x; i >= 0; i--)
			{
				if (i - 1 >= 0)
				{
					if (Main_Figures_Positions[ChoosedFigure.y][i - 1] <= 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y][i - 1] = 1;
					}
					if (Main_Figures_Positions[ChoosedFigure.y][i - 1] != 0)
					{
						break;
					}
				}
			}
			//Right
			for (int i = ChoosedFigure.x; i < 8; i++)
			{
				if (i + 1 < 8)
				{
					if (Main_Figures_Positions[ChoosedFigure.y][i + 1] <= 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y][i + 1] = 1;
					}
					if (Main_Figures_Positions[ChoosedFigure.y][i + 1] != 0)
					{
						break;
					}
				}
			}
		}
		if (Main_Figures_Positions[ChoosedFigure.y][ChoosedFigure.x] == 3) //Standart BLACK HORSE step.
		{
			//Up
			if (ChoosedFigure.y - 2 >= 0 && ChoosedFigure.x + 1 < 8)
			{
				if (Main_Figures_Positions[ChoosedFigure.y - 2][ChoosedFigure.x + 1] <= 0) 
				{
					obj.Figures_Steps_Positions[ChoosedFigure.y - 2][ChoosedFigure.x + 1] = 1;
				}
			}
			if (ChoosedFigure.y - 2 >= 0 && ChoosedFigure.x - 1 >= 0)
			{
				if (Main_Figures_Positions[ChoosedFigure.y - 2][ChoosedFigure.x - 1] <= 0)
				{
					obj.Figures_Steps_Positions[ChoosedFigure.y - 2][ChoosedFigure.x - 1] = 1;
				}
			}
			//Down
			if (ChoosedFigure.y + 2 < 8 && ChoosedFigure.x + 1 < 8)
			{
				if (Main_Figures_Positions[ChoosedFigure.y + 2][ChoosedFigure.x + 1] <= 0)
				{
					obj.Figures_Steps_Positions[ChoosedFigure.y + 2][ChoosedFigure.x + 1] = 1;
				}
			}
			if (ChoosedFigure.y + 2 < 8 && ChoosedFigure.x - 1 >= 0)
			{
				if (Main_Figures_Positions[ChoosedFigure.y + 2][ChoosedFigure.x - 1] <= 0)
				{
					obj.Figures_Steps_Positions[ChoosedFigure.y + 2][ChoosedFigure.x - 1] = 1;
				}
			}
			//Left
			if (ChoosedFigure.y + 1 < 8 && ChoosedFigure.x - 2 >= 0)
			{
				if (Main_Figures_Positions[ChoosedFigure.y + 1][ChoosedFigure.x - 2] <= 0)
				{
					obj.Figures_Steps_Positions[ChoosedFigure.y + 1][ChoosedFigure.x - 2] = 1;
				}
			}
			if (ChoosedFigure.y - 1 >= 0 && ChoosedFigure.x - 2 >= 0)
			{
				if (Main_Figures_Positions[ChoosedFigure.y - 1][ChoosedFigure.x - 2] <= 0)
				{
					obj.Figures_Steps_Positions[ChoosedFigure.y - 1][ChoosedFigure.x - 2] = 1;
				}
			}
			//Right
			if (ChoosedFigure.y + 1 < 8 && ChoosedFigure.x + 2 < 8)
			{
				if (Main_Figures_Positions[ChoosedFigure.y + 1][ChoosedFigure.x + 2] <= 0)
				{
					obj.Figures_Steps_Positions[ChoosedFigure.y + 1][ChoosedFigure.x + 2] = 1;
				}
			}
			if (ChoosedFigure.y - 1 >= 0 && ChoosedFigure.x + 2 < 8)
			{
				if (Main_Figures_Positions[ChoosedFigure.y - 1][ChoosedFigure.x + 2] <= 0)
				{
					obj.Figures_Steps_Positions[ChoosedFigure.y - 1][ChoosedFigure.x + 2] = 1;
				}
			}
		}
		if (Main_Figures_Positions[ChoosedFigure.y][ChoosedFigure.x] == 4) //Standart BLACK BISHOP step.
		{
			//Left up
			for (int i = 0; i < 8; i++)
			{
				if (ChoosedFigure.y - 1 - i >= 0 && ChoosedFigure.x - 1 - i >= 0)
				{
					if (Main_Figures_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x - 1 - i] == 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x - 1 - i] = 1;
					}
					if (Main_Figures_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x - 1 - i] < 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x - 1 - i] = 1;
						break;
					}
					if (Main_Figures_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x - 1 - i] != 0)
					{
						break;
					}
					
				}
			}
			//Right up
			for (int i = 0; i < 8; i++)
			{
				if (ChoosedFigure.y - 1 - i >= 0 && ChoosedFigure.x + 1 + i < 8)
				{
					if (Main_Figures_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x + 1 + i] == 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x + 1 + i] = 1;
					}
					if (Main_Figures_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x + 1 + i] < 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x + 1 + i] = 1;
						break;
					}
					if (Main_Figures_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x + 1 + i] != 0)
					{
						break;
					}
				}
			}
			//Left down
			for (int i = 0; i < 8; i++)
			{
				if (ChoosedFigure.y + 1 + i < 8 && ChoosedFigure.x - 1 - i >= 0)
				{
					if (Main_Figures_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x - 1 - i] == 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x - 1 - i] = 1;
					}
					if (Main_Figures_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x - 1 - i] < 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x - 1 - i] = 1;
						break;
					}
					if (Main_Figures_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x - 1 - i] != 0)
					{
						break;
					}
				}
			}
			//Right down
			for (int i = 0; i < 8; i++)
			{
				if (ChoosedFigure.y + 1 + i < 8 && ChoosedFigure.x + 1 + i < 8)
				{
					if (Main_Figures_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x + 1 + i] == 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x + 1 + i] = 1;
					}
					if (Main_Figures_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x + 1 + i] < 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x + 1 + i] = 1;
						break;
					}
					if (Main_Figures_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x + 1 + i] != 0)
					{
						break;
					}
				}
			}
		}
		if (Main_Figures_Positions[ChoosedFigure.y][ChoosedFigure.x] == 6) //Standart BLACK KING step.
		{
			//Left up
			if (ChoosedFigure.y - 1 >= 0 && ChoosedFigure.x - 1 >= 0)
			{
				if (Main_Figures_Positions[ChoosedFigure.y - 1][ChoosedFigure.x - 1] <= 0) 
				{
					obj.Figures_Steps_Positions[ChoosedFigure.y - 1][ChoosedFigure.x - 1] = 1;
				}
			}
			//Right up
			if (ChoosedFigure.y - 1 >= 0 && ChoosedFigure.x + 1 < 8)
			{
				if (Main_Figures_Positions[ChoosedFigure.y - 1][ChoosedFigure.x + 1] <= 0) 
				{
					obj.Figures_Steps_Positions[ChoosedFigure.y - 1][ChoosedFigure.x + 1] = 1;
				}
			}
			//Left down
			if (ChoosedFigure.y + 1 < 8 && ChoosedFigure.x - 1 >= 0)
			{
				if (Main_Figures_Positions[ChoosedFigure.y + 1][ChoosedFigure.x - 1] <= 0)
				{
					obj.Figures_Steps_Positions[ChoosedFigure.y + 1][ChoosedFigure.x - 1] = 1;
				}
			}
			//Right down
			if (ChoosedFigure.y + 1 < 8 && ChoosedFigure.x + 1 < 8)
			{
				if (Main_Figures_Positions[ChoosedFigure.y + 1][ChoosedFigure.x + 1] <= 0) 
				{
					obj.Figures_Steps_Positions[ChoosedFigure.y + 1][ChoosedFigure.x + 1] = 1;
				}
			}
			//Up
			if (ChoosedFigure.y - 1 >= 0)
			{
				if (Main_Figures_Positions[ChoosedFigure.y - 1][ChoosedFigure.x] <= 0) 
				{
					obj.Figures_Steps_Positions[ChoosedFigure.y - 1][ChoosedFigure.x] = 1;
				}
			}
			//Down
			if (ChoosedFigure.y + 1 < 8)
			{
				if (Main_Figures_Positions[ChoosedFigure.y + 1][ChoosedFigure.x] <= 0) 
				{
					obj.Figures_Steps_Positions[ChoosedFigure.y + 1][ChoosedFigure.x] = 1;
				}
			}
			//Left
			if (ChoosedFigure.x - 1 >= 0)
			{
				if (Main_Figures_Positions[ChoosedFigure.y][ChoosedFigure.x - 1] <= 0) 
				{
					obj.Figures_Steps_Positions[ChoosedFigure.y][ChoosedFigure.x - 1] = 1;
				}
			}
			//Right
			if (ChoosedFigure.x + 1 < 8)
			{
				if (Main_Figures_Positions[ChoosedFigure.y][ChoosedFigure.x + 1] <= 0) 
				{
					obj.Figures_Steps_Positions[ChoosedFigure.y][ChoosedFigure.x + 1] = 1;
				}
			}		
		}
		if (Main_Figures_Positions[ChoosedFigure.y][ChoosedFigure.x] == 5) //Standart BLACK QUEEN step.
		{
			//Up
			for (int i = ChoosedFigure.y; i >= 0; i--)
			{
				if (i - 1 >= 0)
				{
					if (Main_Figures_Positions[i - 1][ChoosedFigure.x] <= 0)
					{
						obj.Figures_Steps_Positions[i - 1][ChoosedFigure.x] = 1;
					}
					if (Main_Figures_Positions[i - 1][ChoosedFigure.x] != 0)
					{
						break;
					}
				}
			}
			//Down
			for (int i = ChoosedFigure.y; i < 8; i++)
			{
				if (i + 1 < 8)
				{
					if (Main_Figures_Positions[i + 1][ChoosedFigure.x] <= 0)
					{
						obj.Figures_Steps_Positions[i + 1][ChoosedFigure.x] = 1;
					}
					if (Main_Figures_Positions[i + 1][ChoosedFigure.x] != 0)
					{
						break;
					}
				}
			}
			//Left
			for (int i = ChoosedFigure.x; i >= 0; i--)
			{
				if (i - 1 >= 0)
				{
					if (Main_Figures_Positions[ChoosedFigure.y][i - 1] <= 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y][i - 1] = 1;
					}
					if (Main_Figures_Positions[ChoosedFigure.y][i - 1] != 0)
					{
						break;
					}
				}
			}
			//Right
			for (int i = ChoosedFigure.x; i < 8; i++)
			{
				if (i + 1 < 8)
				{
					if (Main_Figures_Positions[ChoosedFigure.y][i + 1] <= 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y][i + 1] = 1;
					}
					if (Main_Figures_Positions[ChoosedFigure.y][i + 1] != 0)
					{
						break;
					}
				}
			}
			//Left up
			for (int i = 0; i < 8; i++)
			{
				if (ChoosedFigure.y - 1 - i >= 0 && ChoosedFigure.x - 1 - i >= 0)
				{
					if (Main_Figures_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x - 1 - i] == 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x - 1 - i] = 1;
					}
					if (Main_Figures_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x - 1 - i] < 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x - 1 - i] = 1;
						break;
					}
					if (Main_Figures_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x - 1 - i] != 0)
					{
						break;
					}

				}
			}
			//Right up
			for (int i = 0; i < 8; i++)
			{
				if (ChoosedFigure.y - 1 - i >= 0 && ChoosedFigure.x + 1 + i < 8)
				{
					if (Main_Figures_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x + 1 + i] == 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x + 1 + i] = 1;
					}
					if (Main_Figures_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x + 1 + i] < 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x + 1 + i] = 1;
						break;
					}
					if (Main_Figures_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x + 1 + i] != 0)
					{
						break;
					}
				}
			}
			//Left down
			for (int i = 0; i < 8; i++)
			{
				if (ChoosedFigure.y + 1 + i < 8 && ChoosedFigure.x - 1 - i >= 0)
				{
					if (Main_Figures_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x - 1 - i] == 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x - 1 - i] = 1;
					}
					if (Main_Figures_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x - 1 - i] < 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x - 1 - i] = 1;
						break;
					}
					if (Main_Figures_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x - 1 - i] != 0)
					{
						break;
					}
				}
			}
			//Right down
			for (int i = 0; i < 8; i++)
			{
				if (ChoosedFigure.y + 1 + i < 8 && ChoosedFigure.x + 1 + i < 8)
				{
					if (Main_Figures_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x + 1 + i] == 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x + 1 + i] = 1;
					}
					if (Main_Figures_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x + 1 + i] < 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x + 1 + i] = 1;
						break;
					}
					if (Main_Figures_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x + 1 + i] != 0)
					{
						break;
					}
				}
			}
		}
		if (Main_Figures_Positions[ChoosedFigure.y][ChoosedFigure.x] == 1) //BLACK PAWN step.
		{
			if (ChoosedFigure.y == 1) //First BLACK PAWN step.
			{
				if (ChoosedFigure.y + 1 < 8)
				{
					if (Main_Figures_Positions[ChoosedFigure.y + 1][ChoosedFigure.x] == 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y + 1][ChoosedFigure.x] = 1;
						if (ChoosedFigure.y + 2 < 8)
						{
							if (Main_Figures_Positions[ChoosedFigure.y + 2][ChoosedFigure.x] == 0)
							{
								obj.Figures_Steps_Positions[ChoosedFigure.y + 2][ChoosedFigure.x] = 1;
							}
						}
					}
				}
				if (ChoosedFigure.y + 1 < 8 && ChoosedFigure.x + 1 < 8)
				{
					if (Main_Figures_Positions[ChoosedFigure.y + 1][ChoosedFigure.x + 1] < 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y + 1][ChoosedFigure.x + 1] = 1;
					}
				}
				if (ChoosedFigure.y + 1 < 8 && ChoosedFigure.x - 1 >= 0)
				{
					if (Main_Figures_Positions[ChoosedFigure.y + 1][ChoosedFigure.x - 1] < 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y + 1][ChoosedFigure.x - 1] = 1;
					}
				}
			}
			if (ChoosedFigure.y != 1) //Standart BLACK PAWN step.
			{
				if (ChoosedFigure.y + 1 < 8)
				{
					if (Main_Figures_Positions[ChoosedFigure.y + 1][ChoosedFigure.x] == 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y + 1][ChoosedFigure.x] = 1;
					}
				}
				if (ChoosedFigure.y + 1 < 8 && ChoosedFigure.x + 1 < 8)
				{
					if (Main_Figures_Positions[ChoosedFigure.y + 1][ChoosedFigure.x + 1] < 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y + 1][ChoosedFigure.x + 1] = 1;
					}
				}
				if (ChoosedFigure.y + 1 < 8 && ChoosedFigure.x - 1 >= 0)
				{
					if (Main_Figures_Positions[ChoosedFigure.y + 1][ChoosedFigure.x - 1] < 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y + 1][ChoosedFigure.x - 1] = 1;
					}
				}
			}
		}
		/*

		WHITE FIGURES

		*/
		if (Main_Figures_Positions[ChoosedFigure.y][ChoosedFigure.x] == -2) //Standart WHITE ROOK step.
		{
			//Up
			for (int i = ChoosedFigure.y; i >= 0; i--)
			{
				if (i - 1 >= 0)
				{
					if (Main_Figures_Positions[i - 1][ChoosedFigure.x] >= 0)
					{
						obj.Figures_Steps_Positions[i - 1][ChoosedFigure.x] = 1;
					}
					if (Main_Figures_Positions[i - 1][ChoosedFigure.x] != 0)
					{
						break;
					}
				}
			}
			//Down
			for (int i = ChoosedFigure.y; i < 8; i++)
			{
				if (i + 1 < 8)
				{
					if (Main_Figures_Positions[i + 1][ChoosedFigure.x] >= 0)
					{
						obj.Figures_Steps_Positions[i + 1][ChoosedFigure.x] = 1;
					}
					if (Main_Figures_Positions[i + 1][ChoosedFigure.x] != 0)
					{
						break;
					}
				}
			}
			//Left
			for (int i = ChoosedFigure.x; i >= 0; i--)
			{
				if (i - 1 >= 0)
				{
					if (Main_Figures_Positions[ChoosedFigure.y][i - 1] >= 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y][i - 1] = 1;
					}
					if (Main_Figures_Positions[ChoosedFigure.y][i - 1] != 0)
					{
						break;
					}
				}
			}
			//Right
			for (int i = ChoosedFigure.x; i < 8; i++)
			{
				if (i + 1 < 8)
				{
					if (Main_Figures_Positions[ChoosedFigure.y][i + 1] >= 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y][i + 1] = 1;
					}
					if (Main_Figures_Positions[ChoosedFigure.y][i + 1] != 0)
					{
						break;
					}
				}
			}
		}
		if (Main_Figures_Positions[ChoosedFigure.y][ChoosedFigure.x] == -3) //Standart WHITE HORSE step.
		{
			//Up
			if (ChoosedFigure.y - 2 >= 0 && ChoosedFigure.x + 1 < 8)
			{
				if (Main_Figures_Positions[ChoosedFigure.y - 2][ChoosedFigure.x + 1] >= 0)
				{
					obj.Figures_Steps_Positions[ChoosedFigure.y - 2][ChoosedFigure.x + 1] = 1;
				}
			}
			if (ChoosedFigure.y - 2 >= 0 && ChoosedFigure.x - 1 >= 0)
			{
				if (Main_Figures_Positions[ChoosedFigure.y - 2][ChoosedFigure.x - 1] >= 0)
				{
					obj.Figures_Steps_Positions[ChoosedFigure.y - 2][ChoosedFigure.x - 1] = 1;
				}
			}
			//Down
			if (ChoosedFigure.y + 2 < 8 && ChoosedFigure.x + 1 < 8)
			{
				if (Main_Figures_Positions[ChoosedFigure.y + 2][ChoosedFigure.x + 1] >= 0)
				{
					obj.Figures_Steps_Positions[ChoosedFigure.y + 2][ChoosedFigure.x + 1] = 1;
				}
			}
			if (ChoosedFigure.y + 2 < 8 && ChoosedFigure.x - 1 >= 0)
			{
				if (Main_Figures_Positions[ChoosedFigure.y + 2][ChoosedFigure.x - 1] >= 0)
				{
					obj.Figures_Steps_Positions[ChoosedFigure.y + 2][ChoosedFigure.x - 1] = 1;
				}
			}
			//Left
			if (ChoosedFigure.y + 1 < 8 && ChoosedFigure.x - 2 >= 0)
			{
				if (Main_Figures_Positions[ChoosedFigure.y + 1][ChoosedFigure.x - 2] >= 0)
				{
					obj.Figures_Steps_Positions[ChoosedFigure.y + 1][ChoosedFigure.x - 2] = 1;
				}
			}
			if (ChoosedFigure.y - 1 >= 0 && ChoosedFigure.x - 2 >= 0)
			{
				if (Main_Figures_Positions[ChoosedFigure.y - 1][ChoosedFigure.x - 2] >= 0)
				{
					obj.Figures_Steps_Positions[ChoosedFigure.y - 1][ChoosedFigure.x - 2] = 1;
				}
			}
			//Right
			if (ChoosedFigure.y + 1 < 8 && ChoosedFigure.x + 2 < 8)
			{
				if (Main_Figures_Positions[ChoosedFigure.y + 1][ChoosedFigure.x + 2] >= 0)
				{
					obj.Figures_Steps_Positions[ChoosedFigure.y + 1][ChoosedFigure.x + 2] = 1;
				}
			}
			if (ChoosedFigure.y - 1 >= 0 && ChoosedFigure.x + 2 < 8)
			{
				if (Main_Figures_Positions[ChoosedFigure.y - 1][ChoosedFigure.x + 2] >= 0)
				{
					obj.Figures_Steps_Positions[ChoosedFigure.y - 1][ChoosedFigure.x + 2] = 1;
				}
			}
		}
		if (Main_Figures_Positions[ChoosedFigure.y][ChoosedFigure.x] == -4) //Standart WHITE BISHOP step.
		{
			//Left up
			for (int i = 0; i < 8; i++)
			{
				if (ChoosedFigure.y - 1 - i >= 0 && ChoosedFigure.x - 1 - i >= 0)
				{
					if (Main_Figures_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x - 1 - i] == 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x - 1 - i] = 1;
					}
					if (Main_Figures_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x - 1 - i] > 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x - 1 - i] = 1;
						break;
					}
					if (Main_Figures_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x - 1 - i] != 0)
					{
						break;
					}

				}
			}
			//Right up
			for (int i = 0; i < 8; i++)
			{
				if (ChoosedFigure.y - 1 - i >= 0 && ChoosedFigure.x + 1 + i < 8)
				{
					if (Main_Figures_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x + 1 + i] == 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x + 1 + i] = 1;
					}
					if (Main_Figures_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x + 1 + i] > 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x + 1 + i] = 1;
						break;
					}
					if (Main_Figures_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x + 1 + i] != 0)
					{
						break;
					}
				}
			}
			//Left down
			for (int i = 0; i < 8; i++)
			{
				if (ChoosedFigure.y + 1 + i < 8 && ChoosedFigure.x - 1 - i >= 0)
				{
					if (Main_Figures_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x - 1 - i] == 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x - 1 - i] = 1;
					}
					if (Main_Figures_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x - 1 - i] > 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x - 1 - i] = 1;
						break;
					}
					if (Main_Figures_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x - 1 - i] != 0)
					{
						break;
					}
				}
			}
			//Right down
			for (int i = 0; i < 8; i++)
			{
				if (ChoosedFigure.y + 1 + i < 8 && ChoosedFigure.x + 1 + i < 8)
				{
					if (Main_Figures_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x + 1 + i] == 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x + 1 + i] = 1;
					}
					if (Main_Figures_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x + 1 + i] > 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x + 1 + i] = 1;
						break;
					}
					if (Main_Figures_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x + 1 + i] != 0)
					{
						break;
					}
				}
			}
		}
		if (Main_Figures_Positions[ChoosedFigure.y][ChoosedFigure.x] == -6) //Standart WHITE KING step.
		{
			//Left up
			if (ChoosedFigure.y - 1 >= 0 && ChoosedFigure.x - 1 >= 0)
			{
				if (Main_Figures_Positions[ChoosedFigure.y - 1][ChoosedFigure.x - 1] >= 0)
				{
					obj.Figures_Steps_Positions[ChoosedFigure.y - 1][ChoosedFigure.x - 1] = 1;
				}
			}
			//Right up
			if (ChoosedFigure.y - 1 >= 0 && ChoosedFigure.x + 1 < 8)
			{
				if (Main_Figures_Positions[ChoosedFigure.y - 1][ChoosedFigure.x + 1] >= 0)
				{
					obj.Figures_Steps_Positions[ChoosedFigure.y - 1][ChoosedFigure.x + 1] = 1;
				}
			}
			//Left down
			if (ChoosedFigure.y + 1 < 8 && ChoosedFigure.x - 1 >= 0)
			{
				if (Main_Figures_Positions[ChoosedFigure.y + 1][ChoosedFigure.x - 1] >= 0)
				{
					obj.Figures_Steps_Positions[ChoosedFigure.y + 1][ChoosedFigure.x - 1] = 1;
				}
			}
			//Right down
			if (ChoosedFigure.y + 1 < 8 && ChoosedFigure.x + 1 < 8)
			{
				if (Main_Figures_Positions[ChoosedFigure.y + 1][ChoosedFigure.x + 1] >= 0)
				{
					obj.Figures_Steps_Positions[ChoosedFigure.y + 1][ChoosedFigure.x + 1] = 1;
				}
			}
			//Up
			if (ChoosedFigure.y - 1 >= 0)
			{
				if (Main_Figures_Positions[ChoosedFigure.y - 1][ChoosedFigure.x] >= 0)
				{
					obj.Figures_Steps_Positions[ChoosedFigure.y - 1][ChoosedFigure.x] = 1;
				}
			}
			//Down
			if (ChoosedFigure.y + 1 < 8)
			{
				if (Main_Figures_Positions[ChoosedFigure.y + 1][ChoosedFigure.x] >= 0)
				{
					obj.Figures_Steps_Positions[ChoosedFigure.y + 1][ChoosedFigure.x] = 1;
				}
			}
			//Left
			if (ChoosedFigure.x - 1 >= 0)
			{
				if (Main_Figures_Positions[ChoosedFigure.y][ChoosedFigure.x - 1] >= 0)
				{
					obj.Figures_Steps_Positions[ChoosedFigure.y][ChoosedFigure.x - 1] = 1;
				}
			}
			//Right
			if (ChoosedFigure.x + 1 < 8)
			{
				if (Main_Figures_Positions[ChoosedFigure.y][ChoosedFigure.x + 1] >= 0)
				{
					obj.Figures_Steps_Positions[ChoosedFigure.y][ChoosedFigure.x + 1] = 1;
				}
			}
		}
		if (Main_Figures_Positions[ChoosedFigure.y][ChoosedFigure.x] == -5) //Standart WHITE QUEEN step.
		{
			//Up
			for (int i = ChoosedFigure.y; i >= 0; i--)
			{
				if (i - 1 >= 0)
				{
					if (Main_Figures_Positions[i - 1][ChoosedFigure.x] >= 0)
					{
						obj.Figures_Steps_Positions[i - 1][ChoosedFigure.x] = 1;
					}
					if (Main_Figures_Positions[i - 1][ChoosedFigure.x] != 0)
					{
						break;
					}
				}
			}
			//Down
			for (int i = ChoosedFigure.y; i < 8; i++)
			{
				if (i + 1 < 8)
				{
					if (Main_Figures_Positions[i + 1][ChoosedFigure.x] >= 0)
					{
						obj.Figures_Steps_Positions[i + 1][ChoosedFigure.x] = 1;
					}
					if (Main_Figures_Positions[i + 1][ChoosedFigure.x] != 0)
					{
						break;
					}
				}
			}
			//Left
			for (int i = ChoosedFigure.x; i >= 0; i--)
			{
				if (i - 1 >= 0)
				{
					if (Main_Figures_Positions[ChoosedFigure.y][i - 1] >= 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y][i - 1] = 1;
					}
					if (Main_Figures_Positions[ChoosedFigure.y][i - 1] != 0)
					{
						break;
					}
				}
			}
			//Right
			for (int i = ChoosedFigure.x; i < 8; i++)
			{
				if (i + 1 < 8)
				{
					if (Main_Figures_Positions[ChoosedFigure.y][i + 1] >= 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y][i + 1] = 1;
					}
					if (Main_Figures_Positions[ChoosedFigure.y][i + 1] != 0)
					{
						break;
					}
				}
			}
			//Left up
			for (int i = 0; i < 8; i++)
			{
				if (ChoosedFigure.y - 1 - i >= 0 && ChoosedFigure.x - 1 - i >= 0)
				{
					if (Main_Figures_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x - 1 - i] == 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x - 1 - i] = 1;
					}
					if (Main_Figures_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x - 1 - i] > 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x - 1 - i] = 1;
						break;
					}
					if (Main_Figures_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x - 1 - i] != 0)
					{
						break;
					}

				}
			}
			//Right up
			for (int i = 0; i < 8; i++)
			{
				if (ChoosedFigure.y - 1 - i >= 0 && ChoosedFigure.x + 1 + i < 8)
				{
					if (Main_Figures_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x + 1 + i] == 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x + 1 + i] = 1;
					}
					if (Main_Figures_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x + 1 + i] > 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x + 1 + i] = 1;
						break;
					}
					if (Main_Figures_Positions[ChoosedFigure.y - 1 - i][ChoosedFigure.x + 1 + i] != 0)
					{
						break;
					}
				}
			}
			//Left down
			for (int i = 0; i < 8; i++)
			{
				if (ChoosedFigure.y + 1 + i < 8 && ChoosedFigure.x - 1 - i >= 0)
				{
					if (Main_Figures_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x - 1 - i] == 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x - 1 - i] = 1;
					}
					if (Main_Figures_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x - 1 - i] > 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x - 1 - i] = 1;
						break;
					}
					if (Main_Figures_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x - 1 - i] != 0)
					{
						break;
					}
				}
			}
			//Right down
			for (int i = 0; i < 8; i++)
			{
				if (ChoosedFigure.y + 1 + i < 8 && ChoosedFigure.x + 1 + i < 8)
				{
					if (Main_Figures_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x + 1 + i] == 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x + 1 + i] = 1;
					}
					if (Main_Figures_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x + 1 + i] > 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x + 1 + i] = 1;
						break;
					}
					if (Main_Figures_Positions[ChoosedFigure.y + 1 + i][ChoosedFigure.x + 1 + i] != 0)
					{
						break;
					}
				}
			}
		}
		if (Main_Figures_Positions[ChoosedFigure.y][ChoosedFigure.x] == -1) //WHITE PAWN step.
		{
			if (ChoosedFigure.y == 6) //First WHITE PAWN step.
			{
				if (ChoosedFigure.y - 1 >= 0)
				{
					if (Main_Figures_Positions[ChoosedFigure.y - 1][ChoosedFigure.x] == 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y - 1][ChoosedFigure.x] = 1;
						if (ChoosedFigure.y - 2 >= 0)
						{
							if (Main_Figures_Positions[ChoosedFigure.y - 2][ChoosedFigure.x] == 0)
							{
								obj.Figures_Steps_Positions[ChoosedFigure.y - 2][ChoosedFigure.x] = 1;
							}
						}	
					}
				}
				if (ChoosedFigure.y - 1 >= 0 && ChoosedFigure.x - 1 >= 0)
				{
					if (Main_Figures_Positions[ChoosedFigure.y - 1][ChoosedFigure.x - 1] > 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y - 1][ChoosedFigure.x - 1] = 1;
					}
				}
				if (ChoosedFigure.y - 1 >= 0 && ChoosedFigure.x + 1 < 8)
				{
					if (Main_Figures_Positions[ChoosedFigure.y - 1][ChoosedFigure.x + 1] > 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y - 1][ChoosedFigure.x + 1] = 1;
					}
				}
			}
			if (ChoosedFigure.y != 6) //Standart WHITE PAWN step.
			{
				if (ChoosedFigure.y - 1 >= 0)
				{
					if (Main_Figures_Positions[ChoosedFigure.y - 1][ChoosedFigure.x] == 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y - 1][ChoosedFigure.x] = 1;
					}
				}
				if (ChoosedFigure.y - 1 >= 0 && ChoosedFigure.x - 1 >= 0)
				{
					if (Main_Figures_Positions[ChoosedFigure.y - 1][ChoosedFigure.x - 1] > 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y - 1][ChoosedFigure.x - 1] = 1;
					}
				}
				if (ChoosedFigure.y - 1 >= 0 && ChoosedFigure.x + 1 < 8)
				{
					if (Main_Figures_Positions[ChoosedFigure.y - 1][ChoosedFigure.x + 1] > 0)
					{
						obj.Figures_Steps_Positions[ChoosedFigure.y - 1][ChoosedFigure.x + 1] = 1;
					}
				}
			}
		}
	}

	/*If new choosed figure coordinate not equal to old
	make all step positions equal to zero.*/
	if (ChoosedFigure_Buffer != ChoosedFigure) 
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				obj.Figures_Steps_Positions[i][j] = 0;
			}
		}
	}

	/*Right click.
	Make all step positions array equal to zero after right click.*/
	if (check == true) 
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				obj.Figures_Steps_Positions[i][j] = 0;
			}
		}
	}
	ChoosedFigure_Buffer = ChoosedFigure;
}

Figures::~Figures()
{
}
