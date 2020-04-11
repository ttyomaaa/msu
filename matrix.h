int read_matrix(double *a, int m, int n, const char *name);
void init_matrix(double *a, int m, int n);
void print_matrix(double *a, int m, int n);
void remover(double *a, int m, int n, int k, int l);

#define M_MAX 10
#define N_MAX 10

#define SUCCESS 1
#define ERROR_READ -1
#define ERROR_OPEN -2
