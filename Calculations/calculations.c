#include <stdio.h>
#include <math.h>

#define EULER 0.57721
#define ERROR -1


/* Approximates value of harmonic function using formula
   H = ln(N) + y + 1/(12N) where y is euler's constant (0.57721...) */
long double harmonic_nat_log(unsigned n);

/* Calculates the harmonic function for up to N. This is one not an approximation */
long double harmonic_sigma(unsigned n);

/* Calculates ceiling of lg lg N...ceil(log_2(log_2(N))) without library math functions */
unsigned calculate(unsigned n);

/* Calculates the number of bits in teh binary representation of lg(N!)
   In general, ceiling(lg(N + 1)) is the number of 
   bits in N, so calcaulate do ceiling(lg(N! + 1)) */
long unsigned calc_bits_in_lg_N_facotorial(long unsigned n);

/* prints out the prime numbers up to N */
void sieve_of_eratosthenes_original(long unsigned N);

/* Prints out prime numbers up to N and
   returns the number of prime numbers */
unsigned sieve_of_eratosthenes_1(long unsigned N);

/* returns the number of prime numbers */
unsigned sieve_of_eratosthenes_num_primes(long unsigned N);



int main(int argc, char *argv[]) {
	printf("CALCULATION 1\n");
	printf("Implementing the functions to calculate the harmonic sigma function, as well as a function to\n"
		"approximate it. As N increases, the approximation will become more accurate\n");
	for (unsigned i = 1; i <= 9; i++) {
		unsigned N = pow(10, i);
		printf("Calculating the harmonic function with N = %d\n", N);
		printf("Real value: %lf\tApproximation: %lf\n\n", harmonic_sigma(N), harmonic_nat_log(N));
	}
	printf("\n\n\n");
	
	printf("CALCULATION 2\n");
	printf("Implementing the function to calculate ceil(lg(lg(N))) without built in library functions\n");
	for (unsigned i = 1; i <= 9; i++) {
		unsigned N = pow(10, i);
		printf("lg(lg(%d)) = %d\n", N, calculate(N));
	}
	printf("\n\n\n");

	printf("CALCULATION 3\n");
	printf("Implementing the function to calculate the number of bits in the binary representation of lg(N!)\n");
	for (unsigned i = 0; i <= 13; i++) {
		printf("Number of bits in binary representation of lg(%d!) = %d\n", i, calc_bits_in_lg_N_facotorial(i));
	}
	printf("\n\n\n");
	
	printf("CALCULATION 4\n");
	printf("Implementing the function prints out and calculates all of the prime numbers up to some integer N\n");
	long unsigned N = 1000;
	unsigned num_primes = sieve_of_eratosthenes_1(N);
	printf("Number of prime numbers less than %d: %d\n\n\n", N, num_primes);
	printf("\n\n\n");
	
	printf("CALCULATION 5\n");
	printf("This will print out the number of primes less than a particular number for all numbers up to some integer N\n");
	int num_primes, a[N1], i, j;
	for (i = 1; i < N1; i++)
		a[i] = sieve_of_eratosthenes_num_primes(i);
	for (i = 1; i < N1; i++) {
		if (i == 1 || i % 24 == 0) {
			printf("%-8c:", 'N');
			for (j = i; j < i + 24 && j < N1; j++)
				printf("%4d", j);
			printf("\n");
			printf("%-8s:", "Primes");
			for (j = i; j < i + 24 && j < N1; j++)
				printf("%4d", a[j]);
			printf("\n\n");
		}
	}
	printf("\n\n\n");
	return 0;
}



long double harmonic_nat_log(long unsigned n) {
	return log(n) + EULER + 1.0 / (n * (long unsigned)12);
}

long double harmonic_sigma(unsigned n) {
	if (n < 1) {
		printf("error. n must be at least 1\n");
		return ERROR;
	}
	long double harmonic = 0;
	for (int i = 1; i <= n; i++)
		harmonic += 1.0 / i;
	return harmonic;
}

unsigned calculate(unsigned n) {
	if (n <= 1) {
		printf("Error. N must be at least 2\n");
		return ERROR;
	}

	unsigned lg1 = 0,		//will be highest whole integer power of 2 that is less than or equal to n
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
	unsigned lg2; 
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


long unsigned calc_bits_in_lg_N_facotorial(long unsigned n) {
	long unsigned factorial = 1,
		num_bits = 1,	//even 0! = 1 which is 1 bit
		remainder = 0;
	//step 1: calculate factorial and add 1
	for (int i = n; i > 1; i--)
		factorial *= i;
	factorial++;
	//step 2: calculate ceiling lg(factorial)
	long unsigned lg = 0;
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


void sieve_of_eratosthenes_original(long unsigned N) {
	long unsigned i, j;
	int *a = (int*)malloc(sizeof(int) * N);
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
	for (i = 2; i < N; i++) {
		if (a[i])
			printf("%4d\n", i);
	}
	printf("\n");
}


unsigned sieve_of_eratosthenes_1(long unsigned N) {
	long unsigned i, j;
	unsigned num_primes = 0;
	int *a = (int*)malloc(sizeof(int) * N);
	if (a == NULL) {
		printf("malloc failure\n");
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

	for (i = 2; i < N; i++) {
		if (a[i]) {
			printf("%4d\n", i);
			num_primes++;
		}
	}

	free(a);
	return num_primes;
}


unsigned sieve_of_eratosthenes_num_primes(long unsigned N) {
	long unsigned i, j; 
	unsigned num_primes = 0;
	int *a = (int*)malloc(sizeof(int) * N);

	if (a == NULL) { 
		printf("Malloc failure\n"); 
		exit(1);
	}
	for (i = 2; i < N; i++)
		a[i] = 1;
	
	for (i = 2; i < N; i++)
		if (a[i])
			for (j = i; i * j < N; j++)
				a[i * j] = 0;
	
	for (i = 2; i < N; i++) {
		if (a[i])
			num_primes++;
	}
	free(a);
	
	return num_primes;
}
