#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "f.h"
#define LEN 1234

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

static int slova(char arr[LEN][LEN], char *buf_t, char *s)
{

    int i;
    int j;
    while (s[i]!='\0')
    {
        if ((buf_t[(int)s[i]]==1)&&(flag==1))
        {
            slova[j][0];
            
            
            
        }
    return j;
}


int f(const char *a, const char *b, const char *s, const char *t)
{
    FILE *f1, *f2;
    char buf[LEN];
    char buf_t[256];
    char arr[LEN][LEN];
    int res=0, flag;
    
    	if(!(f1=fopen(a,"r")))
	    return ERROR_OPEN_A;
        if(!(f2=fopen(b,"w")))
        {
	    fclose(f1);
	    return ERROR_OPEN_B;
	}
    alph(buf_t,t);
    flag=slova(arr,buf_t,s);
	while (fgets (buf, LEN, f1))
	{

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


/*
if (strlen(s)==1)
{if (strcspn(buf,s)!=strlen(buf))
    {
	fprintf (f2, "%s", buf);
	res++;
    }
}
 */
















