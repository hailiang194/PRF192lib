#ifndef DRAW_SHAPE_H
	#define DRAW_SHAPE_H

#include <stdio.h>
#include <stdlib.h> // for abs
#include "..\constant.h"

//check if (x, y) is the location to print the star for fill retangle
int isStarInFillRet(int x, int y, int col, int row);

//check if (x, y) is the location to print the star for unfill retangle
int isStarInUnfillRet(int x, int y, int col, int row);

//check if (x, y) is the location to print the star for unfill left angle half pyramid
int isStarInUnfillLeftAngleHalfPyramid(int x, int y, int col, int row);

//check if (x, y) is the location to print the star for unfill right angle half pyramid
int isStarInUnfillRightAngleHalfPyramid(int x, int y, int col, int row);

//check if (x, y) is the location to print the star for unfill invert left angle half pyramid
int isStarInUnfillInvertLeftAngleHalfPyramid(int x, int y, int col, int row);

//check if (x, y) is the location to print the star for unfill invert right angle half pyramid
int isStarInUnfillInvertRightAngleHalfPyramid(int x, int y, int col, int row);

//check if (x, y) is the location to print the star for fill left angle half pyramid
int isStarInFillLeftAngleHalfPyramid(int x, int y, int col, int row);

//check if (x, y) is the location to print the star for fill right angle half pyramid
int isStarInFillRightAngleHalfPyramid(int x, int y, int col, int row);

//check if (x, y) is the location to print the star for fill invert left angle half pyramid
int isStarInFillInvertLeftAngleHalfPyramid(int x, int y, int col, int row);

//check if (x, y) is the location to print the star for fill invert right half pyramid
int isStarInFillInvertRightAngleHalfPyramid(int x, int y, int col, int row);

//check if (x, y) is the location to print the star for fill pyramid
int isStarInFillPyramid(int x, int y, int col, int row);

//check if (x, y) is the location to print the star for unfill pyramid
int isStarInUnfillPyramid(int x, int y, int col, int row);

int isStarInUnfillInvertPyramid(int x, int y, int col, int row);

int isStarInFillInvertPyramid(int x, int y, int col, int row);

//draw the shape using '*' base on the condition of isStar
void drawShape(int row, int col, int(*isStar)(int, int, int, int));
#endif