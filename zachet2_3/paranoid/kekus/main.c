#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "f.h"
#include "matrix.h"
int main (int argc, char *argv[])
{
    int i, j, m, n, iread, jread, ret;
    char **a;
    char *name=0, *t;

    if (!((argc == 7) && (m = atoi (argv[1])) && (n = atoi (argv[2]))&&(sscanf(argv[3],"%d",&iread))&&(sscanf(argv[4],"%d",&jread))))
    {
        printf ("USAGE: %s m n i j fileName t\n", argv[0]);
        return -4;
    }
    
    a=(char**)malloc(m*n*sizeof(char*));
    if (!a)
    {
        printf ("Memory allocation error\n");
        return -3;
    }
        
    name=argv[5];
    t=argv[6];
	
    ret=read_matrix (a, m, n, name, t);
    if (ret!=SUCCESS)
    {
        printf ("READ ERROR. CODE = %d\n", ret);
        free(a);
	return -5;
    }
        
    print_matrix (a, m, n);
    if((iread<n)&&(jread<n)) solve (a, m, n, iread, jread);		
    printf ("\nRESULT:\n");
    print_matrix (a, m, n);
          
    for (i=0; i<m; i++)
    {        
        for (j=0; j<n; j++)
        if (a[i*n+j]) free(a[i*n+j]);
    }
    free(a);
    
    return 0;
}
