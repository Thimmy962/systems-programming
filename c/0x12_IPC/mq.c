#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

const char *MSG_NAME = "/mq";

typedef struct
{
    char msg[1024];
} message;

int main()
{
    struct mq_attr attr = {
        attr.mq_maxmsg = 50,
        attr.mq_msgsize = 2048,
        attr.mq_flags = O_NONBLOCK
    };

    mqd_t mq = mq_open(MSG_NAME, O_CREAT | O_RDWR, S_IWUSR | S_IRUSR | S_IXUSR, &attr);
    if (mq == -1)
    {
        perror("Error");
    }
    exit(EXIT_SUCCESS);
}
