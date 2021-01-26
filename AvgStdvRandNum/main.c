#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "AvgStdvRandNum.h"

int main(int argc, char *argv[])
{
	AVG_STDV hMy_avg_stdv = NULL;
	int N, r;

	hMy_avg_stdv = avg_and_stdv_init_default();
	if (hMy_avg_stdv == NULL) {
		printf("Failed to allocate memory for object\n");
		exit(1);
	}

	
	/*3.3*/
	for (N = pow(10, 3); N <= pow(10, 6); N *= 10) {
		for (r = pow(10, 1); r <= pow(10, 3); r *= 10) {
			if (!avg_and_stdv_calculate_avg_and_stdv2(hMy_avg_stdv, N, r)) {
				printf("Failed to calculate average and standard deviation. N or r not within bounds\n");
				exit(1);
			}
			printf("For the set of %d random numbers between 0 and %d:\n"
				"\tAverage: %.2f\n\tStandard Deviation: %.2f\n", N, r - 1, avg_and_stdv_get_avg(hMy_avg_stdv),
				avg_and_stdv_get_stdv(hMy_avg_stdv));
			printf("\n");
		}
	}

	/*3.2
	Also, Number is typedef int, not typedef double*/
	for (N = pow(10, 3); N <= pow(10, 6); N *= 10) {
		for (r = pow(10, 1); r <= pow(10, 3); r *= 10) {
			if (!avg_and_stdv_calculate_avg_and_stdv1(hMy_avg_stdv, N, r)) {
				printf("Failed to calculate average and standard deviation. N or r not within bounds\n");
				exit(1);
			}
			printf("For the set of %d random numbers between 0 and %d:\n"
				"\tAverage: %.2f\n\tStandard Deviation: %.2f\n", N, r - 1, avg_and_stdv_get_avg(hMy_avg_stdv),
				avg_and_stdv_get_stdv(hMy_avg_stdv));
			printf("\n");
		}
	}

	//3.4: part 1
	/*for (N = pow(10, 3); N <= pow(10, 6); N *= 10) {
		for (r = pow(2, 1); r < pow(2, 4); r *= 2) {
			if (r == pow(2, 3))
				r *= 2;
			if (!avg_and_stdv_calculate_avg_and_stdv1(hMy_avg_stdv, N, r)) {
				printf("Failed to calculate average and standard deviation. N or r not within bounds\n");
				exit(1);
			}
			printf("For the set of %d random numbers between 0 and %d:\n"
				"\tAverage: %.2f\n\tStandard Deviation: %.2f\n", N, r - 1, avg_and_stdv_get_avg(hMy_avg_stdv),
				avg_and_stdv_get_stdv(hMy_avg_stdv));
			printf("\n");
		}
	}*/

	////3.4: part 2
	//for (N = pow(10, 3); N <= pow(10, 6); N *= 10) {
	//	for (r = pow(2, 1); r < pow(2, 4); r *= 2) {
	//		if (r == pow(2, 3))
	//			r *= 2;
	//		if (!avg_and_stdv_calculate_avg_and_stdv1(hMy_avg_stdv, N, r)) {
	//			printf("Failed to calculate average and standard deviation. N or r not within bounds\n");
	//			exit(1);
	//		}
	//		printf("For the set of %d random numbers between 0 and %d:\n"
	//			"\tAverage: %.2f\n\tStandard Deviation: %.2f\n", N, r - 1, avg_and_stdv_get_avg(hMy_avg_stdv),
	//			avg_and_stdv_get_stdv(hMy_avg_stdv));
	//		printf("\n");
	//	}
	//}

	avg_and_stdv_destroy(&hMy_avg_stdv);

	return 0;
}


                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
