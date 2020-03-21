#include "math.h"
#include "f9.h"
void f(double *a, double *b, double *c, int m, int n)
{
    int i,j;
    double buf;

    for(i=0;i<m;i++)
    {
        buf=0;
        for (j=0;j<n;j++) buf+=a[i*n+j]*b[j];
        c[i]=buf;
    }
}
