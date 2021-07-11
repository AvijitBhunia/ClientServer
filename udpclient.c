#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
int main()
{
int sockfd,len;
struct sockaddr_in address;
char recvline[256],sendline[256];
sockfd=socket(AF_INET,SOCK_DGRAM,0);
address.sin_family=AF_INET;
address.sin_port=5514;
address.sin_addr.s_addr=inet_addr("127.0.0.1");
bind(sockfd,(struct sockaddr *)&address,sizeof(address));
len=sizeof(address);
while(1)
{
printf("\nEnter msg to send to Server : ");
gets(sendline);
sendto(sockfd,sendline,sizeof(sendline),0,(struct sockaddr *)&address,len);
recvfrom(sockfd,recvline,sizeof(recvline),0,(struct sockaddr *)&address,&len);
printf("\nMessage from Server : ");
puts(recvline);
}
close(sockfd);
return(0);
}