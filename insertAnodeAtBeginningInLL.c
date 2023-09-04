#include<stdio.h>
#include<stdlib.h>
struct node* add_beg(struct node* head, int data);
struct node
{
    int data;
    struct node *link;
};
int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->data = 5;
    head->link = NULL;

    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = 10;
    ptr->link = NULL;

    head->link = ptr;

    head = add_beg(head, 3);

    head = add_beg(head, 39);

    struct node* temp;
    temp = head;
    while(temp!=NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL");

    return 0;
}
struct node* add_beg(struct node* head, int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    temp->link = head;
    head = temp;
    return head;
}
