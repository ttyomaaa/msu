#include "math.h"
#include "f5.h"
double f(double *A, double *B, int m, int n)
{
    int i,j,k;
    double *pi, *pk;
    double buf, sum, res=-1;
        
    for (i=0;i<m;i++)
    {
        pi=A+i*n;
        sum=0;
        for(j=0;j<m;j++)
        {
            pk=B+j;
            if (i==j) buf=-1;
            else buf=0;
            
            for (k=0;k<n;k++) buf+=pi[k]*pk[k*m];
            
            sum+=fabs(buf);
        }
    res=fmax(sum,res);
    }
    return res;
}
