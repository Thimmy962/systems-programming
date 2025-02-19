#include <sys/mman.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

char *name = "MMemory";
int main(int argc, char *argv[])
{
    int sh = shm_open(name, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (sh == -1)
    {
        perror("Shared memory open error");
        exit(EXIT_FAILURE);
    }

    // Define the size of the shared memory
    const char *message = "Dada Oluwatimilyin";
    size_t size = strlen(message) + 1;

    if (ftruncate(sh, size) == -1 ) {
        perror("Shared memory truncate error");
        shm_unlink(name);
        exit(EXIT_FAILURE);
    }

    char *address = mmap(NULL, 64, PROT_READ | PROT_WRITE, MAP_SHARED, sh, 0);
    if (address == MAP_FAILED)
    {
        perror("Memory map failed");
        exit(EXIT_FAILURE);
    }
    int pid = fork();
    if (pid == -1) {
        perror("Fork error");
        munmap(address, size);
        shm_unlink(name);
    }

    if (pid == 0) {
        printf("%s\n", address);

        munmap(address, size);
        shm_unlink(name);
    }
    else{
        strcpy(address, message);
        wait(NULL);

        munmap(address, size);
        shm_unlink(name);
    }
    close(sh);
    return(0);
}
