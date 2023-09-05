#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} Node;

Node *newNode(Node *nextNode, int data)
{
    Node *temp = (Node*)malloc(sizeof(Node));

    temp->data = data;
    temp->link = NULL;
    temp->link = nextNode;

    return temp;
}

void print(Node *head)
{
    Node *ptr = head;
    if (ptr == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}

int main()
{
    Node *head = NULL;
    head = newNode(head, 45);
    head = newNode(head, 455);
    head = newNode(head, 495);

    print(head);

    return 0;
}
