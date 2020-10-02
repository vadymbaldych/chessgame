#include "Player.h"

Player::Player(String file_M, int w, int h, String file_E)
{
	File_Mouse = file_M;
	File_Empty = file_E;
	W = w;
	H = h;

	Texture_Mouse.loadFromFile("Resources/Mouse/" + File_Mouse);
	Sprite_Mouse.setTexture(Texture_Mouse);
	Sprite_Mouse.setTextureRect(IntRect(0, 0, W, H));
	
	Texture_Empty.loadFromFile("Resources/Mouse/" + File_Empty);
	Sprite_Empty.setTexture(Texture_Empty);
	Sprite_Empty.setTextureRect(IntRect(0, 0, W, H));
}

void Player::UpdateFrame(float time, RenderWindow &window, bool check)
{
	/*Animation for mouse rectangle contour.*/
	CurrentFrame += 0.001 * time;
	if (CurrentFrame > 2)
	{
		CurrentFrame -= 2;
	}
	Sprite_Mouse.setTextureRect(IntRect(0, 128 * int(CurrentFrame), W, H));

	/*Getting mouse position, then divide it on 128, coordinates from (450, 670) to (3, 5)*/
	MousePosition = Mouse::getPosition(window);
	MousePosition = MousePosition / 128;

	/*Mouse contour will stay only on the board.
	If mouse not on boad it will continue it is 
	way, but only on ht board.*/
	if (MousePosition.x > 7)
	{
		MousePosition.x = 7;
	}
	if (MousePosition.x < 0)
	{
		MousePosition.x = 0;
	}
	if (MousePosition.y > 7)
	{
		MousePosition.y = 7;
	}
	if (MousePosition.y < 0)
	{
		MousePosition.y = 0;
	}

	/*Contour move only if check variable is true*/
	if (check == true)
	{
		Sprite_Mouse.setPosition(MousePosition.x * W, MousePosition.y * H);
	}

	/*Draw ways contour*/
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Figures_Steps_Positions[i][j] == 1)
			{
				Figures_Steps[i][j].setTexture(Texture_Mouse);
				Figures_Steps[i][j].setTextureRect(IntRect(0, 0, W, H));
				Figures_Steps[i][j].setPosition(j * W, i * H);
			}
			if (Figures_Steps_Positions[i][j] == 0)
			{
				Figures_Steps[i][j].setTexture(Texture_Empty);
				Figures_Steps[i][j].setTextureRect(IntRect(0, 0, W, H));
				Figures_Steps[i][j].setPosition(j * W, i * H);
			}
		}
	}

	/*Animations for ways contours*/
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Figures_Steps[i][j].setTextureRect(IntRect(0, 128 * int(CurrentFrame), W, H));
		}
	}
}

Player::~Player()
{
}
