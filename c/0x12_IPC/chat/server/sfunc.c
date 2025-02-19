#include "main.h"



/**
 * log - logs to log file
 * @str: what is to be logged
*/

void log(char *str) {
    timeinfo = local(&rawtime);
    strftime(buffer, strlen(buffer), "%A, %H:%M:%S, %d-%m-%y%", timeinfo);

    char buf[64];
    snprintf(buf, "%s: %s\n", buf, str);
    write(file_descriptor, buf, sizeof(buf));
}


/**
 * daemonize - turns a program into a daemon
 * return: an int -1 for any form of error and 0 for successful
 */
int daemonize()
{
    // Initialize syslog
    openlog(logname, LOG_PID, LOG_DAEMON);

    umask(0);
    char *log_file = "/var/log/server.log"; 
    int file_fd = open(log_file, O_CREAT|O_APPEND, 0666);
    if(file_fd > 0) {
        printf("Log opened: %s\n", log_file);
    } else {
        printf("Failed to open\n");
        exit(0);
    }
    switch (fork()) {
    case -1:
        return -1;
    case 0:
        break;
    default:
        exit(0);
    }

    // Create a new session and set the child as the leader
    if (setsid() < 0) {
        perror("setsid");
        return -1;
    }

    // Change the working directory to the root directory
    if (chdir("/") < 0) {
        perror("chdir");
        return -1;
    }

    close(STDIN_FILENO);
    close(STDIN_FILENO);
    close(STDIN_FILENO);

    // Optionally, reopen stdin, stdout, and stderr to /dev/null
    int fd = open("/dev/null", O_RDWR);
    if (fd != STDIN_FILENO) {
        return -1;
    }
    if (dup2(fd, STDOUT_FILENO) != STDOUT_FILENO) {
        return -1;
    }
    if (dup2(fd, STDERR_FILENO) != STDERR_FILENO) {
        close(file_fd);
        return -1;
    }

    return file_fd;
}

/**
 * close_mylog - logs before closing the syslog
 *  return: void
 */
void close_mylog(int fd)
{
    char *closing_remark = "Closing server\n";
    write(fd, closing_remark, strlen(closing_remark));
    close(fd);

}

/**
 * receive_message - receives message throught the message queue
 * @mq: the fd of the opened mq
 * return: returns an int -1 for error, 0 for success
 */
int receive_message(mqd_t receive_mq)
{
    struct mq_attr attr;
    int att = mq_getattr(receive_mq, &attr);

    if (att == -1) {
        syslog(LOG_ERR, "Error getting attributes of message queue");
        return -1;
    }
    ssize_t len = attr.mq_msgsize;
    int priority = 0;
    char buffer[len];
    sleep(300);
    len = mq_receive(receive_mq, buffer, len, &priority);
    return (0);
}

void handler(int num) {
    mq_close(mq_main);
    close_mylog();
    mq_unlink(mqname);
    exit(0);
}



