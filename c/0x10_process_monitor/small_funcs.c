#include "main.h"

/**
 * info - initializes the TOTAL_MEMORY variable
*/
void info() {
    struct sysinfo info;
    if(sysinfo(&info) == 0) {
        TOTAL_MEMORY = info.totalram / 1024;
    }
}

/**
 * monitor - monitors the events
 * return: void
*/
void monitor() {
    char buffer[BUF_LEN];
    while (1) {
        int rd = read(FD, buffer, BUF_LEN);
        if (rd <= 0) {
            perror("Could not monitor the processes");
            exit(rd == -1 ? 1 : 2);
        }

        char *ptr;
        for (ptr = buffer; ptr < buffer + rd; ) {
            struct inotify_event *event = (struct inotify_event *) ptr;

            // Print event name is numeric or name is == status
            if (event->len > 0 && is_numeric(event->name)) {
                printf("Name: %s\tMask: %d\n", event->name, event->mask);
            }

            // Move pointer to the next event
            ptr += sizeof(struct inotify_event) + event->len;
        }
    }
}
