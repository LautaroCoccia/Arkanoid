#include "Game_over.h"

#include "raylib.h"
#include "gameplay.h"
#include "../Objects/Palette.h"
#include "../Objects/bricks.h"
#include "../Objects/ball.h"


static void UpdateGameOver();
static void DrawGameOver();

void RunGameOver()
{
	UpdateGameOver();
}
static void DrawGameOver()
{
	if (bricksActive == zeroBricks)
	{
		DrawText("YOU WIN!!", 350, 50, 20, RAYWHITE),
		DrawText("PRESS \"ENTER\" TO RETURN MENU", 210, 100, 20, RAYWHITE),
		DrawText("PRESS \"ESCAPE\" TO CLOSE GAME", 210, 150, 20, RAYWHITE);
		DrawText("PRESS \"ESCAPE\" TO CLOSE GAME", 210, 150, 20, RAYWHITE);
	}	
	else if (lifePoints < livesMin)
	{
		DrawText("YOU LOSE!!", 340, 50, 20, RAYWHITE),
		DrawText("PRESS \"ENTER\" TO RETURN MENU", 210, 100, 20, RAYWHITE),
		DrawText("PRESS \"ESCAPE\" TO CLOSE GAME", 210, 150, 20, RAYWHITE);
	}
	
}
static void UpdateGameOver()
{
	DrawGameOver();
	if (IsKeyDown(KEY_ENTER)) menu = !menu, InitRecPositionNScore(), InitRecColor(),
		InitBricksAtributes(), BallObj::InitBall(), lifePoints = livesMax;
}