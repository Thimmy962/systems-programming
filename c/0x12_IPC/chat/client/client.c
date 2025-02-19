#include "cfunc.c"

int main()
{
    signal(SIGINT, handler);
    signal(SIGTERM, handler);
    struct mq_attr attr;

    pid_t pid = fork();
    if (pid < 0)
    {
        perror("Error");
        exit(1);
    }

    if (pid == 0)
    {
        mqd_t client_mq = mq_open(mqname, O_WRONLY); // open in write mode
        if (client_mq < 0)
        {
            perror("Error");
            mq_close(client_mq);
            exit(1);
        }
        mq_getattr(client_mq, &attr);
        char *msg = malloc(attr.mq_msgsize);
        if (msg == NULL)
        {
            exit(1);
        }
        while (1)
        {
            scanf("%s", msg);
            send_message(client_mq, msg);
        }
        free(msg);
    } else
    {
        mqd_t client_mq = mq_open(mqname, O_RDONLY); // open in read mode
        if (client_mq < 0)
        {
            perror("Error");
            mq_close(client_mq);
            exit(1);
        }
        mq_getattr(client_mq, &attr);
        char *msg = malloc(attr.mq_msgsize);
        if (msg == NULL)
        {
            exit(1);
        }
        while (1)
        {
            receive_message(client_mq, msg, attr.mq_msgsize);
            printf("%s\n", msg);
        }
        free(msg);
    }

    mq_close(client_mq);
    exit(0);
}
