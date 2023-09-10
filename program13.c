#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <string.h>

int main(int args, char* argc[]){
	fd_set rf;

    	FD_ZERO(&rf);
    	FD_SET(0,&rf);


    	struct timeval timep;
    	timep.tv_sec = 10;
    	timep.tv_usec = 0;


    	int rval = select(1, &rf, NULL,NULL, &timep);

    	if (rval == -1)
        	perror("error");
    	else if (rval){
        	const char* x = "Data is present.\n";
        	write(STDOUT_FILENO,x,strlen(x));

   	 }
    	else{
        	const char* x = "No data.\n";
        	write(STDOUT_FILENO,x,strlen(x));
   	 }
		return 0;

}
