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

void DisplayPrime(PNODE first)
{
    int iNo = 0, i = 0, flag = 0;

    while (first != NULL)
    {
        iNo = first->data;
        flag = 1;

        if (iNo <= 1)
        {
            first = first->next;
            continue;
        }

        for (i = 2; i <= iNo / 2; i++)
        {
            if (iNo % i == 0)
            {
                flag = 0;
                break;
            }
        }

        if (flag == 1)
        {
            printf("%d ", iNo);
        }

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
    InsertFirst(&head,5);
    InsertFirst(&head,2);

    Display(head);

    DisplayPrime(head);
    
    return 0;
}