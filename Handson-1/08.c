/*
    08. Write a program to open a file in read only mode, 
        read line by line and display each line as it is read. Close the file when end of file is reached.
*/
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int fd = open("./08.c", O_RDONLY);

    int line_size = 0;
    int buff_size = 10;
    char *buff = (char *)malloc(buff_size*sizeof(char));
    char c;

    while(read(fd, &c, 1)) {
        if(c == '\n') {
            write(STDOUT_FILENO, buff, line_size+1);
            write(STDOUT_FILENO, "\n", 1);
            line_size = 0;
            free(buff);
            buff_size = 2;
            buff = (char *)malloc(buff_size*sizeof(char));
        }
        else {
            line_size++;
            
            if(line_size == buff_size) {
                buff_size *= 2;
                buff = realloc(buff, buff_size);
            }

            buff[line_size] = c;
        }
    }

    write(STDOUT_FILENO, buff, line_size+1);
    free(buff);
    close(fd);
}