#include <stdio.h>
#include <stdlib.h>
#include "f.h"
int main(int argc, char* argv[]) 
{
    int res;
    char *a, *b;
    char *s, *t;
       if (argc!=5)
           {
               printf("USAGE: %s a.txt b.txt string(s) string(t)", argv[0]);
	       return 1;
	   }
       a=argv[1];
       b=argv[2];
       s=argv[3];
       t=argv[4];
      
       res=f(a,b,s,t);
       if(res<SUCCESS)
       {
           switch(res)
		{
			case ERROR_OPEN_A:
			printf("CANNOT OPEN %s\n",argv[1]); break;
			case ERROR_OPEN_B:
			printf("CANNOT OPEN %s\n",argv[2]); break;
			case ERROR_READ_A:
			printf("CANNOT READ %s\n",argv[1]); break;
			case ERROR_WRITE_B:
			printf("CANNOT WRITE %s\n",argv[2]); break;
			default:
			printf("UNKNOWN ERROR\n"); break;
		}
        }
	printf("RESULT=%d\n", res);
    return 0;
}

