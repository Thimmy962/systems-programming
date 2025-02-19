#include "queue.c"
// #include "stack.c"

/**
 * Main function
 * To test the stack implementation
 */
int main() {
    int ar;
    enqueque(3);
    enqueque(10);
    enqueque(5);
    enqueque(3);
    enqueque(8);
    enqueque(2);
    // dequeue(&ar);
    enqueque(1);
    // dequeue(&ar);
    // dequeue(&ar);
    // dequeue(&ar);


    peek();

    display();
    
    free_queue();

    display();
}
