#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void Process(double *matr, int N, int M);
int main(void)
{
    FILE *in,*out;
    int i,j;
    int N,M;
    double *a;


    if(!(in=fopen("input.txt","r"))) return -1;

    if(!(out=fopen("output.txt","w"))) return -1;
    
    if(fscanf(in,"%d%d",&N,&M)!=2) return -1;
    
       // printf("123\n");
    if (!(a=(double*)malloc(N*M*sizeof(double)))) return -1;
    
    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
            if(fscanf(in,"%lf ",a+i*M+j)!=1)
                {
                    fclose(in);
                    fclose(out);
                    free(a);
                    return -1;
                }
    fclose(in);
    Process(a,N,M);
    
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++) fprintf(out,"%lf ",a[i*M+j]);
        printf("\n");
    }
    
    free(a);
    fclose(out);
    
    return 0;
}

void Process(double *matr, int N, int M)
{
    double max1=matr[0], max2;
    int i,j,imax=0;
    
    for (i=0;i<N;i++)
    {
        for (j=0;j<M;j++)
        {
            if(matr[i*M+j]>max1) 
            {
                max1=matr[i*M+j];
                imax=i;
            }    
        }     
    }
    
    
        for(j=0;j<M;j++)
        {  
            max2=matr[j];
            for(i=0;i<N;i++)
            {
                 if(matr[i*M+j]>max2) 
                 {
                     max2=matr[i*M+j];
                 }      
            }
            matr[imax*M+j]=max2;
        }
}



