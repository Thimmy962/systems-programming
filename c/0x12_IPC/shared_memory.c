#include <sys/mman.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

char *name = "memory";
int main()
{
    int sh = shm_open(name, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if(sh == -1) {
       perror("Shared memory open error");
       exit(EXIT_FAILURE);
    }

    int pid = fork();
    if(pid == -1) {
        perror("Fork error");
    }

}
