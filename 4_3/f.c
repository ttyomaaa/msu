#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "f.h"
#include "func.h"
int solver(double(*f)(double), double a, double b, double eps, double *x)
{
    int it;
    double c, res_a = f(a),res_b = f(b), res_c;
    
    if (fabs(res_a)<eps)
    {
        *x=a;
        return 0;
    }
    
    if (fabs(res_b)<eps)
    {
        *x=b;
        return 0;
    }

    for(it=0;it<MAXIT;it++)
    {
        if( (b-a)<eps)
        {
            *x = (a+b)/2;
            return it;
        }
        
        c=a-res_a*(b-a)/(res_b-res_a);
	if( (a<=c && a>=c) || (b<=c && b>=c) ) return -2;
        
	res_c = f(c);
        
	if( res_a*res_c<=0 )
	{
            b=c;
            res_b=res_c;
	}
	else
	{
            a=c;
            res_a=res_c;
	}
    }
    if (it>=MAXIT) return -2;
    return it;
}