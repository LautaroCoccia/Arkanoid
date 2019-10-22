#include "Palette.h"

#include "ball.h"
#include "bricks.h"

namespace Arkanoid
{
	bool menu = true;
	bool playing = false;
	bool pause = false;
	static void UpdateGame();
	static void CheckWin();
	static void CheckColisionBallPlayers();
	static void PauseGame();
	static const float musicStreamMenu = 0.2f;
	Music music;

	void LoadMusic()
	{
		music = LoadMusicStream("assets/sounds/music.ogg");
		SetMusicVolume(music, musicStreamMenu);
		PlayMusicStream(music);
	}
	void UnloadMyMusic()
	{
		UnloadMusicStream(music);
	}
	void RunGame()
	{

		UpdateGame();
	}

	static void UpdateGame()
	{

		PauseGame();
		if (!pause)
		{
			UpdateMusicStream(music);
			CheckPlayerMovement();
			Arkanoid::CheckBallWallsLimit();
			CheckColisionBallPlayers();
			CheckCollisionBricks();
		}
		else if (pause)
		{
			DrawText("PAUSED ", 320, 170, 40, RAYWHITE);
		}

		DrawPlayersPoints();
		DrawRectangleRec(boxP1, boxP1.color);
		DrawBricks();
		Arkanoid::DrawMyBall();

		CheckWin();
	}

	static void CheckWin()
	{
		if (bricksActive == zeroBricks || lifePoints < livesMin)
		{
			playing = false;
		}
	}

	static void CheckColisionBallPlayers()
	{

		if (CheckCollisionCircleRec(Arkanoid::ball.ballPosition, Arkanoid::ball.ballRadius, boxP1))
		{
			Arkanoid::ball.ballPosition.y = boxP1.y - Arkanoid::ball.ballRadius;
			Arkanoid::ball.ballColor = boxP1.color;
			Arkanoid::ball.ballSpeed.y *= Arkanoid::changeDirectionY;
			PlaySound(Arkanoid::colisionSound);
		}
		Arkanoid::ball.ballPosition.x += Arkanoid::ball.ballSpeed.x * GetFrameTime();
		Arkanoid::myBoundingBox.x = Arkanoid::ball.ballPosition.x - Arkanoid::ball.ballRadius;
		Arkanoid::ball.ballPosition.y += Arkanoid::ball.ballSpeed.y * GetFrameTime();
		Arkanoid::myBoundingBox.y = Arkanoid::ball.ballPosition.y - Arkanoid::ball.ballRadius;
	}
	static void PauseGame()
	{
		if (IsKeyPressed('P'))
		{
			pause = !pause;

		}

	}
}
