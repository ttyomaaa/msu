#include "math.h"
#include "f7.h"
#include "matrix.h"
void f(double *a, int m, int n)
{
    int i,j,j0=0;
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
    remover(a, m, n, -1, j0);
}
	    