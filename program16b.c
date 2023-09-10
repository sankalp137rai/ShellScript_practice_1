/*
============================================================================
Name : 16b.c
Author : Sankalp Rai
Description : Write a program to perform mandatory locking.
 a. Implement read lock

 
Date: 25th Aug, 2023.
============================================================================
*/

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h> 
#include <sys/types.h> 
#include <sys/stat.h>  

int main(int argc, char *argv[])
{

    char *filename;
    struct flock lock, lockStatus;
    int fileDescriptor;

    if (argc != 2)
        printf("Pass the file name to be locked as the argument!");
    else
    {
        filename = argv[1];

        lock.l_type = F_RDLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = 0;         
        lock.l_len = 0;           
        lock.l_pid = getpid();


        lockStatus = lock;

        fileDescriptor = open(filename, O_RDONLY);

        // Checking file lock status
        fcntl(fileDescriptor, F_GETLK, &lockStatus);

        if (lockStatus.l_type == F_WRLCK)
            printf("File already locked for writing\n");
        else if (lockStatus.l_type == F_RDLCK)
            printf("File already locked for reading\n");
        else
        {
            // Applying lock
            fcntl(fileDescriptor, F_SETLK, &lock);
            printf("File is now locked for reading\n");
    	}
    }
    return 0;
}
