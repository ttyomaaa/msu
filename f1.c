#include "math.h"
#include "f1.h"
double f(double *a, int m, int n)
{
    int i,j;
    double s, res=-1;
    double *pi;

    for (i=0;i<m;i++)
    {
        pi=a+i*n;
        s=0;
        for (j=0;j<n;j++) s+=fabs(pi[j]);
        res=fmax(s,res);
    }

    return res;
}
