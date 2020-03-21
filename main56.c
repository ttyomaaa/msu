#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "arr56.h"
int main (int argc, char * argv[])
{
    double x,eps,res,res2;
    int task=0;
    double t;
    
    if ( !( (argc == 3)&&sscanf(argv[1], "%lf", &x)&&sscanf(argv[2], "%lf", &eps) ) )
    {
        printf("USAGE %s x eps\n", argv[0]);
        return 1;
    }
    
        
        printf("INPUT TASK:\n");
        scanf("%d",&task);
        
    t = clock ();
    
    if (task==5)
        {  
        res=mysin(x,eps);
        res2=sin(x);
                printf("DONE(5).\nRETURNED MYSIN = %lf\n", res);
                printf("SIN = %lf\nDIFFERENCE IS: %lf\n", res2, fabs(res2-res));
        }
    else if (task==6)
        {
        res=mycos(x,eps);
        res2=cos(x);
                printf("DONE(6).\nRETURNED MYCOS = %.50lf\n", res);
                printf("COS = %.50lf\nDIFFERENCE IS: %.50lf\n", res2, fabs(res2-res));
        }
    else 
        printf("NO SUCH TASK\n");
    
    t = (clock() - t)/CLOCKS_PER_SEC;
    printf("ELAPSED = %lf\n", (double) t);
    return 0;
}

double mysin(double x, double eps)
{
    int i,flag=0;
    double res,term,n;

    if(x<0)
    {
        x*=-1;
        flag=1;
    }
    
    n=floor(x/(2*M_PI));
    x-=n*2*M_PI;
    
    if(x>M_PI)
    {
        x-=M_PI;
        if (flag==0) flag=1;
        else if (flag==1) flag=0;
    }

    if(x>1)
    {
        x-=M_PI/2;
        if(x<0) x*=-1;
        
        term=1;
        res=1;
        for(i=1;fabs(term)>eps;i++)
        {
            term*=(-1)*x*x/((2*i-1)*2*i);
            res+=term;
        }
    } 
    else
    {
        term=x;
        res=x;
        for(i=1;fabs(term)>eps;i++)
        {
            term*=(-1)*x*x/((2*i+1)*2*i);
            res+=term;
        }
    }
    if(flag==1) res*=-1;
    
    return res;
}

double mycos(double x, double eps)
{
    int i,flag=0;
    double res,term,n;

    if(x<0) x*=-1;
    
    n=floor(x/(2*M_PI));
    x-=n*2*M_PI;
    
    if(x>M_PI)
    {
        x-=M_PI;
        if (flag==0) flag=1;
        else if (flag==1) flag=0;
    }

    if(x>1)
    {
        x-=M_PI/2;
        if(x<0) x*=-1;
        else 
        {
            if (flag==0) flag=1;
            else if (flag==1) flag=0;
        }
        
        term=x;
        res=x;
        for(i=1;fabs(term)>eps;i++)
        {
            term*=(-1)*x*x/((2*i+1)*2*i);
            res+=term;
        }
    } 
    else
    {       
        term=1;
        res=1;
        for(i=1;fabs(term)>eps;i++)
        {
            term*=(-1)*x*x/((2*i-1)*2*i);
            res+=term;
        }
    }
    if(flag==1) res*=-1;
    
    return res;
}


