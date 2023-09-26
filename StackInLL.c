#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node *top=NULL;

void push(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if(temp == NULL) {
        printf("Stack is full!!");
    }
    temp->data = data;
    temp->next = top;
    top = temp;
    printf("push is called ");
}

void pop() {
    if(top == NULL) {
        printf("Stack is Empty! Can't pop");
        return;
    }
    Node* temp = top;
    top = top->next;
    free(temp);
    printf("pop is called ");
}

int peek(){
    if(top != NULL) {
        return top->data;
    }else {
        return INT_MIN;
    }

}

void display(){
    Node * temp = top;
    printf("Stack:");

    while(temp !=NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void displayRev(Node* p) {
    if(p == NULL) {
        printf("Reverse: ");
        return;
    }
    displayRev(p->next);
    printf("%d ",p->data);
}

int main() {
    push(4);
    display();
    push(5);
    display();
    pop();
    display();
    push(7);
    display();
    displayRev(top);
    printf("\n");

    printf("Top = %d\n",peek());

}