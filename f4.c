#include "math.h"
#include "f4.h"
#include "matrix.h"
void f(double *a, int m, int n)
{
    int i,j,j0=0,i0=0;
    double sum, min_sum;

    for(j=0;j<n;j++)
    {
        sum=0;
        
        for(i=0;i<m;i++) sum+=fabs(a[i*n+j]);
        
        if (j==0) {min_sum=sum;continue;}

        if (sum<min_sum)
        {
            min_sum=sum;
            j0=j;
        }
    }
    
    for (i=0;i<m;i++)
    {
        sum = 0;

        for (j=0;j<n;j++) sum+=fabs(a[i*n+j]);

        if (i==0) {min_sum=sum;continue;}
        
        if (sum<min_sum)
        {
            min_sum = sum;
            i0=i;
        }
    }
    remover(a, m, n, i0, j0);
}