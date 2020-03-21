#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "matrix.h"
#include "f7.h"

int main (int argc, char * argv[])
{
    int n,m,i,j;
    double *a;
    double t;
    char *name=0;
    
    if (!(((argc==5)||(argc==6))&&((m=atoi(argv[1]))>0)&&((n=atoi(argv[2]))>0)&&(sscanf(argv[3],"%d",&i))&&(sscanf(argv[4],"%d",&j))))
    {
        printf ("USAGE: %s m n i j [file]\n",argv[0]);
        return -1;
    }
    
    if (argc==6) name=argv[5];
    
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
    if ((n<=i)||(n<=j)||(i<0)||(j<0)) printf("ERROR:NO SUCH COLUMNS.RETURNING WITH NO CHANGES...\n");
    else if (i!=j) f(a,m,n,i,j);
    t = clock() - t;
    
    printf ("RESULT:\n");
    print_matrix(a, m, n);
    printf ("ELAPSED = %.2lf\n", t/CLOCKS_PER_SEC);
    
    free(a);
    return 0;
}

