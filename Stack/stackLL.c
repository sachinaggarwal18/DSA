#include <stdio.h>
#include <stdlib.h>

int size;
typedef struct Node
{
    int val;
    struct Node *next;
} Node;

Node *head;

void insertAtHead(int v)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->val = v;
    n->next = head;
    head = n;
    size++;
}

void remAtHead()
{
    if (head == NULL)
    {
        printf("Underflow\n");
        return;
    }

    if (size == 1)
    {
        free(head);
        size--;
        return;
    }

    Node *temp = head->next;
    // head->next = NULL;
    free(head);
    head = temp;
    size--;
}

void push(int v)
{
    insertAtHead(v);
}

void pop()
{
    remAtHead();
}

void print()
{
    Node *cur = head;
    while (cur != NULL)
    {
        printf("%d->", cur->val);
        cur = cur->next;
    }
}

int main()
{
    push(2);
    push(4);
    push(3);
    push(23);
    push(445);
    push(31);
    print();
    printf("\n");
    pop();
    print();
    return 0;
}
