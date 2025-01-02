#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <sys/prctl.h>


const char *keywords[] = {
    "Name",
    "VmSize",
    "VmRss",
    "VmData",
    "VmStk",
    "VmExe",
    "VmLib",
    "Threads",
    "State"
};

void error(int);
void print_memory_layout(int);

int main(int argc, char *argv[]) {

    error(argc);
    char *args[10];
    int j = 0;

     // Copy command-line arguments
    for (int i = 1; i < argc; i++, j++) {
        args[j] = argv[i];
    }
    args[j] = NULL;

    int fd[2];
    if (pipe(fd) == -1) {
        perror("Pipe creation failed");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if(pid == -1) {
        perror("Process could not be created\n");
        exit(1);
    }
    if(pid == 0) {
        /**
         * send the pid of this process to the main process using a pipe
         * check the current dir first for the command
         * if found continue to the main process, else check the bin dir where all commands are stored
         * if not found exit else continue to main process
         */
        int child_process_pid = getpid();
        close(0);
        close(1);
        close(2);

        // Set the process name explicitly (if execv fails, we might still execute this code)
        prctl(PR_SET_NAME, args[0], 0, 0, 0);

        // close read end of the pipe
        close(fd[0]);
        int wr = write(fd[1], &child_process_pid, sizeof(int));


        if(wr == -1) {
            perror("Could not write to file");
            exit(EXIT_FAILURE);
        }

        close(fd[1]);

        int err = execv(args[0], args);

        if(err == -1){
            err = execvp(args[0], args);
            if(err == -1) {
                perror("Command not found");
                _Exit(EXIT_FAILURE);
            }
        }
    }

    // close write end of the pipe
    close(fd[1]);
    int child_process_pid;
    read(fd[0], &child_process_pid, sizeof(int));

    print_memory_layout(child_process_pid);

    close(fd[0]);
    return (0);
}

void error(int argc) {
    if(argc < 2) {
        char *err = "Arguments must be greater than 1\n";
        // write to standard error
        int wr = write(2, err, strlen(err));

        if(wr == -1) {
            perror("Could not write to file");
            exit(EXIT_FAILURE);
        }
    
        exit(EXIT_FAILURE);
    }
}

void print_memory_layout(int pid){
    char filepath[128];
    snprintf(filepath, sizeof(filepath), "/proc/%d/status", pid);
    FILE *file = fopen(filepath, "r");
    if(!file) {
        perror("Could not open file\n");
        exit(1);
    }
    char line[256];
	while(fgets(line, sizeof(line), file)) {
		for (int i = 0; i < 9; i++) {
            if (strstr(line, keywords[i]) != NULL) {
                printf("%s", line);
                break; // No need to check further once a match is found
            }
        }
	}
    fclose(file);   
}