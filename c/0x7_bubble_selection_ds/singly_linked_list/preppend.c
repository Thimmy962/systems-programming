/**
 * Preppending to a singly linked list implementation in C.
 */
#include "singly_func.c"

int main()
{
    Node *head = NULL;
    preppend(&head, 20);
    preppend(&head, 10);
    preppend(&head, 30);
    preppend(&head, 40);
    preppend(&head, 50);

    print_list(head);
    free_list(head);
}
