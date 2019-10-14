#include "../Objects/Palette.h"
#include "../Objects/ball.h"
#include "../Objects/bricks.h"
bool menu = true;
bool playing = false;
bool pause = false;
static void UpdateGame();
static void CheckWin();
static void SetGameAspectRatio();
static void CheckColisionBallPlayers();
static bool PauseGame();

void RunGame()
{
	UpdateGame();
}

static void UpdateGame()
{
	if (!PauseGame())
	{
		CheckPlayerMovement();
		BallObj::CheckBallWallsLimit();
		CheckColisionBallPlayers();
		CheckCollisionBricks();
	}
	else if (PauseGame)
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
	}
	BallObj::ball.ballPosition.x += BallObj::ball.ballSpeed.x * GetFrameTime();
	BallObj::myBoundingBox.x = BallObj::ball.ballPosition.x - BallObj::ball.ballRadius;
	BallObj::ball.ballPosition.y += BallObj::ball.ballSpeed.y * GetFrameTime();
	BallObj::myBoundingBox.y = BallObj::ball.ballPosition.y - BallObj::ball.ballRadius;
}
static bool PauseGame()
{
	if (IsKeyPressed('P'))
	{
		pause = !pause;
	}
	return pause;
}