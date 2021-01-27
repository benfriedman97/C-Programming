#ifndef DIMENSIONS_H
#define DIMENSIONS_H

#include "generic_vector.h"

typedef void* POINT;

/* Precondition: none
   Postcondition: returns handle to valid point object */
POINT point_init_default(void);

/* Precondition: hPoint is a handle to valid point object
   Postcondition: point information has been stored in the point object. This
   includes the number of dimensions and coordinates. */
Status point_get_point(POINT hPoint, int dimensions);
// alternate version
Status point_get_point2(POINT hPoint, int dimensions, int num);


/* Precondition: hRight and hLeft are valid point objects
   Postcondition: returns the distance between the two points. */
double point_calculate_distance_two_points(POINT hRight, POINT hLeft);

/* Precondition: hPoint is a valid point object
   Postcondition: prints the dimensions and coordinates stored in the object. */
void point_print_information(POINT hPoint);

/* Precondition: right is a handle to a valid object. pLeft is a pointer
   to an already valid object or NULL. In that case it will be created.
   Postcondition: A complete and independent copy of the object on the right has been
   created and is now stored in the vector. */
Status point_assignment(ITEM *pLeft, ITEM right);

/* Precondition: phPoint is a pointer to a handle of a valid point object
   Postcondition: the handle has been destroyed. */
void point_destroy(ITEM *pItem);

#endif
