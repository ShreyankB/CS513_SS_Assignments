/*
    19. Create a FIFO file by
        d. mknod system call
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

int main() {
    if(mknod("./fifo1", S_IFIFO | 0666, 0) == -1)
        printf("%s", strerror(errno));
}
