/**
 * used to get attributes of a message queue
 * */

#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

const char *MSG_NAME = "/mq";

int main() {
    struct mq_attr attri;

    mqd_t mq = mq_open(MSG_NAME, O_RDONLY);
    if(mq == -1) {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    if(mq_getattr(mq, &attri) == -1) {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    printf("Maximum Message: %ld\n", attri.mq_maxmsg);
    printf("Message size: %ld\n", attri.mq_msgsize);
    printf("# Number of messages: %ld\n", attri.mq_curmsgs);


    exit(EXIT_SUCCESS);
}
