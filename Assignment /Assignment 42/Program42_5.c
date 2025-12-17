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


int Minimum(PNODE Head)
{
    int min = Head->Data;

    while (Head != NULL)
    {
        if(Head ->Data < min)
        {
        min = Head->Data;
        }
        Head = Head->Next;
    }
    return min;
}

int main()
{
    PNODE First = NULL;
    int Ret = 0;

    InsertFirst(&First, 640);
    InsertFirst(&First, 240);
    InsertFirst(&First, 20);
    InsertFirst(&First, 230);
    InsertFirst(&First, 110);

    Ret = Minimum(First);
    printf("%d", Ret);

    return 0;
}
