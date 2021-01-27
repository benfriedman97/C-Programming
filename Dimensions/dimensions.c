#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dimensions.h"

#define INIT_DIMENSIONS 2


typedef struct point {
	int dimensions;
	double *data;
} Point;


POINT point_init_default(void) {
	Point *pPoint = (Point*)malloc(sizeof(Point));
	if (pPoint != NULL) {
		pPoint->dimensions = INIT_DIMENSIONS;
		pPoint->data = (double*)malloc(sizeof(double) * pPoint->dimensions);
		if (pPoint->data == NULL) {
			free(pPoint);
			return NULL;
		}
	}
	return (POINT)pPoint;
}


Status point_get_point(POINT hPoint, int dimensions) {
	Point *pPoint = (Point*)hPoint;
	int i;
	double *temp;

	if (pPoint->dimensions < dimensions) {
		temp = (double*)malloc(sizeof(double) * dimensions);
		if (temp == NULL)
			return FAILURE;
		fre(pPoint->data);
		pPoint->data = temp;
		pPoint->dimensions = dimensions;
	}

	for (i = 0; i < dimensions; i++) {
		pPoint->data[i] = (double)rand();
		while (pPoint->data[i] > 1)
			pPoint->data[i] /= 10;
	}
}


Status point_get_point2(POINT hPoint, int dimensions, int num) {
	Point *pPoint = (Point*)hPoint;
	int i;
	double *temp;

	if (pPoint->dimensions < dimensions) {
		temp = (double*)malloc(sizeof(double) * dimensions);
		if (temp == NULL)
			return FAILURE;
		free(pPoint->data);
		pPoint->data = temp;
		pPoint->dimensions = dimensions;
	}

	for (i = 0; i < dimensions; i++) {
		pPoint->data[i] = (double)num;
		while (pPoint->data[i] > 1)
			pPoint->data[i] /= 10;
	}
}


double point_calculate_distance_two_points(POINT hRight, POINT hLeft) {
	Point *pRight = (Point*)hRight, *pLeft = (Point*)hLeft;
	double sum = 0;
	int i;

	for (i = 0; i < pRight->dimensions; i++)
		sum += pow(pRight->data[i] - pLeft->data[i], 2);
	sum = sqrt(sum);
	return sum;
}


void point_print_information(POINT hPoint) {
	Point *pPoint = (Point*)hPoint;
	int i;

	printf("Dimensions: %d\n", pPoint->dimensions);
	printf("Coordinates: (");
	for (i = 0; i < pPoint->dimensions; i++)
		i < pPoint->dimensions - 1 ? printf("%.2f, ", pPoint->data[i]) : 
		printf("%.2f", pPoint->data[i]);
	printf(")\n");
}


Status point_assignment(ITEM *pLeft, ITEM right) {
	Point *temp_left;
	Point *temp_right = (Point*)right;	//need to know dimensions of right in case of creation
	int i;

	//if left doesn't exist, create the object
	if (*pLeft == NULL) {
		temp_left = (Point*)malloc(sizeof(Point));
		if (temp_left == NULL)
			return FAILURE;
		temp_left->data = (double*)malloc(sizeof(double) * temp_right->dimensions);
		if (temp_left->data == NULL) {
			free(temp_left);
			return FAILURE;
		}
		*pLeft = temp_left;
	}

	//cast to known types
	temp_left = (Point*)*pLeft;
	temp_right = (Point*)right;

	//copy info in right into left object (dimensions and coordinates)
	temp_left->dimensions = temp_right->dimensions;
	for (i = 0; i < temp_right->dimensions; i++)
		temp_left->data[i] = temp_right->data[i];

	return SUCCESS;
}


void point_destroy(ITEM *pItem) {
	Point *pPoint = (Point*)*pItem;
	free(pPoint->data);
	free(pPoint);
	*pItem = NULL;
}
