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

int CountPrime(PNODE first)
{
    int iNo = 0;
    int iCnt = 0;
    int iCount = 0;
    int bPrime = 1;

    while (first != NULL)
    {
        iNo = first->data;
        bPrime = 1;

        if (iNo < 2)
        {
            first = first->next;
            continue;
        }

        for (iCnt = 2; iCnt <= (iNo / 2); iCnt++)
        {
            if ((iNo % iCnt) == 0)
            {
                bPrime = 0;
                break;
            }
        }

        if (bPrime == 1)
        {
            iCount++;
        }

        first = first->next;
    }

    return iCount;
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
    InsertFirst(&head,5);
    InsertFirst(&head,2);

    Display(head);

    iRet = CountPrime(head);
    printf("Count of prime number is :%d\n", iRet);
    
    return 0;
}