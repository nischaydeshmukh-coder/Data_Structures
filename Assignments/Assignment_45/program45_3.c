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

int LastOccur(PNODE first, int no)
{
    int ipos = 0, iCnt = 0;

    while (first != NULL)
    {
        iCnt++;

        if (first->data == no)
        {
            ipos = iCnt;
        }
        first = first->next;
    } 
    
        if(ipos == 0)
        {
            return -1;
        }
    return ipos;
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

    InsertFirst(&head,22);
    InsertFirst(&head,51);
    InsertFirst(&head,22);
    InsertFirst(&head,12);

    Display(head);

    printf("Enter a number :");
    scanf("%d",&iValue);

    iRet = LastOccur(head,iValue);
    printf("Last Occurance of the element: %d\n",iRet);
    
    return 0;
}