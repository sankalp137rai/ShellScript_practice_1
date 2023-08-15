#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char filename[100];
    int fileDis;

    printf("Enter the filename which you want to create: ");
    scanf("%s", filename);

    fileDis = creat(filename, S_IRUSR | S_IWUSR);

    if (fileDis == -1) {
        perror("Error while creating the file");
        exit(EXIT_FAILURE);
    }

    printf("File created successfully and  File Description is: %d\n", fileDis);
    close(fileDis);

    return 0;
}
