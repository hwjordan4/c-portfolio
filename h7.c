/* 
        Harrison Jordan
        cs3540/01
        10/22/14
        Assignment 7
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include <unistd.h>
#include <strings.h>
void err_sys(const char* message);

int main()
{
	const char* dir = "a";
	int size = PATH_MAX + 1;
	char* path;
	char* parent = malloc(2* sizeof(char));
	parent = "..";
	char* buf = malloc(size);
	int i = 0;
	char* all_files = malloc(2 * sizeof(char));
	all_files = "/*";

	while(1)
	{
		if(mkdir(dir, S_IRWXU | S_IRWXG | S_IRWXO) >= 0)
			printf("Create dir was successfull\n");
		else
			err_sys("Failed to create dir\n");
		if(chdir(dir) < 0)
			err_sys("Failed to chdir\n");
		printf("%d\n", i);
		path = getcwd(buf, size);
		if(path == NULL)
		{
			printf("Failed to get cwd\n");
			break;
		}
		i++;
		
		
	}
	while(i > 0)
	{
	if(chdir(parent) < 0)
		err_sys("Failed to change to parent directory\n");
	path = getcwd(buf, size);
	printf("%s", path);
	if(rmdir(path) < 0)
		err_sys("Failed to rmdir\n");
	else
		printf("Removed directory");
	path = getcwd(buf, size);
	printf("path: %s", path); 
	i--;
	}
	free(all_files);
	free(parent);
	free(buf);
	return 0;
}

void err_sys(const char* message)
{
	printf("%s\n", message);
	exit(0);
}
