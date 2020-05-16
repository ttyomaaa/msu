#include "math.h"
#include "fx.h"
static int ff8(double a, double b, double eps, double *r, double (*fx)(double))
{
    int i;
    double s_n, s_2n;
    int n=4;
    double h=(b-a)/n;
    double x;

    s_n=(fx(a)+fx(b))/2;
    for (i=1;i<n;i++)
    {
        x=a+h*i;
        s_n+=fx(x);
    }
    s_n *= h;

    for (;n<N;n*=2)
    {
        s_2n=s_n/2;

        h/=2;

        for (i=0;i<n;i++)
        {
            x=a+(2*i+1)*h;
            s_2n+=fx(x)*h;
        }

        if (fabs(s_n-s_2n)<eps)
        {
            *r=s_2n;
            return n;
        }

        s_n=s_2n;
       // n*=2;
    }

    if (n>=N) return -1;

    return n;
}

static int ff9(double a, double b, double eps, double *r, double (*fx)(double))
{
    int i;
    double s_n, s_2n, s_0=0;
    int n=4;
    double h=(b-a)/(2*n);
    double x;

    s_n=(fx(a)+fx(b))/2;
    
    for (i=0;i<n;i++)
    {
        x=a+2*i*h+h;
        s_0+=fx(x);
    }
    
    for (i=1;i<n;i++)
    {
        x=a+2*i*h;
        s_n+=fx(x);
    }

    s_n+=2*s_0;
    s_n*=2*h;
    s_n/=3;
    
    s_0*=h;
    
    s_2n=s_n/2-s_0/3;
    n*=2;
    
    for (;n<N;n*=2)
    {
        s_2n=s_n/2-s_0/3;
        h=(b-a)/(2*n);
        s_0=0;

        for (i=0;i<n;i++)
        {
            x=a+h*2*i+h;
            s_0+=fx(x);
        }

        s_2n+=(4*h*s_0)/3;

        if (fabs(s_n-s_2n)<eps)
        {
            *r=s_2n;
            return n;
        }
        s_n=s_2n;
    }


    if (n>=N) return -1;

    return n;
}

double f10(double a, double eps, double *r, double (*fx)(double))
{
    int i;
    double I=0,S=0,h=1,b;
    int res;

    for (i=0;i<MAXIT;i++)
    {
        b=a+h;

        res=ff8(a, b, eps, &I, fx);
        if (res==-1) return -1;

        S+=I;

        if (fabs(I)<eps)
        {
            *r=S;
            return b;
        }
        h*=2;
        a=b;
    }

    if (i>=MAXIT) return -1;

    return b;
}

double f11(double a, double eps, double *r, double (*fx)(double))
{
    int i;
    double I=0,S=0,h=1,b;
    int res;

    for (i=0;i<MAXIT;i++)
    {
        b=a+h;

        res=ff9(a, b, eps, &I, fx);
        if (res==-1) return -1;

        S+=I;

        if (fabs(I)<eps)
        {
            *r=S;
            return b;
        }
        h*=2;
        a=b;
    }

    if (i>=MAXIT) return -1;

    return b;
}
