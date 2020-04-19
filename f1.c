#include "math.h"
#include "f1.h"
#include "matrix.h"
double f(double *a, double *x0, double *x, int m, int n)
{
    int i,j,k;
    double res,sc,ch=0,zn=0;

    for (k=0;k<m;k++)
    {
        for(i=0;i<n;i++)
        {
            sc=0;
            for(j=0;j<n;j++) sc+=a[i*n+j]*x0[j];
            x[i]=sc;
        }
        for (i=0;i<n;i++) x0[i]=x[i];
    }
    for(i=0;i<n;i++)
    {
        sc=0;
        for(j=0;j<n;j++) sc+=a[i*n+j]*x0[j];
        ch+=sc*x0[i];
        zn+=x0[i]*x0[i];
    }
    for (i=0;i<n;i++) x[i]=x0[i];
    
    res=ch/zn;
    return res;
}
