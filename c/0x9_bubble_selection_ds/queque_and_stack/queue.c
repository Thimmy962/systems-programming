/**
 * functions to implement queque using linked list
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

int used = 0;

/**
 * isEmpty - checks if the queque is empty
 */
int isEmpty() { if(front == NULL || rear == NULL) {
        return 1;
    }
    return 0;
}

/**
 * enqueque - adds a node to the queque
 * @data: the data of the new node to be added
 */
void enqueque(int data) {
    Node *new_node = malloc(sizeof(Node));

    if(new_node == NULL) {
        printf("Error in allocating memory\n");
        return;
    }
    new_node->data = data;
    new_node->next = NULL;

    if(isEmpty() == 1) {
        front = new_node;
        rear = new_node;
        used = 1;
        return;
    }

    rear->next = new_node;
    rear = new_node;
}

/**
 * display - display all the data in this queque
 */
void display() {
    if(isEmpty() == 1) {
        printf("Queque is empty\n");
        return;
    }
    Node *tmp = front;
    while(tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}


/**
 * dequeque - removes a node from the front of a queque
 */
void dequeue() {
    if(isEmpty() == 1) {
        printf("Queue is empty\n");
        return ;
    }

    Node *tmp = front;
    front = front->next;
    tmp->next = NULL;
    free(tmp);
}


/**
 * free_queque - free all the nodes in a queque
 */

void free_queue() {
    while(front != NULL) {
        dequeue();
    }
}


int see_front(int *val) {
    if(used == 0) {
        return 1;
    }
    Node *tmp = front;
    *val = tmp->data;
    return 0;
}
