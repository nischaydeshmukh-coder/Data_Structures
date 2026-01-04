#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int BOOL;

struct node
{
    int Data;
    struct node *Next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE Head, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> Next = NULL;
    newn -> Data = no;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn -> Next = *Head;
        *Head = newn;
    }
}
void DisplayPrime(PNODE Head)
{
    int iCnt = 0;
    BOOL flag = TRUE;

    printf("Prime number: ");
    while(Head != NULL)
    {
        if(Head->Data < 2)
        {
            Head = Head ->Next;
            continue;
        }

        flag = TRUE;
        for(iCnt = 2; iCnt<= Head->Data/2 ; iCnt++)
        {
            if((Head->Data % iCnt) == 0)
            {
                flag = FALSE;
                break;
            }
        }

        if(flag == TRUE)
        {
            printf("%d", Head->Data);
        }
        Head = Head -> Next;
    }
    printf("\n");
}

void Display(PNODE Head)
{
    while(Head != NULL)
    {
        printf("| %d |->", Head->Data);
        Head = Head -> Next;
    }
    printf("NULL\n");

}

int main()
{
    PNODE First = NULL;
    int iRet = 0;

    InsertFirst(&First,101);
    InsertFirst(&First,51);
    InsertFirst(&First,21);
    InsertFirst(&First,6);

    Display(First);

    DisplayPrime(First);
    

}