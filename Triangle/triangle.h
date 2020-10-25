#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "generic_vector.h"

typedef void* TRIANGLE;

/*Precondition: none
Postcondition: returns handle to valid triangle object*/
TRIANGLE triangle_init_default(void);

/*Precondition: hTriangle is a handle to a valid triangle object
Postcondition: returns area of a triangle using Heron's formula*/
void triangle_calculate_single_area(TRIANGLE hTriangle);

/*Precondition: hTriangle is a valid triangle object
Postcondition: returns area of triangle*/
double triangle_get_area(TRIANGLE hTriangle);


/*Precondition: hTriangle is a handle to a valid triangle object
Postcondition: the 3 points of the triangle have been assigned
random (x, y) coordinate pairs within the unit square*/
void triangle_generate_random_points(TRIANGLE hTriangle);

/*Calculates distance between two points*/
double distance_formula(double x1, double y1, double x2, double y2);


/*Precondition: phItem is a pointer to a handle to a triangle object
Postcondition: the triangle object has been destroyed*/
void triangle_destroy(ITEM* phItem);

Status triangle_assignment(ITEM *pLeft, ITEM right);

#endif
