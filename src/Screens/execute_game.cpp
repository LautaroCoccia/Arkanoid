#include "execute_game.h"

#include "ball.h"
#include "bricks.h"
#include "gameplay.h"
#include "game_over.h"
#include "menu.h"

void ExecuteGame()
{
	InitWindow(800,450, "Arkanoid.exe - Lautaro Coccia");
	// Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------
	SetTargetFPS(60);

	InitAudioDevice();
	LoadMusic();
	BallObj::LoadColisionSound();
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
	BallObj::UnloadMySound();
	UnloadMyMusic();
	CloseWindow();
}