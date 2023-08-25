#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("test.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
    
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    const char data1[30] = "Hey! doing handson que 10";
    int  bytes_written = write(fd, data1, sizeof(data1) - 1);

    if (bytes_written != sizeof(data1) - 1) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    // moving the pointer by 10 bytes 
    off_t new_offset = lseek(fd, 10, SEEK_CUR);

    if (new_offset == -1) {
        perror("Error using lseek");
        close(fd);
        return 1;
    }

    // Write 20 more bytes after moving the file pointer
    const char data2[] = "writting more lines in file!!";
    bytes_written = write(fd, data2, sizeof(data2) - 1);

    if (bytes_written != sizeof(data2) - 1) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    close(fd);

    return 0;
}

