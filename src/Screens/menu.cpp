#include "menu.h"

#include "controls.h"
#include "gameplay.h"
#include "Palette.h"

namespace Arkanoid
{
	static const Color normalColorRec = RED;
	static void DrawMenu();
	static void CheckColorInput();
	static void UpdateMenu();
	static void DrawPlayButton();
	static void DrawControlsButton();

	void RunMenu()
	{
		UpdateMenu();
	}
	static void DrawMenu()
	{
		DrawPlayButton();
		DrawControlsButton();
		DrawText("Arkanoid", 305, 50, 40, RAYWHITE);
		DrawText("v1.0", 760, 430, 20, RAYWHITE);
	}
	static void DrawPlayButton()
	{
		if (GetMouseX() >= 358 && GetMouseX() <= 358 + 80 && GetMouseY() >= 170 && GetMouseY() <= 170 + 40)
		{
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				menu = false;
				playing = true;	
			}
			DrawRectangle(358, 170, 80, 40, RAYWHITE);
			DrawText("Play", 375, 180, 20, BLACK);
		}
		else
		{
			DrawRectangle(358, 170, 80, 40, normalColorRec);
			DrawText("Play", 375, 180, 20, RAYWHITE);
		}
	}

	static void DrawControlsButton()
	{
		if (GetMouseX() >= 350 && GetMouseX() <= 345 + 100 && GetMouseY() >= 240 && GetMouseY() <= 240 + 40)
		{
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				menu = false;
				controls = true;
			}
			DrawRectangle(350, 240, 100, 40, RAYWHITE);
			DrawText("Contorls", 355, 250, 20, BLACK);
		}
		else
		{
			DrawRectangle(350, 240, 100, 40, BLUE);
			DrawText("Contorls", 355, 250, 20, RAYWHITE);
		}
	}
	static void CheckColorInput()
	{
		CheckColorPlayer1Right();
		CheckColorPlayer1Left();
	}
	void UpdateMenu()
	{
		// Check Input and Update
		//----------------------------------------------------------
		CheckColorInput();
		
		DrawMenu();
		DrawRectangleRec(boxP1, boxP1.color);

		
	}

}

