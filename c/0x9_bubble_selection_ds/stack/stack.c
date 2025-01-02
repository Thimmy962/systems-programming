/**
 * functions to implement stack using linked list
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}Node;

struct node *top = NULL;

void push(int data) {
    Node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = top;
    top = new_node;
}

int isEmpty() {
    if(isEmpty() == 1) {
        return 1;
    }
    return 0;
}

int pop() {
    if(isEmpty() == 1) {
        printf("Stack is empty\n");
        return -1;
    }
    int data = top->data;
    Node *tmp = top;
    top = top->next;
    free(tmp);
    return data;
}

int peek() {
    if(isEmpty() == 1) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

void display() {
    if(isEmpty() == 1) {
        printf("Stack is empty\n");
        return;
    }
    Node *tmp = top;
    while(tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

/**
 * free_stack - free all the nodes in a queque
 */

void free_stack() {
    while(top != NULL) {
        pop();
    }
}