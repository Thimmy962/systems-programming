#include <stdio.h>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

char *mqn = "/mqn";
char *message = "Hello to you, my name is Dada Oluwatimileyin Olayemi";

int send_message(mqd_t mq) {
    struct mq_attr attr;
    if (mq_getattr(mq, &attr) == -1) {
        perror("Error getting attributes");
        return -1;
    }

   if (mq_send(mq, message, strlen(message) + 1, 0) == -1) {
        perror("MQ sender error");
        return -1;
    }
    return 0;
}

int receive_message(mqd_t mq) {
    struct mq_attr attr;

    if (mq_getattr(mq, &attr) == -1) {
        perror("Error getting attributes");
        return -1;
    }

    char *buff = malloc(attr.mq_msgsize);
    if (buff == NULL) {
        perror("Malloc error");
        return -1;
    }

    unsigned int priority;
    ssize_t received = mq_receive(mq, buff, attr.mq_msgsize, &priority);
    if (received == -1) {
        perror("MQ receiver error");
        free(buff);
        return -1;
    }

    printf("Received: %s\n", buff);
    free(buff);
    return 0;
}

int main() {
    struct mq_attr attr = {
        .mq_flags = 0,
        .mq_maxmsg = 10,
        .mq_msgsize = 256,
        .mq_curmsgs = 0
    };

    mqd_t mq = mq_open(mqn, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR, &attr);
    if (mq == (mqd_t)-1) {
        perror("Error creating message queue");
        exit(EXIT_FAILURE);
    }

    int pid = fork();
    if (pid == -1) {
        perror("Fork error");
        mq_close(mq);
        mq_unlink(mqn);
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        mqd_t child_mq = mq_open(mqn, O_RDONLY);
        if (child_mq == (mqd_t)-1) {
            perror("Child failed to open queue");
            exit(EXIT_FAILURE);
        }

        if (receive_message(child_mq) == -1) {
                mq_close(child_mq);
                mq_unlink(mqn);
                exit(EXIT_FAILURE);
            }

            mq_close(child_mq);
    } else {
        if (send_message(mq) == -1) {
            mq_close(mq);
            mq_unlink(mqn);
            exit(EXIT_FAILURE);
        }

        wait(NULL); // Wait for child process to finish
    }

    mq_close(mq);
    mq_unlink(mqn); // Cleanup message queue
    return 0;
}