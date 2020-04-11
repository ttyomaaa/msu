#include "math.h"
#include "f9.h"
#include "matrix.h"
void f(double *a, int m, int n)
{
    int i, j, k, l, j0=0, i0=0;
    double sum, sum1, sum2, max_sum=-1, aij;
    
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            sum1=0;
            sum2=0;
            aij=a[i*n+j];

            for(k=0;k<n;k++) sum1+=fabs(a[i*n+k]-aij);

            for(l=0;l<m;l++) sum2+=fabs(a[l*n+j]-aij);

            sum=sum1+sum2;
            
            if (sum>max_sum)
            {
                max_sum=sum;
                i0=i;
                j0=j;
            }
        }
    }
    remover(a, m, n, i0, j0);
}