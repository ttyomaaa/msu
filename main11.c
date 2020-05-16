#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "fx.h"
int main (int argc, char * argv[])
{
    int k, c;
    double a, b, eps;
    double r;
    double t;
    
    if  (!((argc==4)&&(sscanf(argv[1],"%lf",&a))&&(sscanf(argv[2],"%lf",&eps))&&(sscanf(argv[3],"%d",&k))))
    {
        printf ("USAGE: %s a eps k\n",argv[0]);
        return -1;
    }
    if ((k!=0)&&(k!=1)&&(k!=2)&&(k!=3)&&(k!=4)&&(k!=5)&&(k!=6)) 
    {printf("INCORRECT INPUT: k!=0,1,2,3,4,5,6\n");return -1;}
    
    t = clock();
    b=f11(a,eps,&r,fswitch(k));
    t = clock()-t;

    c=get_count();
    
    if (b<0)
    {
        printf("ERROR\n");
        return -1;
    }
    
    printf("Answer = %e %e %d %lf\n", r, b, c, t/CLOCKS_PER_SEC);

    return 0;
}