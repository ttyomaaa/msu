#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "fx.h"
int main (int argc, char * argv[])
{
    int k, count;
    double x, h;
    double res;
    double t;
    
    if  (!((argc==4)&&(sscanf(argv[1],"%lf",&x))&&(sscanf(argv[2],"%lf",&h))&&(sscanf(argv[3],"%d",&k))))
    {
        printf ("USAGE: %s x h k\n",argv[0]);
        return -1;
    }
    if ((k!=0)&&(k!=1)&&(k!=2)&&(k!=3)&&(k!=4)&&(k!=5)&&(k!=6)) 
    {printf("INCORRECT INPUT: k!=0,1,2,3,4,5,6\n");return -1;}
    
    t = clock();
    res=f2(x,h,fswitch(k));
    t = clock()-t;
    
    count=get_count();
    
    printf("Answer = %e %d %lf\n", res, count, t/CLOCKS_PER_SEC);

    return 0;
}