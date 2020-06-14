#include <stdio.h>
#include <stdlib.h>
#include "f.h"
#include "func.h"
int main(int argc, char* argv[]) 
{
    int res;
    double x0;
    double eps;
    double x;
       if ((argc!=3)||(sscanf(argv[1],"%lf",&x0)!=1)||(sscanf(argv[2],"%lf",&eps)!=1)||(eps<=0))
           {
               printf("USAGE: %s x0 eps", argv[0]);
	       return 1;
	   }
       
       res=solver(&f, x0, eps, &x);
       
       	if(res>=0)
		//printf("x = %e\niterations = %d\n", x, res);
                printf("x = %lf\niterations = %d\n", x, res);
	else
		printf("CAN'T FIND ROOT\n");
    return 0;
}

