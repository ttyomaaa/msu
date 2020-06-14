#include <stdio.h>
#include <stdlib.h>
#include "f.h"
#include "func.h"
int main(int argc, char* argv[]) 
{
    int res;
    double a, b;
    double eps;
    double x;
       if ((argc!=4)||(sscanf(argv[1],"%lf",&a)!=1)||(sscanf(argv[2],"%lf",&b)!=1)||(sscanf(argv[3],"%lf",&eps)!=1)||(eps<=0)||(a>b))
           {
               printf("USAGE: %s a b eps", argv[0]);
	       return 1;
	   }
       
       res=solver(&f, a, b, eps, &x);
       
       	if(res>=0)
		//printf("x = %e\niterations = %d\n", x, res);
                printf("x = %lf\niterations = %d\n", x, res);
	else
		printf("CAN'T FIND ROOT\n");
    return 0;
}

