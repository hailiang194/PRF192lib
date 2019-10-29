#include "draw-shape.h"

int isStarInFillRet(int x, int y, int col, int row)
{
	return TRUE;
}

int isStarInUnfillRet(int x, int y, int col, int row)
{
	return ((x == 0) || (y == 0) || (x == col - 1) || (y == row - 1));
}

int isStarInUnfillLeftAngleHalfPyramid(int x, int y, int col, int row)
{
	return ((x == y) || (x == 0) || (y == col - 1));
}

int isStarInUnfillRightAngleHalfPyramid(int x, int y, int col, int row)
{
	return ((x == row - 1 - y) || (x == col - 1) || (y == row - 1));
}

int isStarInUnfillInvertLeftAngleHalfPyramid(int x, int y, int col, int row)
{
	return ((x == row - 1 - y) || (y == 0) || (x == 0));
}

int isStarInUnfillInvertRightAngleHalfPyramid(int x, int y, int col, int row)
{
	return ((x == y) || (y == 0) || (x == row - 1));
}

int isStarInFillLeftAngleHalfPyramid(int x, int y, int col, int row)
{
	return ((x <= y));
}

int isStarInFillRightAngleHalfPyramid(int x, int y, int col, int row)
{
	return (x >= row - 1 - y);
}

int isStarInFillInvertLeftAngleHalfPyramid(int x, int y, int col, int row)
{
	return (x <= row - 1 - y);
}

int isStarInFillInvertRightAngleHalfPyramid(int x, int y, int col, int row)
{
	return (x >= y);
}

int isStarInFillPyramid(int x, int y, int col, int row)
{
	return (abs(x + 1 - col / 2) <= y);
}

int isStarInUnfillPyramid(int x, int y, int col, int row)
{
	return ((abs(x + 1 - col / 2) == y ) || (y == row - 1) && !((x == col - 1) && (y = row - 1)));
}

void drawShape(int row, int col, int(*isStar)(int, int, int , int))
{
	for(int y = 0; y < row; y++)
	{
		for(int x = 0; x < col; x++)
		{
			if((*isStar)(x, y, col, row))
				putchar('*');
			else
				putchar(' ');
		}

		putchar('\n');
	}
}