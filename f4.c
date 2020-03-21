#include "math.h"
#include "f4.h"
void f(double *a, int n)
{
    int i,j;
    
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
        {
            a[i*n+j]=(a[i*n+j]+a[j*n+i])/2;
            a[j*n+i]=a[i*n+j];
        }
}