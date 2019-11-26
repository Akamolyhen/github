#include <stdio.h>  
#include <stdlib.h>  
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/types.h>
#define MAXBUF 1024 16 17 18 
int main(int argc, char **argv) 
{  int sockfd, new_fd;
	socklen_t len;
	 struct sockaddr_in my_addr, their_addr; 
	 unsigned int myport, lisnum; 
	  char buf[MAXBUF + 1]; 
	   fd_set rfds; 
	    struct timeval tv; 
	     int retval, maxfd = -1; 
	      if (argv[1])
	       myport = atoi(argv[1]); 
	       else 
	        myport = 7838;
	         if (argv[2]) 
	          lisnum = atoi(argv[2]);  
	          else  lisnum = 2;  
	          if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1) 
	           { 
	            perror("socket"); 
	             exit(1); 
	           }
	            bzero(&my_addr, sizeof(my_addr)); 
	             my_addr.sin_family = PF_INET; 
	              my_addr.sin_port = htons(myport); 
	               if (argv[3]) 
	                my_addr.sin_addr.s_addr = inet_addr(argv[3]); 
	                 else 
	                  my_addr.sin_addr.s_addr = INADDR_ANY;
	                   if (bind(sockfd, (struct sockaddr *) &my_addr, sizeof(struct sockaddr)) == -1) 
	                   { perror("bind"); 
	                    exit(1); 
	                     } 
	                      if (listen(sockfd, lisnum) == -1) 
	                      { perror("listen"); 
	                      exit(1);  
	                      } 
	                       while (1) 
	                       {  printf  (" ----等待新的连接到来开始新的聊天…… "); 
	                        len = sizeof(struct sockaddr); 
	                         if ((new_fd =  accept(sockfd, (struct sockaddr *) &their_addr,  &len)) == -1) 
	                         {  perror("accept");
	                          exit(errno); 
	                          } 
	                          else
	                           printf("server: got connection from %s, port %d, socket %d ", inet_ntoa(their_addr.sin_addr),  ntohs(their_addr.sin_port), new_fd); 
	                           /* 开始处理每个新连接上的数据收发 */ 
	                            printf (" 准备就绪，可以开始聊天了……输入消息回车即可发信息给对方 "); 
	                            while (1) {  /* 把集合清空 */  FD_ZERO(&rfds); 
	                            /* 把标准输入句柄0加入到集合中 */  FD_SET(0, &rfds); 
	                             maxfd = 0; 
	                              /* 把当前连接句柄new_fd加入到集合中 */ 
	                               FD_SET(new_fd, &rfds); 
	                                if (new_fd > maxfd) 
	                                 maxfd = new_fd; 
	                                  /* 设置最大等待时间 */ 
	                                   tv.tv_sec = 1; 
	                                    tv.tv_usec = 0;  
	                                    /* 开始等待 */ 
	                                     retval = select(maxfd + 1, &rfds, NULL, NULL, &tv);  
	                                     if (retval == -1) 
	                                     { 
	                                      printf("将退出，select出错！ %s", strerror(errno)); 
	                                       break; 
	                                        } else if (retval == 0) 
	                                        {100 /* printf101 ("没有任何消息到来，用户也没有按键，继续等待…… "); */102 continue;103 } else {104 if (FD_ISSET(0, &rfds)) {105 /* 用户按键了，则读取用户输入的内容发送出去 */106 bzero(buf, MAXBUF + 1);107 fgets(buf, MAXBUF, stdin);108 if (!strncasecmp(buf, "quit", 4)) {109 printf("自己请求终止聊天！ ");110 break;111 }112 len = send(new_fd, buf, strlen(buf) - 1, 0);113 if (len > 0)114 printf115 ("消息:%s 发送成功，共发送了%d个字节！ ",116 buf, len);117 else {118 printf119 ("消息'%s'发送失败！错误代码是%d，错误信息是'%s' ",120 buf, errno, strerror(errno));121 break;122 }123 }124 if (FD_ISSET(new_fd, &rfds)) {125 /* 当前连接的socket上有消息到来则接收对方发过来的消息并显示 */126 bzero(buf, MAXBUF + 1);127 /* 接收客户端的消息 */128 len = recv(new_fd, buf, MAXBUF, 0);129 if (len > 0)130 printf131 ("接收消息成功:'%s'，共%d个字节的数据 ",132 buf, len);133 else {134 if (len < 0)135 printf136 ("消息接收失败！错误代码是%d，错误信息是'%s' ",137 errno, strerror(errno));138 else139 printf("对方退出了，聊天终止 ");140 break;141 }142 }143 }144 }145 close(new_fd);146 /* 处理每个新连接上的数据收发结束 */147 printf("还要和其它连接聊天吗？(no->退出)");148 fflush(stdout);149 bzero(buf, MAXBUF + 1);150 fgets(buf, MAXBUF, stdin);151 if (!strncasecmp(buf, "no", 2)) {152 printf("终止聊天！ ");153 break;154 }155 }156 157 close(sockfd);158 return 0;159 }