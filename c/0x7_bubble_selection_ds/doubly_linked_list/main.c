#include "doubly_func.c"


/**
 * main - entry point of the program
 * description: This function is the entry point of the program.
 */
int main() {
    Node *head = NULL;
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);

    print_list(head);

    insert_node(&head, 6, 20);

    print_list(head);

    free_list(head);
}