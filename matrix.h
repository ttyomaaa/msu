int read_matrix(double *a, int m, int n, const char *name);
void init_matrix(double *a, int m, int n);
void print_matrix(double *a, int m, int n);
double nev1(double *a, double *b, double *x, int n);
double nev2(double *x, int n);
void bb(double *a, double *b, int n);

#define M_MAX 10
#define N_MAX 10

#define SUCCESS 1
#define ERROR_READ -1
#define ERROR_OPEN -2
