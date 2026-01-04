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

bool Search(PNODE first, int No)
{
    while (first != NULL)
    {
        if (first->data == No)
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

int Count(PNODE first)
{
    int iCount = 0;

    while(first!= NULL)
    {
        iCount++;
        first = first -> next;
    }

    return iCount;
}

int main()
{
    PNODE head = NULL;
    int iRet = 0 , iValue = 0 ;

    InsertFirst(&head,75);
    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    Display(head);

    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);

    printf("Enter element to search: ");
    scanf("%d", &iValue);

    if (Search(head, iValue))
    {
        printf("Element %d is present in the linked list.\n", iValue);
    }
    else
    {
        printf("Element %d is NOT present in the linked list.\n", iValue);
    }
    
    return 0;
}