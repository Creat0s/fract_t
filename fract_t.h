#ifndef FRACT_T_H
#define FRACT_T_H

#define MAX_FRACTION_MUL 3000000000L
#define MAX_FRACTION_ADD 4600000000000000000L

typedef struct
{
    long long num;
    long long den;
} fract_t;

// Checks whether a number is of type fract_t
char is_fract_t(fract_t *fct);

// GCD for numerator and denominator
long long fract_gcd(fract_t fct);

// SWAP numerator and denominator
void fract_swap(fract_t *fct);

// Integer and fractional part of a number
long long fract_get_int(fract_t fct);
fract_t fract_get_fract(fract_t fct);

// Reducing fractions
void fract_red(fract_t *fct, long long val);

// Arithmetic operations
fract_t fract_mul(fract_t fst, fract_t scd);    // Multiplication
fract_t fract_div(fract_t fst, fract_t scd);    // Division
fract_t fract_add(fract_t fst, fract_t scd);    // Addition
fract_t fract_sup(fract_t fst, fract_t scd);    // Subtraction

#endif