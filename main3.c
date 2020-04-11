#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "matrix.h"
#include "f3.h"

int main (int argc, char * argv[])
{
    int n, m;
    double *A, *b, *x;
    double t;
    double res;
    char *name1=0, *name2=0, *name3=0;
    
    if (!(((argc==3)||(argc==6))&&((m=atoi(argv[1]))>0)&&((n=atoi(argv[2]))>0)))
    {
        printf ("USAGE: %s m n [file_a] [file_b] [file_x]\n",argv[0]);
        return -1;
    }
    
    if (argc==6) {name1=argv[3];name2=argv[4];name3=argv[5];}
    
    if (!(A=(double*)malloc(m*n*sizeof(double))))
    {
        printf ("NOT ENOUGH MEMORY\n");
	return -2;
    }
    
    if (!(b=(double*)malloc(m*sizeof(double))))
    {
        printf ("NOT ENOUGH MEMORY\n");
        free(A);
	return -2;
    }
    
    if (!(x=(double*)malloc(n*sizeof(double))))
    {
        printf ("NOT ENOUGH MEMORY\n");
        free(A);
        free(b);
	return -2;
    }
    
    if ((name1)&&(name2))
    {
        int ret1;
        int ret2;
        int ret3;
	ret1=read_matrix(A, m, n, name1);
       	ret2=read_matrix(b, 1, m, name2);
        ret3=read_matrix(x, n, 1, name3);
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
            free(A);
            free(b);
            free(x);
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
            free(A);
            free(b);
            free(x);
            return -3;
	}
        else if (ret3!=SUCCESS)
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
            free(A);
            free(b);
            free(x);
            return -3;
	}
    }
    else 
    {
        init_matrix(A, m, n);
        init_matrix(b, 1, m);
        init_matrix(x, n, 1);
    }
    printf("MATRIX A:\n");
    print_matrix(A, m, n);
    printf("MATRIX B:\n");
    print_matrix(b, 1, m);
    printf("MATRIX X:\n");
    print_matrix(x, n, 1);
    
    t = clock();
    res=f(A,b,x,m,n);
    t = clock() - t;
    
    printf("RESULT = %lf\n",res);
    printf ("ELAPSED = %.2lf\n", t/CLOCKS_PER_SEC);
    
    free(A);
    free(b);
    free(x);
    
    return 0;
}



