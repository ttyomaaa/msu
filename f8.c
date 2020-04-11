#include "math.h"
#include "f8.h"
#include "matrix.h"
void f(double *a, int m, int n)
{
    int i, j, k, j0=0, i0=0;
    double sum, sum1, sum2, max_sum=-1;

    for(i=0;i<m;i++)
    {
        sum1=0;

        for(k=0;k<n;k++) sum1+=fabs(a[i*n+k]);

        for(j=0;j<n;j++)
        {
            sum2=0;

            for(k=0;k<m;k++) sum2+=fabs(a[k*n+j]);

            sum=sum1+sum2-2*a[i*n+j];

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
