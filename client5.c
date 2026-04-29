#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int main()
{
    int s, v;
    char msg[50];
    struct sockaddr_in server;
    s = socket(AF_INET, SOCK_DGRAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = htons(9001);  
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    printf("Enter vote (1-3): ");
    scanf("%d", &v);
    sendto(s,&v, sizeof(v),0,(struct sockaddr*)&server,sizeof(server));
    recvfrom(s,msg, sizeof(msg),0,NULL,NULL);
    printf("Server: %s\n",msg);
    close(s);
}
