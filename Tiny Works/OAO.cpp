// Copyright (c) Penyo. All rights reserved.

#include <stdio.h>
#include <graphics.h>

#define X_PIXEL 300
#define Y_PIXEL X_PIXEL * 0.533333
#define L_EYE_X X_PIXEL * 0.2
#define L_EYE_Y L_EYE_X
#define R_EYE_X X_PIXEL - L_EYE_X
#define R_EYE_Y L_EYE_X
#define EYE_RANGE L_EYE_X * 0.5
#define P1X X_PIXEL * 0.5 - EYE_RANGE * 1.25
#define P1Y L_EYE_X + EYE_RANGE * 2
#define P2X X_PIXEL * 0.5 + EYE_RANGE * 1.25
#define P2Y P1Y
#define P3X X_PIXEL * 0.5
#define P3Y L_EYE_X + EYE_RANGE * 0.75

int main()
{
	initgraph(X_PIXEL, Y_PIXEL);
	circle(L_EYE_X, L_EYE_Y, EYE_RANGE),
		circle(R_EYE_X, R_EYE_Y, EYE_RANGE);
	line(P1X, P1Y, P2X, P2Y),
		line(P1X, P1Y, P3X, P3Y),
		line(P2X, P2Y, P3X, P3Y);
	while (1);
}
