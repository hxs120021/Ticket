#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
void ServerListen()
{
	int server_sockfd;//服务端套接字
	int client_sockfd;//客户端套接字
	int len;//暂不知
	struct sockaddr_in server_addr;//服务器网络地址结构
	struct sockaddr_in client_addr;//客户端网络地址结构
	int sin_size;

	char buf[BUFSIZ];//数据传送缓冲区
	memset(&server_addr, 0, sizeof(server_addr));//初始化数据，清零
	server_addr.sin_family = AF_INET;//设置ip通信
	server_addr.sin_addr.s_addr = INADDR_ANY;//服务器ip地址，允连接到本地地址上
	server_addr.sin_port = htons(6666);//服务器端口号
	
	/*服务端创建套接字，ipv4 面向链接通信，tcp协议*/
	server_sockfd = socket(PF_INET,	SOCK_STREAM,0);
	/*套接字绑定到服务器上网络地址上*/
	bind(server_sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr));
	/*监听链接请求，队列长度5*/
	listen(server_sockfd, 5);
	sin_size = sizeof(struct sockaddr_in);
	
	/*等待客户端链接*/
	client_sockfd = accept(server_sockfd,(struct sockaddr*)&client_addr, &sin_size);

	printf("accept slient %s\n", inet_ntoa(client_addr.sin_addr));
	len = send(client_sockfd, "welcome to sercer\n",18,0);
	/*接受客户端的数据, recv返回接到的字节数，send返回发送的字节数*/
	while((len = recv(client_sockfd, buf, BUFSIZ, 0))>0)
	{
		buf[len] = '\0';
		printf("%s\n",buf);
		if(send(client_sockfd, buf, len, 0) < 0)
		{
			perror("write");
			return;
		}
	}
	close(client_sockfd);
	close(server_sockfd);
	printf("listen over\n");
	return;
}

int ClientUse()
{
	int client_sockfd;
	int len;
	struct sockaddr_in server_addr;//服务器网络地址结构
	char buf[BUFSIZ];
	memset(&server_addr, 0, sizeof(server_addr));//初始化数据
	server_addr.sin_family = AF_INET;//设置ip通信
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");//服务器ip
	server_addr.sin_port = htons(6666);
	/*客户端创建套接字， ipv4面向连接通信，tcp协议*/
	client_sockfd = socket(PF_INET, SOCK_STREAM, 0);
	/*套接字绑定到客户端上网络地址上*/
	connect(client_sockfd, (struct sockaddr*)&server_addr, sizeof(struct sockaddr));
	printf("connect to sercer\n");
	len = recv(client_sockfd, buf, BUFSIZ, 0);
	buf[len] = '\0';
	printf("%s\n", buf);//打印服务端消息

	/*循环大宋接受消息并打印*/
	while(1)
	{
		printf("Enter string to send:");
		scanf("%s", buf);
		if(!strcmp(buf,"0"))
			break;
		len = send(client_sockfd, buf, strlen(buf), 0);
		printf("%d", len);
		len = recv(client_sockfd, buf, BUFSIZ, 0);
		buf[len] = '\0';
		printf("received : %s\n", buf);
	}
	close(client_sockfd);
	return 0;
}
