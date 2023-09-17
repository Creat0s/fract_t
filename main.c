#include <stdio.h>
#include "fract_t.h"

int main(void)
{
    fract_t x = { 2980000013, 312 };
    fract_t y = { 81256, 1278100040 };
    fract_t z, w, l = { 18, 9 };
    float val;
    
    z = fract_div(x, y);
    
    w = fract_get_fract(x);
    
    val = fract_to_float(l);
    
    printf("%lld/%lld\n", z.num, z.den);
    printf("%lld/%lld\n", w.num, w.den);
    printf("%f\n", val);
    
    return 0;
}