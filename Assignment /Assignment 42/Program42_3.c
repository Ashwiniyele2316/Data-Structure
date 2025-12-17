
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
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->Data = no;
    newn->Next = NULL;

    if (*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->Next = *Head;
        *Head = newn;
    }
}


int Addition(PNODE Head)
{
    int sum = 0;

    while (Head != NULL)
    {
        sum = sum + Head->Data;
        Head = Head->Next;
    }
    return sum;
}

int main()
{
    PNODE First = NULL;
    int Ret = 0;

    InsertFirst(&First, 40);
    InsertFirst(&First, 30);
    InsertFirst(&First, 20);
    InsertFirst(&First, 10);

    ret = Addition(First);
    printf("%d", ret);

    return 0;
}
