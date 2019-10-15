#ifndef PALETTE_H
#define PALETTE_H
#include "raylib.h"
const int livesMax = 3;
const int livesMin = 1;
const int rectangleHeight = 10;
const int rentangleWidth = 120;
const int halfRectangleHeight = rectangleHeight / 2;
const int halfRectangleWidth = rentangleWidth / 2;
const int BaseScreenWidth = 800;
const int BaseScreenHeight = 450;
const int halfScreenWidth = BaseScreenWidth / 2;
const int halfScreenHeight = BaseScreenHeight / 2;
extern Rectangle boxP1;
extern int lifePoints;
extern void InitRecColor();
extern void CheckColorPlayer1Right();
extern void CheckColorPlayer1Left();
extern void InitRecPositionNScore();
extern void CheckPlayerMovement();
extern void DrawRectangles();
extern void DrawPlayersPoints();
#endif