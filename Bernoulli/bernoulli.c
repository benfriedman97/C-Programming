#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bernoulli(int N, int M, int p);
int heads(int p);

int main(void)
{
	int N, M, p;
	srand(time(0));
	printf("Enter # of coin flips: "); scanf("%d", &N);
	printf("Enter # of experiments: "); scanf("%d", &M);
	printf("Enter n for probability (1 / n): "); scanf("%d", &p);
	bernoulli(N, M, p);

	return 0;
}

int heads(int p)
{
	return rand() < RAND_MAX / p;
}

void bernoulli(int N, int M, int p)
{
	int i, j, cnt;
	int *f = (int*)malloc(sizeof(int) * (N + 1));
	for (j = 0; j <= N; j++)
		f[j] = 0;
	for (i = 0; i < M; i++, f[cnt]++)
		for (cnt = 0, j = 0; j <= N; j++)
			if (heads(p))
				cnt++;
	for (j = 0; j <= N; j++) {
		printf("%2d", j);
		for (i = 0; i < f[j]; i += 10)
			printf("*");
		printf("\n");
	}
	free(f);
}
