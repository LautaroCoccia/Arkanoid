#include "menu.h"

#include "gameplay.h"
#include "Palette.h"
static void DrawMenu();
static void CheckColorInput();
static void UpdateMenu();

void RunMenu()
{
	UpdateMenu();
}
static void DrawMenu()
{
	DrawText("Arkanoid", 305, 50, 40, RAYWHITE);
	DrawText("Select color using <- Or -> arrows", 230, 90, 20, RAYWHITE);
	DrawText("Contorls: Pause: \"P\" ", 295, 120, 20, RAYWHITE);
	DrawText("Movement: <- Or -> arrows ", 270, 150, 20, RAYWHITE);
	DrawText("Press Enter", 330, 180, 20, RAYWHITE);
	DrawText("Created by: Lautaro Coccia ", 270, 200, 20, RAYWHITE);
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
	
	if (IsKeyPressed(KEY_ENTER))
	{
		menu = false;
		playing = true;
	}
}