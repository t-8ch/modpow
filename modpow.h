#ifndef __MODPOW_H__

#include <gmp.h>

void mod_pow(mpz_t result, const mpz_t base, const mpz_t exponent, const mpz_t modulus);

#define __MODPOW_H__
#endif
