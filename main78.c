#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "arr78.h"
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
    
    if(eps<0) 
    {
        printf("INCORRECT EPS");
        return 1;
    }
        
        printf("INPUT TASK:\n");
        scanf("%d",&task);
        
    t = clock ();
    
    if (task==7)
        {  
        res=myexp(x,eps);
        res2=exp(x);
                printf("DONE(7).\nRETURNED MYEXP = %lf\n", res);
                printf("EXP = %lf\nDIFFERENCE IS: %lf\n", res2, fabs(res2-res));
        }
    else if (task==8)
        {
          if(x<=0) {printf("ERROR:X IS INCORRECT(LOG)\nl");}
          else
          {
            res=mylog(x,eps);
            res2=log(x);
                printf("DONE(8).\nRETURNED MYLOG = %.50lf\n", res);
                printf("LOG = %.50lf\nDIFFERENCE IS: %.50lf\n", res2, fabs(res2-res));
          }
        }
    else 
        printf("NO SUCH TASK\n");
    
    t = (clock() - t)/CLOCKS_PER_SEC;
    printf("ELAPSED = %lf\n", (double) t);
    return 0;
}

double myexp(double x, double eps)
{
    int i, flag=0;
    double res=1,term=1,integ,fract,f=1;

    if(x<0)
    {
    x*=-1;
    flag=1;
    integ=floor(x);
    x*=-1;
    fract=x+integ;
    }
    else 
    {
    integ=ceil(x);
    fract=integ-x;
    fract*=-1;
    }
    for(i=0;i<integ;i++) res*=M_E;
    if(flag==1) {res=1/res;}
    
    for(i=1;fabs(term)>eps;i++)
    {
        term*=(fract/i);
	f=f+term;
    }
    res*=f;
    return res; 
}

double mylog(double x, double eps)
{
    double res=0,term,x_red;
    int i,count1=0,count2=0;

    x_red=x;
    
    while (x_red>2)
    {
        x_red/= 2;
        count1++;
    }
    res+=count1*M_LN2;
    
    if(!((x>0.5)&&(x<1)))
    {
        while (x_red<1)
        {
            x_red*= 2;
            count2++;
        }
    res-=count2*M_LN2;
    }

    term=x_red-1; 
    res+=x_red-1;
    
    for (i=2;fabs(term)>eps;i++)
    {
        term*=(-1)*(x_red-1);
        res+=term/i;  
        
        //printf("%.20lf\n",term);
    }

    return res;
}