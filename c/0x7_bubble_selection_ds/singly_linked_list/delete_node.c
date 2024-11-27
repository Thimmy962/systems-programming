/**
 * Delete a node from a linked list
 * Node zero positioned
 */

#include "singly_func.c"


int main()
{
    struct Node *head = NULL;
    preppend(&head, 20);
    preppend(&head, 10);
    preppend(&head, 30);
    preppend(&head, 40);
    preppend(&head, 50);

    print_list(head);
    int remove = get_int("Position to remove: ");
    delete_node(&head, remove);

    print_list(head);
    free_list(head);
}
