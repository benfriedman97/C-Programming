#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Distance.h"

#define ERROR_TOLERANCE 0.0001

typedef struct point {
	float x, y;
} Point;

/*For problem 3.9, not used in this program*/ 
typedef struct polar_coord {
	float radius, theta;
} Polar_coord;

POINT point_init_default(void)
{
	Point *pPoint = (Point*)malloc(sizeof(Point));
	if (pPoint != NULL) {
		pPoint->x = 0;
		pPoint->y = 0;
	}
	return (POINT)pPoint;
}


Status point_get_point(POINT hPoint)
{
	Point *pPoint = (Point*)hPoint;
	int status = 0;

	printf("Enter x coordinate: ");
	status += scanf("%f", &pPoint->x); while (getchar() != '\n');
	printf("Enter y coordinate: ");
	status += scanf("%f", &pPoint->y); while (getchar() != '\n');
	if (status == 2)
		return SUCCESS;
	else
		return FAILURE;
}


float point_get_distance_two_points(POINT hPoint1, POINT hPoint2, Status *pStatus)
{
	Point *pPoint1 = (Point*)hPoint1, *pPoint2 = (Point*)hPoint2;
	if (pPoint1 == NULL || pPoint2 == NULL) {
		if (*pStatus != NULL)
			*pStatus = FAILURE;
		return FAILURE_CODE;
	}
	if (*pStatus != NULL)
		*pStatus = SUCCESS;
	return sqrt(pow(pPoint2->x - pPoint1->x, 2) + pow(pPoint2->y - pPoint1->y, 2));
}


float point_get_x_coordinate(POINT hPoint)
{
	Point *pPoint = (Point*)hPoint;
	return pPoint->x;
}


float point_get_y_coordinate(POINT hPoint)
{
	Point *pPoint = (Point*)hPoint;
	return pPoint->y;
}


Status point_swap_points(POINT hPoint_to_change, POINT hPoint)
{
	if (hPoint_to_change == NULL || hPoint == NULL)
		return FAILURE;
	Point* pPoint_to_change = (Point*)hPoint_to_change, *pPoint = (Point*)hPoint;
	pPoint_to_change->x = pPoint->x;
	pPoint_to_change->y = pPoint->y;
	return SUCCESS;
}


Boolean point_three_points_are_collinear(POINT hPoint1, POINT hPoint2, POINT hPoint3)
{
	Point *pPoint1 = (Point*)hPoint1, *pPoint2 = (Point*)hPoint2, *pPoint3 = (Point*)hPoint3;
	float slope1, slope2;

	//case where x values are the same so in all or 2 of the points slope would be undefined.
	if (pPoint2->x == pPoint1->x && pPoint3->x == pPoint1->x)
		return TRUE;
	else if ((pPoint2->x == pPoint1->x && pPoint3->x != pPoint1->x) ||
		(pPoint3->x == pPoint1->x && pPoint2->x != pPoint1->x))
		return FALSE;
	slope1 = (pPoint2->y - pPoint1->y) / (pPoint2->x - pPoint1->x);
	slope2 = (pPoint3->y - pPoint1->y) / (pPoint3->x - pPoint1->x);
	return fabs(slope2 - slope1) <= ERROR_TOLERANCE ? TRUE : FALSE;
}


void point_destroy(POINT* phPoint)
{
	Point *pPoint = (Point*)*phPoint;
	free(pPoint);
	*phPoint = NULL;
}
