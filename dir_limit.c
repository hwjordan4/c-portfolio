/* 
        Harrison Jordan
        cs3540/01
        10/22/14
        Assignment 6
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <dirent.h>

#define MAXLINE PATH_MAX
#define	FILE_MODE (111111111)

int main(){
char buf[MAXLINE];
char* pathname = malloc(sizeof(getcwd(buf, MAXLINE)));
pathname = getcwd(buf, MAXLINE);
char* newdir = malloc(sizeof(8));
newdir ="/test";
strcat(pathname, newdir);
char count = '1';
int num_of_leaves = 1;
printf("\n%s", pathname);
while(mkdir(pathname, FILE_MODE) > -1){
	
	if(chdir(pathname) < 0)
		printf("Couldnt change directory");
		
	

	
	pathname[strlen(pathname)] =  count;	
	printf("\n%s", pathname);
	count++;
	num_of_leaves++;
	
}
printf("\nNumber of directories made %d", &num_of_leaves);
free (pathname);
free (newdir);
exit(0);
}
