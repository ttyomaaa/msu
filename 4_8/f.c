#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "f.h"
#include "func.h"
int solver(double(*f)(double), double a, double b, double eps, double *x)
{
    int it;
    double h=(fabs(a)+fabs(b))/10,x0=a,x1=a+h;
    
    if (fabs(h)<eps)
    {
        *x = f(x0);
        return 0;
    }

    for (it=0;it<MAXIT;it++)
    {
        if (fabs(h) < eps)
        {
            *x=f(x1);
            return it;
        }

        if ((f(x0)<f(x1)))
        {
            if (!(x1+h<b)) h/=10;
            x0=x1;
            x1+=h;
        }
        else if ((f(x0)>f(x1)))
        {
            h =(-1)*h;
            if (!(x1+h>b)) h/=10;
            x0=x1;
            x1+=h;
        }
        else return -2;
    }

    if (it >= MAXIT) return -2;
    return it;
}