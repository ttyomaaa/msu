#include "math.h"
#include "f8.h"
void f(double *a, int m, int n)
{
    int i,j;
    double b;

    for(i=m-2;i>0;i--)
    {
        b=a[i*n+m-2];
        for(j=n-2;j>0;j--) 
        {
            a[i*n+j]=(a[(i-1)*n+j]+a[(i+1)*n+j]+b+a[i*n+(j-1)])/5;
            b=a[i*n+j];
        }
    }   
}
