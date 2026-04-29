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
    server.sin_port=htons(9001);
    server.sin_addr.s_addr=INADDR_ANY;
    bind(s,(struct sockaddr*)&server,sizeof(server));
    char ch;
    recvfrom(s, &ch, 1, 0, NULL, NULL);
    printf("Received from server: %c\n", ch);
close(s);
}
