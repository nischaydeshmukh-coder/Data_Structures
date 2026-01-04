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

    newn->Next = NULL;
    newn->Data = no;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->Next = (*Head);
        *Head = newn;
    }
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

int SumDigit(PNODE Head)
{
    int no = 0, sum = 0, digit = 0;

    printf("Sum of Digits:\t");

    while(Head != NULL)
    {
        no = Head->Data;
        sum = 0;

        while(no != 0)
        {
            digit = no % 10;
            sum = sum + digit;
            no = no / 10;
        }

        printf("%d\t", sum);
        Head = Head -> Next;
    }
    printf("\n");

}


int main()
{
    PNODE First = NULL;
    int iRet = 0;

    InsertFirst(&First,101);
    InsertFirst(&First,51);
    InsertFirst(&First,21);
    InsertFirst(&First,11);

   
    Display(First);
    SumDigit(First);
    
    

}