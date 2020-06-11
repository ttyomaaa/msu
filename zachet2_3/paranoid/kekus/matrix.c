#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

int read_matrix (char ** a, int m, int n, const char *name, const char *t)
{
    FILE *fp;
    int i, j, k, uch, shift;
    char buf[LEN];
    char *str;
    
    if (!(fp=fopen(name, "r")))  return ERROR_OPEN;
    
    for (i=0; i<m; i++)
    {
        if (!fgets (buf, LEN, fp))
        {
            for (j=0; j<i*n; j++) if (a[j]) free(a[j]);			
		return ERROR_READ;
        }
        for (j=0;(j<(int)strlen(buf))&&(buf[j]);j++)
        {
            if (buf[j]=='\n') break;
        }
        buf[j]='\0';
        str=buf;
        shift=-1;
        for (j=0; j<n; j++)
        {
            uch=strcspn(str+shift, t);
            a[i*n+j]=(char*)malloc(sizeof(char)*(uch+1));
            if (!a[i*n+j])
            {
                for (k=0; k<(i*n+j); k++) if (a[k]) free (a[k]);
                return ERROR_MEMORY;
            }
            for (k=0; k<uch; k++) a[i*n+j][k]=(str+shift)[k];
            a[i*n+j][uch]='\0';
            shift+=uch;
            shift+=strspn(str+shift, t);
            if (shift>=(int)strlen(buf))
            {
                j++;
                break;
            }
        }
        for(j=j;j<n;j++) a[i*n+j]=0;
    }
    fclose (fp);
    return SUCCESS;
}

void print_matrix (char **a, int m, int n)
{
    int i, j, N, M;
    M = m > MAX_M? MAX_M: m;
    N = n > MAX_N? MAX_N: n;
    for (i=0; i<M; i++)
    {
        for (j=0;j<N;j++)
        {
            if (a[i*n+j]) printf("%s ", a[i*n+j]);
        }
        printf ("\n");
    }
}
