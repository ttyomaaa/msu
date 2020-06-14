#include <stdio.h>
#include <string.h>
#include "f.h"
#define LEN 1234
#define LEN2 256

static int test_f(char *buf, char *buf_s) 
{
    int i=0;
      while ((buf[i]!='\0')&&(buf[i]!='\n'))
      {
          if (buf_s[(int)buf[i]]==1) i++;
          else return 0;
      }
    return 1;
}

static void alph(char *buf_s, const char *s)
{
    int i;
        for (i=0; i<256; i++)
        {
            buf_s[i] = 0;
        }
    i=0;
        while (s[i]!='\0')
        {
            buf_s[(int)s[i]]=1;
            i++;
        }
}

int f(const char *a, const char *b, const char *s, const char *t)
{
    FILE *f1, *f2;
    char buf[LEN];
    char buf_s[LEN2];
    int res=0, i=0;
    	if(!(f1=fopen(a,"r")))
	    return ERROR_OPEN_A;
        if(!(f2=fopen(b,"w")))
        {
	    fclose(f1);
	    return ERROR_OPEN_B;
    alph(buf_s,s);
    	while(fgets(buf,LEN,f1))
	{
            for(i=0; buf[i]; i++)
	    {
	    if(buf[i]=='\r')
		{
		    buf[i]='\0';
                    break;
		}
	    }
             if (test_f(buf,buf_t,buf_s)==1)
             {
                 res++;
                 fprintf(f2, "%s", buf);
             }
        }
	if(!feof(f1))
	{
		fclose(f1);
		fclose(f2);
		return ERROR_READ_A;
	}
    fclose(f1);
    fclose(f2);
    return res;
}