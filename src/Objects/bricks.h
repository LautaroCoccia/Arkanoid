#ifndef BRICKS_H
#define BRICKS_H
#include "raylib.h"

namespace Arkanoid
{
	const int linesOfBricks = 3;
	const int bricksPerLine = 16;
	const float brickWidth = static_cast<float>((800 / bricksPerLine) - linesOfBricks);
	const float halfBrickSizeX = brickWidth / 2;
	const float brickHeight = 40.0f;
	const float halfBrickSizeY = brickHeight / 2;
	const int initialDownPosition = 50;
	extern int bricksActive;
	extern bool activateBricks;
	extern const int zeroBricks;
	extern bool activateBricks;
	extern Vector2 brickSize;
	extern Rectangle bricks[linesOfBricks][bricksPerLine];
	extern void InitBricksAtributes();
	extern void InitBricksPosition();
	extern void CheckCollisionBricks();
	extern void DrawBricks();
}
#endif

