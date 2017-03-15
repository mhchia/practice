#include <stdio.h>
#include <stdlib.h>

typedef struct listnode {
    int val;
    struct listnode* next;
} ListNode;

ListNode* GenerateList()
{
    ListNode *a = (ListNode*)malloc(sizeof(ListNode));
    a->val = 1;
    a->next = NULL;
    ListNode *b = (ListNode*)malloc(sizeof(ListNode));
    b->val = 2;
    b->next = a;
    ListNode *c = (ListNode*)malloc(sizeof(ListNode));
    c->val = 3;
    c->next = b;
    return c;
}

void PrintList(ListNode* a)
{
    while (a != NULL) {
        printf("%d ", a->val);
        a = a->next;
    }
}

ListNode* InvertList(ListNode* a)
{
    if (!a) return NULL;
    ListNode *prev = NULL, *current = a, *next;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main(void)
{
    ListNode *a = GenerateList();
    PrintList(a);
    puts("");
    a = InvertList(a);
    PrintList(a);
    puts("");

}

