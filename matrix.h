int read_matrix(double *a, int n, const char *name);
void print_matrix(double *a, int m, int l, int n);
void init_matrix(double *a, int n, int k);
void init_b(double *a, double *b, int n);
double residual(double *a, double *b, double *x, int n);
double accuracy(double *x, int n);

#define SUCCESS 1
#define ERROR_READ -1
#define ERROR_OPEN -2
