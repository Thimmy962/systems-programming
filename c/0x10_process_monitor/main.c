#include "func.c"
#include "small_funcs.c"


const char *dict_keyss[] = {
    "Name", "Pid", "PPid", "State", "Memory(%)"
};

char *proc = "/proc"; // path to the proc folder

int main() {
   char  BUFFER[1024];
    FD = inotify_init();

    if(FD == -1) {
        perror("Could not start monitoring API");
        _Exit(EXIT_FAILURE);
    }

    inotify_add_watch(FD, proc, IN_ALL_EVENTS);

    /**
     * this function get infor mation about the system
     * like ram size, CPU time etc
    */
    info();

    // open the proc folder
    DIR *dir = opendir(proc);
    struct dirent *entry;

    if (dir == NULL) {
        perror("Could not open proc folder");
        return (1);
    }

    // print headers
    for(int i = 0; i < keylen; i++) {
        if(i == 0) {
            printf("%-*s", namlen, dict_keyss[i]);    
        } else {
                printf("%-*s", column_width, dict_keyss[i]);
        }
    }
    printf("\n");

    for (int i = 0; i < keylen; i++) {
        if(i == 0) {
            for (int j = 0; j < namlen - 1; j++) printf("-");
        } else {
            for (int j = 0; j < column_width - 1; j++) printf("-");
        }
        printf(" ");
    }
    printf("\n");

    //loop through the file in the proc folder
    while ((entry = readdir(dir)) != NULL) {

        /**
         * the one below can also work
         * (entry->d_type == DT_DIR && is_numeric(entry->d_name))
         * DT_DIR = 4
         * if entry is of type dir and name is just numbers
         */
        if(entry->d_type == 4 && is_numeric(entry->d_name)) {
            print_op(entry->d_name);
            printf("\n");
        }
    }

    closedir(dir);
    monitor(); 
    return (0);
}
