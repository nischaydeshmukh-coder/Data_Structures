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

int Difference(PNODE first)
{
    int iMax = 0;
    int iMin = 0;

    if (first == NULL)
    {
        return 0;
    }

    iMax = first->data;
    iMin = first->data;

    while (first != NULL)
    {
        if (first->data > iMax)
        {
            iMax = first->data;
        }

        if (first->data < iMin)
        {
            iMin = first->data;
        }

        first = first->next;
    }

    return (iMax - iMin);
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
    int iRet = 0 , iValue = 0 ;

    InsertFirst(&head,75);
    InsertFirst(&head,51);
    InsertFirst(&head,22);
    InsertFirst(&head,11);

    Display(head);

    iRet = Difference(head);

    printf("Difference between Max and Min : %d\n", iRet);    
    
    return 0;
}