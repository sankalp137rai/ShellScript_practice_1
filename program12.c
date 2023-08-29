#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	
	if(argc!=2){
		printf("You are useless\n");
		return 0;
	}


    	int file_descriptor = open(argv[1], O_RDONLY);
    
    	if (file_descriptor == -1) {
        	perror("Error opening the file");
        	return 1;
    	}
    
   	int flags = fcntl(file_descriptor, F_GETFL);
    
    	if (flags == -1) {
        	perror("Error getting file status flags");
        	return 1;
   	 }
    
   	 if (flags & O_RDWR) {
        	printf("The opening mode of the file is: read-write\n");
   	 }
	 else if (flags & O_WRONLY) {
        	printf("The opening mode of the file is: write-only\n");
   	 }
	 else {
        	printf("The opening mode of the file is: read-only\n");
   	 }

	close(file_descriptor);
    
    return 0;
}

