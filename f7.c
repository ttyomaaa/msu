#include "math.h"
#include "f7.h"
void f(double *a, int m, int n, int i, int j)
{
    int k;
    double buf;

    for(k=0;k<m;k++)
    {
        buf=a[k*n+i];
        a[k*n+i]=a[k*n+j];
        a[k*n+j]=buf;
    }
}
