#include "cmain.h"

/**
 * send_message - handles sendong of message to the mq
 * @mq: the fd of the opened mq in write mode
 * @message: the message to be sent
 * return: -1 for error and 0 for success
 */
int send_message(mqd_t mq, char *message) {
    return mq_send(mq, message, strlen(message), 0);
}


/**
 * receive_message - handles receiving of message from the mq
 * @mq: the fd of the opened mq in read mode
 * @message: address to save the read message
 * @len: msgsize attribute of the opened mq
 * return: -1 for error and 0 for success
 */
int receive_message(mqd_t mq, char *message, long int len) {
    int priority = 0;
    return mq_receive(mq, message, len, &priority);
}

/**
 * handler - handles signals from the kernel
 */
void handler(int num) {
    mq_close(client_mq);
    mq_unlink(mqname);
    exit(0);
}
