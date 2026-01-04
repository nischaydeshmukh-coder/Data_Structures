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

bool CheckAllPositive(PNODE first)
{
    while (first != NULL)
    {
        if (first->data = 0)
        {
            return true;
        }
        first = first->next;
    }
    return false;
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
    InsertFirst(&head,-11);

    Display(head);

    if (CheckAllPositive(head))
    {
        printf(" All Elements are positive.\n");
    }
    else
    {
        printf("All Elements are not positive.\n");
    }
    
    return 0;
}