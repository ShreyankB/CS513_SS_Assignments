/*
    1. Create the following types of a files using (i) shell command (ii) system call
        a. soft link (symlink system call)
*/

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    // soft link
    const char *linkpath = "./01a.c";
    const char *target = "./soft_link";

    int res = symlink(linkpath, target);

    if(res == 0)
        printf("soft link succesfully created\n %s -> %s \n", linkpath, target);
    else if(res == -1)
        printf("error: %s\n", strerror(errno));
}
