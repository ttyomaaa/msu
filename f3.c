#include "math.h"
#include "f3.h"
#include "matrix.h"
void f(double *a, int m, int n)
{
    int i,j,j0=0;
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
    remover(a, m, n, -1, j0);
}