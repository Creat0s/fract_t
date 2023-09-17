#include "fract_t.h"

char is_fract_t(fract_t *fct)
{
    if(fct->den == 0) return 0;
    else return 1;
}

long long fract_gcd(fract_t fct)
{
    long long tmp;
    
    while(fct.den != 0)
    {
        tmp = fct.den;
        fct.den = fct.num%fct.den;
        fct.num = tmp;
    }
    
    return fct.num;
}

void fract_swap(fract_t *fct)
{
    long long tmp;
    
    tmp = fct->num;
    fct->num = fct->den;
    fct->den = tmp;
    
    return;
}

long long fract_get_int(fract_t fct)
{
    if(!is_fract_t(&fct))
    {
        return 0;
    }
    
    return fct.num/fct.den;
}

fract_t fract_get_fract(fract_t fct)
{
    if(!is_fract_t(&fct))
    {
        return (fract_t){ 0, 0 };
    }
    else if(fct.den < 0)
    {
        fct.num *= -1;
        fct.den *= -1;
    }
    
    fct.num %= fct.den;
    
    return fct;
}

void fract_red(fract_t *fct, long long val)
{
    fct->num /= val;
    fct->den /= val;
    
    return;
}

fract_t fract_mul(fract_t fst, fract_t scd)
{
    long long tmp;
    
    if
    (
        !is_fract_t(&fst) ||
        !is_fract_t(&scd) ||
        fst.num > MAX_FRACTION_MUL ||
        fst.den > MAX_FRACTION_MUL ||
        scd.num > MAX_FRACTION_MUL ||
        scd.den > MAX_FRACTION_MUL
    )
    {
        return (fract_t){ 0, 0 };
    }
    
    tmp = fract_gcd(fst);
    fract_red(&fst, tmp);
    
    tmp = fract_gcd(scd);
    fract_red(&scd, tmp);
    
    fst.num *= scd.num;
    fst.den *= scd.den;
    
    tmp = fract_gcd(fst);
    fract_red(&fst, tmp);
    
    if(fst.num == 0)
    {
        fst.den = 0;
    }
    else if(fst.den < 0)
    {
        fst.num *= -1;
        fst.den *= -1;
    }
    
    return fst;
}

fract_t fract_div(fract_t fst, fract_t scd)
{    
    fract_swap(&scd);
    
    fst = fract_mul(fst, scd);
    
    return fst;
}

fract_t fract_add(fract_t fst, fract_t scd)
{
    long long tmp;
    
    if
    (
        !is_fract_t(&fst) ||
        !is_fract_t(&scd) ||
        fst.num > MAX_FRACTION_ADD ||
        fst.den > MAX_FRACTION_ADD ||
        scd.num > MAX_FRACTION_ADD ||
        scd.den > MAX_FRACTION_ADD
    )
    {
        return (fract_t){ 0, 0 };
    }
    else if(fst.num == 0)
    {
        if(scd.den < 0)
        {
            scd.num *= -1;
            scd.den *= -1;
        }
    
        return scd;
    }
    else if(scd.num == 0)
    {
        if(fst.den < 0)
        {
            fst.num *= -1;
            fst.den *= -1;
        }
        
        return fst;
    }
    
    tmp = fract_gcd(fst);
    fract_red(&fst, tmp);
    
    tmp = fract_gcd(scd);
    fract_red(&scd, tmp);
    
    tmp = fst.den;
    
    fst.num *= scd.den;
    fst.den *= scd.den;
    
    scd.num *= tmp;
    scd.den *= tmp;
    
    fst.num += scd.num;
    
    tmp = fract_gcd(fst);
    fract_red(&fst, tmp);
    
    if(fst.den < 0)
    {
        fst.num *= -1;
        fst.den *= -1;
    }
    
    return fst;
}

fract_t fract_sup(fract_t fst, fract_t scd)
{
    scd.num *= -1;
    
    fst = fract_add(fst, scd);
    
    return fst;
}