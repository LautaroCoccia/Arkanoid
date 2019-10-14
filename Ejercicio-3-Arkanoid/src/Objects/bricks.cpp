#include "bricks.h"
#include "ball.h"

bool activateBricks;
Vector2 brickSize;
Rectangle bricks[linesOfBricks][bricksPerLine];
using namespace std;
int bricksActive = zeroBricks;
void InitBricksAtributes()
{
	activateBricks = true;
	brickSize = { (float)(GetScreenWidth() / bricksPerLine), 40 };
	InitBricksPosition();
	
}
void InitBricksPosition() 
{
	if (activateBricks)
	{
		for (int i = zeroBricks; i < linesOfBricks; i++)
		{
			for (int j = zeroBricks; j < bricksPerLine; j++)
			{
				bricks[i][j].width = halfBrickSizeX;
				bricks[i][j].height = halfBrickSizeY;
				bricks[i][j].x = j * brickSize.x + halfBrickSizeX;
				bricks[i][j].y = i * brickSize.y + initialDownPosition;
				bricks[i][j].active = true;
				bricksActive++;

				
			}
			
		}
		activateBricks = false;
	}
	
}
void CheckCollisionBricks()
{
	for (int i = zeroBricks; i < linesOfBricks; i++)
	{
		for (int j = zeroBricks; j < bricksPerLine; j++)
		{
			if (bricks[i][j].active && (BallObj::myBoundingBox.x >= bricks[i][j].x - BallObj::ball.ballRadius && BallObj::ball.ballPosition.x <= bricks[i][j].x + bricks[i][j].width) && BallObj::ball.ballPosition.y <= bricks[i][j].y + bricks[i][j].height + BallObj::ball.ballRadius
				&& BallObj::ball.ballSpeed.y < zeroBricks)
			{
				bricks[i][j].active = false;
				BallObj::ball.ballSpeed.y *= BallObj::changeDirectionY;
				bricksActive--;
			}
			
		}
	}
}

void DrawBricks() 
{
	for (int i = zeroBricks; i < linesOfBricks; i++)
	{
		for (int j = zeroBricks; j < bricksPerLine; j++)
		{

			if (bricks[i][j].active)
			{
				if ((i + j) % 2 == zeroBricks) DrawRectangle(static_cast<int>(bricks[i][j].x - halfBrickSizeX), static_cast<int>(bricks[i][j].y - halfBrickSizeY), static_cast<int>(brickSize.x), static_cast<int>(brickSize.y), GRAY);
				else DrawRectangle(static_cast<int>(bricks[i][j].x - halfBrickSizeX), static_cast<int>(bricks[i][j].y - halfBrickSizeY), static_cast<int>(brickSize.x), static_cast<int>(brickSize.y), DARKGRAY);
				
			}
		}
	}

}
