/*
        Harrison Jordan
        cs3540/01
        11/07/14
        Assignment 8
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <setjmp.h>

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
void err_sys(char* message);

int sockfd, newsockfd;
int portno;
int clilength;
int n;
int debug = 1;

static jmp_buf jmpbuffer;

char buf[256];

struct sockaddr_in serv_addr, cli_addr;

int main(int argc, char* argv[])
{


	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
		err_sys("Failed to create socket...");

	bzero((char *)&serv_addr, sizeof(serv_addr));
	portno = 80;
	
	if(setjmp(jmpbuffer) != 0) {
		portno = 4040;
	}	

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);
	if(bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
		longjmp(jmpbuffer, 1);	
	listen(sockfd, 5);

	clilength = sizeof(cli_addr);
	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilength);
	if(newsockfd < 0)
		err_sys("Error on accept");

	bzero(buf, 256);
	n = read(newsockfd, buf, 255);
	if(n < 0)
		err_sys("Error on read");
	printf("Here is what we got: %s\n", buf);
	n = write(newsockfd, "I got your message", 18);
	if(n < 0)
		err_sys("Error on write");
	close(sockfd);
	close(newsockfd);
	
	return 0;
}

void err_sys(char* message)
{
	printf("%s\n", message);
	exit(0);
}
