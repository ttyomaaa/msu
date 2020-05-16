#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "fx.h"
int main (int argc, char * argv[])
{
    int n, k, c;
    double a, b;
    double res;
    double t;
    
    if  (!((argc==5)&&(sscanf(argv[1],"%lf",&a))&&(sscanf(argv[2],"%lf",&b))&&(sscanf(argv[3],"%d",&n))&&(sscanf(argv[4],"%d",&k))))
    {
        printf ("USAGE: %s a b n k\n",argv[0]);
        return -1;
    }
    if ((k!=0)&&(k!=1)&&(k!=2)&&(k!=3)&&(k!=4)&&(k!=5)&&(k!=6)) 
    {printf("INCORRECT INPUT: k!=0,1,2,3,4,5,6\n");return -1;}
    
    t = clock();
    res=f6(a,b,n,fswitch(k));
    t = clock()-t;
    
    c=get_count();
    
    printf("Answer = %e %d %lf\n", res, c, t/CLOCKS_PER_SEC);

    return 0;
}