/*
    19. Create a FIFO file by
        c. use strace command to find out, which command (mknod or mkfifo) is better.
*/

/*
    strace -c mknod myfifo p 
    strace -c mkfifo myfifo2

    mkfifo internally calls mknod. So, it is better to use mknod.
*/