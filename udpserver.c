#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
int main()
{
int server_sockfd, client_sockfd;
int server_len,b;
char recvline[256],sendline[256]; 
struct sockaddr_in server_address; 
server_sockfd=socket(AF_INET,SOCK_DGRAM,0);
server_address.sin_family=AF_INET; 
server_address.sin_port=5514;
server_address.sin_addr.s_addr=inet_addr("127.0.0.1"); 
server_len=sizeof(server_address);
bind(server_sockfd,(struct sockaddr *)&server_address,server_len);
if(b<0)
    printf("Binding fail.\n");
while(1)
{
    char ch;
    printf("\nServer Waiting\n"); 
printf("\nMessege from Client : ");
recvfrom(server_sockfd,recvline,sizeof(recvline),0,(struct sockaddr *)&server_address,&server_len);
puts(recvline);
printf("\nEnter msg to send to Client : ");
gets(sendline);
sendto(server_sockfd,sendline,sizeof(sendline),0,(struct sockaddr *)&server_address,server_len);
//close(server sockfd);
}
}