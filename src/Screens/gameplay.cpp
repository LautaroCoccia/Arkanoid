#include "Palette.h"

#include "ball.h"
#include "bricks.h"

#include <iostream>
using namespace std;
bool menu = true;
bool playing = false;
bool pause = false;
static void UpdateGame();
static void CheckWin();
static void SetGameAspectRatio();
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
		BallObj::CheckBallWallsLimit();
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
	BallObj::DrawMyBall();
	
	CheckWin();
}

static void CheckWin()
{
	if (bricksActive == zeroBricks|| lifePoints< livesMin)
	{
		playing = false;
	}
}

static void CheckColisionBallPlayers()
{

	if (CheckCollisionCircleRec(BallObj::ball.ballPosition, BallObj::ball.ballRadius, boxP1))
	{
		BallObj::ball.ballPosition.y =  boxP1.y - BallObj::ball.ballRadius;
		BallObj::ball.ballColor = boxP1.color;
		BallObj::ball.ballSpeed.y *= BallObj::changeDirectionY;
		PlaySound(BallObj::colisionSound);
	}
	BallObj::ball.ballPosition.x += BallObj::ball.ballSpeed.x * GetFrameTime();
	BallObj::myBoundingBox.x = BallObj::ball.ballPosition.x - BallObj::ball.ballRadius;
	BallObj::ball.ballPosition.y += BallObj::ball.ballSpeed.y * GetFrameTime();
	BallObj::myBoundingBox.y = BallObj::ball.ballPosition.y - BallObj::ball.ballRadius;
}
static void PauseGame()
{
	if (IsKeyPressed('P'))
	{
		pause = !pause;

	}
	
}