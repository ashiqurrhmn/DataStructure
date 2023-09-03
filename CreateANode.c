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

    printf("%d", head->data);

    return 0;
}
