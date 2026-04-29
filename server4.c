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
    int a,b,res;
    char op;
    s = socket(AF_INET,SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = htons(9000);
    server.sin_addr.s_addr = INADDR_ANY;
   bind(s, (struct sockaddr*)&server, sizeof(server)) ;
    listen(s, 5);
    printf("Server waiting...\n");
    len = sizeof(client);
    ns = accept(s, (struct sockaddr*)&client, &len);
    printf("Client connected\n");
    recv(ns, &a, sizeof(a), 0);
    recv(ns, &b, sizeof(b), 0);
    recv(ns, &op, sizeof(op), 0);
    printf("Received: %d %d %c\n", a, b, op);
    if(op == '+') 
    {
        res = a + b;
    }
    else if(op == '-') 
    {
        res = a - b;
    }
    else if(op == '*') 
    {
        res = a * b;
    }
    else if(op == '/') 
    {
        if(b == 0) 
        {
            res = -1;   
        } else {
            res = a / b;
        }
    }
    else {
        res = -2;  
    }
    send(ns, &res, sizeof(res), 0);
    printf("Result sent to client\n");
    close(ns);
    close(s);
    return 0;
}
