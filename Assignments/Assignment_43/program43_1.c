#include<stdio.h>
#include<stdlib.h>

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
void DisplayPerfect(PNODE Head)
{
    int iCnt = 0,sum = 0;
    int no = 0;

    printf("Perfect number: ");
    while(Head != NULL)
    {
        no = Head->Data;
        sum = 0;

        for(iCnt = 1; iCnt<= no/2 ; iCnt++)
        {
            if(no % iCnt == 0)
            {
                sum = sum + iCnt;
            }
        }

        if(sum == no)
        {
            printf("%d", no);
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

    DisplayPerfect(First);
    

}