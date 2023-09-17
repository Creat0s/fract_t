# fract_t

**fract_t** is a simple data structure for *C99+*, consisting of two variables of
type *long long*, representing the numerator *.num* and the denominator *.den* of
a fraction. It allows you to work with rational numbers of small sizes and has
certain limitations. The library includes all the necessary arithmetic operations,
as well as functions for converting to basic types *float* and *double*.

## Goal

This library was not created for computational purposes and has many limitations.
It is primarily designed to demonstrate how familiar fractions would look on a
computer and approximately how they would work with them. The **main.c** file
serves as an example and is not part of the library itself.

## Variable Declaration

> fract_t <name> = { <num>, <den> };

If the number is negative, assign the numerator *.num* a negative value. Do not
declare variables with a denominator *= 0*; otherwise, any operations with this
number will result in *0/0*.

If the numerator's value is *= 0*, some operations with it will also return *0/0*.
This is a special value that prevents further errors.

## Limitations

The actual valid range of values for both the numerator and denominator is
*9223372036854775807*; however, for arithmetic operations, this range is
significantly smaller.

For multiplication and division, a limiter is used: *MAX_FRACTION_MUL*
> MAX_FRACTION_MUL = 3000000000L / -3000000000L

For addition and subtraction, a limiter is used: *MAX_FRACTION_ADD*
> MAX_FRACTION_ADD = 4600000000000000000L / -4600000000000000000L

The result of calculations may be greater or less than these limits.
Limiters exist to ensure that you do not exceed the maximum allowed value
for *long long*.

If a number exceeds the limiter, performing arithmetic operations will return *0/0*.

## Arithmetic Operations

- fract_mul(fst, scd)   Product of two numbers
- fract_div(fst, scd)   Quotient of two numbers
- fract_add(fst, scd)   Sum of two numbers
- fract_sub(fst, scd)   Difference of two numbers

When performing arithmetic operations, the fraction is automatically reduced.

- fract_red(\*fct, val) Reduces the numerator and denominator by the value *val*.

## Conversion to Floating-Point Numbers

The functions *fract_to_float()* and *fract_to_double()* allow you
to convert *fract_t* to a decimal fraction.

## Additional Information

You can also obtain the integer and fractional parts of a number using the
*fract_get_int()* and *fract_get_fract()* functions. The integer part is returned
with the type *long long*, and the fractional part with the type *fract_t*.
You can read about the other functions in the header file **fract_t.h**.