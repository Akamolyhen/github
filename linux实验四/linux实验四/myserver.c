#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <pthread.h>
#include <time.h>
#define  Local_Port  8888
#define MAX_MESSAGE_SIZE 1024
#define MAX_CONNECT_NUM 5
char *Local_IP = "192.168.43.140";//
char SendBuffer[MAX_MESSAGE_SIZE];
char RecvBuffer[MAX_MESSAGE_SIZE];

struct Message
{
	int _Sockfd;
	int _Flag; 
	int _OnlineNum;
};
pthread_t Precv;
pthread_t Psend;
struct Message *SendMessage, *RecvMessage;
int ClientArray[MAX_CONNECT_NUM];
int OnlineNum = 0;

void Deal(int dealfd)
{
	int i,j;
	for (i=0;i<OnlineNum+1;i++)
	{
		if (ClientArray[i]==dealfd)
		{
			for (;i<OnlineNum;i++)
			{
				ClientArray[i] = ClientArray[i + 1];
			}
			printf("[Current online:]");
			for (j=0;j<OnlineNum;j++)
			{
				printf("[User ID:%d]\n", ClientArray[j]);
			}
		}
	}
}
void SendToClient(char *buffer, int dealfd)
{
	int i;
	for (i = 0; i < OnlineNum; i++)
	{
		if (ClientArray[i] == dealfd)
		{
			continue;
		}
		if (send(ClientArray[i], buffer, MAX_MESSAGE_SIZE, 0) == -1)
		{
			printf("Message sending failed\n");
		}/*第一个参数指定发送端套接字描述符；

第二个参数指明一个存放应用程序要发送数据的缓冲区；

第三个参数指明实际要发送的数据的字节数；

第四个参数一般置0。*/
	}
	bzero(buffer, MAX_MESSAGE_SIZE);
}
void *RecvMessageFromServer(void *recvfd)
{
	int dealfd = *(int *)recvfd;
	while (1) {
		if (recv(dealfd, RecvBuffer, MAX_MESSAGE_SIZE, 0) == -1) /*第一个参数指定接收端套接字描述符；

第二个参数指明一个缓冲区，该缓冲区用来存放recv函数接收到的数据；

第三个参数指明buf的长度；

第四个参数一般置0。*/
		{
			printf("Message reception failed\n");
		}
		RecvMessage= (struct Message*)RecvBuffer;
		RecvMessage->_Sockfd = dealfd;
		if (RecvMessage->_Flag == 1)
		{
			OnlineNum--;
			RecvMessage->_OnlineNum = OnlineNum;
			Deal(dealfd);
			printf("[User ID:%d Downline]\n", dealfd);
			SendToClient(RecvBuffer, dealfd);
			close(dealfd);
			return NULL;
		}
		SendToClient(RecvBuffer, dealfd);
	}
	close(dealfd);
	return NULL;
}
void Progress()
{
	int i, num = 1;
	const char* pic = "|/-\\";
	while (1)
	{
		if (101 == num)
		{
			break;
		}

		printf("[");
		for (i = 0; i < num / 10; i++)
			printf(">>");
		printf("]");

		printf("%d%%[%c]\r", num++, pic[num % 4]);
		fflush(stdout);
		usleep(30000);

	}
}
void Menu()
{
	system("clear");
	printf("################################\n");
	printf("####Welcome To LAN Chat Room####\n");
	printf("####This Is The Server  Side####\n");
	printf("################################\n");
	printf("[Loading]\n");
	Progress();
	system("date");
}
int main(int argc, char const *argv[])
{
	Menu();
	int serverfd, recvfd;
	socklen_t sockleng;
	struct sockaddr_in serveraddr, clientaddr;
	pid_t ChildID;

	if ((serverfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		printf("Failed to create server socket\n");
		exit(0);
	}

	serveraddr.sin_family = AF_INET;//Internet协议
	serveraddr.sin_port = htons(Local_Port);/*htons 把unsigned short类型从主机序转换到网络序
htonl 把unsigned long类型从主机序转换到网络序
ntohs 把unsigned short类型从网络序转换到主机序
ntohl 把unsigned long类型从网络序转换到主机序*/
	serveraddr.sin_addr.s_addr = inet_addr(Local_IP);//将点分形式的ip地址转换成无符号长整型

	if (bind(serverfd, (struct sockaddr *)&serveraddr, sizeof(struct sockaddr)) == -1)
	{
		printf("Failed to bind socket\n");
		exit(0);
	}

	if (listen(serverfd, 5) == -1)
	{
		printf("Failed to listen to socket\n");
	}

	printf("[Listening Local Port:%d,Waiting For Connection:]\n", Local_Port);

	while (1) {
		if ((recvfd = accept(serverfd, (struct sockaddr *)&clientaddr, &sockleng)) == 0)
		{
			printf("Failed to receive message\n");
			exit(0);
		}
		ClientArray[OnlineNum++] = recvfd;

		printf("[User ID:%d online]\n", recvfd);

		SendMessage = (struct Message *)SendBuffer;
		SendMessage->_Sockfd = recvfd;
		SendMessage->_Flag = 0;
		SendMessage->_OnlineNum = OnlineNum;
		int j;
		for (j = 0; j < OnlineNum; j++) {
			if (send(ClientArray[j], SendBuffer, MAX_MESSAGE_SIZE, 0) == -1) 
			{
				printf("Message sending failed\n");
			}
		}
		bzero(SendBuffer, MAX_MESSAGE_SIZE);
		if ((pthread_create(&Precv, NULL, RecvMessageFromServer, &recvfd)) != 0)
		{
			printf("FAILED\n");
			exit(0);
		}//第一个参数为指向线程标识符的指针。第二个参数用来设置线程属性。第三个参数是线程运行函数的起始地址。最后一个参数是运行函数的参数
	}
	close(serverfd);
	return 0;
}
