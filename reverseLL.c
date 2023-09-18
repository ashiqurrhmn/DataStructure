#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} Node;
Node *create(int data, Node *head)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->link = head;
    head = temp;

    return head;
}
void print(Node *head)
{
    Node *ptr = head;
    while(ptr!=NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}
Node *reverse(Node *head)
{
    Node *next = NULL;
    Node *prev = NULL;

    while(head != NULL)
    {
        next = head->link;
        head->link = prev;
        prev = head;
        head = next;
    }
    head = prev;
    return head;
}
int main()
{
    Node *head = create(60, create(77, create(89, create(100, NULL))));
    printf("Before reverse :");
    print(head);

    printf("\n\nAfter reverse : ");
    head = reverse(head);
    print(head);
}
