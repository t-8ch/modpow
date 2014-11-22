#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include <gmp.h>

static bool zero(const mpz_t input) {
	return mpz_cmp_d(input, 0) == 0;
}

static void shift_right(mpz_t input) {
	(void) mpz_tdiv_q_2exp(input, input, 1);
}

static bool last_bit_set(const mpz_t input) {
	/* FIXME this work in O(1) */
	return mpz_scan1(input, 0) == 0;
}

static void square(mpz_t input) {
	mpz_mul(input, input, input);
	return;
}

static void mod(mpz_t input, const mpz_t modulus) {
	mpz_mod(input, input, modulus);
	return;
}

static bool read_arg(const char *argument, mpz_t *target) {
	return 1 == gmp_sscanf(argument, "%Zd", target);
}

void mod_pow(mpz_t result, const mpz_t base, const mpz_t exponent, const mpz_t modulus) {
	mpz_t current_squared, current_exponent, res;

	mpz_init_set(current_squared, base);
	mpz_init_set(current_exponent, exponent);
	mpz_init_set_ui(res, 1);

	while(!zero(current_exponent)) {
		square(current_squared);
		mod(current_squared, modulus);

		if (last_bit_set(current_exponent)) {
			mpz_mul(res, res, current_squared);
			mod(res, modulus);
		}

		shift_right(current_exponent);
	}

	mpz_set(result, res);
	mpz_clears(current_squared, current_exponent, res, NULL);
	return;
}

int main(int argc, char **argv) {
	mpz_t result, base, exponent, modulus;

	if (4 != argc) {
		fprintf(stderr, "Usage: %s <base> <exponent> <modulus>",
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
