#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "li.h"
#include "f.h"
int main (int argc, char *argv[])
{
    int ret;
    double t;
    char *fname=0, *s=0;
    list *head, *res;

    if (argc!=3)
    {
        printf("USAGE %s [file] [string s]\n", argv[0]);
        return -1;
    }
        
    fname = argv[1];
    s=argv[2];
    ret = read_list(fname, &head);

    if (ret != SUCCESS)
    {
        switch(ret)
        {
            case OPEN_ERROR:
                printf("CAN'T OPEN!\n");
                break;
            case MEMORY_ERROR:
                printf("MEMORY ERROR!\n");
                break;
            case READ_ERROR:
                printf("CAN'T READ!\n");
                break;
            default:
                printf("UNKNOWN ERROR!\n");

        }
        return -2;
    }

    print_list(head);

    t = clock();
    res=func(head, s);
    t = clock() - t;
    printf ("\nRESULT = \n");
    print_list(res);
    printf("Elapsed = %.2f\n", t / CLOCKS_PER_SEC);

    delete_list(res);
    return 0;
}
