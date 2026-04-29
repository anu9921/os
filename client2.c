#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<fcntl.h>
int main()
{
    int s;
    struct sockaddr_in server;
    s = socket(AF_INET,SOCK_STREAM,0);
    server.sin_family=AF_INET;
    server.sin_port=htons(9000);
    server.sin_addr.s_addr=inet_addr("127.0.0.1");
    connect(s,(struct sockaddr*)&server,sizeof(server));
   char file[50],buf[100];
    int fd,n;
    printf("Enter file: ");
    scanf("%s",file);
    send(s,file,50,0);
    fd=creat("new.txt",0666);
    while((n=recv(s,buf,100,0))>0)
    {
        write(fd,buf,n);
    }
    close(fd);
    close(s);
}
