#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
int main (int argc , char** argv)
{
	if(argc < 3){
		printf("Usage: cp file file \n");
		return 1;
	}
	int fd1 = open(argv[1],O_RDONLY);
	int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(fd2 == -1 )
	{
		printf("Unable to open destination file\n");
		close(fd1);
		return 1;
	}
	int readcount ,writecount;
	char buff [1024];
	while((read(fd1 , buff, sizeof(buff)))> 0){
		writecount = write(fd2 , buff , 1024);
		if (writecount == -1 )
		{
			printf("Failed to write\n");
			close(fd1);
			close(fd2);
			return 1;
		}
	}
	close(fd2);
	close(fd1);
	return 0;
}
