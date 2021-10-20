/*
    14. Write a program to find the type of a file.
        a. Input should be taken from command line.
        b. program should be able to identify any type of a file. 
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    struct stat info;
    
    if(argc != 2){
        printf("give file input using command line: ");
        return 0;
    }

    if(stat(argv[1], &info) == -1) {
        printf("error while obtainig info");
        return 0;
    }
    else{
        printf("File type:  ");

        switch (info.st_mode & S_IFMT) {
        case S_IFBLK:  printf("block device\n");            break;
        case S_IFCHR:  printf("character device\n");        break;
        case S_IFDIR:  printf("directory\n");               break;
        case S_IFIFO:  printf("FIFO/pipe\n");               break;
        case S_IFLNK:  printf("symlink\n");                 break;
        case S_IFREG:  printf("regular file\n");            break;
        case S_IFSOCK: printf("socket\n");                  break;
        default:       printf("unknown?\n");                break;
        }
    }
}