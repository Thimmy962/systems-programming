#include "queue.c"
// #include "stack.c"


/**
 * Main function
 * To test the stack implementation
 */
int main() {
    int ar;
    if(see_front(&ar)== 1)
       printf("Queue is empty\n");
    else
        printf("%d\n", ar);
    enqueque(5);
    enqueque(3);
    enqueque(8);
    enqueque(2);
    enqueque(1);
    

    display();
    free_queue();
    display();
}
