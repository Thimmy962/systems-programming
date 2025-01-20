#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/inotify.h>
#include <sys/sysinfo.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_LEN (100 * sizeof(struct inotify_event))

int FD; // file descriptor for inotify_init
int WD;
int TOTAL_MEMORY;
struct inotity_event *event;


int is_numeric(const char *);
void print_op(char *);
void extract_values_from_key(FILE *, char *);
char *tokenized_value(char *);
void search_status_file(DIR *, char *, char *);
void monitor();

#endif
