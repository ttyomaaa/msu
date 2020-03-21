#include "math.h"
#include "f8.h"
void f(double *a, int m, int n, int i, int j, double b)
{
    (void) m;
    int k;
    double buf;

    for(k=0;k<n;k++)
    {
        buf=a[j*n+k]+a[i*n+k]*b;
        a[k+j*n]=buf;
    }
}
