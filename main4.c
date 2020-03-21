#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "arr4.h"
int main (int argc, char * argv[])
{
    double *x, *y, *d;
    double x0,res=0;
    int n,err;
    double t;
    char *file;
    
    if ( !( (argc == 4)&&sscanf(argv[1], "%d", &n)&&sscanf(argv[3], "%lf", &x0) ) )
    {
        printf("USAGE %s n [file] x0\n", argv[0]);
        return 1;
    }
    
    x =(double *)malloc(n * sizeof(double));
    if (!x)
    {
        printf("NOT ENOUGH MEMORY\n");
        return 1;
    }
    
    y =(double *)malloc(n * sizeof(double));
    if (!y)
    {
        free(x);
        printf("NOT ENOUGH MEMORY\n");
        return 1;
    }
    
    d =(double *)malloc(n * sizeof(double));
    if (!d)
    {
        free(x);
        free(y);
        printf("NOT ENOUGH MEMORY\n");
        return 1;
    }
    
    
        file=argv[2];
    
        err = read_array(file, x, y, d, n);
        if (err < 0)
        {
            switch(err)
            {
                case -1 :
                    printf("CAN'T OPEN FILE %s\n", file);
                    break;
                case -2 :
                    printf("CANNOT READ FILE %s\n", file);
                    break;
                default:
                    printf("UNKNOWN ERROR %s\n", file);
                    break;
            }
            free(x);
            free(y);
            return 1;
        }
        
    /*
            if (n<=20)
            {printf("X\n");
                print_array(x, n);
                printf("Y\n");
                print_array(y, n);
                     printf("dis\n");
                print_array(d, n);}
           if (n>20)
            {printf("X\n");
                print_array(x, n);
                printf("Y\n");
                print_array(y, n);
                     printf("dis\n");
                print_array(d, n);}
                
                    printf("X0\n");
                    printf("%lf\n",x0);
     */
    
    t = clock ();
    
    res=newt4(x0,x,y,d,n);
    printf("DONE(4).\nRETURNED VALUE:%lf\n", res);
    
    t = (clock() - t)/CLOCKS_PER_SEC;
    printf("ELAPSED = %lf\n", (double) t);
    
    free(x);
    free(y);
    free(d);
    return 0;
}

static int divided_difference(int n, int k, double *x, double *y)//2
{
    int i;

    for (i = n - 1; i >= k; i--)
    {
        y[i] = (y[i - 1] - y[i]) / (x[i - 1 - k] - x[i]);
    }

    return 0;
}

static int derivative_divided_difference(int n, int k, double *x, double *y, double *d, int d_k, int y_k)//4
{
    int i;
    int j;

    for (i = 2 * n - 1; i > k; i--)
    {
        j = i >> 1;

        if (i & 1)// == 1
        {
            d[j] = (y[j] - d[j]) / (x[j - d_k] - x[j]);
        }
        else
        {
            y[j] = (y[j] - d[j - 1]) / (x[j] - x[j - y_k]);
        }
    }

    return 0;
}

double newt4(double x0, double *x, double *y, double *d, int n)
{
    int i;
    int j;
    int d_k;
    int y_k;
    double L;
    double D;

    D = 1.;
    d_k = 1;
    y_k = 1;

    divided_difference(n, 0, x, y);
    for (i = 1; i < 2 * n - 1; i++)
    {
        derivative_divided_difference(n, i, x, y, d, d_k, y_k);


        if (i % 2 == 0)
            d_k++;
        else
            y_k++;
    }

    L = y[0];
    D = (x0 - x[0]);

    for (i = 2; i <= 2 * n; i++)
    {
        j = i >> 1;

        if (i % 2 == 0)
        {
            j -= 1;
            L += d[j] * D;
        }
        else
        {
            L += y[j] * D;
        }

        D *= (x0 - x[j]);
    }

    return L;
}
