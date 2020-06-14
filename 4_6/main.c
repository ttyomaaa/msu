#include <stdio.h>
#include <stdlib.h>
#include "f.h"
#include "func.h"
int main(int argc, char* argv[]) 
{
    int res, m;
    double a, b;
    double eps;
    double x, *d;
    if ((argc!=5)||(sscanf(argv[1], "%d", &m)!=1)||(sscanf(argv[2],"%lf",&a)!=1)||(sscanf(argv[3],"%lf",&b)!=1)||(sscanf(argv[4],"%lf",&eps)!=1)||(eps<=0)||(a>b))
           {
               printf("USAGE: %s m a b eps", argv[0]);
	       return 1;
	   }
    
    if( !(d = (double *)malloc(3*(m + 1)*sizeof(double)) ))
    {
        printf("MEMORRY ERROR\n");
        return -2;
    }   
    
       res=solver(&f, a, b, eps, &x, d, m);
       
       	if(res>=0)
		//printf("x = %e\niterations = %d\n", x, res);
                printf("x = %lf\niterations = %d\n", x, res);
	else
		printf("CAN'T FIND ROOT\n");
       
    free(d);
    return 0;
}

