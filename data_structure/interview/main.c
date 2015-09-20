#include <stdio.h>
#include <stdlib.h>


struct tree {
    int data;
    struct tree *l;
    struct tree *r;
};
typedef struct tree Tree;


void Inorder(Tree *t)
{
    if (t != NULL) {
        Inorder(t->l);
        printf("%d ", t->data);
        Inorder(t->r);
    }
}

Tree *InorderSuccessor(Tree *t)
{
    if (t == NULL || t->r == NULL) return NULL;
    Tree *s = t->r;
    while (s->l != NULL)
        s = s->l;

    return s;
}

void *insert(Tree *t, int data)
{
    if (t == NULL) {
        t = (Tree*)malloc(sizeof(Tree));
        t->data = data;
        t->l = NULL;
        t->r = NULL;
        return;
    }

    if (data > t->data)
        insert(t->r, data);
    else if (data < t->data)
        insert(t->l, data);
    else {
        // do nothing.
    }
}

Tree *GetTree(void)
{
    int data[] = {98, 20, 6, 5, 8, 29, 49, 38, 10, 2, 1, 50, 40, 0};
    unsigned int i = 0;

    Tree *node = (Tree*)malloc(sizeof(Tree));
    while (data[i] != 0) {
        insert(node, data[i]);
    }
    return node;
}

int main(void)
{
    Tree *node = GetTree();
    Tree *is = InorderSuccessor(node);
    if (is != NULL) {
        printf("%d\n", is->data);
    }
    Inorder(node);
    printf("\n");
}

