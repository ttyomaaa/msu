#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "f.h"
#define LEN 1234

int f(const char *a, const char *b, const char *s, const char *t)
{
    FILE *f1, *f2;
    char buf[LEN];
    char *flag, *s_upd;
    int len;
    int res=0;
    
    	if(!(f1=fopen(a,"r")))
	    return ERROR_OPEN_A;
        if(!(f2=fopen(b,"w")))
        {
	    fclose(f1);
	    return ERROR_OPEN_B;
	}
        len=strlen(s);
    	if (len<1) return 0;
        s_upd=malloc(len*sizeof(char*));
        strcpy(s_upd,s);
        s_upd[len-2]='\0';
        
	while (fgets (buf, LEN, f1))
	{
	    if ((s[len-2]=='\\')&&(s[len-1]=='>'))
		{
                  flag=strstr(buf,s_upd);
                  while(flag)
		   {
		     if (((flag+len-1)==(buf+strlen(buf)))||(strspn(flag+len-2,t)!=0))
		      {
			fprintf (f2, "%s", buf);
			res++;
		      }
                      flag=strstr(flag+1,s_upd);
		   }
		}
	    else 
		{
		   if (strstr(buf,s))
		     {
               	       fprintf (f2, "%s", buf);
		       res++;
		     }
		}
	}
        free(s_upd);
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
















