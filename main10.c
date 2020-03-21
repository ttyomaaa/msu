#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "matrix.h"
#include "f10.h"

int main (int argc, char * argv[])
{
    int n, m, k;
    double *a, *b, *c;
    double t;
    char *name1=0, *name2=0;
    
    if (!(((argc==4)||(argc==6))&&((m=atoi(argv[1]))>0)&&((n=atoi(argv[2]))>0)&&((k=atoi(argv[3]))>0)))
    {
        printf ("USAGE: %s m n k [file_a] [file_b]\n",argv[0]);
        return -1;
    }
    
    if (argc==6) {name1=argv[4];name2=argv[5];}
    
    if (!(a=(double*)malloc(m*n*sizeof(double))))
    {
        printf ("NOT ENOUGH MEMORY\n");
	return -2;
    }
    
    if (!(b=(double*)malloc(n*k*sizeof(double))))
    {
        printf ("NOT ENOUGH MEMORY\n");
        free(a);
	return -2;
    }
    
    if (!(c=(double*)malloc(m*k*sizeof(double))))
    {
        printf ("NOT ENOUGH MEMORY\n");
        free(a);
        free(b);
	return -2;
    }
    
    if ((name1)&&(name2))
    {
        int ret1;
        int ret2;
	ret1=read_matrix(a, m, n, name1);
       	ret2=read_matrix(a, n, k, name2);
        if (ret1!=SUCCESS)
	{
            switch (ret1)
		{
                    case ERROR_OPEN:
                        printf ("CANNOT OPEN FILE 1\n");
                        break;
		    case ERROR_READ:
			printf ("CANNOT READ FILE 1\n");
			break;
                    default:
                        printf ("UNKNOWN ERROR 1\n");
		}
            free(a);
            free(b);
            free(c);
            return -3;
	}
        else if (ret2!=SUCCESS)
	{
            switch (ret2)
		{
                    case ERROR_OPEN:
                        printf ("CANNOT OPEN FILE 2\n");
                        break;
		    case ERROR_READ:
			printf ("CANNOT READ FILE 2\n");
			break;
                    default:
                        printf ("UNKNOWN ERROR 2\n");
		}
            free(a);
            free(b);
            free(c);
            return -3;
	}
    }
    else 
    {
        init_matrix(a, m, n);
        init_matrix(b, n, k);
    }
    printf("MATRIX A:\n");
    print_matrix(a, m, n);
    printf("MATRIX B:\n");
    print_matrix(b, n, k);
    
    t = clock();
    f(a,b,c,m,n,k);
    t = clock() - t;
    
    printf("MATRIX C:\n");
    print_matrix(c, m, k);
    printf ("ELAPSED = %.2lf\n", t/CLOCKS_PER_SEC);
    
    free(a);
    free(b);
    free(c);
    
    return 0;
}

