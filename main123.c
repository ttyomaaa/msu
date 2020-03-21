#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "arr123.h"
int main (int argc, char * argv[])
{
    double *x, *y;
    double x0,res=0;
    int n,err,task=0;
    double t;
    char *file;
    
    if (!((argc == 4)&&sscanf(argv[1], "%d", &n)&&sscanf(argv[3], "%lf", &x0)))
    {
        printf("USAGE %s n [file] x0\n", argv[0]);
        return 1;
    }
    
    x =(double *)malloc(n * sizeof(double));
    if (!x)
    {
        printf("NOT ENOUGH MEMORY\n");
        return 1;
    }
    
    y =(double *)malloc(n * sizeof(double));
    if (!y)
    {
        free(x);
        printf("NOT ENOUGH MEMORY\n");
        return 1;
    }
    
    
        file=argv[2];
    
        err = read_array(file, x, y, n);
        if (err < 0)
        {
            switch(err)
            {
                case -1 :
                    printf("CAN'T OPEN FILE %s\n", file);
                    break;
                case -2 :
                    printf("CANNOT READ FILE %s\n", file);
                    break;
                default:
                    printf("UNKNOWN ERROR %s\n", file);
                    break;
            }
            free(x);
            free(y);
            return 1;
        }
        
        printf("INPUT TASK:\n");
        scanf("%d",&task);    
    t = clock ();
    
            if (task==1)
        {res=lag(x0,x,y,n);printf("DONE(1).\nRETURNED VALUE:%lf\n", res);}
            else if(task==2)
        {res=newt(x0,x,y,n);printf("DONE(2).\nRETURNED VALUE:%lf\n", res);}
            else if(task==22)
        {res=newt2(x0,x,y,n);printf("DONE(2v2).\nRETURNED VALUE:%lf\n", res);}
            else if(task==3)
        {res=ait(x0,x,y,n);printf("DONE(3).\nRETURNED VALUE:%lf\n", res);}
            else printf("NO SUCH TASK\n");
    
    t = (clock() - t)/CLOCKS_PER_SEC;
    printf("ELAPSED = %lf\n", (double) t);
    
    free(x);
    free(y);
    return 0;
}

double lag(double x0, double *x, double *y, int n)
{
    int i,j;
    double res=0,buf;
    
    for(i=0;i<n;i++)
    {
        buf=1;
        for(j=0;j<n;j++)
        { 
            if (i!=j)
            buf*=(x0-x[j])/(x[i]-x[j]);
        }
        res+=y[i]*buf;
      //  printf("%lf\n",res);
    }
    
    return res;
}

double newt(double x0, double *x, double *y, int n)
{
    int i,j,k=1;
    double res=0;
    
    for (j=n-1;j>0;j--)
    {
        for (i=0;i<j;i++)
        {
            y[n-1-i]=(y[n-1-i]-y[n-i-2])/(x[n-i-1]-x[n-i-1-k]);
        }
        k++;
    }
    res=y[n-1];
    for (i=n-1;i>0;i--)
    {
        res*=(x0-x[i-1]);
        res+=y[i-1];
    }
    
    return res;
}

double newt2(double x0, double *x, double *y, int n)
{
    int i,j;
    double buf=1,res=y[0];

    for(i=0;i<n-1;i++)
    {
	for(j=0;j<n-i-1;j++)
            y[j]=(y[j+1]-y[j])/(x[j+i+1]-x[j]);
        buf*=(x0-x[i]);
	res+=y[0]*buf;
    }
    
    return res;
}

double ait(double x0, double *x, double *y, int n)
{
    int i,j;

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
            y[j]=((x0-x[j])*y[j+1]-(x0-x[j+i+1])*y[j])/(x[j+i+1]-x[j]);

    }

    return y[0];
}





//y[j]=((x0-x[j+1+i])*y[j+1]-(x0-x[j])*y[j])/(x[i+1+j]-x[j]);