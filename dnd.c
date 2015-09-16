#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define ON (S_IRUSR | S_IWUSR | S_IWGRP)
#define OFF (S_IRUSR | S_IWUSR | S_IWGRP | S_IWOTH)

int main(int argc, char* argv[])
{
	if(argc != 2)
		printf("usage: ./DND <ON|OFF>\n");
	
	if(strcmp(argv[1],"ON") == 0)
	{
		//do stuff
		char* path = ttyname(STDIN_FILENO);
		if( chmod(path, ON) != 0)
			printf("Failed to set DND to ON\n");
		else
			printf("DND set to ON\n");
	}
	else
	{
		if(strcmp(argv[1],"OFF") == 0)
		{
			//do stuff
			char* path = ttyname(STDIN_FILENO);
			if(chmod(path, OFF) != 0)
				printf("Failed to set DND to off\n");
			else
				printf("DND set to OFF\n");
		}
	}

	return 0;
}
