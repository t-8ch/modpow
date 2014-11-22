#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "modpow.h"

static bool read_arg(const char *argument, mpz_t *target) {
	return 1 == gmp_sscanf(argument, "%Zd", target);
}

int main(int argc, char **argv) {
	mpz_t result, base, exponent, modulus;

	if (4 != argc) {
		fprintf(stderr, "Usage: %s <base> <exponent> <modulus>\n",
				argv[0]);
		return EXIT_FAILURE;
	}

	mpz_inits(result, base, exponent, modulus, NULL);

	if (
			!read_arg(argv[1], &base) ||
			!read_arg(argv[2], &exponent) ||
			!read_arg(argv[3], &modulus)
			) {
		return EXIT_FAILURE;
	}

	mod_pow(result, base, exponent, modulus);
	gmp_printf("Result: %Zd\n", result);
	return EXIT_SUCCESS;
}
