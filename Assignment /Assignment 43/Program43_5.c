#include <stdio.h>
#include <stdlib.h>


struct node
{
    int Data;
    struct node *Next;
};


typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;


void InsertFirst(PPNODE Head, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->Data = no;
    newn->Next = *Head;
    *Head = newn;
}


int SumDigit(int no)
{
    int iSum = 0;
    int iCnt = 0;   

    while (no != 0)
    {
        iCnt++;               
        iSum = iSum + (no % 10);
        no = no / 10;
    }
    return iSum;
}


void DisplaySumDigit(PNODE Head)
{
    while (Head != NULL)
    {
        printf("%d ", SumDigit(Head->Data));
        Head = Head->Next;
    }
}


int main()
{
    PNODE First = NULL;

    InsertFirst(&First, 640);
    InsertFirst(&First, 240);
    InsertFirst(&First, 20);
    InsertFirst(&First, 230);
    InsertFirst(&First, 110);

    DisplaySumDigit(First);

    return 0;
}
