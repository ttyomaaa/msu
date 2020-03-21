#include "math.h"
#include "f2.h"
double f(double *a, int n)
{
    int i;
    double tr=0;

    for(i=0;i<n;i++) tr+=a[i*(n+1)];

    return tr;
}