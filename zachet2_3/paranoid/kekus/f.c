#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "f.h"

void solve (char **a, int m, int n, int i, int j)
{
    int k;
    char *buf;

    for(k=0;k<m;k++)
    {
        buf=a[k*n+i];
        a[k*n+i]=a[k*n+j];
        a[k*n+j]=buf;
    }
}
