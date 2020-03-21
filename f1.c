#include "math.h"
#include "f1.h"
int f(double *a, int n)
{
    int i,j;
    
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(fabs(a[i*n+j]-a[j*n+i])>0) return 0;

    return 1;
}