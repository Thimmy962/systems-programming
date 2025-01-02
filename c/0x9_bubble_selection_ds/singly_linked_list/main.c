#include "singly_func.c"

int main()
{
    struct Node *head = NULL;
    append(&head, 20);
    append(&head, 10);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);

    print_list(head);
    free_list(head);
}
