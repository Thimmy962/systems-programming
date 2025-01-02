#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// PB = program break

int main() {
    void *first = sbrk(0); // move the PB by 0 bytes i.e where the PB is currently
    void *second = sbrk(20); // move the PB by 20 and return the address of where it was before
    void *third = sbrk(21);

    printf("PB Address: %p\n", first);
    printf("PB Address: %p\n", second);
    printf("PB Address: %p\n", third);
}