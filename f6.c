#include "math.h"
#include "f6.h"
void f(double *a, int m, int n, int i, int j)
{
    (void) m;
    int k;
    double buf;
    
    for(k=0;k<n;k++)
    {
        buf=a[i*n+k];
        a[i*n+k]=a[j*n+k];
        a[j*n+k]=buf;
    }
}
