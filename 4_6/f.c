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

int solver(double(*f)(double), double a, double b, double eps, double *x, double *d, int m)
{
    int it,i;
    double x0,y0,y_max,h;
    
    h = (fabs(a)+fabs(b))/(m+1);

    for (i=0;i<m+1;i++)
    {
        d[i]=a+h*i;
        d[i+m+1]=a+h*i;
        d[i+2*m+2]=f(d[i]);
    }

    for (it=0;it<MAXIT;it++)
    {
        x0=newt(m+1,0,d+2*m+2,d);
        y0=f(x0);

        if (fabs(y0) < eps)
        {
            *x=x0;
            return it;
        }
        
        for (i=0;i<m+1;i++) y_max=max(fabs(y0),fabs((d+(2*m+2))[i]));


        if ((y_max>=fabs(y0))&&(y_max<=fabs(y0))) return -2;

        for (i = 0;i<m+1; i++)
        {
            if ((y_max >= fabs(d[i + 2 * m + 2])) && (y_max <= fabs(d[i + 2 * m + 2])))
            {
                d[i + m + 1] = x0;
                d[i + 2 * m + 2] = y0;
            }
        }
        
        for (i=0;i<m+1;i++) d[i]=(d+(m+1))[i];
    }
    if (it>=MAXIT) return -2;
    return it;
}