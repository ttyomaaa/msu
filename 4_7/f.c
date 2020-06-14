#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "f.h"
#include "func.h"
int solver(double (*f)(double), double x0, double eps, double *x)
{
    int it;
    double x1;

    for (it = 0; it < MAXIT; it++)
    {
        x1=f(x0);

        if (fabs(x1-x0)< eps)
        {
            *x=x0;
            return it;
        }
        x0=x1;
    }

    if (it >= MAXIT) return -2;
    return it;
}
