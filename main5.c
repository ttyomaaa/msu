#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "matrix.h"
#include "f5.h"

int main (int argc, char * argv[])
{
    int n,m;
    double res;
    double *A, *B;
    double t;
    char *name1=0, *name2=0;
    
    if (!(((argc==3)||(argc==5))&&((m=atoi(argv[1]))>0)&&((n=atoi(argv[2]))>0)))
    {
        printf ("USAGE: %s m n [file_a] [file_b]\n",argv[0]);
        return -1;
    }
    
    if (argc==5) {name1=argv[3];name2=argv[4];}
    
    if (!(A=(double*)malloc(m*n*sizeof(double))))
    {
        printf ("NOT ENOUGH MEMORY\n");
	return -2;
    }
    
    if (!(B=(double*)malloc(n*m*sizeof(double))))
    {
        printf ("NOT ENOUGH MEMORY\n");
        free(A);
	return -2;
    }
    
    if ((name1)&&(name2))
    {
        int ret1;
        int ret2;
	ret1=read_matrix(A, m, n, name1);
       	ret2=read_matrix(B, n, m, name2);
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
            free(B);
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
            free(B);
            return -3;
	}
    }
    else 
    {
        init_matrix(A, m, n);
        init_matrix(B, n, m);
    }
    printf("MATRIX A:\n");
    print_matrix(A, m, n);
    printf("MATRIX B:\n");
    print_matrix(B, n, m);
    
    t = clock();
    res=f(A,B,m,n);
    t = clock() - t;
    
    printf("RESULT = %lf\n",res);
    printf ("ELAPSED = %.2lf\n", t/CLOCKS_PER_SEC);
    
    free(A);
    free(B);
    
    return 0;
}

