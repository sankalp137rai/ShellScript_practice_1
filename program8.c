#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	if(argc!=2){
                printf("You are useless\n");
                return 0;
        }
        int fd_read = open(argv[1], O_RDONLY);
        if(fd_read ==-1){
                printf("Useless");
        }

        while(1) {
                char buf;
                int char_read = read(fd_read, &buf, 1);
                if(char_read == 0)
                        break;
		printf("%c",buf);

        }
        int fd_read_close = close(fd_read);

        if(fd_read_close ==-1){
                printf("Totly Useless");
        }


        return 0;

}
