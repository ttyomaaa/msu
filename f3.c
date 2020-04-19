#include "math.h"
#include "stdio.h"
#include "f3.h"
#include "matrix.h"
int f(double *a, double *x0, double *x, double *b, double *r, int m, int n, double *n1, double *n2)
{
    int i,j,k;
    double sum,ch,zn;
    double eps=1e-17;

    bb(a, b, n);
    print_matrix(b,1,n);
    printf("\n");

    for(k=0;k<n;k++)
    {
        sum=0;
        for (j=0;j<n;j++) sum+=a[k*n+j]*x0[j];
        r[k]=sum-b[k];
    }

    for(k=0;k<m;k++)
    {
        ch=0;
        zn=0;
        for (i=0;i<n;i++)
        {
            sum=0;
            for(j=0;j<n;j++) sum+=a[i*n+j]*r[j];
            
            x[i]=sum;
            ch+=r[i]*r[i];
            zn+=r[i]*sum;
        }

        if (fabs(zn)<eps)
        {
            for(i=0;i<n;i++) x[i]=x0[i];
            *n1=nev1(a, b, x, n);
            *n2=nev2(x, n);
            return 0;
        }
        
        for(i=0;i<n;i++) x0[i]-=r[i]*ch/zn;
        for(i=0;i<n;i++) r[i]-=x[i]*ch/zn;
    }
    for(i=0;i<n;i++) x[i]=x0[i];

    *n1=nev1(a, b, x, n);
    *n2=nev2(x, n);

    return 0;
}