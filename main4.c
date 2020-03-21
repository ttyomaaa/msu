#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "matrix.h"
#include "f4.h"

int main (int argc, char * argv[])
{
    int n;
    double *a;
    double t;
    char *name=0;
    
    if (!(((argc==2)||(argc==3))&&((n =atoi(argv[1]))>0)))
    {
        printf ("USAGE: %s n [file]\n",argv[0]);
        return -1;
    }
    
    if (argc==3) name=argv[2];
    
    if (!(a=(double*)malloc(n*n*sizeof(double))))
    {
        printf ("NOT ENOUGH MEMORY\n");
	return -2;
    }
    
    if (name)
    {
        int ret;
	ret=read_matrix(a, n, n, name);
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
            return -3;
	}
    }
    else init_matrix(a, n, n);
    print_matrix(a, n, n);
    
    t = clock();
    f(a, n);
    t = clock() - t;
    
    printf ("DONE. RESULT:\n");
    print_matrix(a, n, n);
    printf ("ELAPSED = %.2lf\n", t/CLOCKS_PER_SEC);
    
    free(a);
    return 0;
}

