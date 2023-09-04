#include<stdio.h>
#include<stdlib.h>
struct node* add_at_end(struct node *ptr, int data);
struct node
{
    int data;
    struct node *link;
};
int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *second = malloc(sizeof(struct node));
    second->data = 5;
    second->link = NULL;

    head->link = second;

    struct node *ptr = second;
    ptr = add_at_end(ptr, 78);
    ptr = add_at_end(ptr, 798);

    ptr = head;
    while(ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL");


    return 0;
}
struct node* add_at_end(struct node *ptr, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    ptr->link = temp;
    return temp;
}
