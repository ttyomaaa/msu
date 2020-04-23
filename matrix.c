#include <stdio.h>
#include <math.h>
#include "matrix.h"

int read_matrix(double *a, int n, const char *name)
{
    FILE *fp;
    int i, len=n*n;

    if (!(fp=fopen(name, "r"))) return ERROR_OPEN;

    for (i=0;i<len;i++)
        if (fscanf(fp,"%lf",a+i)!=1)
        {
            fclose(fp);
            return ERROR_READ;
        }
    fclose(fp);
    return SUCCESS;
}

static double formula1(int n, int i, int j)
{
	return n-fmax(i,j);
}

static double formula2(int i, int j)
{
	return fmax(i,j);
}

static double formula3(int i, int j)
{
	return fabs(i-j);
}

static double formula4(int i, int j)
{
	return 1.0/(i+j+1);
}

void init_matrix(double *a, int n, int k)
{
	int i, j;
        
        switch(k)
        {
            case 1:
            for(i=0;i<n;i++)
                for(j=0;j<n;j++)
                    a[i*n+j]=formula1(n, i, j);
            break;
            
            case 2:
            for(i=0;i<n;i++)
                for(j=0;j<n;j++)
                    a[i*n+j]=formula2(i, j);
            break;
            
            case 3:
            for(i=0;i<n;i++)
                for(j=0;j<n;j++)
                    a[i*n+j]=formula3(i, j);
            break;
            
            case 4:
            for(i=0;i<n;i++)
                for(j=0;j<n;j++)
                    a[i*n+j]=formula4(i, j);
            break;
        }
}

void print_matrix(double *a, int m, int l, int n)
{
    int i,j,n_min,l_min,l_max,n_max;
        
    n_min=fmin(m,n);
    l_min=fmin(l,n);
        
    n_max = (n_min > N_MAX ? N_MAX : n_min);
    l_max = (l_min > L_MAX ? L_MAX : l_min);
        
    for(i=0;i<l_max;i++)
    {
        for(j=0;j<n_max;j++)
            printf(" %10.3e", a[i*n+j]);
        printf("\n");
    }
}

void init_b(double *a, double *b, int n)
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


double residual(double *a, double *b, double *x, int n)
{
    int i,j;
    double tmp,res=0;

    for(i=0;i<n;i++)
    {
        tmp=0;
	for(j=0;j<n;j++) tmp+=a[i*n+j]*x[j];
	tmp-=b[i];
	res+=tmp*tmp;
    }
    
    tmp=0;
    for(i=0;i<n;i++) tmp+=b[i]*b[i];
    
    res=sqrt(res);
    tmp=sqrt(tmp);
    
    res/=tmp;
    
    return res;
}

double accuracy(double *x, int n)
{
    int i;
    double tmp,res=0;
    
    for (i=0;i<n;i++)
    {
        tmp=x[i];        
	if (i%2==0) tmp-=1;
        res+=tmp*tmp;
    }
    res=sqrt(res);
    
    return res;
}
