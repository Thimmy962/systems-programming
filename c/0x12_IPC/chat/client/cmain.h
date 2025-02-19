#ifndef CMAIN_H

#define CMAIN_H


#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <mqueue.h>
#include <signal.h>
#include <unistd.h>


char *mqname = "/chat";
mqd_t client_mq;


#endif
