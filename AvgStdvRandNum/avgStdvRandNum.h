#ifndef AVG_STDV_RAND_NUM_H
#define AVG_STDV_RAND_NUM_H

#include "status.h"

typedef void* AVG_STDV;

/* Precondition: none
   Postcondition: returns handle to a valid avg_and_stdv object.
   avg and stdv within the object are intialized to 0 */
AVG_STDV avg_and_stdv_init_default(void);

/* Precondition: hAvg_and_stdv is a valid handle to an avg_and_stdv object
   Postcondition: calculates the average and standard deviation for N random integers
   between 0 and r - 1 by using rand() % r. The average and stdev are now stored in
   the object. */
Status avg_and_stdv_calculate_avg_and_stdv1(AVG_STDV hAvg_and_stdv, int N, int r);

/* Precondition: hAvg_and_stdv is a valid handle to an avg_and_stdv object
    Postcondition: similar to the other function except it calculates the
    N random numbers differently. It generates N random numbers of type double
    between 0 and 1, transforms them into integers between 0 and r - 1 by multiplying
    by r, and then truncating the result. The average and stdev are now stored in
   the object. */
Status avg_and_stdv_calculate_avg_and_stdv2(AVG_STDV hAvg_and_stdv, int N, int r);

/*Precondition: hAvg_and_stdv is a valid object
Postcondition: returns the average stored in the object*/
double avg_and_stdv_get_avg(AVG_STDV hAvg_and_stdv);

/*Precondition: hAvg_and_stdv is a valid object
Postcondition: returns the standard deviation stored in the object*/
double avg_and_stdv_get_stdv(AVG_STDV hAvg_and_stdv);

/*Precondition: phAvg_and_stdv is a pointer to a handle of a valid
avg_and_stdv object
Postcondition: the avg_and_stdv object has been destroyed*/
void avg_and_stdv_destroy(AVG_STDV* phAvg_and_stdv);

#endif
