#include <stdlib.h>
#include <math.h>
#include "AvgStdvRandNum.h"


typedef double Number;	// must be "int", not double, for stdv1 function
typedef struct avg_and_stdv {
	double avg, stdv;
} Avg_and_stdv;


AVG_STDV avg_and_stdv_init_default(void) {
	Avg_and_stdv *pAvg_stdv = (Avg_and_stdv*)malloc(sizeof(Avg_and_stdv));
	if (pAvg_stdv != NULL) {
		pAvg_stdv->avg = 0;
		pAvg_stdv->stdv = 0;
	}
	return (AVG_STDV)pAvg_stdv;
}


void avg_and_stdv_destroy(AVG_STDV* phAvg_and_stdv) {
	Avg_and_stdv *pAvg_stdv = (Avg_and_stdv*)*phAvg_and_stdv;
	free(pAvg_stdv);
	*phAvg_and_stdv = NULL;
}


Status avg_and_stdv_calculate_avg_and_stdv1(AVG_STDV hAvg_and_stdv, int N, int r) {
	if (N < 1 || r < 1)
		return FAILURE;

	Avg_and_stdv *pAvg_stdv = (Avg_and_stdv*)hAvg_and_stdv;
	Number x;
	double avg = 0, sum_of_squares = 0;
	srand(5);
	for (int i = 0; i < N; i++) {
		x = rand() % r;
		if (x > r - 1) {
			printf("x = %f", x);
			exit(1);
		}
		avg += (double)x / N;
		sum_of_squares += (double)x * x / N;
	}
	pAvg_stdv->avg = avg;
	pAvg_stdv->stdv = sqrt(sum_of_squares - pow(avg, 2));
	return SUCCESS;
}


Status avg_and_stdv_calculate_avg_and_stdv2(AVG_STDV hAvg_and_stdv, int N, int r) {
	if (N < 1 || r < 1)
		return FAILURE;

	Avg_and_stdv *pAvg_stdv = (Avg_and_stdv*)hAvg_and_stdv;
	Number x;
	double avg = 0, sum_of_squares = 0;

	for (int i = 0; i < N; i++) {
		x = rand();
		while ((x /= 10) >= 1);
		x = floor(x * r);
		avg += (double)x / N;
		sum_of_squares += (double)x * x / N;
	}
	pAvg_stdv->avg = avg;
	pAvg_stdv->stdv = sqrt(sum_of_squares - pow(avg, 2));
	return SUCCESS;
}


double avg_and_stdv_get_avg(AVG_STDV hAvg_and_stdv) {
	Avg_and_stdv *pAvg_stdv = (Avg_and_stdv*)hAvg_and_stdv;
	return pAvg_stdv->avg;
}

double avg_and_stdv_get_stdv(AVG_STDV hAvg_and_stdv) {
	Avg_and_stdv *pAvg_stdv = (Avg_and_stdv*)hAvg_and_stdv;
	return pAvg_stdv->stdv;
}
