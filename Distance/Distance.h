#ifndef DISTANCE_H
#define DISTANCE_H

#include "status.h"

#define FAILURE_CODE -9999.1234
#define ERROR_TOLERANCE 0.0001

typedef void* POINT;

/* Precondition: none
   Postcondition: returns handle to valid point object */
POINT point_init_default(void);

/* Precondition: hPoint is a valid to a valid point object
   Postcondition: the x and y coordinates of a point have been to the object */
Status point_get_point(POINT hPoint);

/* Precondition: hPoint1 and hPoint2 are valid point objects
   Postcondition: returns the distance between two points, else returns
   a specific error code. Also inputs a status via pass by reference
   to indicate success or failure in addition to the error code in 
   the return value */
float point_get_distance_two_points(POINT hPoint1, POINT hPoint2, Status *pStatus);

/* Precondition: hPoint1 is a handle to valid point object
   Postcondition: returns the x coordinate of the point */
float point_get_x_coordinate(POINT hPoint);

/* Precondition: hPoint1 is a handle to valid point object
   Postcondition: returns the y coordinate of the point */
float point_get_y_coordinate(POINT hPoint);

/* Precondition: hPoint1 and hPoint2 are handles to valid point objects
   Postcondition: stores the (x,y) coordinate pair of hPoint in hPoint_to_change */
Status point_swap_points(POINT hPoint_to_change, POINT hPoint);

/* Precondition: hPoint1 and hPoint2 are handles to valid point objects all within the unit circle
   Postcondition: returns TRUE if 3 points are collinear to within an error tolerance of
   ERROR_TOLERANCE, else FALSE */
Boolean point_three_points_are_collinear(POINT hPoint1, POINT hPoint2, POINT hPoint3);

/* Precondition: phPoint is a pointer to a handle to a valid point object
   Postcondition: the object in the handle pointed to by phPoint has been destroyed */
void point_destroy(POINT* phPoint);

#endif
