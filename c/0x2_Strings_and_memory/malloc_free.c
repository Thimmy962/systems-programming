/**
 * implements and test fmalloc and free functions
 */

#include <stdio.h>
#include <stdbool.h>

#define MEMORY_SIZE 32000
#define BLOCK_SIZE 32

char MEMORY_CHUNK[BLOCK_SIZE * MEMORY_SIZE] = {0};

typedef struct memory{
    bool free;
    struct memory *next;
}memory;

memory *memory_head = (memory *)MEMORY_CHUNK;


bool call_malloc = true;
void initialize()
{
    printf("Initializing memory\n");
    
    for(int i = 0; i < MEMORY_SIZE; i++)
    {
        if(i == MEMORY_SIZE - 1)
        {
            memory_head[i].next = NULL;
        }
        memory_head[i].free = true;
        memory_head[i].next = (memory*)((char*)memory_head + (i + 1) * BLOCK_SIZE);
    }
}

/**
 * breaks the memory into a fixed size of 64 bytes
 */
void *fmalloc() {
    // if this is the first call to fmalloc, initialize the memory
    if(call_malloc != false){
        printf("Hello from fmalloc function: %d\n", call_malloc);
        initialize();
        call_malloc++;
    }
    if (memory_head == NULL) {
        return (NULL);
    }
    memory *current = memory_head; // Take the current head as allocated block
    memory_head = memory_head->next; // Move head to the next free block
    current->free = false;
    current->next = NULL; // Disconnect the allocated block from the free list
    return (void*)current;
}

void ffree(void *ptr) {
    // if the pointer is not valid, return
    // how do i dtermine if the pointer is valid or not?
    // check if the pointer is within the memory chunk and within the memory size
    if((char *)ptr < MEMORY_CHUNK || (char *)ptr >= (char*)memory_head + (BLOCK_SIZE * MEMORY_SIZE)){
        printf("Invalid pointer\n");
    }

    if (ptr == NULL) return; // Check for NULL pointer

    memory *block = (memory*)ptr;
    block->free = true;
    block->next = memory_head; // Insert block at the beginning of the free list
    memory_head = block; // Update the head to this newly freed block
}
#include <stdlib.h>

int main() {

    int *intt = fmalloc();
    *intt = 10;

    int *intt2 = fmalloc();
    *intt2 = 20;

    int *intt3 = malloc(4);
    *intt3 = 30;

    printf("%d\n", *intt);
    printf("%d\n", *intt2);
    printf("%d\n", *intt2);
    printf("Address of intt: %p\n", intt);
    printf("Address of intt2: %p\n", intt2);
    printf("Address of intt2: %p\n", intt2);

    ffree(intt);
    ffree(intt2);
    free(intt3);

    *intt3 = 40;
    printf("%d\n", *intt);
}