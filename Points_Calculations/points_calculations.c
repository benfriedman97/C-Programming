#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h.>

typedef struct {
	double x, y;
} point;

int count_points(double d, int N, point *p1, point *bp2);
double distance(point a, point b);
double randFloat(void);

int main(void)
{
	point a, b;
	srand(time(0));
	int N;
	double d;
	printf("Maximum distance: "); scanf("%lf", &d);
	printf("Number of points: "); scanf("%d", &N);
	printf("%d edges shorter than %f\n", count_points(d, N, &a, &b), d);
	printf("Coordinates of closest pair of points: (%.2f, %.2f) and (%.2f, %.2f)\n",
		a.x, a.y, b.x, b.y);
	return 0;
}

int count_points(double d, int N, point *p1, point *p2)
{
	int i, j, cnt = 0;
	double distance1, distance_shortest;
	point *a = (point*)malloc(sizeof(point) * N);
	for (i = 0; i < N; i++) {
		a[i].x = randFloat();
		a[i].y = randFloat();
	}
	for (i = 0; i < N - 1; i++) {
		for (j = i + 1; j < N; j++) {
			distance1 = distance(a[i], a[j]);
			if (distance1 < d)
				cnt++;
			if ((i == 0 && j == 1) || distance1 < distance_shortest) {
				distance_shortest = distance1;
				p1->x = a[i].x;
				p1->y = a[i].y;
				p2->x = a[j].x;
				p2->y = a[j].y;
			}

		}
	}
	free(a);
	return cnt;
}

double distance(point a, point b)
{
	double dx = a.x - b.x,
		dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}

double randFloat(void)
{
	return (double)rand() / RAND_MAX;
}
