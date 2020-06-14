#include <stdio.h>
#include <string.h>
#include "f.h"
#define LEN 1234
#define LEN2 256

static int func(char *buf, char *buf_s,char *buf_r,FILE *f2) 
{
    int i=0,res=0;
    for (i=0; buf[i]; i++)
    {
        if (buf_s[(int)buf[i]]==1)
        {
            fprintf(f2,"%c",buf_r[(int)buf[i]]);
            res++;
        }
        else
            fprintf(f2,"%c",buf[i]);
    }
    return res;
}

static void alph(char *buf_s,char *buf_r, const char *s, const char *r, int len1, int len2)
{
    int i;
        for (i=0; i<256; i++)
        {
            buf_s[i]=0;
            buf_r[i]=0;
        }
    i=0;
        while (s[i]!='\0')
        {
            buf_s[(int)s[i]]=1;
            if (i<len2) {buf_r[(int)s[i]] = (int)r[i];}
        i++;          
        }
}


int f(const char *a, const char *b, const char *s, const char *r)
{
    FILE *f1, *f2;
    char buf[LEN];
    char buf_s[LEN2];
    char buf_r[LEN2];
    int res=0, i=0, len1, len2;
    	if(!(f1=fopen(a,"r")))
	    return ERROR_OPEN_A;
        if(!(f2=fopen(b,"w")))
        {
	    fclose(f1);
	    return ERROR_OPEN_B;
	}
    
    len1 = strlen(s);
    len2 = strlen(r);
    
    alph(buf_s,buf_r,s,r,len1, len2);
    
    	while(fgets(buf,LEN,f1))
	{
              
            for(i=0; buf[i]; i++)
	    {
	    if(buf[i]=='\n')
		{
		    buf[i]='\0';
                    break;
		}
	    }
            
            res=res+func(buf,buf_s,buf_r,f2);
            
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