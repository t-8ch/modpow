#include <stdbool.h>

#include "modpow.h"

static bool zero(const mpz_t input) {
	return mpz_cmp_d(input, 0) == 0;
}

static void shift_right(mpz_t input) {
	(void) mpz_tdiv_q_2exp(input, input, 1);
}

static bool last_bit_set(const mpz_t input) {
	return mpz_tstbit(input, 0) == 1;
}

static void square(mpz_t input) {
	mpz_mul(input, input, input);
	return;
}

static void mod(mpz_t input, const mpz_t modulus) {
	mpz_mod(input, input, modulus);
	return;
}

void mod_pow(mpz_t result, const mpz_t base, const mpz_t exponent, const mpz_t modulus) {
	mpz_t current_squared, current_exponent, res;

	mpz_init_set(current_squared, base);
	mpz_init_set(current_exponent, exponent);
	mpz_init_set_ui(res, 1);

	while(!zero(current_exponent)) {

		if (last_bit_set(current_exponent)) {
			mpz_mul(res, res, current_squared);
			mod(res, modulus);
		}

		square(current_squared);
		mod(current_squared, modulus);

		shift_right(current_exponent);
	}

	mpz_set(result, res);
	mpz_clears(current_squared, current_exponent, res, NULL);
	return;
}
