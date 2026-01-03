/*
Linked List Elements are: 
| 11 | -> | 21 | -> | 51 | -> | 101 | -> | 111 | -> NULL
Number of nodes are: 5
Element 101 is present in the Linked List

After DeleteFirst and DeleteLast:
Linked List Elements are: 
| 21 | -> | 51 | -> | 101 | -> NULL
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

    if(*first == NULL) {
        *first = newn;
    } else {
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

    if(*first == NULL) {
        *first = newn;
    } else {
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE first)
{
    PNODE temp = *first;
    if(*first == NULL) return;

    if((*first)->next == NULL) {
        free(*first);
        *first = NULL;
    } else {
        *first = (*first)->next;
        free(temp);
    }
}

void DeleteLast(PPNODE first)
{
    PNODE temp = *first;
    if(*first == NULL) return;

    if((*first)->next == NULL) {
        free(*first);
        *first = NULL;
    } else {
        while(temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void Display(PNODE first)
{
    printf("Linked List Elements are: \n");
    while(first != NULL) {
        printf("| %d | -> ", first->data);
        first = first->next;
    }
    printf("NULL\n");
}

int Count(PNODE first)
{
    int iCount = 0;
    while(first != NULL) {
        iCount++;
        first = first->next;
    }
    return iCount;
}



bool Search(PNODE Head, int No)
{
    bool bFlag = false;

    while(Head != NULL)
    {
        if(Head->data == No)
        {
            bFlag = true;
            break;
        }
        Head = Head->next;
    }
    return bFlag;
}


int main()
{
    PNODE head = NULL;
    bool bRet = false;
    int iRet = 0;

    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);
    InsertLast(&head, 101);
    InsertLast(&head, 111);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are: %d\n", iRet);

    int iValue = 101;
    bRet = Search(head, iValue);

    if(bRet == true) {
        printf("Element %d is present in the Linked List\n", iValue);
    } else {
        printf("Element %d is NOT present in the Linked List\n", iValue);
    }

    DeleteFirst(&head);
    DeleteLast(&head);

    printf("\nAfter DeleteFirst and DeleteLast:\n");
    Display(head);

    return 0;
}
