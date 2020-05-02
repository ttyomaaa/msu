#include "math.h"
#include "f17.h"
#include "matrix.h"
static double L1_norm(int n, double *a)
{
    int i,j;
    double sum, max=-1;
    
    for(j=0;j<n;j++)
    {
        sum=0;
        for(i=0;i<n;i++) sum+=fabs(a[i*n+j]);
        if (sum>max) max=sum;
    }
    
    return max;
}

int solver(int n, double *a, double *b, double *x, int *ord)
{
    int i,j,k,max_i, max_j;
    double max_a, buf, norm;
    
    norm=L1_norm(n,a);
    // printf("%lf\n",norm);
    if(fabs(norm)<1e-100) return -1;

    for(i=0;i<n;i++) ord[i]=i;
    
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
     
        i=ord[k];
	ord[k]=ord[max_j];
        ord[max_j]=i;        
        
        buf=b[k];
	b[k]=b[max_i];
	b[max_i]=buf;
        
        for(i=0;i<n;i++)
	{
            buf=a[k*n+i];
            a[k*n+i]=a[max_i*n+i];
            a[max_i*n+i]=buf;
        }
        
	for(j=0;j<n;j++)
	{
            buf = a[j*n+k];
            a[j*n+k]=a[j*n+max_j];
            a[j*n+max_j]=buf;
	}
        
        
        //  printf("%e\n\n",a[k*n+k]);
        //  printf("%e\n\n",norm*1e-16);
                
        if (fabs(a[k*n+k])<(1.269653e-16*norm)) {return -1;}
        
        buf=1.0/a[k*n+k];
        
       // a[k*n+k]=1.0;
        
        for(j=k+1;j<n;j++) a[k*n+j]*=buf;
        b[k]*=buf;

        for(i=0;i<k;i++)
        {
            //if (k==i) continue;
            buf=a[i*n+k];
            //a[i*n+k]=0.0;
            for (j=k+1;j<n;j++) a[i*n+j]-=a[k*n+j]*buf;
            b[i]-= b[k]*buf;
        }
        
        for(i=k+1;i<n;i++)
        {
            //if (k==i) continue;
            buf=a[i*n+k];
            //a[i*n+k]=0.0;
            for (j=k+1;j<n;j++) a[i*n+j]-=a[k*n+j]*buf;
            b[i]-= b[k]*buf;            
        }
       
    }
       
   for(i=0;i<n;i++) x[ord[i]]=b[i];
       
    return 0;
}
