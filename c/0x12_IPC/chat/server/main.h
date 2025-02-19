#ifndef MAIN_H

#define MAIN_H


#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <syslog.h>
#include <mqueue.h>
#include <sys/types.h>
#include <pwd.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <pwd.h>
#include <time.h>

time_t rawtime;
struct tm *timeinfo;
char buffer[32];

 // Get current time
time(&rawtime);

#define MAXMSG 20
#define MSG


int true = 1;
int false = 0;
int file_descriptor; // file descriptor for the log file used through the server program
char *mqname = "/chat"; // the name of the message queue


mqd_t mq_main; // fiel descriptor of the message queue
/**
 * logname - the name given to syslog to log from this program
 */
char *logname = "server";


#endif
