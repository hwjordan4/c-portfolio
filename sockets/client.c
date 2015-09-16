#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void err_sys(char* message);

int main(int argc, char* argv[])
{

	if(argc < 2)
		err_sys("usage: ./client <hostname> <port number>");	
	int sockfd, portno, n;
	char buf[256];
	struct sockaddr_in serv_addr;
	struct hostent *server;

	portno = atoi(argv[2]);
	server = gethostbyname(argv[1]);
	if(server == NULL)
		err_sys("Error no such host");
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
		err_sys("Error opening socket");
	
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char *) server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
	serv_addr.sin_port = htons(portno);

	if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
		err_sys("Error connecting..");

	printf("Please enter a message: ");
	bzero(buf,256);
	fgets(buf, 255, stdin);
	
	n = write(sockfd, buf, strlen(buf));
	if(n < 0)
		err_sys("Error writing to socket");

	bzero(buf, 256);
	n = read(sockfd, buf, 256);
	if(n < 0)
		err_sys("Error reading from socket");

	printf("%s\n", buf);

	return 0;
}
void err_sys(char* message)
{
	printf("%s\n", message);
	exit(0);
}
