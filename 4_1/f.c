#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "f.h"
#include "func.h"
int solver(double(*f)(double), double a, double b, double eps, double *x)
{
    int it;
    double c, res_a=f(a), res_c, res_b=f(b);
    
    if (fabs(res_a) < eps)
    {
        *x = a;
        return 0;
    }

    if (fabs(res_b) < eps)
    {
        *x = b;
        return 0;
    }

    for(it=0;it<MAXIT;it++)
    {
	c=(a+b)/2;
        
	if((b-a)<eps)
	{
            *x=c;
            return it;
	}       
        
        res_c=f(c);
        
        if (fabs(res_c)<eps)
        {
            *x = c;
            return it;
        }
        
        if (  ( (res_c>=0)&&(res_a<=0) )||( (res_c <= 0)&&(res_a >= 0) )  )
        {
            b=c;
            res_b=res_c;
        }
        else if (((res_c>=0)&&(res_b <= 0))||((res_c <= 0)&&(res_b >= 0)))
        {
            a = c;
            res_a = res_c;
        }
        else return -2;
    }
    
    if (it >= MAXIT) return -2;
    return it;
}