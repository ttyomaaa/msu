#include "math.h"
#include "f6.h"
#include "matrix.h"
void f(double *a, int m, int n)
{
    int i,j,j0=0;
    double sum, max_sum=-1,ajj;

    for(j=0;j<n;j++)
    {
        sum=0;
        ajj=a[j*n+j];
        
        for(i=0;i<m;i++) if (i!=j) sum+=fabs(a[i*n+j]-ajj);        

        if (sum>max_sum)
        {
            max_sum=sum;
            j0=j;
        }
    }
    remover(a, m, n, -1, j0);
}