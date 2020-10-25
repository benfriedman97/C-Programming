#include <stdlib.h>
#include <math.h>
#include "triangle.h"

#define UNDEFINED -2

typedef struct cartesian_point {
	double x, y;
} Cartesian_point;

typedef struct triangle {
	Cartesian_point p1, p2, p3;
	double area;
} Triangle;


TRIANGLE triangle_init_default(void)
{
	Triangle *pTriangle = (Triangle*)malloc(sizeof(Triangle));
	if (pTriangle != NULL) {
		pTriangle->p1.x = UNDEFINED;
		pTriangle->p1.y = UNDEFINED;
		pTriangle->p2.x = UNDEFINED;
		pTriangle->p2.y = UNDEFINED;
		pTriangle->p3.x = UNDEFINED;
		pTriangle->p3.y = UNDEFINED;
		pTriangle->area = UNDEFINED;
	}
	return (TRIANGLE)pTriangle;
}

void triangle_calculate_single_area(TRIANGLE hTriangle)
{
	Triangle *pTriangle = (Triangle*)hTriangle;
	double side1 = distance_formula(pTriangle->p1.x, pTriangle->p1.y,
		pTriangle->p2.x, pTriangle->p2.y),
		side2 = distance_formula(pTriangle->p1.x, pTriangle->p1.y,
			pTriangle->p3.x, pTriangle->p3.y),
		side3 = distance_formula(pTriangle->p2.x, pTriangle->p2.y,
			pTriangle->p3.x, pTriangle->p3.y),
		perimeter = (side1 + side2 + side3) / 2;
	pTriangle->area = sqrt(perimeter * (perimeter - side1) * (perimeter - side2)
		* (perimeter - side3));
}


void triangle_generate_random_points(TRIANGLE hTriangle)
{
	Triangle *pTriangle = (Triangle*)hTriangle;
	double x, y;

	do {
		for (int i = 0; i < 3; i++) {
			//get x and y coordinate (0, 1]
			x = rand();
			while (x > 1)
				x /= 10;
			y = rand();
			while (y > 1)
				y /= 10;
			//assign to proper point
			if (i == 0) {
				pTriangle->p1.x = x;
				pTriangle->p1.y = y;
			}
			else if (i == 1) {
				pTriangle->p2.x = x;
				pTriangle->p2.y = y;
			}
			else {
				pTriangle->p3.x = x;
				pTriangle->p3.y = y;
			}
		}
	} while ((pTriangle->p1.x == pTriangle->p2.x == pTriangle->p3.x) ||
		(pTriangle->p1.y == pTriangle->p2.y == pTriangle->p3.y));
}


double distance_formula(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}


Status triangle_assignment(ITEM *pLeft, ITEM right)
{
	Triangle *temp, *temp_right;

	if (*pLeft == NULL) {
		temp = (Triangle*)malloc(sizeof(Triangle));
		if (temp == NULL)
			return FAILURE;
		*pLeft = (ITEM)temp;
	}

	temp = (Triangle*)*pLeft;
	temp_right = (Triangle*)right;
	*temp = *temp_right;
	return SUCCESS;
}

void triangle_destroy(ITEM* pItem)
{
	Triangle *pTriangle = (ITEM*)*pItem;
	free(pTriangle);
	*pItem = NULL;
}


void triangle_print_information(TRIANGLE hTriangle)
{
	Triangle *pTriangle = (Triangle*)hTriangle;
	printf("Points: (%.3f, %.3f)\t(%.3f, %.3f)\t(%.3f, %.3f)\nArea: %f\n\n",
		pTriangle->p1.x, pTriangle->p1.y, pTriangle->p2.x, pTriangle->p2.y,
		pTriangle->p3.x, pTriangle->p3.y, pTriangle->area);
}

double triangle_get_area(TRIANGLE hTriangle)
{
	Triangle *pTriangle = (Triangle*)hTriangle;
	return pTriangle->area;
}
