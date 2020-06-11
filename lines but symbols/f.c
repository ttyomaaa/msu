#include <stdio.h>
#include <string.h>
#include "f.h"
#define LEN 1234

int f(const char *a, const char *b)
{
    FILE *f1, *f2;
    char buf[LEN];
    int res=0, i=0, j=0, k=0, m=0;
    	
    if(!(f1=fopen(a,"r"))) return ERROR_OPEN_A;
        
    if(!(f2=fopen(b,"w")))
    {
        fclose(f1);
        return ERROR_OPEN_B;
    }
        
    	while(fgets(buf,LEN,f1))
	{
            i=0;
            j=0;
            m=0;
            while (buf[i]!='\0')
            {
                if((buf[i]=='('))
                {
                    fprintf(f2,"%c",' ');
                    while((buf[i]=='('))
                    {
                        j=0;
                        m=0;
                        fprintf(f2,"%c",'(');
                        i++;
                        res++;
                        if((buf[i]==' ')) i++;
                    }
                }
                else if((buf[i]==')'))
                {
                    while((buf[i]==')'))
                    {                        
                        for(k=0;k<j;k++)                    
                        {
                            fprintf(f2,"%c",' ');
                        }                    
                        j=0;                                                
                        m=1;                        
                        fprintf(f2,"%c",')');
                        i++;
                        res++;
                        if((buf[i]==' ')) i++;
                    }    
                    fprintf(f2,"%c",' ');
                }
                if(buf[i]!='\0')
                {
                    if(m==1)
                    {
                        if((buf[i]!=' '))                   
                        {                                   
                            m=0;
                            fprintf(f2,"%c",buf[i]);                                                        
                        }    
                    }
                    else
                    {                    
                        if((buf[i]==' ')) j++;                    
                        else                    
                        {                            
                            for(k=0;k<j;k++)                                           
                            {                           
                                fprintf(f2,"%c",' ');                        
                            }                                           
                            j=0;
                        
                            fprintf(f2,"%c",buf[i]);                                                       
                        }
                    }   
                    i++;
                }
            }
        }          
    for(k=0;k<j;k++)                    
    {
        fprintf(f2,"%c",' ');
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