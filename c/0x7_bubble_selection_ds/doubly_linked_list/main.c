#include "doubly_func.c"


/**
 * main - entry point of the program
 * description: This function is the entry point of the program.
 */
int main() {
    Node *head = NULL;
    prepend(&head, 1);
    prepend(&head, 2);
    prepend(&head, 3);
    prepend(&head, 4);

    print_list(head);

    insert_node(&head, 5, 20);

    print_list(head);
    // Node *new = head->next;
    // printf("%d\n", new->value);
    // Node *new2 = new->next;
    // printf("%d\n", new2->value);
    // Node *new3 = new2->previous;

    // printf("%d\n", new3->value);

    free_list(head);
}