#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} Node;

Node *create(int data, Node *head)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->link = head;
    head = temp;
    return head;
}

// Function to delete even-valued nodes from the linked list
Node *deleteEvenNodes(Node *head)
{
    Node *current = head;
    Node *prev = NULL;

    while (current != NULL)
    {
        if (current->data % 2 == 0)
        {
            Node *temp = current;

            // If the even node is the head, update the head
            if (current == head)
                head = head->link;
            else
                prev->link = current->link;

            current = current->link;
            free(temp);
        }
        else
        {
            prev = current;
            current = current->link;
        }
    }

    return head;
}

int main()
{
    Node *head = create(63, create(35, create(60, create(55, create(45, create(40, create(99, NULL)))))));
    head = create(30, head);

    printf("Original Linked List: ");
    Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->link;
    }

    // Delete even-valued nodes
    head = deleteEvenNodes(head);

    printf("\nLinked List after deleting even-valued nodes: ");
    current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->link;
    }

    return 0;
}
