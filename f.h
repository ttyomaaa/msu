int integral(double a, double b, double eps, double *r, double (*func) (double t, double x, double eps));
int solver(double a, double b, double eps, double *x, double (*func1) (double t, double x, double eps), double (*func2) (double res, double x));
int integral_0(double a, double b, double eps, double *r, double (*func) (double u, double x, double t), double t, double x);
int solve(double eps);
#define MAXIT 1e4
#define SUCCESS 0
#define ERROR -1
#define IT_ERR -3
#define EPS_CONST 1e8
#define N 40