#include <stdio.h>
#include <stdlib.h>

/**
 * Node - structure of a node in the linked list
 */
typedef struct Node
{
    int value;
    struct Node *next;
    struct Node *previous;
}Node;



/**
 * print_list - prints the elements of the linked list
 * @head: head of the linked list
 */
void print_list(struct Node *head) {
    Node *ptr = head;
    while(ptr != NULL) {
        printf("%d ", ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}

/**
 * free_list - frees the memory of the linked list
 * @head: head of the linked list
 */
void free_list(struct Node *head)
{
    Node *tmp;
    while (head != NULL)
    {
        tmp = head->next; // Store the next struct Node before freeing
        free(head);       // Free the current struct Node
        head = tmp;       // Move to the next struct Node
    }
}


/**
 * delete_node - deletes a node from the linked list
 * @head: a pointer to the head
 * @position: the position to the node to remove
 */
void delete_node(Node **head, int position) {
    // if the head is null print error message and return
    if(*head == NULL || position < 1) {
        printf("List is null\n");
        exit(1);
        return;
    }
    Node *tmp = *head;

    if(position == 1) {
        // create a tmp pointing to the beginning
        // let the head point to the 2nd node
        *head = tmp->next;
        tmp->next = NULL;
        tmp->previous = NULL;
        // free the 1st node
        free(tmp);
        return;
    }
    
    for(int i = 1; tmp != NULL && i < position-1; i++) {
        tmp = tmp->next;
    }

    if(tmp == NULL || tmp->next == NULL) {
        printf("Position is out of range\n");
        return;
    }

    Node *node_to_delete = tmp->next;
    Node *node_after_node_to_delete = node_to_delete->next;
    if(node_after_node_to_delete != NULL)
    {
        node_after_node_to_delete->previous = tmp;
    }
    tmp->next = node_to_delete->next;
    node_to_delete->next = NULL;
    node_to_delete->previous = NULL;
    free(node_to_delete);
    return;
}


/**
 * prepend - adds a new node at the beginning of the linked list
 * @head: pointer to the head of the linked list
 */
void prepend(Node **head, int value) {
    Node *ptr = malloc(sizeof(Node));
    if(ptr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    ptr->value = value;
    ptr->previous = NULL;
    ptr->next = *head;
    *head = ptr;
}


/**
 * insert_node - deletes a node from the linked list
 * @head: a pointer to the head
 * @position: the position to add the new node
 * @value: the value of the node to add
 */
void insert_node(Node **head, int position, int value) {
    // Check if the list is empty or the position is invalid
    if(*head == NULL || position < 1) {
        printf("List is null\n");
        exit(1); // Exit if the list is null or position is less than 1
        return;
    }

    // Allocate memory for the new node and handle memory allocation failure
    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL) {
        printf("Memory allocation failed\n");
        free_list(*head); // Free the list if memory allocation fails
        exit(1); // Exit due to critical memory allocation error
    }

    // Initialize the new node with the given value and null pointers
    new_node->value = value;
    new_node->next = NULL;
    new_node->previous = NULL;

    // Temporary pointer to traverse the list
    Node *tmp = *head;

    // Special case: Insert at the head of the list
    if(position == 1) {
        // Make the new node point to the current head
        new_node->next = *head;
        (*head)->previous = new_node;
        // Update the head to point to the new node
        *head = new_node;
        return; // Exit after inserting at the head
    }

    // Traverse the list to find the node at position - 1
    for(int i = 1; tmp != NULL && i < position - 1; i++) {
        tmp = tmp->next; // Move to the next node
    }

    // Check if the position is out of range
    if(tmp == NULL) {
        printf("Position is out of range\n");
        return; // Exit if position is invalid
    }

    // Save the current node at the target position (if exists)
    Node *temp = tmp->next;


    // Update pointers to insert the new node
    new_node->previous = tmp; // New node's previous points to the node at position - 1
    new_node->next = temp;    // New node's next points to the node at the target position
    tmp->next = new_node;     // Node at position - 1 points forward to the new node

    // Update the previous pointer of the node at the target position (if it exists)
    if(temp != NULL) {
        temp->previous = new_node;
    }


    return; // Exit after successfully inserting the node
}

/**
 * append - adds a new node at the end of the linked list
 * @head: pointer to the head of the linked list
 * @value: the value of the node to add
 */
void append(struct Node **head, int value) {
    Node *ptr = malloc(sizeof(struct Node));
    if(ptr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    ptr->value = value;
    ptr->previous = NULL;
    ptr->next = NULL;

    if(*head == NULL) {
        *head = ptr;
        return;
    }
    Node *tmp = *head;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = ptr;
    ptr->previous = tmp;
}