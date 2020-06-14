#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "f.h"
#define LEN 1234
static int replace(char *s_upd,const char *s, int flag)
{
    int i,j=0;
    i=flag;
    while (s[i])
    {
        if ((s[i]=='\\')&&((s[i+1]=='\\')||(s[i+1]=='$')))
            i++;
        s_upd[j]=s[i];
        i++;
        j++;
    }
    s_upd[j]='\0';
    return j;
}


int f(const char *a, const char *b, const char *s)
{
    FILE *f1, *f2;
    char buf[LEN];
    int res=0, len, i=0,len_upd, fl_src;
    char *flag;
        char *s_upd;
        len=strlen(s);
        if((len==0)|| (len==1 && s[0]=='$'))
            return ERROR_EMPTY_SRC;
    	if(!(f1=fopen(a,"r")))
	    return ERROR_OPEN_A;
        if(!(f2=fopen(b,"w")))
        {
	    fclose(f1);
	    return ERROR_OPEN_B;
	}
        s_upd=malloc(len);
     
    if (s[len-1]=='$' && s[len-2]!='\\')
    {
             len_upd=replace(s_upd,s,1);           
    	while(fgets(buf,LEN,f1))
	{
            len=strlen(buf);
            buf1=buf;
            if(flag=strstr(buf1,s_upd))
            {
               b 
               if (flag+len_upd==&buf[0]) {res++;fprintf(f2, "%s", buf);}
            }
            
        }
    }
    else
    {       
        len_upd=replace(s_upd,s,0);  
    	while(fgets(buf,LEN,f1))
	{
            if (flag=strstr(buf,s))
             {
                res++;
                fprintf(f2, "%s", buf);
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