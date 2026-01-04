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
typedef struct node *PNODE;
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

void CountDigits(PNODE first)
{
    int iNo = 0, iCnt = 0;

    while (first != NULL)
    {
        iNo = first->data;
        iCnt = 0;

        if (iNo == 0)
        {
            iCnt = 1;
        }
        else
        {
            while (iNo != 0)
            {
                iCnt++;
                iNo = iNo / 10;
            }
        }

        printf("Digits in %d : %d\n", first->data, iCnt);
        first = first->next;
    }
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
    InsertFirst(&head,22);
    InsertFirst(&head,12);

    Display(head);

    CountDigits(head);
    
    return 0;
}