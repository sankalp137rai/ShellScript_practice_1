#include <unistd.h>
#include <stdio.h>

int main(){
	const char *target = "/home/sankalp/Documents/handsOnShell/session1/temp.txt";
	const char *linkname = "soft_link_for_temp_using_C";
	int result = symlink(target, linkname);

	if(result == 0){
		printf("Symbolic link created successfully\n");
	}
	else{
		perror("Error creating symbolic link");
	}
}
