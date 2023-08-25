#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char* argv[]){
	const char *file_path = "./temp1.text";
	struct stat file_stat;
	if(stat(file_path, &file_stat) == -1){
		perror("Error");
		return 1;
	}

	printf("Inode: %lu\n", file_stat.st_ino);
	printf("Number of Hard Links: %lu\n", file_stat.st_nlink);
    	printf("UID: %u\n", file_stat.st_uid);
    	printf("GID: %u\n", file_stat.st_gid);
    	printf("Size: %ld bytes\n", file_stat.st_size);
    	printf("Block Size: %ld bytes\n", file_stat.st_blksize);
    	printf("Number of Blocks: %ld\n", file_stat.st_blocks);

    	char last_access_time[20];
    	char last_modification_time[20];
    	char last_change_time[20];

    	strftime(last_access_time, sizeof(last_access_time), "%Y-%m-%d %H:%M:%S", localtime(&file_stat.st_atime));
    	strftime(last_modification_time, sizeof(last_modification_time), "%Y-%m-%d %H:%M:%S", localtime(&file_stat.st_mtime));
    	strftime(last_change_time, sizeof(last_change_time), "%Y-%m-%d %H:%M:%S", localtime(&file_stat.st_ctime));

    	printf("Last Access Time: %s\n", last_access_time);
    	printf("Last Modification Time: %s\n", last_modification_time);
    	printf("Last Change Time: %s\n", last_change_time);

    return 0;
}
