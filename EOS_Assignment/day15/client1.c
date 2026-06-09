#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define SERV_ADDR	"10.156.176.141/24"
#define SERV_PORT	4000

int main(void)
{
	//1. create a socket
	int cli_fd = socket(AF_INET, SOCK_STREAM, 0);

	//2. connect with server socket
	struct sockaddr_in serv_addr;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(SERV_PORT);
	inet_aton(SERV_ADDR, &serv_addr.sin_addr);
	connect(cli_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

	//3. send and recv data with client
	char msg[64];
	do{
		printf("client> ");
		scanf(" %[^\n]s", msg);
		send(cli_fd, msg, strlen(msg)+1, 0);
		
		recv(cli_fd, msg, sizeof(msg), 0);
		printf("server> %s\n", msg);
	}while(strcmp(msg, "bye") != 0);

	//6. close client socket
	close(cli_fd);

	return 0;
}























