#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

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
    len=sizeof(client);
    ns=accept(s,(struct sockaddr*)&client,&len);
    int x,y,found=0;
    char name[50];
    FILE *fp;
    recv(ns,&x,sizeof(x),0);
    fp = fopen("data.txt","r");
    while(fscanf(fp,"%d %s",&y,name)!=EOF)
    {
        if(x==y)
        {
            send(ns,name,50,0);
            found=1;
            break;
        }
    }
    if(!found)
    {
        strcpy(name,"Not found");
        send(ns,name,50,0);
    }
    fclose(fp);
    close(ns);
    close(s);
}