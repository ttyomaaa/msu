int read_matrix (char ** a, int m, int n, const char *name, const char *t);
void print_matrix (char **a, int m, int n);


#define MAX_M 20
#define MAX_N 10

#define SUCCESS 0
#define ERROR_OPEN -1
#define ERROR_READ -2
#define ERROR_MEMORY -3
#define LEN 1234
