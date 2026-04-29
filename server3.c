#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int main()
{
    int s;
    struct sockaddr_in server,client1,client2;
    socklen_t len;
    s = socket(AF_INET,SOCK_DGRAM, 0);
    server.sin_family=AF_INET;
    server.sin_port=htons(9000);
    server.sin_addr.s_addr=INADDR_ANY;
    bind(s,(struct sockaddr*)&server,sizeof(server));
    len = sizeof(client1);
    char ch;
    printf("Server waiting...\n");
    recvfrom(s,&ch,1,0,(struct sockaddr*)&client1,&len);
    printf("Received from client1:%c\n",ch);    
    ch=ch-1;
    client2.sin_family=AF_INET;
    client2.sin_port=htons(9001);
    client2.sin_addr.s_addr=inet_addr("127.0.0.1");
    sendto(s,&ch,1,0,(struct sockaddr*)&client2,sizeof(client2));
    close(s);
}
