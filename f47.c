#include "math.h"
#include "fx.h"

static double sign(double x)
{
    if (x>0) return 1;
    else if (x<0) return -1;
    else return 0;
}

double f4(double a, double b, int n, double (*fx)(double))
{
    int i;
    double res;
    double h=(b-a)/n;
    double x;
    
    res=(fx(a)+fx(b))/2;

    for (i=1;i<n;i++)
    {
        x=a+h*i;
        res+=fx(x);
    }

    res*=h;

    return res;
}

double f5(double a, double b, int n, double (*fx)(double))
{
    int i;
    double res;
    double h=(b-a)/(2*n);
    double x;
    
    res=(fx(a)+fx(b))/2;

    for (i=1;i<(2*n);i++)
    {
        x=a+h*i;
        if((i%2)==1) res+=2*fx(x);
        else res+=fx(x);
    }

    res*=2*h;
    res/=3;

    return res;
}

double f6(double a, double b, int n, double (*fx)(double))
{
    int i, sgn1, sgn2;
    double p1,p2;
    double y1,y2;
    double h=(b-a)/n;
    double res=0;

    y1=fx(a);
    
    for(i=0;i<n;i++)
    {
        y2=fx(a+h);
        p1=(y2-y1);
        p2=y1*(a+h)-y2*a;
        
        sgn1=sign(a);
        sgn2=sign(a+h);

        res+=p1*2*(sqrt(pow(fabs(a+h),3))-sqrt(pow(fabs(a),3)))/3  + p2*2*(sgn2*sqrt(fabs(a+h))-sgn1*sqrt(fabs(a)));
        
        y1=y2;
        a+=h;
    }
    res/=h;
    
    return res;
}