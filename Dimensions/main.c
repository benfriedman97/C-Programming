#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "3.23dimensions.h"

void get_dimensions_points_max_length(int *pDimensions, int *pNum_points, 
	double *pMax_length);

int main(int argc, char *arv[])
{
	GENERIC_VECTOR hVector = NULL;
	POINT hPoint = NULL;
	int dimensions, number_of_points, i, j, lines_less_than_max = 0;
	double max_length, length;

	hVector = generic_vector_init_default(point_assignment, point_destroy);
	hPoint = point_init_default();

	//get number of dimensions, number of points, and max length
	get_dimensions_points_max_length(&dimensions, &number_of_points, &max_length);
	
	//srand(time(0));
	//create objects and store them in vector
	for (i = 0; i < number_of_points; i++) {
		//point_get_point2(hPoint, dimensions, i);
		point_get_point(hPoint, dimensions);
		generic_vector_push_back(hVector, (ITEM)hPoint);
	}
	//print info
	for (i = 0; i < number_of_points; i++) {
		point_print_information((POINT)generic_vector_at(hVector, i));
		printf("\n");
	}

	//calculate how many meet the criteria
	for (i = 0; i < number_of_points - 1; i++) {
		for (j = i + 1; j < number_of_points; j++) {
			length = point_calculate_distance_two_points((POINT)generic_vector_at(hVector, i), 
				(POINT)generic_vector_at(hVector, j));
			if (length < max_length)
				lines_less_than_max++;
		}
	}

	printf("\nThere were %d lines less than the max of %.2f\n", lines_less_than_max, max_length);
	point_destroy(&hPoint);
	generic_vector_destroy(&hVector);
	return 0;
}

void get_dimensions_points_max_length(int *pDimensions, int *pNum_points, double *pMax_length)
{
	printf("Enter number of dimensions, number of points, and max length between two points\n");
	scanf("%d%d%lf", pDimensions, pNum_points, pMax_length);
}
