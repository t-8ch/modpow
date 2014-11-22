#define _POSIX_C_SOURCE 199309L

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "modpow.h"

static long rounds = 1000000;
static long base = 1234567890987654321;
static long exponent = 1234567890987654321;
static long modulus =  1234567890;

int main() {
	mpz_t result, base_m, exponent_m, modulus_m;
	struct timespec start, stop;
	long i;

	mpz_init(result);
	mpz_init_set_ui(base_m, base);
	mpz_init_set_ui(exponent_m, exponent);
	mpz_init_set_ui(modulus_m, modulus);

	mod_pow(result, base_m, exponent_m, modulus_m);

	gmp_printf("Calculating %ld^%ld mod %ld\n", base, exponent, modulus);
	gmp_printf("The result is: %Zd\n", result);

	clock_gettime(CLOCK_THREAD_CPUTIME_ID, &start);
	for(i = 0; i < rounds; i++) {
		mod_pow(result, base_m, exponent_m, modulus_m);
	}
	clock_gettime(CLOCK_THREAD_CPUTIME_ID, &stop);

	printf("%ld rounds took %ld seconds and %ld nanoseconds\n",
			rounds, stop.tv_sec - start.tv_sec,
			stop.tv_nsec - start.tv_nsec);

	return EXIT_SUCCESS;
}
