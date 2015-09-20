#include <stdio.h>
#include <stdlib.h>

struct listnode {
    int data;
    struct listnode *next;
};
typedef struct listnode ListNode;

ListNode *top;

void Init(ListNode *top)
{
    top = NULL;
}

int Empty(ListNode *top)
{
    return !top;
}

void Push(ListNode *top, int data)
{
    ListNode *temp = (ListNode*)malloc(sizeof(ListNode));
    temp->data = data;
    temp->next = top;
    top = temp;
}

int Pop(ListNode *top)
{
    if (Empty()) {
        fprintf(stderr, "stack is empty!\n");
        return -1;
    }
    int temp = top->data;
    top = top->next;
    return temp;
}

