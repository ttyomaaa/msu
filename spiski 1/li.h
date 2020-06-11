#define SUCCESS 0
#define OPEN_ERROR -1
#define MEMORY_ERROR -2
#define READ_ERROR -3


#define LEN 1234


struct _list;

typedef struct _list
{
    char *string;
    struct _list *next;
}list;


list *func(list *head, char *s);
int read_list(const char *fname, list **p_head);
void delete_list(list *head);
void print_list(list *head);
