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
        if ((s[i]=='\\')&&((s[i+1]=='\\')||(s[i+1]=='^')))
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
    int res=0, len, i=0,len_upd;
    char *flag;
        char *s_upd;
    	if(!(f1=fopen(a,"r")))
	    return ERROR_OPEN_A;
        if(!(f2=fopen(b,"w")))
        {
	    fclose(f1);
	    return ERROR_OPEN_B;
	}
        len=strlen(s);
        s_upd=malloc(len);
    
    if (s[0]=='^')
    {
             len_upd=replace(s_upd,s,1);           
            // printf("%s",s_upd);
    	while(fgets(buf,LEN,f1))
	{
            if(flag=strstr(buf,s_upd))
            {
                //printf("here");
               if (flag==&buf[0]) {res++;fprintf(f2, "%s", buf);}
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