#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define SERV_ADDR	"172.18.4.231"
#define SERV_PORT	4000

int main(void)
{
	//1. create a socket
	int serv_fd = socket(AF_INET, SOCK_STREAM, 0);

	//2. bind ip and port with a socket
	struct sockaddr_in serv_addr;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(SERV_PORT);
	inet_aton(SERV_ADDR, &serv_addr.sin_addr);
	bind(serv_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

	//3. mark socket as listening/server socket
	listen(serv_fd, 5);

	//4. accept connacetions from client
	struct sockaddr_in cli_addr;
	socklen_t socklen = sizeof(cli_addr);
	int cli_fd = accept(serv_fd, (struct sockaddr *)&cli_addr, &socklen);
	
	//5. send and recv data with client
	char msg[64];
	do{
		recv(cli_fd, msg, sizeof(msg), 0);
		printf("client> %s\n", msg);
		printf("server> ");
		scanf(" %[^\n]s", msg);
		send(cli_fd, msg, strlen(msg)+1, 0);
	}while(strcmp(msg, "bye") != 0);

	//6. close client socket
	close(cli_fd);

	//7. shutdwon listening socket
	shutdown(serv_fd, SHUT_RDWR);

	return 0;
}























