#include "math.h"
#include "f17.h"
#include "matrix.h"
static void replace_lines(double *a, int n, int i, int j)
{
    int k;
    double buf;

    for(k=0;k<n;k++)
    {
        buf=a[k+i*n];
        a[k+i*n]=a[k+j*n];
        a[k+j*n]=buf;
    }
}

static void replace_columns(double *a, int n, int i, int j)
{
    int k;
    double buf;

    for(k=0;k<n;k++)
    {
        buf=a[i+k*n];
        a[i+k*n]=a[j+k*n];
        a[j+k*n]=buf;
    }
}

int solver(int n, double *a, double *b, double *x, int *ord)
{
    int i,j,k,max_i, max_j;
    double max_a, buf;
    
    for(i=0;i<n;i++) ord[i]=i;
    
    for(i=0;i<n;i++) x[i]=b[i];
    
    for(k=0;k<n;k++)
    {
        max_a=a[k*n+k];
        max_i=k;
        max_j=k;
        
        for(i=k;i<n;i++)        
            for(j=k;j<n;j++)            
                if (a[i*n+j]>max_a)
                {               
                    max_a=a[i*n+j];                           
                    max_i=i;
                    max_j=j;
                }
                
        replace_lines(a,max_i,i,n);
        replace_columns(a,max_j,j,n);
        
        replace_columns(x,max_i,i,n);
        
        i=ord[k];
	ord[k]=ord[max_i];
        ord[max_i]=i;
        
        if (a[k*n+k]<1e-17) return -1;
        
        buf=1.0/a[k*n+k];
        
        a[k*n+k]=1.0; //cheat
        
        for(j=k+1;j<n;j++) a[k*n+j]*=buf;
        x[k]*=buf;

        for(i=0;i<n;i++)
        {
            if (k==i) continue;
            buf=a[i*n+k];
            a[i*n+k]=0.0;//cheat
            for (j=k+1;j<n;j++) a[i*n+j]-=a[k*n+j]*buf;
            x[i]-= x[k]*buf;
            
        }

    }

    /*print_matrix(a, 5, n, n);
    printf("\n");
        printf("\n");
            printf("\n");*/
       
    return 0;
}
