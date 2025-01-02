#include <stdio.h>
#include <sys/mman.h>

/**
 * get_string - uses mmap to allocate memory
 * @prompt: request for that determines what the user inouts
 * return: an address to the allocated memory
 */
char *get_string(char *prompt) {
    /**
     * mmap requsts for memory same as malloc
     * you dont need to call free when you are done
    */ 
    char *input = mmap(NULL, 100, PROT_WRITE | PROT_READ, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    printf("%s", prompt);
    fgets(input, 100, stdin);
    return input;
}

/**
 * mallocp - a function that mimicks malloc but does not need to be freed
 * @size: the size of memory needed in bytes
 * return: void pointer
 */
void *mallocp(int size) {
    void *add = mmap(NULL, size, PROT_WRITE | PROT_READ, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if(add != NULL) {
        return add;
    }
    return NULL;
}

int main() {
    /**
     * @NULL: the address of the location you want the memory to be allocated to, can be null
     * @4: the size of the memory needed
     * @PROT: the protection involved e.g PROT_READ, PROT_WRITE, PROT_EXEC
     */
    int *age = mallocp(4);
    printf("Enter your age: ");
    scanf("%d", age);
    printf("Memory: %p holds the value: %d with size of: %ld\n", age, *age, sizeof(*age));
}