#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "f.h"
#include "li.h"
#define LEN2 256

list *f(list *head)
{
    int res,flag=0;
    list *curr, *prev=NULL;
 
    if (!head->next) return head;
 
    res=strcmp(head->string, head->next->string);


    while (head->next && res==0)
    {
        flag=1;
        res=strcmp(head->string, head->next->string);
        curr=head;
        head=head->next;
        free(curr->string);
        free(curr);
    } 
    
    
    prev = head;
 
    for (curr = head->next; curr && curr->next; curr = prev->next)
    {
        
        res=strcmp(curr->string, curr->next->string);
 
        if (res==0)
        {                          
            flag=1;
            prev->next = curr->next;
            free(curr->string);
            free(curr);
        }
        else
        {
            if (flag==1)
            {          
                prev->next = curr->next;          
                free(curr->string);          
                free(curr);
                flag=0;
            }
            else prev = curr;      
        }
    }
    
    if (res==0)
    {
        prev->next = curr->next;

        free(curr->string);
        free(curr);
    }
 
    return head;
}