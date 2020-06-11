#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "f.h"
#define LEN 1234

static int test_s(char *s, char *x, char *a)
{
    if (strlen(x)==1)
    {
        if (x[0]=='>') 
        {
            if(strcmp(a,s)>0) return 1;
            else return 0;      
        }  
        else if (x[0]=='<') 
        {   
            if(strcmp(a,s)<0) return 1;   
            else return 0;      
        }      
    }
    else if(strlen(x)==2)
    {   
        if ((x[1]=='=')&&(x[0]=='='))
        {    
            if(strcmp(a,s)==0) return 1;   
            else return 0;         
        }
        else if ((x[1]=='=')&&(x[0]=='>'))
        {   
            if((strcmp(a,s)>0)||(strcmp(a,s)==0)) return 1;       
            else return 0;       
        }
        else if ((x[1]=='=')&&(x[0]=='<'))
        {        
            if((strcmp(a,s)<0)||(strcmp(a,s)==0)) return 1;      
            else return 0;       
        }
        else if ((x[1]=='=')&&(x[0]=='!'))
        { 
            if(strcmp(a,s)==0) return 0;       
            else return 1;          
        }
        else return 0;
    }
    return 0;
    
}

static int words(char *s, char *t, char *x, char *a)
{
    int slova=0,len1=0,sum=0,shift=0;
    char arr[LEN][LEN];
   // printf("\n");
    while (a[sum]!='\0')   
    {        
        len1=strcspn(a+sum, t); 
        if (len1==0) 
        {
            shift=strspn(a+sum,t);
            sum+=shift;
        }  
        else  
        {
            memcpy(arr[slova],a+sum,len1);
            arr[slova][len1+1]='\0';
            
            //printf("slovo:%s\n",arr[slova]);
            if (test_s(s,x,arr[slova])==0) {return 0;}
            slova+=1;
            sum+=len1;
        }
    }
    //printf("slova:%d\n",slova);
    return slova;
}



int f(char *a,char *b, char *s, char *t, char *x)
{
    FILE *f1, *f2;
    char buf[LEN];
    int res=0,i=0;
    
    
    if(!(f1=fopen(a,"rt"))) return ERROR_OPEN_A;
        
    if(!(f2=fopen(b,"w")))
    {
        fclose(f1);	
        return ERROR_OPEN_B;
    }
	
    while (fgets (buf, LEN, f1))
    {
        for(i=0; buf[i]; i++)
	{
	    if(buf[i]=='\n')
            {
		buf[i]='\0';
                break;
            }
	}
        if(words(s,t,x,buf)>0)
        {
            //printf("%d\n",words(s,t,x,buf));
            fprintf(f2, "%s\n", buf);
            res++;   
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


