#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "f.h"

static int count=0;

static double func0(double u, double x, double t)
{
    return 1.0/sqrt(1+x*x*u*u*t*t*t*t*t*t);
}

static double func1(double t, double x,  double eps)
{
    double res=0;
    integral_0(0,1,eps,&res,&func0, t, x);
    return res;
}

static double func2(double res, double x)
{
    count++;
    return res - x*x*x;
}


int integral_0(double a, double b, double eps, double *r, double (*func) (double u, double x, double t), double t, double x)
{
    int i,n,j;
    double s_n, s_2n;
    double ui, h;

    s_n=0;
    s_2n=0;

    n=60;
    h=(b-a)/n;

    s_n=(func0(a, x, t)+func0(b, x, t))/2;

    for (i=1; i<n; i++)
    {
        ui=a+h*i;
        s_n+=func(ui, x, t);
    }

    s_n*=h;

    for (j=0; j<N; j++)
    {
        s_2n=s_n/2;

        h/=2;

        for (i = 0; i < n; i++)
        {
            ui=a+(2*i+1)*h;
            s_2n+=func(ui, x, t)*h;
        }

        if (fabs(s_n-s_2n) < eps)
        {
            *r = s_2n;
            return n;
        }

        s_n=s_2n;
        n*=2;
    }

    if (j>=N) return ERROR;

    return n;
}


int solver(double a, double b, double eps, double *x, double (*func1) (double t, double x, double eps), double (*func2) (double res, double x))
{
    int it;
    int n;
    double c;
    double res=0;
    double res_a,res_b,res_c;
    count = 0;

    n = integral(0, a, eps, &res, func1);
    if (n == ERROR) return ERROR;
    res_a = func2(res, a);
    n = integral(0, b, eps, &res, func1);
    if (n == ERROR) return ERROR;
    res_b = func2(res, b);

    if (fabs(res_a) < eps)
    {
        *x = a;
        return 0;
    }

    if (fabs(res_b) < eps)
    {
        *x = b;
        return 0;
    }

    for (it=0; it<MAXIT; it++)
    {
        c=(a+b)/2;
        n = integral(0, c, eps, &res, func1);
        if(n==ERROR) return ERROR;
        res_c=func2(res, c);

        if (fabs(res_c) < eps)
        {
            *x = c;
            return it;
        }

        if ((res_c >= 0 && res_a <= 0) || (res_c <= 0 && res_a >= 0))
        {
            b = c;
            res_b = res_c;
        }
        else if ((res_c >= 0 && res_b <= 0) || (res_c <= 0 && res_b >= 0))
        {
            a = c;
            res_a = res_c;
        }
        else return ERROR;
    }

    if (it >= MAXIT) return ERROR;


    return it;
}

int integral(double a, double b, double eps, double *r, double (*func) (double t, double x, double eps))
{
    int i,n,t;
    double s_n, s_2n;
    double h,x;

    s_n=0;
    s_2n=0;

    n=60;
    h=(b-a)/n;

    s_n=(func(a, b, eps)+func(b, b, eps))/2;

    for (i=1; i<n; i++)
    {
        x=a+h*i;
        s_n+=func(x, b, eps);
    }

    s_n*=h;

    for (t=0; t<N; t++)
    {
        s_2n=s_n/2;

        h/=2;

        for (i = 0; i < n; i++)
        {
            x=a+(2*i+1)*h;
            s_2n+=func(x, b, eps)*h;
        }

        if (fabs(s_n-s_2n) < eps)
        {
            *r = s_2n;
            return n;
        }

        s_n=s_2n;
        n*=2;
    }

    if (t>=N) return ERROR;

    return n;
}



int solve(double eps)
{
    int i,n,m;
    double a,b,h;
    double res=0;
    double x,x1,x2,y1,y2;

    a=-5;
    b=5;

    h=(b-a)/MAXIT;

    x=a;
    x1=a;
    n = integral(0, x1, eps, &res, &func1);
    if (n == ERROR) return ERROR;
    y1 = func2(res, x1);

    for (i=1;i<MAXIT;i++)
    {
        x2=a+i*h;
        n=integral(0, x2, eps, &res, &func1);
        if (n==ERROR) return ERROR;
        y2=func2(res, x2);

        if ((y1 >= 0 && y2 <= 0) || (y1 <= 0 && y2 >= 0))
        {
            m = solver(x1, x2, eps, &x, &func1, &func2);

            if (m != ERROR)
            {
                n = integral(0, x, eps, &res, &func1);
                if (n != ERROR)
                    printf("Answer = %10.3e  %10.3e  %d\n", x, func2(res, x), count);
            }
        }
        x1 = x2;
        y1 = y2;
    }

    return SUCCESS;
}