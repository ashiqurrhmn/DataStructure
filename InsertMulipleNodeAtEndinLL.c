#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} Node;
int main()
{
    Node *head = NULL;
    head = (Node *)malloc(sizeof(Node));
    head->data = 45;
    head->link = NULL;

    add_at_end(head, 98);
    add_at_end(head, 3);
    add_at_end(head, 67);

    printData(head);

    return 0;
}
void add_at_end(Node *head, int data)
{
    Node *ptr, *temp;
    ptr = head;
    temp = malloc(sizeof(Node));
    temp->data = data;
    temp->link = NULL;

    while(ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
}
void printData(Node *head)
{
    if(head == NULL)
        printf("The Linked List is empty\n");
    while(head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->link;
    }
    printf("NULL");

}
