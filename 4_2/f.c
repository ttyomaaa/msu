#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "f.h"
#include "func.h"
int solver(double (*f)(double), double (*d)(double), double x0, double eps, double *x)
{
    int it;
    double x1,res_x0=f(x0),d_x0=d(x0),res_x1;
    
    if (fabs(res_x0) < eps)
    {
        *x=x0;
        return 0;
    }
    
    for (it = 0; it < MAXIT; it++)
    {
	if(fabs(d_x0)<EPS_CONST) return -2;

        x1=x0-res_x0/d_x0;
        res_x1=f(x1);
        d_x0=d(x1);

        if (fabs(res_x1)<eps)
        {
            *x=x1;
            return it;
        }
        
        x0=x1;
        res_x0=res_x1;
    }

    if (it >= MAXIT) return -2;
    return it;
}