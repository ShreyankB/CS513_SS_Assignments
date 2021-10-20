/*
    4. Write a program to measure how much time is taken to execute 100 getppid ( ) 
       system call. Use time stamp counter.
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
unsigned long long rdtsc ()  
{
     unsigned long long dst;
     __asm__ __volatile__ ("rdtsc":"=A" (dst));
     return dst;  
}

int main() {
   long long int start, end;
   long long int total = 0;
   int i = 0;

   while(i < 100) {
      start = rdtsc();
      int pid = getpid();
      end = rdtsc();

      total += (end - start)/2.3;
      i++;
   }


   printf (" Time taken for 100 pid calls : %lld nano seconds\n", total);
}
