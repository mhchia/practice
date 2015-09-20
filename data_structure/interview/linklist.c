#include <stdio.h>
#include <stdlib.h>

struct listnode {
    int data;
    struct listnode *next;
};
typedef struct listnode ListNode;

void print(ListNode *node)
{
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

ListNode *insert(ListNode *node, int data)
{
    ListNode *temp = (ListNode*)malloc(sizeof(ListNode));
    if (node) {
        temp->data = data;
        temp->next = node;
        node = temp;
    } else {
        temp->data = data;
        temp->next = NULL;
        node = temp;
    }
    return node;
}

ListNode *delete(ListNode *node, int data)
{
    // if the first one is the data
    if (node->data == data) {
        ListNode *temp = node->next;
        free(node);
        node = temp;
        return node;
    }
    // else
    ListNode *temp = node, *temp2;
    while (temp->next != NULL && temp->next->data != data) {
        temp = temp->next;
    }
    // temp->next = data or temp->next == NULL
    if (temp->next->data == data) {
        temp2 = temp->next->next;
        free(temp->next);
        temp->next = temp2;
    }
    return node;
}

ListNode *revert(ListNode *node)
{
    // p is the next, q is now, r is the last.
    ListNode *p = node, *q = NULL, *r;

    while (p != NULL) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    return q;
}

ListNode *revert_recur(ListNode *node)
{

}


ListNode *tail(ListNode *node)
{
    while (node->next != NULL)
        node = node->next;
    return node;
}

int cross(ListNode *l1, ListNode *l2)
{
    return 0;
}

void BubbleSort(ListNode *node)
{
/*
    [           ]
     ---------->
     -------->
     ----->
*/
    while (node->next != NULL) {
        ListNode *i = node;
        while (1) {

        }
        node = node->next;
    }

}

int main(void)
{
    ListNode *temp = NULL;
    int i;
    for (i = 0; i < 10; ++i)
        temp = insert(temp, i);
    print(temp); puts("");
    temp = revert_recur(temp);
    print(temp); puts("");

    /*
    ListNode *t1 = (ListNode*)malloc(sizeof(ListNode));
    t1->data = 1;
    t1->next = NULL;
    ListNode *t2 = (ListNode*)malloc(sizeof(ListNode));
    t2->data = 2;
    t2->next = t1;
    ListNode *t3 = (ListNode*)malloc(sizeof(ListNode));
    t3->data = 3;
    t3->next = t1;
    printf("cross? %d\n", cross(t1, t2));
    */
}

