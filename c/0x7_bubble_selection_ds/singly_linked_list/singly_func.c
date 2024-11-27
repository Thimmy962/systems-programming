#include "func.c"

/**
 * Node - structure of a node in the linked list
 */
typedef struct Node
{
    int value;
    struct Node *next;
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
    tmp->next = node_to_delete->next;
    free(node_to_delete);
    return;
}


/**
 * preppend - adds a new node at the beginning of the linked list
 * @head: pointer to the head of the linked list
 */
void preppend(Node **head, int value) {
    Node *ptr = malloc(sizeof(Node));
    if(ptr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    ptr->value = value;
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
    // if the head is null print error message and return
    if(*head == NULL || position < 1) {
        printf("List is null\n");
        exit(1);
        return;
    }
    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL) {
        printf("Memory allocation failed\n");
        free_list(*head);
        exit(1);
    }
    new_node->value = value;
    new_node->next = NULL;


    Node *tmp = *head;

    if(position == 1) {
        // new node point to head and head points to new node 
        new_node->next = *head;
        *head = new_node;
        return;
    }
    
    for(int i = 1; tmp != NULL && i < position - 1; i++) {
        tmp = tmp->next;
    }

    if(tmp == NULL) {
        printf("Position is out of range\n");
        return;
    }

    new_node->next = tmp->next;
    tmp->next = new_node;
    return;
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
}