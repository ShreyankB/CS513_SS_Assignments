/*
    15. Write a program to display the environmental variable of the user (use environ).
*/

#include <unistd.h>
#include <stdio.h>

int main() {
    
    while(*__environ){
        printf("%s\n", *__environ);
        *__environ++;
    }
}