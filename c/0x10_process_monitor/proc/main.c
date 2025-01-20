#include <proc/readproc.h>
#include <stdio.h>


int main() {
	    PROCTAB *proc = openproc(PROC_FILLSTAT | PROC_FILLSTATUS);
	    if (!proc) {
        perror("Failed to open proc");
        return 1;
    }

    proc_t proc_info;
	    memset(&proc_info, 0, sizeof(proc_t));

    while (readproc(proc, &proc_info) != NULL) {
        printf("PID: %d, Name: %s, State: %c, Memory: %lu KB\n",
	                      proc_info.tid, proc_info.cmd, proc_info.state, proc_info.vm_size);
    }

    closeproc(proc);
    return 0;
}

