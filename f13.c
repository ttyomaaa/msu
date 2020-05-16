#include "math.h"
#include "fx.h"

double f1(double x, double h, double (*fx)(double))
{
    double res;
    
    if (fabs(h)>0)
    {
        res=(fx(x+h)-fx(x))/h;
        return res;
    }
    else return 0;
}

double f2(double x, double h, double (*fx)(double))
{
    double res;
    
    if (fabs(h)>0)
    {
        res=(fx(x+h)-fx(x-h))/(2*h);
        return res;
    }
    else return 0;
}

double f3(double x, double h, double (*fx)(double))
{
    double res;
    
    if (fabs(h)>0)
    {
        res=(fx(x+h)-2*fx(x)+fx(x-h))/(h*h);
        return res;
    }
    else return 0;

}