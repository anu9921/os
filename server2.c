#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<fcntl.h>
int main()
{
    int s,ns;
    struct sockaddr_in server,client;
    socklen_t len;
    s=socket(AF_INET,SOCK_STREAM,0);
    server.sin_family=AF_INET;
    server.sin_port=htons(9000);
    server.sin_addr.s_addr=INADDR_ANY;
    bind(s,(struct sockaddr*)&server,sizeof(server));
    listen(s,5);
    printf("Server waiting...\n");
while(1)
{
    len=sizeof(client);
    ns=accept(s,(struct sockaddr*)&client,&len);
    if(fork()==0)
    {
        char file[50],buf[100];
        int fd,n;
        recv(ns,file,50,0);
        fd=open(file,O_RDONLY);
        if(fd<0)
        {
            strcpy(buf,"ERROR");
            send(ns,buf,100,0);
        } 
        else 
        {
            while((n=read(fd,buf,100))>0)
            {
                send(ns,buf,n,0);
            }
        }
        close(ns);
        exit(0);
    }
}
    close(s);
}

