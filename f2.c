#include "math.h"
#include "f2.h"
double f(double *a, int m, int n)
{
    int i,j;
    double s, res=-1;
    double *pj;

    for (j=0;j<n;j++)
    {
        pj=a+j;
        s=0;
        for (i=0;i<m;i++) s+=fabs(pj[i*n]);
        res=fmax(s,res);
    }

    return res;
}
