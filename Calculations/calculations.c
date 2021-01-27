#include <stdio.h>
#include <math.h>

#define EULER 0.57721
#define ERROR -1


/* Approximates value of harmonic function using formula
   H = ln(N) + y + 1/(12N) where y is euler's constant (0.57721...) */
long double harmonic_nat_log(int n);

/* Calculates the harmonic sigma function for up to N */
long double harmonic_sigma(int n);

/* Calculates lg lg N-- log_2(log_2 N) */
int calculate(int n);

/* Calculates the number of bits in lg(N!)
   In general, ceiling(lg(N + 1)) is the number of 
   bits in N, so calcaulate do ceiling(lg(N! + 1)) */
int calc_bits_in_lg_N_facotorial(int n);

/* prints out the prime numbers up to N */
void sieve_of_eratosthenes_original(int N);

/* Prints out prime numbers up to N and
  returns the number of prime numbers */
int sieve_of_eratosthenes_1(int N);

/* Prints out prime numbers less than N and
   returns the number of prime numbers */
int sieve_of_eratosthenes_num_primes(int N);



long double harmonic_nat_log(int n) {
	return log(n) + EULER + 1.0 / (12 * n);
}

long double harmonic_sigma(int n) {
	if (n < 1) {
		printf("error. n must be at least 1\n");
		return ERROR;
	}
	long double harmonic = 0;
	for (int i = 1; i <= n; i++)
		harmonic += 1.0 / i;
	return harmonic;
}



int calculate(int n) {
	if (n <= 1) {
		printf("Error. N must be at least 2\n");
		return ERROR;
	}

	int lg1 = 0,		//will be highest whole integer power of 2 that is less than or equal to n
		remainder = 0;	//calculates remainder after each division of 2
	while (n >= 2) {
		remainder += n % 2;
		n /= 2;
		lg1++;
	}
	/*If n was 9, right now lg1 would be 3 because 2^3 = 8 and remainder
	would be 1 because of step 1 where 9 % 2 = 1*/
	
	//special case if n was 3
	if (lg1 == 1 && remainder != 0)
		return 1;

	//check if 2 fits perfectly into lg1
	int lg2; 
	lg2 = remainder = 0;
	while (lg1 > 1) {
		remainder += lg1 % 2;
		lg1 /= 2;
		lg2++;
	}
	if (remainder != 0)
		return lg2 + 1;
	else
		return lg2;
}


int calc_bits_in_lg_N_facotorial(int n) {
	int factorial = 1,
		num_bits = 1,	//even 0! = 1 which is 1 bit
		remainder = 0;
	//step 1: calculate factorial and add 1
	for (int i = n; i > 1; i--)
		factorial *= i;
	factorial++;
	//step 2: calculate ceiling lg(factorial)
	int lg = 0;
	while (factorial >= 2) {
		remainder += factorial % 2;
		factorial /= 2;
		lg++;
	}
	if (remainder != 0)
		return lg + 1;
	else
		return lg;
}


void sieve_of_eratosthenes_original(int N) {
	int i, j,
		*a = (int*)malloc(sizeof(int) * N);
	if (a == NULL) {
		printf("Malloc failure\n");
		exit(1);
	}
	for (i = 2; i < N; i++)
		a[i] = 1;
	for (i = 2; i < N; i++) {
		if (a[i]) {
			for (j = i; i * j < N; j++) {
				a[i * j] = 0;
			}
		}
	}
	for (i = 2; i < N; i++)
		if (a[i])
			printf("%4d ", i);
	printf("\n");
}


int sieve_of_eratosthenes_1(int n) {
	unsigned int i, j;
	int num_primes = 0,
		*a = (int*)malloc(sizeof(int) * n);
	if (a == null) {
		printf("malloc failure\n");
		exit(1);
	}
	for (i = 2; i < n; i++)
		a[i] = 1;
	for (i = 2; i < n; i++) {
		if (a[i]) {
			for (j = i; i * j < n; j++) {
				a[i * j] = 0;
			}
		}
	}

	/*this is the part that prints out all the prime numbers
	and calculates the prime numbers. the print is
	commented out for now because i just want to print
	the total prime numbers of to n using the return statement
	but not actually print every prime number*/
	for (i = 2; i < n; i++)
		if (a[i]) {
			//printf("%4d ", i);
			num_primes++;
		}
	free(a);
	return num_primes;
}

int sieve_of_eratosthenes_num_primes(int N) {
	int i, j, num_primes = 0, *a = (int*)malloc(sizeof(int) * N);
	if (a == NULL) { printf("Malloc failure\n"); exit(1);
	}
	for (i = 2; i < N; i++)
		a[i] = 1;
	for (i = 2; i < N; i++)
		if (a[i])
			for (j = i; i * j < N; j++)
				a[i * j] = 0;
	for (i = 2; i < N; i++)
		if (a[i])
			num_primes++;
	free(a);
	
	return num_primes;
}
