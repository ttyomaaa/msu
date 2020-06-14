#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "f.h"
#include "func.h"
int solver(double(*f)(double), double a, double b, double eps, double *x)
{
    int it;
    double c,res_a=f(a),res_c,res_b=f(b);
    
    if (fabs(res_a)<eps)
    {
        *x = a;
        return 0;
    }

    if (fabs(res_b)<eps)
    {
        *x = b;
        return 0;
    }

    for(it=0;it<MAXIT; it++)
    {
        c =b-(b-a)*res_b/(res_b-res_a);
	res_c=f(c);
        
        if( fabs(res_c)<eps )
	{
            *x = c;
            return it;
	}

        a = b;
	res_a = res_b;
        b = c;
	res_b = res_c;
    }    
    
    if (it >= MAXIT) return -2;
    return it;
}