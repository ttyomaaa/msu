#include <stdio.h>
double lag(double, double*, double*, int);
double newt(double, double*, double*, int);
double newt2(double, double *, double *, int);
double ait(double, double *, double *, int);
void print_array (double *, int);

static int read_array(char *name, double *x, double *y, int n)
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
