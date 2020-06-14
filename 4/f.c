#include <stdio.h>
#include <string.h>
#include "f.h"
#define LEN 1234
#define LEN2 256

static int func(const char *s, char *buf, char *buf_t) 
{
    int i=0,j,k;
     while (buf[i]!='\0')
     {j=0;
        if (buf[i]==s[j])
        {k=i;
            while (buf[k]!='\0')
            {
                if (buf[k] == s[j])
                {
                    k++;
                    j++;
                }
                else
                {
                    if (buf_t[(int)buf[k]]==1) k++;
                    else if (buf_t[(int)s[j]]==1) j++;
                    else break;
                }
            }
        }
        if (s[j]=='\0') break;
        else i++;
    }
if (buf[i]=='\0') return 0;
else return 1;
}

static void alph(char *buf_t, const char *t)
{
    int i;
        for (i=0; i<256; i++)
        {
            buf_t[i] = 0;
        }
    i=0;
        while (t[i]!='\0')
        {
            buf_t[(int)t[i]]=1;
            i++;
        }
}

int f(const char *a, const char *b, const char *s, const char *t)
{
    FILE *f1, *f2;
    char buf[LEN];
    char buf_t[LEN2];
    int res=0, i=0;
    char *flag;
    	if(!(f1=fopen(a,"r")))
	    return ERROR_OPEN_A;
        if(!(f2=fopen(b,"w")))
        {
	    fclose(f1);
	    return ERROR_OPEN_B;
	}
        alph(buf_t,t);
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
            
            
            if (func(s,buf,buf_t)==1)
                {
                 res++;
                 fprintf(f2, "%s\n", buf);
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