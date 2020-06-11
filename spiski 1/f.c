#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "f.h"
#include "li.h"
#define LEN2 256

static int test_f(char *buf, char *buf_s) 
{
    if (strspn (buf, buf_s)==(strlen (buf))) return 1;
        
	return 0;
}

list *func(list *head, char *s)
{
    list *curr;
    list *prev;
    
    if (!head->next) return head;
    
    curr=head;
    
    while (head&&head->next&&(test_f(head->string,s)==1))
    {
        curr=head;
        head=head->next;
        free(curr->string);
        free(curr);
    } 
    
    for (prev=head, curr=head->next; curr; curr=curr->next)
    {            
        if (test_f(curr->string,s)==1)
        {
            prev->next = curr->next;
            free(curr->string);
            free(curr);
            curr = prev;
        }
        else prev=curr;
    }

    return head;
}



