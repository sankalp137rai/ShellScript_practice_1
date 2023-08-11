#include <unistd.h>
#include <stdio.h>

int main(){
        const char *target = "/home/sankalp/Documents/handsOnShell/session1/temp.txt";
        const char *linkname = "hard_link_for_temp_using_C";
        int result = link(target, linkname);

        if(result == 0){
                printf("Hard link created successfully\n");
        }
        else{
                perror("Error creating symbolic link");
        }
}

