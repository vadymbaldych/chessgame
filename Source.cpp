#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <windows.h>
#include "Board.h"
#include "Figures.h"
#include "Player.h"
#include "Winner.h"

using namespace sf;
using namespace std;

int main()
{
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
	Vector2i Resolution(1152, 1024);
	RenderWindow Window(VideoMode(Resolution.x, Resolution.y), "Chess by Vadym Baldych", Style::Close);
	Window.setFramerateLimit(60);
	Window.setPosition(Vector2i(480, 25));

	Board GameBoard("DarkSquare_128px.png", "LightSquare_128px.png", 128, 128);
	Figures GameFigures("D_Rook_128px.png", "D_Hourse_128px.png", "D_Bishop_128px.png", "D_King_128px.png", "D_Queen_128px.png", 
						"L_Rook_128px.png", "L_Hourse_128px.png", "L_Bishop_128px.png", "L_King_128px.png", "L_Queen_128px.png", 
						"D_Pawn_128px.png", "L_Pawn_128px.png", 128, 128, "Empty.png");
	Player GamePlayer("MouseGlow.png", 128, 128, "Empty.png");
	Winner GameWinner("WinnerWhite.png", "WinnerBlack.png", 1024, 1024);

	Clock GameClock;

	String Turn_White = "WHITE";
	String Turn_Black = "BLACK";

	Font font;
	font.loadFromFile("Lucida Grande.ttf");

	Text turn_text("", font, 38);
	turn_text.setStyle(Text::Bold);
	String Game_Turn = Turn_White;

	int Start_Positions[8][8] =
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

	int TimeSpeed = 500;

	bool Check = true;

	while (Window.isOpen())
	{
		float Time = GameClock.getElapsedTime().asMicroseconds();
		GameClock.restart();
		Time = Time / TimeSpeed;

		Event event;
		while (Window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				Window.close();
			/*Restart game with making start positions and turn.*/
			if (event.type == event.KeyReleased && event.key.code == Keyboard::Tab) 
			{
				Game_Turn = Turn_White;
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						GameFigures.Main_Figures_Positions[i][j] = Start_Positions[i][j];
					}
				}
			}
			/*Exit from game*/
			if (event.type == event.KeyReleased && event.key.code == Keyboard::Escape)
			{
				return 0;
			}

			if (event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left)
			{
				cout << GamePlayer.MousePosition.x << "  MOUSE_CLICK_LEFT  " << GamePlayer.MousePosition.y << endl;

				/*If i click left mouse button on another figure, and 
				contour was fixed, contour will move to the new
				choosed position. It is saves choosed figure coordinate
				from mouse coordinate (1). It is setting contour in new position (2)*/
				if (Game_Turn == Turn_White)
				{
					if (Check == false && GameFigures.Main_Figures_Positions[GamePlayer.MousePosition.y][GamePlayer.MousePosition.x] < 0) //Only white figures 
					{
						GameFigures.ChoosedFigure = GamePlayer.MousePosition; //(1)
						GamePlayer.Sprite_Mouse.setPosition(GamePlayer.MousePosition.x * GamePlayer.W, GamePlayer.MousePosition.y * GamePlayer.H); //(2)
					}
				}
				if (Game_Turn == Turn_Black)
				{
					if (Check == false && GameFigures.Main_Figures_Positions[GamePlayer.MousePosition.y][GamePlayer.MousePosition.x] > 0) //Only black figures
					{
						GameFigures.ChoosedFigure = GamePlayer.MousePosition; //(1)
						GamePlayer.Sprite_Mouse.setPosition(GamePlayer.MousePosition.x * GamePlayer.W, GamePlayer.MousePosition.y * GamePlayer.H); //(2)
					}
				}

				/*If i click left mouse button first time or after step
				check variable became false (1) and contour became fixed on 
				choosed figure. It is saves choosed figure coordinate
				from mouse coordinate (2).*/
				if (Game_Turn == Turn_White)
				{
					if (Check == true && GameFigures.Main_Figures_Positions[GamePlayer.MousePosition.y][GamePlayer.MousePosition.x] < 0) //Only white figures
					{
						GameFigures.ChoosedFigure = GamePlayer.MousePosition; //(2)
						Check = false; //(1)
					}
				}
				if (Game_Turn == Turn_Black)
				{
					if (Check == true && GameFigures.Main_Figures_Positions[GamePlayer.MousePosition.y][GamePlayer.MousePosition.x] > 0) //Only black figures
					{
						GameFigures.ChoosedFigure = GamePlayer.MousePosition; //(2)
						Check = false; //(1)
					}
				}

				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						cout << setw(3) << GameFigures.Main_Figures_Positions[i][j];
					}	
					cout << endl;
				}
				cout << "CHECK: "  << Check << endl;
			}
			if (event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Right)
			{
				cout << GamePlayer.MousePosition.x << "  MOUSE_CLICK_RIGHT  " << GamePlayer.MousePosition.y << endl;
				
				/*If i click right mouse button when contour is fixed,
				we move figure to the right clicked cell (1), previous
				cell became empty (2). If i click on cell with black figure with 
				choosed white figure (3). If i click on cell with white figure
				with choosed black figure (4)*/
				if (GamePlayer.Figures_Steps_Positions[GamePlayer.MousePosition.y][GamePlayer.MousePosition.x] == 1 && Check == false) //First part of if - allow player set position on special way 
				{
					Check = true;
					if (GameFigures.ChoosedFigure != GamePlayer.MousePosition)
					{
						if (GameFigures.Main_Figures_Positions[GamePlayer.MousePosition.y][GamePlayer.MousePosition.x] >= 0 && GameFigures.Main_Figures_Positions[GameFigures.ChoosedFigure.y][GameFigures.ChoosedFigure.x] < 0 || //(3)
							GameFigures.Main_Figures_Positions[GamePlayer.MousePosition.y][GamePlayer.MousePosition.x] <= 0 && GameFigures.Main_Figures_Positions[GameFigures.ChoosedFigure.y][GameFigures.ChoosedFigure.x] > 0) //(4)
						{
							GameFigures.Main_Figures_Positions[GamePlayer.MousePosition.y][GamePlayer.MousePosition.x] = GameFigures.Main_Figures_Positions[GameFigures.ChoosedFigure.y][GameFigures.ChoosedFigure.x]; //(1)
							GameFigures.Main_Figures_Positions[GameFigures.ChoosedFigure.y][GameFigures.ChoosedFigure.x] = 0; //(2)
						}
					}

					/*Change turn.
					After right click it check for game turn,
					if it is white it became black, it became
					white, if it was black or game was restarted*/
					if (Game_Turn == Turn_White) 
					{
						Game_Turn = Turn_Black;
					}
					else
					{
						Game_Turn = Turn_White;
					}
				}

				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						cout << setw(3) << GameFigures.Main_Figures_Positions[i][j];
					}
					cout << endl;
				}
				cout << "CHECK: " << Check << endl;
			}
		}

		GameFigures.DrawSteps(GamePlayer, Check);
		GamePlayer.UpdateFrame(Time, Window, Check);
		GameFigures.UpdateFigures();

		Window.clear();
		/*Here we setting up text with turn
		in main programm window.*/
		turn_text.setString(Game_Turn);
		turn_text.setPosition(1024, 512);
		Window.draw(turn_text);
	
		/*It draw arrays with sprites
		for board with black and white cells (1)
		and figures on the board (2)*/
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				Window.draw(GameBoard.Main_Board[i][j]); //(1)
			}
		}
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				Window.draw(GameFigures.Main_Figures[i][j]); //(2)
			}
		}

		/*Draw current mouse positiopn square (1).
		Draw figures ways from array (2).*/
		Window.draw(GamePlayer.Sprite_Mouse); //(1)
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				Window.draw(GamePlayer.Figures_Steps[i][j]); //(2)
			}
		}

		/*Check king figure to set a winner*/
		if (GameWinner.CheckWinner(GameFigures) == -1)
		{
			Window.draw(GameWinner.Sprite_Winner_White);
			GamePlayer.MousePosition.y = 10;
			GamePlayer.MousePosition.x = 10;
		}
		if (GameWinner.CheckWinner(GameFigures) == 1)
		{
			Window.draw(GameWinner.Sprite_Winner_Black);
			GamePlayer.MousePosition.y = 10;
			GamePlayer.MousePosition.x = 10;
		}
		if (GameWinner.CheckWinner(GameFigures) == 0)
		{
			//
		}

		Window.display();
	}
	return 0;
}

