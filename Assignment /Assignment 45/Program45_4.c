/*
| 11 | -> | 21 | -> | 51 | -> NULL
Number of nodes are : 3
| 11 | -> | 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 | -> NULL
Number of nodes are : 6
| 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 | -> NULL
Number of nodes are : 5
| 21 | -> | 51 | -> | 101 | -> | 111 | -> NULL
Number of nodes are : 4
Number of elements greater than 100 are : 2
*/

#include<stdio.h>
#include<stdlib.h>

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
    if(*first == NULL) 
    {
        return;
    }
    *first = (*first)->next;
    free(temp);
}

void DeleteLast(PPNODE first)
{
    PNODE temp = *first;
    if(*first == NULL) 
    {
        return;
    }
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

int CountGreater(PNODE Head, int X)
{
    int iCount = 0;

    while(Head != NULL)
    {
        if(Head->data > X)
        {
            iCount++;
        }
        Head = Head->next;
    }
    return iCount;
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);
    
    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n", iRet);
    
    InsertLast(&head, 101);
    InsertLast(&head, 111);
    InsertLast(&head, 121);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n", iRet);

    DeleteFirst(&head);
    
    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n", iRet);

    DeleteLast(&head);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n", iRet);

    iRet = CountGreater(head, 100);
    printf("Number of elements greater than 100 are : %d\n", iRet);

    return 0;
}
