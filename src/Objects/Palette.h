#ifndef PALETTE_H
#define PALETTE_H

#include "raylib.h"

extern const int livesMax;
extern const int livesMin;
extern const int rectangleHeight;
extern const int rentangleWidth;
extern const int halfRectangleHeight;
extern const int halfRectangleWidth;
const int BaseScreenWidth = 800;
const int BaseScreenHeight = 450;
const float halfScreenWidth = BaseScreenWidth / 2;
const float halfScreenHeight = BaseScreenHeight / 2;
extern Rectangle boxP1;
extern int lifePoints;
extern void InitRecColor();
extern void InitRecPositionNScore();
extern void CheckColorPlayer1Right();
extern void CheckColorPlayer1Left();
extern void CheckPlayerMovement();
extern void DrawPlayersPoints();
#endif