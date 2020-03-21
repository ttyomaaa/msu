#include "math.h"
#include "f10.h"
void f(double *a, double *b, double *c, int m, int n, int k)
{
    int i,j,l;
    double buf;

    for (i=0;i<m;i++)
    {
        for(j=0;j<k;j++)
        {
            buf=0;
            for (l=0;l<n;l++) buf+=a[i*n+l]*b[l*k+j];
            c[i*k+j]=buf;
        }
    }
}
