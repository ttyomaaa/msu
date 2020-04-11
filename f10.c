#include "math.h"
#include "f10.h"
#include "matrix.h"
void f(double *a, int m, int n)
{
    int i,j,j0=0,i0=0;
    double sum, min_res, res, buf;

    for(j=0;j<n;j++)
    {
        res=0;
        sum=0;
        
        for(i=0;i<m;i++) sum+=a[i*n+j];
        
        sum/=m;
        
        for(i=0;i<m;i++)
        {
            buf=a[i*n+j]-sum;
            res+=buf*buf;
        }

        if (j==0) min_res=res;
        else if (res<min_res)
        {
            min_res=res;
            j0=j;
        }
    }
    
    for(i=0;i<m;i++)
    {
        res=0;
        sum=0;
        
        for(j=0;j<n;j++) sum+=a[i*n+j];
        
        sum/=n;
        
        for(j=0;j<n;j++)
        {
            buf=a[i*n+j]-sum;
            res+=buf*buf;
        }

        if (i==0) min_res=res;
        else if (res<min_res)
        {
            min_res=res;
            i0=i;
        }
    }
    remover(a, m, n, i0, j0);
}
