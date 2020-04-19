#include <stdio.h>
#include <math.h>
#include "matrix.h"

int read_matrix(double*a, int m,int n, const char*name)
{
FILE*fp;
 int i=0;
 int len=0;
 if(!(fp=fopen(name,"r")))
   {
     return ERROR_OPEN;
   }
len=n*m;
for(i=0;i<len;i++)
{
 if(fscanf(fp,"%lf",a+i)!=1)
   {
	fclose(fp);
        return ERROR_READ;
   }
}
fclose(fp);
return SUCCESS;
}

static double formula(int n, int i, int j)
{
	return n-fmax(i,j);
}

void init_matrix(double *a, int m, int n)
{
	int i, j;

	for(i=0;i<m;i++)
	    for(j=0;j<n;j++)
                a[i*n+j]=formula(n, i, j);
}

void print_matrix(double *a, int m, int n)
{
	int i, j, m_max, n_max;

        n_max = (n>N_MAX ? N_MAX : n);
	m_max = (m>M_MAX ? M_MAX : m);

	for(i=0;i<m_max; i++)
        {
            for(j=0;j<n_max;j++)
		printf(" %lf", a[i*n+j]);
            printf("\n");
        }
}

double nev1(double *a, double *b, double *x, int n)
{
    int i,j;
    double s,res=0;
    
    for (i=0;i<n;i++)
    {
        s=0;
        for (j=0;j<n;j++) s+=a[i*n+j]*x[j];
        res+=fabs(s-b[i]);
    }
    return res;
}

double nev2(double *x, int n)
{
    int i;
    double res=0;
    
    for(i=0;i<n;i++) res+=fabs(x[i]-(i%2));

    return res;
}

void bb(double *a, double *b, int n)
{
    int i;
    int j;
    double sum;

    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=0;j<(n+1)/2;j++)
        {
            sum+=a[i*n+2*j];
        }
        b[i]=sum;
    }
}