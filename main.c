#include <stdio.h>
#include <stdlib.h>
#include "f.h"
int main(int argc, char* argv[]) 
{
    int res; 
    double eps;
       if ((argc!=2)||(sscanf(argv[1],"%lf",&eps)!=1)||(eps<0))
           {
               printf("USAGE: %s eps", argv[0]);
	       return 1;
	   }
    res=solve(eps);
    if (res<0) printf("CAN'T FIND ROOT\n");
    return 0;
}
