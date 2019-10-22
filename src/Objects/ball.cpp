#include "Ball.h"

#include "Palette.h"

namespace Arkanoid
{
	Sound colisionSound;
	Rectangle myBoundingBox;
	Ball ball;
	bool checkColission = true;
	const float changeDirectionY = -1.0f;
	const float increaseMovementX = -1.03f;
	const float ballDiameter = ball.ballRadius * 2;
	
	void LoadColisionSound()
	{
		colisionSound = LoadSound("assets/sounds/ColisionSound.wav");
	}

	void UnloadMySound()
	{
		UnloadSound(colisionSound);
	}

	void InitBall()
	{
		ball.ballPosition = 
		{ 
			halfScreenWidth, 
			halfScreenHeight 
		};

		ball.ballSpeed = 
		{ 
			ball.ballMovementX,
			ball.ballMovementY 
		};
		
		myBoundingBox = 
		{
			ball.ballPosition.x - ball.ballRadius,
			ball.ballPosition.y - ball.ballRadius,
			ballDiameter, ballDiameter
		};
	}

	void CheckBallWallsLimit()
	{
		// Check ball-walls limit
		//----------------------------------------------------------------------------------
		if ((ball.ballPosition.x >= (GetScreenWidth() - ball.ballRadius)))
		{
			ball.ballPosition.x = (GetScreenWidth() - ball.ballRadius), ball.ballSpeed.x *= changeDirectionY;
		}
		if (ball.ballPosition.x <= ball.ballRadius - ball.ballRadius)
		{
			ball.ballPosition.x =   ball.ballRadius, ball.ballSpeed.x *= changeDirectionY;
		}

		if ((ball.ballPosition.y >= (GetScreenHeight() + ball.ballRadius)))
		{
			ball.ballPosition.y = boxP1.y - ball.ballRadius;
			ball.ballPosition.x = boxP1.x + halfRectangleWidth - ball.ballRadius;
			ball.ballSpeed.y *= changeDirectionY;
			lifePoints--;
		}

		if (ball.ballPosition.y <= (ball.ballRadius ))
		{
			ball.ballPosition.y = (ball.ballRadius ), ball.ballSpeed.y *= changeDirectionY;
		}
		myBoundingBox.x = ball.ballPosition.x - ball.ballRadius;
		myBoundingBox.y = ball.ballPosition.y - ball.ballRadius;
	}

	void DrawMyBall()
	{
		DrawCircle(static_cast<int>( ball.ballPosition.x), static_cast<int>(ball.ballPosition.y), (ball.ballRadius),ball.ballColor);
	}
}


