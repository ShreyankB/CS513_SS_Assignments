/*
    09.Write a program to print the following information about a given file.
        a. inode
        b. number of hard links
        c. uid
        d. gid
        e. size
        f. block size
        g. number of blocks
        h. time of last access
        i. time of last modification
        j. time of last change
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysmacros.h>

int main(int argc, char *argv[])
{
    struct stat sb;

    if (argc != 2)
    {
        printf("Usage: %s <pathname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (lstat(argv[1], &sb) == -1)
    {
        perror("lstat");
        exit(EXIT_FAILURE);
    }

    printf("I-node number:            %ld\n", (long)sb.st_ino);
    printf("Hard link count:               %ld\n", (long)sb.st_nlink);
    printf("User ID:                  %d\n", (int)sb.st_uid);
    printf("Group ID:                 %d\n", (int)sb.st_gid);
    printf("File size:                %lld bytes\n",(long long)sb.st_size);
    printf("Preferred I/O block size: %ld bytes\n",(long)sb.st_blksize);
    printf("Blocks allocated:         %lld\n",(long long)sb.st_blocks);
    printf("Last status change:       %s", ctime(&sb.st_ctime));
    printf("Last file access:         %s", ctime(&sb.st_atime));
    printf("Last file modification:   %s", ctime(&sb.st_mtime));
}