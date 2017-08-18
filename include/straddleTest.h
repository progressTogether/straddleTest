
typedef struct point_
{
	int x;
	int y;
} point;


typedef struct line_
{
	point pointA;
	point pointB;
} line;

enum STRADDLE_ERROR
{
	STRADDLE_OK                          = 0, ///<Success
	STRADDLE_TWO_LINE_INTERSECT          = 1, ///<Two line intersect
	STRADDLE_TWO_LINE_DISJOINT           = 2, ///<Two line disjoint
	STRADDLE_INVALID_LINE                = 3,  ///<This line is point
	STRADDLE_VALID_LINE                  = 4,///<This line is line
	STRADDLE_FUN_RETURN_ERROR            = 5,///<Function return error
	STRADDLE_TWO_RECTANGLE_INTERSECT     = 6,
	STRADDLE_TWO_RECTANGLE_DISJOINT      = 7
};

	/**
	 * @brief
	 * Get instance before calling other interface function
	 * @remarks
	 *
	 * @return ASKEY_HANDLE
	 *         -1 is invalid. 0 and value greater than 0 are valid.

	 */
int judgeTwoLineIntersect(line lineA,line lineB);
int judgeLineOrpoint(line inputLine);
int judgeTwoRectangleIntersect(line lineA,line lineB);
int getRectangleLeftBottomAndRightTop(line inputLine,point *minPoint,point *maxPoint);
int min(int x,int y);
int max(int x,int y);
