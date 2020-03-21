#include <stdio.h>
double newt4(double, double *, double *, double*, int);
void print_array (double *, int);

static int read_array(char *name, double *x, double *y, double *d, int n)
{
    FILE *fp;
    int i;   
    if( !(fp = fopen(name, "r")) )
        return -1;
    for(i=0; i<n; i++)
    {
        if (fscanf(fp, "%lf", x+i) != 1)
        {
            fclose(fp);
            return -2;
        }
        if (fscanf(fp, "%lf", y+i) != 1)
        {
            fclose(fp);
            return -2;
        }
        if (fscanf(fp, "%lf", d+i) != 1)
        {
            fclose(fp);
            return -2;
        }
    }
    
    fclose(fp);
    return 0;
}

void print_array (double *a, int n)
{
    int i;
    
    for (i=0; i < n; i++)
    {
        printf("%lf\n", a[i]);
    }
}