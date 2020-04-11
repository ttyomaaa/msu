#include "math.h"
#include "f10.h"
void f(double *a, int m, int n)
{
    int i,j;
    double b;

    for(i=m-2;i>0;i--)
    {
        b=a[i*n];
        for(j=1;j<n-1;j++) 
        {
            a[i*n+j]=(a[(i-1)*n+j]+a[(i+1)*n+j]+a[i*n+(j+1)]+b)/5;
            b=a[i*n+j];
        }
    }   
}
