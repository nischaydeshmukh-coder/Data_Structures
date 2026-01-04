#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE; 

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)  // LL is empty
    {
        *first = newn;
    }
    else                // LL contains atleast 1 node
    {
        newn->next = (*first);
        (*first) = newn;
    }
}

bool CheckSorted(PNODE Head)
{
    if (Head == NULL)  
    {
        return true;
    }

    while (Head->next != NULL)
    {
        if (Head->data > Head->next->data)
        {
            return false; 
        }
        Head = Head->next;
    }
    return true;  
}

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d |->",first->data);
        first = first -> next;
    }
    
    printf("NULL \n");
}

int main()
{
    PNODE head = NULL;
    int iRet = 0 ;

    InsertFirst(&head,75);
    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,76);

    Display(head);

    if (CheckSorted(head))
    {
        printf(" Elements are in ascending order.\n");
    }
    else
    {
        printf("Elements are not in ascending order.\n");
    }
    
    return 0;
}