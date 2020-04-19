#include "math.h"
#include "f2.h"
#include "matrix.h"
void f(double *a, double *x0, double *x, double *b, int m, int n, double tu, double *n1, double *n2)
{
    int i,j,k;
    double sum=0;
    
    bb(a,b,n);
     
    for(k=0;k<m;k++)
    {
        for(i=0;i<n;i++)
        {
            sum=0;
            for(j=0;j<n;j++) sum+=a[i*n+j]*x0[j];
            x[i]=(b[i]-sum)*tu+x0[i];
        }
    for(i=0;i<n;i++) x0[i]=x[i];
    }
    
    *n1=nev1(a, b, x, n);
    *n2=nev2(x, n);
}
