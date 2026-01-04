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

int SecMaximum(PNODE Head)
{
    int max1 = Head->Data;
    int max2 = -1;

    while(Head != NULL)
    {
        if(Head-> Data > max1)
        {
            max2 = max1;
            max1 = Head->Data;
        }
        else if( Head->Data > max2 && Head->Data != max1)
        {
            max2 = Head->Next;
        }
        Head = Head->Next;
    } 
    return max2;

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
    iRet = SecMaximum(First);
    printf("Maximum of all elements :%d\n",iRet);
    

}