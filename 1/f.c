#include <stdio.h>
#include <string.h>
#include "f.h"
#define LEN 1234

static void test_f(char *buf, const char *s, const char *r, char *flag, FILE *f2, int len) 
{   int i=0;
    while (buf[i]!='\0')
    {
        if ((buf+i)!=flag)
        {
            fprintf(f2,"%c",buf[i]);
        }
       	if((buf+i)==flag)
        {
            fprintf(f2,"%s",r);
            i=i+len-1;
            flag=strstr(buf+i,s);
        }
        i++;
    }
}

int f(const char *a, const char *b, const char *s, const char *r)
{
    FILE *f1, *f2;
    char buf[LEN];
    int res=0, len;
    char *flag;
    	if(!(f1=fopen(a,"r")))
	    return ERROR_OPEN_A;
        if(!(f2=fopen(b,"w")))
        {
	    fclose(f1);
	    return ERROR_OPEN_B;
	}
    len=strlen(s);
    	while(fgets(buf,LEN,f1))
	{
            if (flag=strstr(buf,s))
            {
                res++;
		test_f(buf,s,r,flag,f2,len);
             }
            else fprintf(f2, "%s", buf);
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