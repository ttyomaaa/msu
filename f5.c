#include "math.h"
#include "f5.h"
void f(double *a, int n)
{
    int i,j;
    
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
        {
            a[i*n+j]=(a[i*n+j]-a[j*n+i])/2;
            a[j*n+i]=0-a[i*n+j]; 
            //if(fabs(a[i*n+j])>0) a[j*n+i]=(-1)*a[i*n+j]; /*minus zero remover*/
           // else a[j*n+i]=a[i*n+j];
        }
}