#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
int main()
{
    int s;
    struct sockaddr_in server;
    s = socket(AF_INET,SOCK_DGRAM,0);
    server.sin_family=AF_INET;
    server.sin_port=htons(9000);
    server.sin_addr.s_addr=INADDR_ANY;
    char ch;
printf("Enter character: ");
scanf(" %c",&ch);
sendto(s,&ch,1,0,(struct sockaddr*)&server,sizeof(server));
close(s);
}
