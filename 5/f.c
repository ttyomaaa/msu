#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "f.h"
#define LEN 1234
static int q(const char *s, char *buf)
{
    int i=0,j=0;
    
    while ((buf[i]!='\0')&&(s[j]!='\0'))
    {
        if ((s[j]=='\\')&&((s[j+1]=='\\')||(s[j+1]=='?')))
        { 
        
          j++;
          if ((buf[i]!=s[j])&&(s[j+1]!='?')) return 0;
          else if ((buf[i]!=s[j])&&(s[j+1]=='?'))
              j++;
          else
          {
              i++;
              j++;
          }           
        }
        
        else
        { 
          if ((buf[i]!=s[j])&&(s[j]=='?')) j++;
          else if ((buf[i]!=s[j])&&(s[j+1]!='?'))
              return 0;
          else if ((buf[i]!=s[j])&&(s[j+1]=='?'))
              j++;
          else
          {
              i++;
              j++;
          }
        }
    }
    
    if ((s[j]=='\0')&&(buf[i]!='\0')) return 0;
    
    while (s[j]!='\0')
    {
        if ((s[j]=='\\')&&((s[j+1]=='\\')||(s[j+1]=='?')))
        {
          j++;
          if (s[j+1]!='?') return 0;
          else j++;
        }
        else
        {
          if (s[j]=='?') j++;
          else
          {    
            if (s[j+1]!='?') return 0;
            j++;
          }
        }
    }
    return 1; 
}


int f(const char *a, const char *b, const char *s)
{
    FILE *f1, *f2;
    char buf[LEN];
    int res=0;
    
    	if(!(f1=fopen(a,"r")))
	    return ERROR_OPEN_A;
        if(!(f2=fopen(b,"w")))
        {
	    fclose(f1);
	    return ERROR_OPEN_B;
	}
    	
        while(fgets(buf,LEN,f1))
	{
            if (q(s,buf)==1)
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