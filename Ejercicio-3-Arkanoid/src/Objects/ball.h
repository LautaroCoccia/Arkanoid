#ifndef BALL_H
#define BALL_H
#include "raylib.h"

namespace BallObj
{
	struct Ball
	{
		float ballMovementX = 400;
		float ballMovementY = 300;
		const float commonBallRadius = 14;
		float ballRadius = commonBallRadius;
		Vector2 ballPosition;
		Vector2 ballSpeed;
		Color ballColor = WHITE;
		bool ballActive;
	};

	extern const float increaseMovementX;
	extern const float changeDirectionY;
	extern Rectangle myBoundingBox;
	extern Ball ball;
	extern void InitBall();
	extern void CheckBallWallsLimit();
	extern void DrawMyBall();


}
#endif
