#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "f.h"
#include "func.h"
static double newt(int n,double x0, double *x, double *y)
{
    int i,j,k=1;
    double res=0;
    
    for (j=n-1;j>0;j--)
    {
        for (i=0;i<j;i++)
        {
            y[n-1-i]=(y[n-1-i]-y[n-i-2])/(x[n-i-1]-x[n-i-1-k]);
        }
        k++;
    }
    res=y[n-1];
    for (i=n-1;i>0;i--)
    {
        res*=(x0-x[i-1]);
        res+=y[i-1];
    }
    
    return res;
}

static double max(double a1, double a2)
{
    if (a1>=a2) return a1;
    else return a2;
}

static double min(double a1, double a2)
{
    if (a1<=a2) return a1;
    else return a2;
}

int solver(double(*f)(double), double a, double b, double eps, double *x)
{
    int it,i;
    double xx[4],yy[4],yy_b[4],y_max=f(a), x_max=a, y_min, h;
    
    xx[0] = a;
    xx[1] = b;
    xx[2] = (a+b)/2;
    
    yy[0]=f(a);
    yy[1]=f(b);
    yy[2] = f(xx[2]);
    
    yy_b[0]=yy[0];
    yy_b[1]=yy[1];
    yy_b[2]=yy[2];

    for (it=0;it<MAXIT;it++)
    {
        x0=newt(3, 0, yy, xx_b);
        y0=f(x0);

        if (fabs(y0) < eps)
        {
            *x = x0;
            return it;
        }

        for (i=0;i<3;i++) y_max=max(fabs(y0),fabs(yy[i]));

        if ((y_max>=fabs(y0))&&(y_max<=fabs(y0))) return -2;

        for (i=0;i<3;i++)
        {
            if ((y_max>=fabs(yy[i]))&&(y_max<=fabs(yy[i])))
            {
                xx[i] = x0;
                yy[i] = y0;
            }
        }

        for (i=0;i<3;i++) xx_b[i]=xx[i];
    }
    if (it >= MAXIT) return -2;
    return it;
}

/*
 for (it = 0; it < MAXIT; it++)
    {
        if (fabs(h) < eps)
        {
            *x = y_maxima;
            return it;
        }

        for (i = 0; i < 3; i++)
        {
            divided_difference(3, i, xx, yy_diff);
        }

        x_maxima = (-1) * yy_diff[1] / 2 / yy_diff[2];
        y_maxima = func(x_maxima);

        y_min = minimum(y_maxima, yy, 3);

        if (y_min == y_maxima)
            return ERROR;

        for (i = 0; i < 3; i++)
        {
            if (y_min == yy[i])//?
            {
                xx[i] = x_maxima;
                yy[i] = y_maxima;
            }
        }

        a = minimum(x_maxima, xx, 3);
        b = maximum(x_maxima, xx, 3);

        h = b - a;

        replace(yy, yy_diff, 3);
    }
*/