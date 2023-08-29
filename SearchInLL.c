#include<stdio.h>
#include<stdlib.h>
struct Node *createLinkedList(int ar[], int size);
struct Node{
int data;
struct Node *next;
};
int main()
{
    int a[] = {23, 33, 43, 56, 78, 90, 54, 6, 87, 56};
    struct Node *head = NULL;
    head = createLinkedList(a, 10);
    printf("Index: %d\n", searchInLL(head, 56));
    return 0;
}
struct Node * createLinkedList(int ar[], int size)
{
    struct Node *head = NULL, *temp = NULL, *current = NULL;
    int i;
    for(i=0; i<size; i++)
    {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = ar[i];
        temp->next = NULL;
        if(head == NULL)
        {
            head = temp;
            current = temp;
        }
        else
        {
            current->next = temp;
            current = current -> next;
        }
    }
    return head;
}
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

