#include "bricks.h"

#include "ball.h"

namespace Arkanoid
{
	bool activateBricks;
	int bricksActive = zeroBricks;
	const int zeroBricks = 0;
	Vector2 brickSize;
	Rectangle bricks[linesOfBricks][bricksPerLine];

	void InitBricksAtributes()
	{
		activateBricks = true;
		brickSize =
		{
			static_cast<float>(GetScreenWidth() / bricksPerLine),40
		};
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
				if (bricks[i][j].active && (Arkanoid::myBoundingBox.x >= bricks[i][j].x - Arkanoid::ball.ballRadius && Arkanoid::ball.ballPosition.x <= bricks[i][j].x + bricks[i][j].width) && Arkanoid::ball.ballPosition.y <= bricks[i][j].y + bricks[i][j].height + Arkanoid::ball.ballRadius
					&& Arkanoid::ball.ballSpeed.y < zeroBricks)
				{
					bricks[i][j].active = false;
					Arkanoid::ball.ballSpeed.y *= Arkanoid::changeDirectionY;
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
					if ((i + j) % 2 == zeroBricks)
					{
						DrawRectangle(static_cast<int>(bricks[i][j].x - halfBrickSizeX),
							static_cast<int>(bricks[i][j].y - halfBrickSizeY),
							static_cast<int>(brickSize.x), static_cast<int>(brickSize.y),
							GRAY);
					}
					else
					{
						DrawRectangle(static_cast<int>(bricks[i][j].x - halfBrickSizeX),
							static_cast<int>(bricks[i][j].y - halfBrickSizeY),
							static_cast<int>(brickSize.x), static_cast<int>(brickSize.y),
							DARKGRAY);
					}
				}
			}
		}

	}
}

