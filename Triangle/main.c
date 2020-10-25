#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "triangle.h"

#define NUM_TRIANGLES 1000

int main(int argc, char *argv[])
{
	GENERIC_VECTOR hVector = NULL;
	TRIANGLE hTriangle = NULL;
	int i;
	double total_area = 0;
	srand(time(0));

	hVector = generic_vector_init_default(triangle_assignment, triangle_destroy);
		//triangle_print_information, triangle_get_area);
	hTriangle = triangle_init_default();

	for (i = 0; i < NUM_TRIANGLES; i++) {
		if (hTriangle == NULL) {
			printf("Failed to allocate memory for triangle object\n");
			exit(1);
		}
		triangle_generate_random_points(hTriangle);
		triangle_calculate_single_area(hTriangle);
		generic_vector_push_back(hVector, (ITEM)hTriangle);
	}
	triangle_destroy(&hTriangle);

	for (i = 0; i < NUM_TRIANGLES; i++) {
		hTriangle = (TRIANGLE)generic_vector_at(hVector, i);
		triangle_print_information(hTriangle);
		total_area += triangle_get_area(hTriangle);
	}
	//generic_vector_print_information(hVector);
	//printf("\n\nThe average area of all the triangles is %f\n\n", generic_vector_calculate_average_area(hVector));
	printf("The average area of all the triangles is %f", total_area / NUM_TRIANGLES);
	hTriangle = NULL;
	generic_vector_destroy(&hVector);
	return 0;
}
