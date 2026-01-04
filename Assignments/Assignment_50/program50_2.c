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

void DisplayGreaterThanAvg(PNODE first)
{
    int iSum = 0;
    int iCount = 0;
    float fAvg = 0.0f;
    PNODE temp = first;

    while (temp != NULL)
    {
        iSum += temp->data;
        iCount++;
        temp = temp->next;
    }

    if (iCount == 0)
    {
        printf("Linked list is empty.\n");
        return;
    }
    fAvg = (float)iSum / iCount;
    printf("Average = %.2f\n", fAvg);

    printf("Elements greater than average are:\n");
    while (first != NULL)
    {
        if (first->data > fAvg)
        {
            printf("%d\t", first->data);
        }
        first = first->next;
    }
    printf("\n");
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

    DisplayGreaterThanAvg(head);
    
    return 0;
}