#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "matrix.h"
#include "f4.h"

int main (int argc, char * argv[])
{
    int i;
    int n,m;
    double *a, *x0, *x, *b, *r;
    double t,n1,n2;
    char *name1=0, *name2=0;
    
    if (!(((argc==3)||(argc==5))&&((m=atoi(argv[1]))>0)&&((n=atoi(argv[2]))>0)))
    {
        printf ("USAGE: %s m n tu [file] [file]\n",argv[0]);
        return -1;
    }
    
    if (argc==5) {name1=argv[3];name2=argv[4];}
    
    if (!(a=(double*)malloc(n*n*sizeof(double))))
    {
        printf ("NOT ENOUGH MEMORY\n");
	return -2;
    }
    
    if (!(x0=(double*)malloc(n*sizeof(double))))
    {
        printf ("NOT ENOUGH MEMORY\n");
        free(a);
	return -2;
    }
    
    if (!(x=(double*)malloc(n*sizeof(double))))
    {
        printf ("NOT ENOUGH MEMORY\n");
        free(a);
        free(x0);
	return -2;
    }
    
    if (!(b=(double*)malloc(n*sizeof(double))))
    {
        printf ("NOT ENOUGH MEMORY\n");
        free(a);
        free(x0);
        free(x);
	return -2;
    }
    
    if (!(r=(double*)malloc(n*sizeof(double))))
    {
        printf("Not enough memory!\n");
        free(a);
        free(x0);
        free(x);
        free(b);
        return -2;
    }
    
    if (name1&&name2)
    {
        int ret1,ret2;
	ret1=read_matrix(a, n, n, name1);
        ret2=read_matrix(x0, n, 1, name2);
        if (ret1!=SUCCESS)
	{
            switch (ret1)
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
            free(x);
            free(x0);
            free(b);
            free(r);
            return -3;
	}
        if (ret2!=SUCCESS)
        {
            switch (ret2)
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
            free(x);
            free(x0);
            free(b);
            free(r);
            return -3;
	}
    }
    else     
    {
       init_matrix(a, n, n);
       
       for (i=0;i<n;i++) x0[i]=1;
    }
    
    //print_matrix(a, n, n);
    //printf("\n");
    //print_matrix(x0, n, 1);
    //printf("\n");
    
    t = clock();
    f(a,x0,x,b,r,m,n,&n1,&n2);
    t = clock()-t; 
    
    print_matrix(x, n, 1);
    printf("\n");
    printf("NEV1=%e\nNEV2=%e\n", n1, n2);

    printf ("ELAPSED = %.2lf\n", t/CLOCKS_PER_SEC);
    
    free(a);
    free(x);
    free(x0);
    free(b);
    free(r);
    return 0;
}