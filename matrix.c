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

static double formula(int k, int n, int i, int j)
{
    if (k==1) return n-fmax(i,j)+1;
            
    if (k==2) return fmax(i,j);
            
    if (k==3) 
    {
        if ((i-j)>=0)  return i-j;
        else return j-i;
    }
    
    if (k==4) return 1.0/(i+j-1);
    
    return 0;
}

void init_matrix(double *a, int n, int k)
{
	int i, j;
        
        for(i=0;i<n;i++)
                for(j=0;j<n;j++) 
                    a[i*n+j]=formula(k,n,i+1,j+1);
}

void print_matrix(double *a, int m, int l, int n)
{
    int i,j,n_min,l_min;
        
    n_min=fmin(m,n);
    l_min=fmin(m,l);
       
    for(i=0;i<l_min;i++)
    {
        for(j=0;j<n_min;j++)
            printf(" %10.3e", a[i*n+j]);
        printf("\n");
    }
}

void init_b(double *a, double *b, int n)
{
    int i,j;
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
	res+=fabs(tmp);
    }
    
    tmp=0;
    for(i=0;i<n;i++) tmp+=fabs(b[i]);
    
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
        res+=fabs(tmp);
    }
    
    return res;
}
