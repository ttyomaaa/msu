#include "math.h"
#include "f4.h"
double f(double *A, double *b, double *x, int m, int n)
{
    int i,j;
    double buf, res=-1;
    double *pi;

    for(i=0;i<m;i++)
    {
        pi=A+i*n;
	buf=0;
	for(j=0;j<n;j++)
	{
            buf+=pi[j]*x[j];
	}
	buf=fabs(buf-b[i]);
        buf=fmax(buf,res);
    }

    return res;
}