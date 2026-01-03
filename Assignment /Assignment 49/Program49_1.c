/*
| 11 | -> | 21 | -> | 51 | -> | 101 | -> | 121 | -> | 5 | -> NULL
Number of nodes are : 6
Difference between Max and Min is : 116

*/

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
typedef struct node* PNODE;
typedef struct node** PPNODE;


void InsertFirst(PPNODE first, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }   
    else
    {
        newn->next = *first;
        *first = newn;
    }
}

void InsertLast(PPNODE first, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    PNODE temp = *first;
    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }   
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE first)
{
    PNODE temp = *first;
    if(*first == NULL) return;
    
    *first = (*first)->next;
    free(temp);
}

void DeleteLast(PPNODE first)
{
    PNODE temp = *first;
    if(*first == NULL) return;
    
    if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d | -> ", first->data);
        first = first->next;
    }
    printf("NULL\n");
}

int Count(PNODE first)
{
    int iCount = 0;
    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }
    return iCount;
}

void InsertAtPos(PPNODE first, int no, int pos)
{
    int iSize = Count(*first);
    PNODE newn = NULL;
    PNODE temp = *first;

    if((pos < 1) || (pos > iSize + 1))
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first, no);
    }
    else if(pos == iSize + 1)
    {
        InsertLast(first, no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteAtPos(PPNODE first, int pos)
{
    int iSize = Count(*first);
    PNODE temp = *first;
    PNODE target = NULL;

    if((pos < 1) || (pos > iSize))
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if(pos == iSize)
    {
        DeleteLast(first);
    }
    else
    {
        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        free(target);
    }
}

int Difference(PNODE Head)
{
   
    if(Head == NULL)
    {
        return 0;
    }

    int iMax = Head->data;
    int iMin = Head->data;

    while(Head != NULL)
    {
        if(Head->data > iMax)
        {
            iMax = Head->data;
        }
        if(Head->data < iMin)
        {
            iMin = Head->data;
        }
        Head = Head->next;
    }

    return (iMax - iMin);
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);
    
    InsertLast(&head, 101);
    InsertLast(&head, 121);
    InsertLast(&head, 5); 

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n", iRet);

    iRet = Difference(head);
    printf("Difference between Max and Min is : %d\n", iRet);

    return 0;
}
