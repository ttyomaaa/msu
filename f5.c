#include "math.h"
#include "f5.h"
#include "matrix.h"
int f(double *a, double *x0, double *x, double *b, double *r, int m, int n, double *n1, double *n2)
{
    int i,j,k;
    double sum,ch,zn,s1,s2;
    double eps=1e-17;

    bb(a, b, n);
    
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
            s1=0;
            s2=0;
            for (j=0;j<n;j++)
            {
                s1+=a[i*n+j]*r[j];
                s2+=a[i*n+j]*r[j]/a[j*n+j];
            }
            x[i]=s1;
            ch+=r[i]*r[i]/a[i*n+i];
            zn+=s2*r[i]/a[i*n+i];
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

