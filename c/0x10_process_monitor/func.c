#include "main.h"


const char *dict_keys[] = {
    	"Name", "Pid", "PPid", "State", "VmRSS"
};

int keylen = 5, column_width = 10, namlen = 16;


/**
 * is_numeric - check if the string passed to it is digits alone
 * @str: the string to check
 * returnL: 1 for true 0 for false
 */
int is_numeric(const char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return 0; // Not numeric
        }
        str++;
    }
    return 1; // Numeric
}

/**
 * print_op - prints the values  of the processes to screen
 * @pid: the pid of the process to manipulate
 * return: void 
 */
void print_op(char *pid) {
    char path[32];

    // concatenate the pid to proc to form the path of each folder
    snprintf(path, sizeof(path), "/proc/%s/", pid);

    DIR *dir = opendir(path);

    if(dir == NULL) {
        perror("Could not open folder");
        exit(2);
    }
    
    search_status_file(dir, path, pid);
    closedir(dir);
}


/**
 * search_status_file - search for the status file in the opened directory
 * @dir: pointer to the opened directory
 * @path: the path to the opened directory that will be concatenated with status to form the path for the status file of each folder
 * @oid: the pid of this particular process
 */
void search_status_file(DIR *dir, char *path, char *pid) {
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // if the name of the current file is "status"
        if (strcmp(entry->d_name, "status") == 0) {
            char full_path[526];

            snprintf(full_path, sizeof(full_path), "%s%s", path, entry->d_name);
            
            // add this file to watch list
            WD =  inotify_add_watch(FD, full_path, IN_ALL_EVENTS);
            if(WD < 0) {
                printf("Could not add process with pid: %s to watch list\n", pid);
            }

            // Open the file relative to its current dir in read mode
            FILE *file = fopen(full_path, "r");

            // Check if file was opened successfully
            if (file != NULL) {
                extract_values_from_key(file, pid);
                fclose(file);
            } 
        }
    }
}

/**
 * extract_values_from_key - extract the value from key in the file 
 * @file: pointer to the opened file to extract data from
 * return: an array of extracted data
 */
void extract_values_from_key(FILE *file, char *pid) {
    char line[256];
    char values[keylen][256]; // Array to store values for each key

    // Read the content of the file line by line
    while (fgets(line, sizeof(line), file)) {
        for (int i = 0; i < keylen; i++) {
            // Match the line strictly with the current key
            /**
             * if strlen(dict_key[i]) = 5, strncmp cpmpares the first 5 letters of line and dict_key[i]
             * this way enforces strict comparism. Well this useful here not strstr because strstr looks for a substring in a bigger string
             * this will cause conflict as searching for Pid will return Pid and PPid, as Pid can be found in PPid
            */
            if (strncmp(line, dict_keys[i], strlen(dict_keys[i])) == 0) {
                char *value = tokenized_value(line);
                // copy the value into the array
                strncpy(values[i], value, sizeof(values[i]) - 1); // Store value
                break;
            }
        }
    }
    for (int i = 0; i < keylen; i++) {
        if(strcmp(dict_keys[i], "Name") == 0) {
            printf("%-*s", namlen, values[i]);
            continue;
        }
        if(strcmp(dict_keys[i], "VmRSS") == 0) {
            /**
             * convert the value ofVmRSS to an int
             * divide this value by the total memory
             * multiple by 100 to get the percentage of memory used by this process
             */
            float percentage_mem = (atof(values[i])/TOTAL_MEMORY) * 100;
            printf("%-*.1f", column_width, percentage_mem);
            continue;

        }
        printf("%-*s", column_width, values[i]);
    }
}



char *tokenized_value(char *str) {
    char *token = strtok(str, ":\t"); // Skip the key
    token = strtok(NULL, " \t\n");   // Get the value and strip \n
    return token;
}
