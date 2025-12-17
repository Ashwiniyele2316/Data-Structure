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


int AdditionEven(PNODE Head)
{
    int iSum = 0;
    int iCnt = 0;   

    while (Head != NULL)
    {
        iCnt++;

        if ((Head->Data % 2) == 0)
        {
            iSum = iSum + Head->Data;
        }
        Head = Head->Next;
    }
    return iSum;
}

int main()
{
    PNODE First = NULL;
    int iRet = 0;

    InsertFirst(&First, 41);
    InsertFirst(&First, 32);
    InsertFirst(&First, 20);
    InsertFirst(&First, 11);

    iRet = AdditionEven(First);

    printf("Addition of even elements is : %d", iRet);

    return 0;
}
