#include<stdio.h>
#include<stdlib.h>
void push(int data);
struct node
{
    int data;
    struct node *link;
}*top=NULL;
int main()
{
    int data;
    push(4);
    push(46);
    push(34);
    struct node *temp;
    temp = top;
    while(temp!=NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL");

    return 0;
}
void push(int data)
{
    struct node *newNode;
    newNode = malloc(sizeof(newNode));
    if(newNode == NULL)
    {
        printf("Stack is overflow");
        exit(1);
    }
    newNode->data = data;
    newNode->link = NULL;

    newNode->link = top;
    top = newNode;
}

