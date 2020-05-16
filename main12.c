#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "fx.h"
int main (int argc, char * argv[])
{
    int k, cx, cy, res;
    double a, b, eps;
    double r;
    double t;

    
    if  (!((argc==5)&&(sscanf(argv[1],"%lf",&a))&&(sscanf(argv[2],"%lf",&b))&&(sscanf(argv[3],"%lf",&eps))&&(sscanf(argv[4],"%d",&k))))
    {
        printf ("USAGE: %s a b eps k\n",argv[0]);
        return -1;
    }
    if ((k!=0)&&(k!=1)&&(k!=2)&&(k!=3)&&(k!=4)&&(k!=5)&&(k!=6)) 
    {printf("INCORRECT INPUT: k!=0,1,2,3,4,5,6\n");return -1;}
    
    t = clock();
    res=f12(a,b,eps,&r,&fxx,fswitch(k));
    t = clock()-t;
    
    
    cx=get_countx();
    cy=get_count();
    
    if (res==-1)
    {
        printf("ERROR\n");
        return -1;
    }
    
    printf("Answer = %e %d %d %d %lf\n", r, res, cx, cy, t/CLOCKS_PER_SEC);

    return 0;
}