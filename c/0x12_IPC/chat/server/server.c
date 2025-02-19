#include "sfunc.c"


int main() {
    signal(SIGTERM, handler);
    signal(SIGINT, handler);
    if (daemonize() < 0){
        syslog(LOG_ERR, "Server daemon could not start");
        close_mylog();
        exit(1);
    }
    /**
    uid_t id = getuid();
     * This is how to get host name 

    // Get the username
    struct passwd *pw = getpwuid(id);
    if (pw == NULL) {
        syslog(LOG_ERR, "Could not get hostname");
        close_mylog();
        exit(1);
    }
    */
    struct mq_attr attr = {
        .mq_flags = 0,
        .mq_maxmsg = 10,
        .mq_msgsize = 1024,
        .mq_curmsgs = 0
    };

    // Open the message queue for creating and writing
    mq_main = mq_open(mqname, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR, &attr);
    if (mq_main < 0) {
        syslog(LOG_ERR, "Could not create message queue");
        close_mylog();
        exit(1);
    }

    // Open the message queue for reading only (inside the loop)
    mqd_t receive_mq = mq_open(mqname, O_RDONLY);
    if (receive_mq == (mqd_t)-1) {
        char *err = strerror(errno);
        syslog(LOG_ERR, "%s", err); // log error to system log
        mq_close(receive_mq); // Close the write-mode mq
        mq_unlink(mqname); // Unlink the message queue
        close_mylog(); // Close syslog
        exit(1);
    }
    while(true) {
        if(receive_message(receive_mq) == -1) {
            syslog(LOG_ERR, "Server could not receive message");
            mq_close(receive_mq); // Close the read-only mq
        }

        // Close the read-only message queue descriptor
        mq_close(receive_mq);
    }

    // Close the write-mode message queue descriptor
    mq_close(mq_main);
    mq_unlink(mqname);
    close_mylog();

    return 0;
}
