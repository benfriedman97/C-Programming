#include <stdio.h>
#include <stdlib.h>
#include <vld.h	>
#include "Distance.h"

int main(int argc, char *argv[]) {

	POINT hPoint1 = NULL, hPoint2 = NULL, hPoint3 = NULL;
	hPoint1 = point_init_default();
	hPoint2 = point_init_default();
	hPoint3 = point_init_default();
	
	printf("Get point 1\n");
	while (!point_get_point(hPoint1))
		printf("Input error. Get point 1 again\n");
	printf("Get point 2\n");
	while (!point_get_point(hPoint2))
		printf("Input error. Get point 2 again\n");
	printf("Get point 3\n");
	while (!point_get_point(hPoint3))
		printf("Input error. Get point 3 again\n");
	if (point_three_points_are_collinear(hPoint1, hPoint2, hPoint3))
		printf("Points (%.2f, %.2f), (%.2f, %.2f), and (%.2f, %.2f) are collinear\n",
			point_get_x_coordinate(hPoint1), point_get_y_coordinate(hPoint1),
			point_get_x_coordinate(hPoint2), point_get_y_coordinate(hPoint2),
			point_get_x_coordinate(hPoint3), point_get_y_coordinate(hPoint3));
	else
		printf("Points (%.2f, %.2f), (%.2f, %.2f), and (%.2f, %.2f) are not collinear\n",
			point_get_x_coordinate(hPoint1), point_get_y_coordinate(hPoint1),
			point_get_x_coordinate(hPoint2), point_get_y_coordinate(hPoint2),
			point_get_x_coordinate(hPoint3), point_get_y_coordinate(hPoint3));

	point_destroy(&hPoint1);
	point_destroy(&hPoint2);
	point_destroy(&hPoint3);

	return 0;
}
