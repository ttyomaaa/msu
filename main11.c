#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "matrix.h"
#include "f11.h"

int main (int argc, char * argv[])
{
    int n,m;
    double *a;
    double t;
    char *name=0;
    
    if (!(((argc==3)||(argc==4))&&((m=atoi(argv[1]))>0)&&((n=atoi(argv[2]))>0)))
    {
        printf ("USAGE: %s m n [file]\n",argv[0]);
        return -1;
    }
    
    if (argc==4) name=argv[3];
    
    if (!(a=(double*)malloc(m*n*sizeof(double))))
    {
        printf ("NOT ENOUGH MEMORY\n");
	return -2;
    }
    
    if (name)
    {
        int ret;
	ret=read_matrix(a, m, n, name);
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
    else init_matrix(a, m, n);
    print_matrix(a, m, n);
    
    t = clock();
    f(a,m,n);
    t = clock() - t;
    
    printf ("RESULT:\n");
    print_matrix(a, m, n);
    printf ("ELAPSED = %.2lf\n", t/CLOCKS_PER_SEC);
    
    free(a);
    return 0;
}
