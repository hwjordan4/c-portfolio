#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>

#define MAXLINE 512

int main(int argc, char* argv[])
{
	//check arguments
	if(argc != 2)
	{
		printf("Usage: ./mywrite.exe <PTS/#>\n");
		exit(0);
	}
	char *path;
	path = malloc(12);
	path = strcpy(path, "/dev/pts/");
	path = strcat(path, argv[1]);
	//path = strcat(path, "\0");
	
	if(freopen(path, "w", stdout) == NULL)
	{
		printf("could not open terminal path...\n");
		exit(0);
	}

	char *login;
	struct passwd *pass;
	pass = getpwuid(getuid());
	login = pass->pw_name;

	printf("\nMessage from ");
	printf("%s\n", login);

	char buff[MAXLINE];

	while(fgets(buff, MAXLINE, stdin) != NULL)
	{
		if(fputs(buff, stdout) == EOF)
			printf("output error\n");
	}

	if(ferror(stdin))
		printf("input error\n");

	if(ferror(stdout))
		printf("output error\n");

	free(path);
	return 0;
}
