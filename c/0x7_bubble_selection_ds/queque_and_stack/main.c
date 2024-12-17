#include "queque.c"
// #include "stack.c"


/**
 * Main function
 * To test the stack implementation
 */
int main() {
    enqueque(5);
    enqueque(3);
    enqueque(8);
    enqueque(2);
    enqueque(1);


    display();

    free_queque();

    // pop();
    // display();
    // int peeek = peek();
    // printf("The top element is: %d\n", peeek);
    // pop();
    // display();
    // pop(); 
    // display();
}