#include "math.h"
#include "f11.h"
static void ff_lines(double *a, int m, int n, int i, int j)
{
    int k;
    double buf;
    (void) m;
    
    for(k=0;k<n;k++)
    {
        buf=a[i*n+k];
        a[i*n+k]=a[j*n+k];
        a[j*n+k]=buf;
    }
}

static void ff_columns(double *a, int m, int n, int i, int j)
{
    int k;
    double buf;

    for(k=0;k<m;k++)
    {
        buf=a[k*n+i];
        a[k*n+i]=a[k*n+j];
        a[k*n+j]=buf;
    }
}

void f(double *a, int m, int n)
{
    int i,j,max_i=0,max_j=0;
    double max=-1;

    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            if (a[i*n+j]>max)
            {
                max=a[i*n+j];
                max_i=i;
                max_j=j;
            }
        }
    }

    ff_lines(a, m, n, max_i, 0);
    ff_columns(a, m, n, max_j, 0);
}
	    