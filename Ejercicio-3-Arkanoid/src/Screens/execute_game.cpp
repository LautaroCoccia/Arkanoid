#include "execute_game.h"
#include "menu.h"
#include "gameplay.h"
#include "../Objects/ball.h"
#include "../Objects/bricks.h"
#include "game_over.h"
void ExecuteGame()
{
	InitWindow(800,450, "Arkanoid.exe - Lautaro Coccia");
	// Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------
	SetTargetFPS(60);
	BallObj::InitBall();
	InitBricksAtributes();
	while (!WindowShouldClose() || IsKeyPressed(KEY_ESCAPE))
	{
		BeginDrawing();
		ClearBackground(BLACK);
		if (menu)
		{
			RunMenu();
		}
		else if (playing)
		{
			RunGame();
		}
		else if (!playing)
		{
			RunGameOver();
		}
		EndDrawing();
	}
}