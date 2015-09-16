#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) 
#define BUFF_SIZE 10

void err_sys(const char* message);

int main(int argc, char* argv[])
{
	int fd_source, fd_destination;
	int nread, nwrite;
	char buf[BUFF_SIZE];

	if(argc != 3)
	{
		err_sys("usage: ./mycopy source destination\n");
	}

	fd_source = open(argv[1], O_RDONLY);
	if(fd_source < 0)
	{
		err_sys("Problems opening the source file\n");
	}

	//fd_destination = creat(arg[2], FILE_MODE);
	fd_destination = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, FILE_MODE);
	if(fd_destination < 0)
	{
		err_sys("Can't open destination.. sorry.\n");
	}
	
	//read
	while(nread = read(fd_source, buf, sizeof(buf)))
	{
		//write
		nwrite = write(fd_destination, buf, nread);
		if(nwrite < 0)
		{
			err_sys("failed to write.\n");
		}
	}
	close(fd_source);
	close(fd_destination);
	return 0;
}

void err_sys(const char* message)
{
	printf("%s\n", message);
	exit(1);
}
