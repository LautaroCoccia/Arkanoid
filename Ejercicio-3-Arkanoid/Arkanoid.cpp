/*******************************************************************************************
*
*   raylib [core] example - Keyboard input
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
struct Ball
{
	float ballMovementX;
	float ballMovementY;
	int ballSize;
	Vector2 ballPosition;
	Vector2 ballSpeed;
	Color ballColor;
};
 Ball ball;
struct Brick 
{
	Vector2 position;
	
};
 Brick brick;

int main(void) {

	// Initialization
	//---------------------------------------------------------------------------------------

	const int screenWidth = 800;
	const int screenHeight = 450;
	ball.ballMovementX = 6.0f;
	ball.ballMovementY = 5.0f;
	ball.ballColor = WHITE;
	ball.ballPosition.x = (float)screenWidth / 2;
	ball.ballPosition.y = (float)screenHeight / 2;
	ball.ballSize = 5.0f;
	ball.ballSpeed.x = ball.ballMovementX;
	ball.ballSpeed.y = ball.ballMovementY;
	const int limit = 2;
	const float rectangleMovement = 6.0f;
	const int rectangleHeight =10;
	const int rentangleWidth = 100;
	const int linesOfBricks = 1;
	const int bricksPerLine = 16;
	int lifePoints = 0;
	Color colorOptions[5] = { BLUE,GOLD, RED, GREEN, PURPLE };
	bool checkColission = false;

	InitWindow(screenWidth, screenHeight, "Arkanoid.exe - Lautaro Coccia");
	const float brickWidth = (float)((screenWidth / bricksPerLine) - linesOfBricks);
	const float brickHeight = 40.0f;

	Rectangle boxP1 = { (float)(screenWidth / 2) - (float)(rentangleWidth / 2), (float)(screenHeight ) - (rectangleHeight ) , rentangleWidth, rectangleHeight };
	Vector2 brickSize = { (float)((screenWidth) / bricksPerLine) - linesOfBricks , 40 };
	Rectangle bricks[linesOfBricks][bricksPerLine] = { (float)(bricks[linesOfBricks][bricksPerLine].x - brickSize.x / 2 + linesOfBricks) , (float)(bricks[linesOfBricks][bricksPerLine].y - brickSize.y), brickWidth, brickHeight };
	//(bricks[i][j].x - brickSize.x / 2) + j, bricks[i][j].y - brickSize.y / 2, brickSize.x, brickSize.y, colorOptions[i]
	bricks[linesOfBricks][bricksPerLine].color = colorOptions[linesOfBricks];
	// Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------
	SetTargetFPS(60);
	//Game Menu loop
	bool game = true;
	bool playing = true;
	int countP1 = 0;
	boxP1.color = colorOptions[countP1];
	
	
	// Main game loop
	while (game) 
	{

		do 
		{
			BeginDrawing();
			ClearBackground(BLACK);
			DrawText("PONG", 360, 50, 20, RAYWHITE);
			DrawText("PRESS ENTER", 310, 125, 20, RAYWHITE);
			DrawText("SELECT BAR COLOR", 285, 100, 20, RAYWHITE);
			if (IsKeyPressed(KEY_RIGHT))
			{
				if (countP1 < 4) 
				{
					countP1 = (countP1 + 1);
					boxP1.color = colorOptions[countP1];
				}
				else 
				{
					countP1 = 0;
					boxP1.color = colorOptions[countP1];
				}
			}
			if (IsKeyPressed(KEY_LEFT)) 
			{
				if (countP1 > 0)
				{
					countP1 = (countP1 - 1);
					boxP1.color = colorOptions[countP1];
				}
				else 
				{
					countP1 = 4;
					boxP1.color = colorOptions[countP1];
				}
			}
			
			DrawRectangleRec(boxP1, boxP1.color);
			EndDrawing();
		} while (IsKeyUp(KEY_ENTER));
		if (IsKeyPressed(KEY_ENTER)) 
		{
			// Initialize bricks
			int initialDownPosition = 50;

			for (int i = 0; i < linesOfBricks; i++)
			{
				for (int j = 0; j < bricksPerLine; j++)
				{
					bricks[i][j].x = j*brickSize.x + brickSize.x / 2 +1;
					bricks[i][j].y =i*brickSize.y + initialDownPosition ;
					bricks[i][j].active = true;
				}
			}
			while (playing) 
			{
				// Update
				//----------------------------------------------------------------------------------
				
				//Player 1
				//----------------------------------------------------------------------------------
				if (IsKeyDown(KEY_LEFT) && boxP1.x > (limit)) boxP1.x -= rectangleMovement;
				if (IsKeyDown(KEY_RIGHT) && boxP1.x < (screenWidth - rentangleWidth - 2)) boxP1.x += rectangleMovement;


				// Check walls limit
				//----------------------------------------------------------------------------------
				if ((ball.ballPosition.x >= (GetScreenWidth() - ball.ballSize)) || (ball.ballPosition.x <= ball.ballSize)) ball.ballSpeed.x *= -1.0f, checkColission = false;
				if ((ball.ballPosition.y >= (GetScreenHeight() - ball.ballSize))) ball.ballSpeed.y *= -1.0f, checkColission = false;
				if (ball.ballPosition.y <= ball.ballSize) ball.ballSpeed.y *= -1.0f, checkColission = false;

				if (lifePoints == 0 ) game = false;
				// collision
				//----------------------------------------------------------------------------------
				if (CheckCollisionCircleRec(ball.ballPosition, ball.ballSize, boxP1) && checkColission == false) ball.ballSpeed.y *= -1.0f,
					checkColission = true, ball.ballColor = boxP1.color;

				for (int i = 0; i < linesOfBricks; i++)
				{
					for (int j = 0; j < bricksPerLine; j++)
					{
						if (bricks[i][j].active)
						{
							if (CheckCollisionCircleRec(ball.ballPosition, ball.ballSize+(brickHeight/2), bricks[i][j]))
							{
								bricks[i][j].active = false;
								ball.ballSpeed.y *= -1;
							}
						}
					}
				}
				ball.ballPosition.x += ball.ballSpeed.x;
				ball.ballPosition.y += ball.ballSpeed.y;
				if (lifePoints == 3 )playing = false;
				// Draw
				//----------------------------------------------------------------------------------
				BeginDrawing();
				// Draw bricks
				
				ClearBackground(BLACK);

				DrawText(TextFormat("Player 1: %i", lifePoints), 10, 10, 20, RAYWHITE);
				for (int i = 0; i < linesOfBricks; i++)
				{
					
					for (int j = 0; j < bricksPerLine; j++)
					{
						if (bricks[i][j].active)
						{
							 DrawRectangle((bricks[i][j].x - brickSize.x / 2 ) +j, bricks[i][j].y - brickSize.y / 2, brickSize.x, brickSize.y, colorOptions[i]);
						}
					}
				}
				
				DrawRectangleRec(boxP1, boxP1.color);
				DrawCircleV(ball.ballPosition, ball.ballSize, ball.ballColor);
				EndDrawing();
				//----------------------------------------------------------------------------------
				while (!playing) 
				{
					BeginDrawing();

					ClearBackground(BLACK);
					if (lifePoints == 3) DrawText("PLAYER 1 WINS!!", 300, 50, 20, RAYWHITE),
						DrawText("PRESS \"F\" TO PAY RESPECTS AND PLAY AGAIN", 175, 100, 20, RAYWHITE);
					
					if (IsKeyDown(KEY_F)) playing = true, lifePoints = 3;
					// De-Initialization
					//--------------------------------------------------------------------------------------
					else if (IsKeyDown(KEY_ESCAPE))  CloseWindow(); // Close window and OpenGL context
					//--------------------------------------------------------------------------------------
				};
			}

		}


	};

	return 0;
}
