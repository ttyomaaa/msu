#include "math.h"
#include "f2.h"
#include "matrix.h"
void f(double *a, int m, int n)
{
    int i,j,j0=0,i0=0;
    double min_a=fabs(a[0]);
    
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            if (fabs(a[i*n+j])<min_a)
            {
                min_a=fabs(a[i*n+j]);
                j0=j;
                i0=i;
            }
        }
    }
    remover(a, m, n, i0, j0);
}
