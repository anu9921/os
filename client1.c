#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
int main()
{
    int s;
    struct sockaddr_in server;
    s = socket(AF_INET,SOCK_STREAM,0);
    server.sin_family=AF_INET;
    server.sin_port=htons(9000);
    server.sin_addr.s_addr=inet_addr("127.0.0.1");
    connect(s,(struct sockaddr*)&server,sizeof(server));
    int x;
    char name[50];
    printf("Enter address: ");
    scanf("%d",&x);
    send(s,&x,sizeof(x),0);
    recv(s,name,50,0);
    printf("Result: %s\n",name);
    close(s);
}
