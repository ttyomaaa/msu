#include "math.h"
#include "f7.h"
void f(double *a, int m, int n)
{
    int i,j;
    double b;
    
    for(i=1;i<m-1;i++)
    {
        b=a[i*n];
        for(j=1;j<n-1;j++) 
        {
            a[i*n+j]=(a[(i-1)*n+j]+a[(i+1)*n+j]+a[i*n+(j+1)]+b)/5;
            b=a[i*n+j];
        }
    }   
     
}
	    