#include <stdio.h>
#include "fract_t.h"

int main(void)
{
    fract_t x = { 2980000013, 312 };
    fract_t y = { 81256, 1278100040 };
    fract_t z, w;
    
    z = fract_mul(x, y);
    w = fract_get_fract(x);
    
    printf("%lld/%lld\n", z.num, z.den);
    printf("%lld/%lld", w.num, w.den);
    return 0;
}