#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *link;
}Node;
int main()
{
    Node *head = NULL;
    head = (Node *)malloc(sizeof(Node));
    head->data = 45;
    head->link = NULL;

    Node *current = NULL;
    current = (Node *)malloc(sizeof(Node));
    current->data = 98;
    current->link = NULL;
    head->link = current;

    current = (Node *)malloc(sizeof(Node));
    current->data = 3;
    current->link = NULL;
    head->link->link = current;

    printf("%d", current->data);

    return 0;
}

