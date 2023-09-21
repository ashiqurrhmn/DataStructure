#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* link;
}Node;
Node *createNode(Node* head, int data)
{
    if(head  == NULL)
    {
        Node *temp = malloc(sizeof(Node));
        temp->data = data;
        temp->link = NULL;

        return temp;
    }
    else
    {
        printf("Linked list is empty....");
    }
}
void print(Node *head)
{
    Node *ptr = head;
    while(ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}
void insertAtEnd(Node* temp, int data)
{
    Node *lastNode = (Node*)malloc(sizeof(Node));
    lastNode->data = data;
    lastNode->link = NULL;

    while(temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = lastNode;
}
Node* insertAtBegin(Node* head, int data)
{
    Node *temp = malloc(sizeof(Node));
    temp->data = data;
    temp->link = NULL;
    temp->link = head;

    head = temp;

    return head;
}
void addAtPos(Node* head, int data, int pos)
{
    Node *ptr = malloc(sizeof(Node));
    ptr->data = data;
    ptr->link = NULL;

    Node *temp = head;\
    pos--;
    while(pos != 1)
    {
        temp = temp->link;
        pos--;
    }
    ptr->link = temp->link;
    temp->link = ptr;
}
Node* reverse(Node* head)
{
    Node* prev = NULL;
    Node* next = NULL;
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
    Node *head = NULL;
    head = createNode(head, 44);
    insertAtEnd(head, 44);
    insertAtEnd(head, 55);
    insertAtEnd(head, 4);
    head = insertAtBegin(head, 10);
    head = insertAtBegin(head, 110);
    print(head);
    //head = reverse(head);
   // printf("After reverse : ");
   // print(head);

   printf("After adding at position 3: ");
   addAtPos(head, 500, 3);
   print(head);

   printf("After adding at position 6: ");
   addAtPos(head, 5500, 6);
   print(head);

    return 0;
}
