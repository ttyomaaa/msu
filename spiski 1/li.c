#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "li.h"

int read_list(const char *fname, list **p_head)
{
    int i;
    FILE *f;
    char buf[LEN];
    list *head;
    list *curr;
    list *end;

    if(!(f=fopen(fname, "r")))
    {
        return OPEN_ERROR;
    }

    if(!(fgets(buf, LEN, f)))
    {
        if (!(feof(f)))
        {
            fclose(f);
            return READ_ERROR;
        }
        fclose(f);
        return READ_ERROR;
    }

    head=(list*)malloc(sizeof(list));

    if (!head)
    {
        fclose(f);
        return MEMORY_ERROR;
    }

    for(i=0; buf[i]; i++)
    {
        if (buf[i]=='\n')
        {
            buf[i]='\0';
            break;
        }
    }

    head->string=(char*)malloc(strlen(buf)+1);

    if (!head->string)
    {
        free(head);
        fclose(f);
        return MEMORY_ERROR;
    }

    strcpy(head->string, buf);
    head->next=NULL;
    end=head;

    while(fgets(buf, LEN, f))
    {
        curr=(list*)malloc(sizeof(list));

        if(!curr)
        {
            delete_list(head);
            fclose(f);
            return MEMORY_ERROR;
        }

        for (i=0; buf[i]; i++)
        {
            if (buf[i]=='\n')
            {
                buf[i]='\0';
                break;
            }
        }

        curr->string=(char*)malloc(strlen(buf)+1);

        if(!curr->string)
        {
            delete_list(head);
            free(curr);
            fclose(f);
            return MEMORY_ERROR;
        }

        strcpy(curr->string, buf);
        curr->next=NULL;
        end->next=curr;
        end=curr;
    }

    if(!(feof(f)))
    {
        delete_list(head);
        fclose(f);
        return READ_ERROR;
    }

    fclose(f);

    *p_head=head;
    return SUCCESS;
}


void delete_list(list *head)
{
    list *curr;
    list *next;

    for (curr=head; curr; curr=next)
    {
        next=curr->next;

        free(curr->string);
        free(curr);
    }
}


void print_list(list *head)
{
    int i;
    list *curr;

    for (i=0, curr=head; i<12&&curr;i++,curr=curr->next)
    {
        printf("%s\n", curr->string);
    }

    printf("\n");
}