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


int SearchLastOcc(PNODE Head, int no)
{
    int pos = 1;
    int lastpos = -1;

    while (Head != NULL)
    {
        if (Head->Data == no)
        {
            lastpos = pos;
        }
        Head = Head->Next;
        pos++;
    }
    return lastpos;
}

int main()
{
    PNODE First = NULL;
    int ret = 0;

    InsertFirst(&First, 70);
    InsertFirst(&First, 30);
    InsertFirst(&First, 50);
    InsertFirst(&First, 40);
    InsertFirst(&First, 30);
    InsertFirst(&First, 20);
    InsertFirst(&First, 10);

    ret = SearchLastOcc(First, 30);
    printf("%d", ret);

    return 0;
}
