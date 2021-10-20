/*
    19. Create a FIFO file by
        d. mkfifo library function
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    if(mkfifo("./myfifo", 0666) == -1)
        printf("%s", strerror(errno));

}
