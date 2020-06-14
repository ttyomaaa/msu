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

int solver(double(*f)(double), double a, double b, double eps, double *x)
{
    int it,i;
    double x0,y0,xx[4],yy[4],xx_b[4],y_max;
    
    xx[0] = a;
    xx[1] = b;
    xx[2] = (a+b)/2;
    
    yy[0]=f(a);
    yy[1]=f(b);
    yy[2] = f(xx[2]);
    
    xx_b[0]=xx[0];
    xx_b[1]=xx[1];
    xx_b[2]=xx[2];

    if (((xx[2]>= xx[1])&&(xx[2]<=xx[1]))||((xx[2]>=x[0])&&(xx[2]<=xx[0]))) return -2;

    if (fabs(yy[0])<eps)
    {
        *x = xx[0];
        return 0;
    }

    if (fabs(yy[1])<eps)
    {
        *x = xx[1];
        return 0;
    }

    if (fabs(yy[2])<eps)
    {
        *x = xx[2];
        return 0;
    }

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