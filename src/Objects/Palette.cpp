#include "Palette.h"

namespace Arkanoid
{
	static const int maxColors = 5;
	static const int limit = 2;
	static const float rectangleMovement = 10.0f;
	const int livesMax = 3;
	const int livesMin = 1;
	const int rectangleHeight = 10;
	const int rentangleWidth = 120;
	const int halfRectangleHeight = rectangleHeight / 2;
	const int halfRectangleWidth = rentangleWidth / 2;

	enum Colors
	{
		color0 = 0,
		color1,
		color2,
		color3,
		color4
	};
	enum Selection
	{
		selection0 = 0,
		selection1,
		selection2,
		selection3,
		selection4
	};
	Color colorOptions[maxColors] = { BLUE,GOLD, RED, GREEN, PURPLE };
	Rectangle boxP1 =
	{
		static_cast<float>(halfScreenWidth) - static_cast<float>(halfRectangleWidth),
		static_cast<float>(BaseScreenHeight) - (rectangleHeight + rectangleHeight + rectangleHeight) ,
		rentangleWidth, rectangleHeight
	};

	int lifePoints = livesMax;
	int colorP1 = color0;

	static void SetPlayerColor();

	static void SetPlayerColor()
	{
		boxP1.color = colorOptions[colorP1];
	}

	void InitRecColor()
	{
		SetPlayerColor();
	}

	void InitRecPositionNScore()
	{
		lifePoints = livesMax;
		boxP1 =
		{
			static_cast<float>(halfScreenWidth) - static_cast<float>(halfRectangleWidth),
			static_cast<float>(BaseScreenHeight) - (rectangleHeight + rectangleHeight + rectangleHeight) ,
			rentangleWidth, rectangleHeight
		};

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

		SetPlayerColor();
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
		SetPlayerColor();
	}

	void CheckPlayerMovement()
	{
		//Player 1
		//----------------------------------------------------------------------------------
		if (IsKeyDown(KEY_LEFT) && boxP1.x > (limit)) boxP1.x -= rectangleMovement;
		if (IsKeyDown(KEY_RIGHT) && boxP1.x < (BaseScreenWidth - rentangleWidth)) boxP1.x += rectangleMovement;
	}

	void DrawPlayersPoints()
	{
		DrawText(TextFormat("Lives: %i", lifePoints), 10, 10, 20, RAYWHITE);
	}

}