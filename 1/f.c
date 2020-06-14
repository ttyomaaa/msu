#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "f.h"
#define LEN 1234

int f(const char *a, const char *b, const char *s, const char *t)
{
    FILE *f1, *f2;
    char buf[LEN];
    char *flag;
    int res=0;
    
    	if(!(f1=fopen(a,"r")))
	    return ERROR_OPEN_A;
        if(!(f2=fopen(b,"w")))
        {
	    fclose(f1);
	    return ERROR_OPEN_B;
	}
    	if (strlen(s)<1) return 0;
	while (fgets (buf, LEN, f1))
	{
	    if ((s[0]=='\\')&&(s[1]=='<'))
		{
		  flag=strstr(buf,s+2);
  		  if (flag)
		   {
		     if ((flag==buf)||(strspn(flag-1,t)>0))
			{
			  fprintf (f2,"%s",buf);
			  res++;
			}
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
















