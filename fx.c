#include <stdio.h>
#include <math.h>
#include "fx.h"
static int count=0;
static int countx=0;
double (*fswitch(int k))(double)
{
    if (k==0) return fx0;
        if(k==1) return fx1;
            if(k==2) return fx2;
                if(k==3) return fx3;
                    if(k==4) return fx4;
                        if(k==5) return fx5; 
                            if(k==6) return fx6;
    return fx0;
}

/*double nofx(double x,int k)
{
    count++;
    if (k==0) return 1;
        if(k==1) return 1.0+x;
            if(k==2) return 1.0+x+x*x;
                if(k==3) return 1.0+x+x*x+x*x*x;
                    if(k==4) return 1.0+x+x*x+x*x*x+x*x*x*x;
                        if(k==5) return exp((-1)*x); 
                            if(k==6) return 1.0/(25*x*x+1);
    return 0;    
}*/

double fx0(double x)
{
    (void)x;
    count++;
    return 1;
    
}

double fx1(double x)
{
    count++;
     return 1.0+x;
}

double fx2(double x)
{
    count++;
    return 1.0+x+x*x;
    
}

double fx3(double x)
{
    count++;
     return 1.0+x+x*x+x*x*x;
}

double fx4(double x)
{
    count++;
    return 1.0+x+x*x+x*x*x+x*x*x*x;
    
}

double fx5(double x)
{
    count++;
    return exp((-1)*x); 
}

double fx6(double x)
{
    count++;
    return 1.0/(25*x*x+1);
    
}

double fxx(double x)
{
    countx++;
    return x;
}


int get_count(void)
{
    return count;
}

int get_countx(void)
{
    return count;
}