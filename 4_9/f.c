#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "f.h"
#include "func.h"
int solver(double (*f)(double), double a, double b, double eps, double *x)
{
    int it;
    double g=(1+sqrt(5))/2, x1, x2, y1, y2;

    x1=a+(b-a)/(g+1);
    x2=b-(b-a)/(g+1);
    y1=f(x1);
    y2=f(x2);
    for(it=0;it<MAXIT;it++)
    {
        if (y1<y2)
	{
            a = x1;
            x1 = x2;
            y1 = y2;
            x2 = b-(b-a)/(g+1);
            y2 = f(x2);
	}
        else
	{
            b = x2;
            x2 = x1;
            y2 = y1;
            x1 = a+(b-a)/(g+1);
            y1 = f(x1);
	}
        
	if(fabs(b-a)<eps)
        {
            *x=(a+b)/2;
            return it;
	}
    }
    if (it >= MAXIT) return -2;
    return it;
}