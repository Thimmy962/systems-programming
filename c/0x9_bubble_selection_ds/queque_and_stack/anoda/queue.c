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
void dequeue_without_return() {
    if(isEmpty() == 1) {
        printf("Queue is empty\n");
        return ;
    }

    Node *tmp = front;
    front = front->next;
    tmp->next = NULL;
    free(tmp);
    printf("Dequed\n");
}


/**
 * free_queque - free all the nodes in a queque
 */

void free_queue() {
    while(front != NULL) {
        dequeue_without_return();
    }
}


int get_front(int *val) {
    if(used == 0) {
        return 1;
    }
    Node *tmp = front;
    *val = tmp->data;
    return 0;
}

void peek() {
    if(front == NULL) {
        printf("Queue is Empty\n");
        return;
    }
    Node *tmp = front;
    int data = tmp->data;
    printf("%d\n", data);
    return;
}

/**
 * dequeue - removes a node from the front of a queue and returns its value
 * @return: the data of the removed node or a special value if the queue is empty
 */
int dequeue(int *val) {
    if(front == NULL) {
        printf("Queue is empty\n");
        return 1; // Indicate failure due to empty queue
    }

    Node *tmp = front;
    *val = tmp->data; // Get the data from the front node
    front = front->next; // Move the front pointer to the next node

    if (front == NULL) { // If the queue is now empty, reset the rear pointer
        rear = NULL;
    }
    free(tmp); // Free the memory of the dequeued node
    printf("Dequed\n");
    return 0; // Indicate success
}
