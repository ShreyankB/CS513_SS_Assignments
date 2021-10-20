/*
    1. Create the following types of a files using (i) shell command (ii) system call
        b. hard link (link system call)
*/

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    // hard link
    const char *linkpath = "./01a.c";
    const char *target = "./hard_link";

    int res = link(linkpath, target);

    if(res == 0)
        printf("hard link succesfully created\n %s -> %s \n", linkpath, target);
    else if(res == -1)
        printf("error: %s\n", strerror(errno));
}
