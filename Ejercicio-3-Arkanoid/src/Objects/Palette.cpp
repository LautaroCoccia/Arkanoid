#include "Palette.h"
const int maxColors = 5;
const int limit = 2;
const float rectangleMovement = 10.0f;

enum Colors
{
	color0 = 0,
	color1,
	color2,
	color3,
	color4
};
enum Seleccion
{
	selection0 = 0,
	selection1,
	selection2,
	selection3,
	selection4
};
Color colorOptions[maxColors] = { BLUE,GOLD, RED, GREEN, PURPLE };
Rectangle boxP1 = { static_cast<float>(halfScreenWidth) - static_cast<float>(halfRectangleWidth), static_cast<float>(BaseScreenHeight)-(rectangleHeight + rectangleHeight + rectangleHeight) , rentangleWidth, rectangleHeight };

int lifePoints = livesMax;
int colorP1 = color0;
static void SetColorPlayer1();

void InitRecColor()
{
	SetColorPlayer1();
}
static void SetColorPlayer1()
{
	boxP1.color = colorOptions[colorP1];
}


void CheckColorPlayer1Right()
{
	if (IsKeyPressed(KEY_RIGHT))
	{
		if (colorP1 < selection4)
		{
			colorP1 = (colorP1 + selection1);
			boxP1.color = colorOptions[colorP1];
		}
		else
		{
			colorP1 = selection0;
			boxP1.color = colorOptions[colorP1];
		}
	}
	
	SetColorPlayer1();
}

void CheckColorPlayer1Left()
{
	if (IsKeyPressed(KEY_LEFT))
	{
		if (colorP1 > selection0)
		{
			colorP1 = (colorP1 - selection1);
			boxP1.color = colorOptions[colorP1];
		}
		else
		{
			colorP1 = selection4;
			boxP1.color = colorOptions[colorP1];
		}
	}
	SetColorPlayer1();
}



void CheckPlayerMovement()
{
	//Player 1
	//----------------------------------------------------------------------------------
	if (IsKeyDown(KEY_LEFT) && boxP1.x > (limit)) boxP1.x -= rectangleMovement;
	if (IsKeyDown(KEY_RIGHT) && boxP1.x < (BaseScreenWidth - rentangleWidth )) boxP1.x += rectangleMovement;
	
}

void InitRecPositionNScore()
{
	lifePoints = livesMax;
	boxP1 = { static_cast<float>(halfScreenWidth) - static_cast<float>(halfRectangleWidth), static_cast<float>(BaseScreenHeight) - (rectangleHeight + rectangleHeight + rectangleHeight) , rentangleWidth, rectangleHeight };
	
}

void DrawPlayersPoints()
{
	DrawText(TextFormat("Lives: %i", lifePoints), 10, 10, 20, RAYWHITE);
}
