//straddleTest
/*
 * Write by <x-hui>
 * TIME：2017/07/29
 */

#include<stdio.h>

#include"straddleTest.h"

line inputLineA,inputLineB;

int judgeTwoLineIntersect(line lineA,line lineB)
{
	if( STRADDLE_INVALID_LINE == judgeLineOrpoint(lineA)
			|| STRADDLE_INVALID_LINE == judgeLineOrpoint(lineB) )
	{
		return STRADDLE_INVALID_LINE;
	}


	if ( STRADDLE_TWO_RECTANGLE_DISJOINT == judgeTwoRectangleIntersect(lineA ,lineB) )
	{
		return STRADDLE_TWO_LINE_DISJOINT;
	}

	return STRADDLE_OK;
}

int judgeLineOrpoint(line inputLine)
{
	if( (inputLine.pointA.x == inputLine.pointB.x)
		&&(inputLine.pointA.y == inputLine.pointB.y) )
	{
		return STRADDLE_INVALID_LINE;
	}
	else
	{
		return STRADDLE_VALID_LINE;
	}
}

int judgeTwoRectangleIntersect(line lineA,line lineB)
{
	point minPointA,minPointB,maxPointA,maxPointB;
	line coincidenceRectangleLine;

	if(STRADDLE_OK != getRectangleLeftBottomAndRightTop(lineB,&minPointA,&maxPointA) )
	{
		return STRADDLE_FUN_RETURN_ERROR;
	}

	if(STRADDLE_OK != getRectangleLeftBottomAndRightTop(lineA,&minPointB,&maxPointB) )
	{
		return STRADDLE_FUN_RETURN_ERROR;
	}

	coincidenceRectangleLine.pointA.x = max(minPointA.x,minPointB.x);
	coincidenceRectangleLine.pointA.y = max(minPointA.y,minPointB.y);

	coincidenceRectangleLine.pointB.x = min(maxPointA.x,maxPointB.x);
	coincidenceRectangleLine.pointB.y = min(maxPointA.y,maxPointB.y);

	if(  (coincidenceRectangleLine.pointA.x >= coincidenceRectangleLine.pointB.x )
	   ||(coincidenceRectangleLine.pointA.y >= coincidenceRectangleLine.pointB.y )
      )
	{
		return STRADDLE_TWO_RECTANGLE_DISJOINT;

	}
	else
	{
		return STRADDLE_TWO_RECTANGLE_INTERSECT;
	}
}

int getRectangleLeftBottomAndRightTop(line inputLine,point *minPoint,point *maxPoint)
{
	(*minPoint).x = min(inputLine.pointA.x,inputLine.pointB.x);
	(*minPoint).y = min(inputLine.pointA.y,inputLine.pointB.y);

	(*maxPoint).x = max(inputLine.pointA.x,inputLine.pointB.x);
	(*maxPoint).y = max(inputLine.pointA.y,inputLine.pointB.y);

	return STRADDLE_OK;
}

int min(int x,int y)
{
	if(x>y)
	{
		return y;
	}

	return x;
}

int max(int x,int y)
{
	if(x>y)
	{
		return x;
	}

	return y;
}

