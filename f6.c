#include "math.h"
#include "f6.h"
double f(double *A, double *B, int m, int n)
{
    int i,j,k;
    double *pj, *pk;
    double buf, sum, res=-1;
        
    for (i=0;i<m;i++)
    {
        pk=B+i;
        sum=0;
        for(j=0;j<m;j++)
        {
            pj=A+j*n;
            if (i==j) buf=-1;
            else buf=0;
            
            for (k=0;k<n;k++) buf+=pj[k]*pk[k*m];
            
            sum+=fabs(buf);
        }
    res=fmax(sum,res);
    }
    return res;
}