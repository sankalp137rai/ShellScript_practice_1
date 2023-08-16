#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	char filename[100];
	int fileDisc;

	printf("Enter the file name which you want to open: ");
	scanf("%s", filename);

	fileDisc = open(filename, O_RDWR);

	if(fileDisc == -1){
		perror("Error while opening the file");
		exit(EXIT_FAILURE);
	}

	// reading first 50 char data from file
	char buf[51];
	int n = read(fileDisc,buf,50);
	buf[n]='\0';
	write(1,buf,n);


    	close(fileDisc);
	return 0;




}
