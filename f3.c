#include "math.h"
#include "f3.h"
void f(double *a, int n)
{
    int i,j;
    double buf;
    
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
        {
            buf=a[i*n+j];
            a[i*n+j]=a[j*n+i];
            a[j*n+i]=buf;
        }

}