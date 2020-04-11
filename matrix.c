#include <stdio.h>
#include <math.h>
#include "matrix.h"

int read_matrix(double *a, int m, int n, const char *name)
{
	FILE *fp;
	int i,j;

	if( !(fp=fopen(name, "r"))) return ERROR_OPEN;
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                if(fscanf(fp,"%lf",a+i*n+j)!=1)
                {
                    fclose(fp);
                    return ERROR_READ;
                }
	fclose(fp);
	return SUCCESS;
}

static double formula(int m, int n, int i, int j)
{
	return fmax(m,n)-fmax(i,j);
}

void init_matrix(double *a, int m, int n)
{
	int i, j;

	for(i=0;i<m;i++)
	    for(j=0;j<n;j++)
                a[i*n+j]=formula(m, n, i, j);
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

void remover(double *a, int m, int n, int i0, int j0)
{
    int i,j,step=0;
    double *pi;

    for(i=0;i<m;i++)
    {
        pi=a+i*n;
        if (i==i0) step+=n;
        else 
            for(j=0;j<n;j++)
            {
                if (j==j0) step++;
                else pi[j-step]=pi[j];
            }
    }
}
