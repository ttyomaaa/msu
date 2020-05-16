//double fx(double x, int k);
double f1(double x, double h, double (*fx)(double));
double f2(double x, double h, double (*fx)(double));
double f3(double x, double h, double (*fx)(double));

double f4(double a, double b, int n, double (*fx)(double));
double f5(double a, double b, int n, double (*fx)(double));
double f6(double a, double b, int n, double (*fx)(double));
double f7(double a, double b, int n, double (*fx)(double));

int f8(double a, double b, double eps, double *r, double (*fx)(double));
int f9(double a, double b, double eps, double *r, double (*fx)(double));

double f10(double a, double eps, double *r, double (*fx)(double));
double f11(double a, double eps, double *r, double (*fx)(double));

int f12(double a, double b, double eps, double *r, double (*fxx) (double) ,double (*fx)(double));

double (*fswitch(int k))(double);
double fxx(double x);

double fx0(double x);
double fx1(double x);
double fx2(double x);
double fx3(double x);
double fx4(double x);
double fx5(double x);
double fx6(double x);

int get_count(void);
int get_countx(void);

#define MAXIT 100
#define N 1e6
