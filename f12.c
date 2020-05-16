#include "math.h"
#include "fx.h"
int f12(double a, double b, double eps, double *r, double (*fxx) (double) ,double (*fx)(double))
{
    int i,j;
    int n=4;
    double x1,x2,y1,y2;
    double p1,p2;
    double xh, yh;
    double s1=0,s2=0;
    double h=(b-a)/n;

    x1=fxx(a);
    y1=fx(a);
    p1=a;

    for(i=1;i<n;i++)
    {
        p2=a+i*h;

        x2=fxx(p2);
        y2=fx(p2);

        if (fabs(h)>0)
        {
            xh=(x2-x1)/h;
            yh=(y2-y1)/h;
        }
        else return -1;

        s1+=sqrt(xh*xh+yh*yh);

        x1=x2;
        y1=y2;
        p1=p2;
    }

    n*=2;
    
    for (;n<N;n*=2)
    {
        p1=a;
        x1=fxx(p1);
        y1=fx(p1);
        
        s2=0;
        h=(b-a)/n;

        for(j=1;j<n;j++)
        {
            p2=a+j*h;

            x2 = fxx(p2);
            y2 = fx(p2);

            if (fabs(h)>0)
            {
                xh = (x2-x1)/h;
                yh = (y2-y1)/h;
            }
            else return -1;

            s2+=sqrt(xh*xh+yh*yh);

            x1=x2;
            y1=y2;
            p1=p2;
        }

        s2*=h;

        if (fabs(s1-s2)<eps)
        {
            *r=s2;
            return n;
        }

        s1=s2;
    }

    if (i>=N) return -1;

    return n;
}