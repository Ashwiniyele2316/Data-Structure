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


int IsPrime(int no)
{
    int iCnt = 0;

    if (no < 2)
        return 0;

    for (iCnt = 2; iCnt <= no / 2; iCnt++)
    {
        if (no % iCnt == 0)
            return 0;
    }
    return 1;
}

void DisplayPrime(PNODE Head)
{
    while (Head != NULL)
    {
        if (IsPrime(Head->Data))
            printf("%d ", Head->Data);

        Head = Head->Next;
    }
}

int main()
{
    PNODE First = NULL;

    InsertFirst(&First, 89);
    InsertFirst(&First, 22);
    InsertFirst(&First, 41);
    InsertFirst(&First, 17);
    InsertFirst(&First, 20);
    InsertFirst(&First, 11);

    DisplayPrime(First);

    return 0;
}
