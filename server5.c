#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int main()
{
    int s, v;
    char msg[50];
    struct sockaddr_in server, client;
    socklen_t len;
    s = socket(AF_INET, SOCK_DGRAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = htons(9001);   
    server.sin_addr.s_addr = INADDR_ANY;
    if(bind(s,(struct sockaddr*)&server, sizeof(server))<0)
    {
        printf("Bind failed\n");
        exit(1);
    }
    len = sizeof(client);
    printf("Server waiting...\n");
    recvfrom(s, &v, sizeof(v), 0, (struct sockaddr*)&client, &len);
    printf("Received vote: %d\n", v);
    if(v >= 1 && v <= 3)
        sprintf(msg, "Vote recorded for Candidate %d", v);
    else
        strcpy(msg, "Invalid vote");
    sendto(s, msg, sizeof(msg), 0, (struct sockaddr*)&client, len);

    close(s);  
}
