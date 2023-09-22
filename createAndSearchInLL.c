#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
int data;
struct Node *next;
}Node;

int searchInLL(struct Node *head, int value)
{
    int index = 1;
    while(head != NULL)
    {
        if(head->data == value)
        {
            return index;
        }
        index++;
        head = head->next;
    }
    return -1;
}
Node *create(Node* head, int data)
{
    Node *temp = malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;

    return temp;
}
void insertEnd(Node* temp, int data)
{
    Node* ptr = malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = NULL;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
}

void print(Node* head)
{
    Node *ptr = head;
    while(ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
int main()
{
    Node *head = NULL;
    head = create(head, 44);
    insertEnd(head, 444);
    insertEnd(head, 4444);

    print(head);

    printf("Searching index : %d\n", searchInLL(head, 4));
    printf("Searching index : %d", searchInLL(head, 444));

    return 0;
}
