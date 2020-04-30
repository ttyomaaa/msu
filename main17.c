#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "matrix.h"
#include "f17.h"

int main (int argc, char * argv[])
{
    int n,m,k;
    int *ord;
    int res;
    double *a,*b,*x;
    double resid, err;
    double t;
    char *name=0;
    
    if (!(((argc==4)||(argc==5))&&((n=atoi(argv[1]))>0)&&((m=atoi(argv[2]))>0)&&(sscanf(argv[3],"%d",&k))))
    {
        printf ("USAGE: %s n m k filename\n",argv[0]);
        return -1;
    }
    
    if (k==0) 
    {
        if (argc==5) name=argv[4]; 
        else {printf("INCORRECT INPUT: k=0 AND filename MISSING");return -1;}
    }
    else if ((k!=1)&&(k!=2)&&(k!=3)&&(k!=4)) {printf("INCORRECT INPUT: k!=0,1,2,3,4");return -1;}
    
    if (!(a=(double*)malloc(n*n*sizeof(double))))
    {
        printf ("NOT ENOUGH MEMORY: a\n");
	return -2;
    }
    
    if (!(b=(double*)malloc(n*sizeof(double))))
    {
        printf ("NOT ENOUGH MEMORY: b\n");
        free(a);
	return -2;
    }
    
    if (!(x=(double*)malloc(n*sizeof(double))))
    {
        printf ("NOT ENOUGH MEMORY: x\n");
        free(a);
        free(b);
	return -2;
    }
    
    if (!(ord=(int*)malloc(n*sizeof(int))))
    {
        printf ("NOT ENOUGH MEMORY: x\n");
        free(a);
        free(b);
        free(x);
	return -2;
    }
    
    if (name)
    {
        int ret;
	ret=read_matrix(a, n, name);
        if (ret!=SUCCESS)
	{
            switch (ret)
		{
                    case ERROR_OPEN:
                        printf ("CANNOT OPEN FILE\n");
                        break;
		    case ERROR_READ:
			printf ("CANNOT READ FILE\n");
			break;
                    default:
                        printf ("UNKNOWN ERROR\n");
		}
            free(a);
            free(b);
            free(x);
            free(ord);
            return -3;
	}
    }
    else init_matrix(a, n, k);
    
    init_b(a, b, n);
    
    printf("A = \n");//starter matrix
    print_matrix(a, m, n, n);
    printf("B = \n");
    print_matrix(b, m, 1, n);
    printf("\n");
    
    t = clock();
    res=solver(n, a, b, x, ord);
    t = clock()-t;
    
    if (res==-1) printf("CAN'T SOLVE\n");
    else
    {
        printf("RESULT(X) = \n");
        print_matrix(x, m, 1, n);
        printf("\n");
        
        if(name){read_matrix(a, n, name);}
        else init_matrix(a, n, k);
        
        init_b(a, b, n);
    
        resid=residual(a, b, x, n);
        printf("RESIDUAL (L1 NORM) = %e\n", resid);
    
        err=accuracy(x, n);
        printf("ERROR (L1 NORM) = %e\n", err);
    }

    printf ("ELAPSED = %.2lf\n", t/CLOCKS_PER_SEC);
    
    free(a);
    free(b);
    free(x);
    free(ord);
    return 0;
}




