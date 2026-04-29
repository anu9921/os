#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int main()
{
    int s,a,b,res;
    char op;
    struct sockaddr_in server;
    s = socket(AF_INET,SOCK_STREAM, 0);
    server.sin_family=AF_INET;
    server.sin_port=htons(9000);
    server.sin_addr.s_addr=inet_addr("127.0.0.1");
    connect(s, (struct sockaddr*)&server, sizeof(server));
    printf("Connected to server\n");
    printf("Enter a b op: ");
    scanf("%d %d %c",&a,&b,&op);
    send(s, &a, sizeof(a),0);
    send(s, &b, sizeof(b),0);
    send(s, &op, sizeof(op),0);
    printf("Data sent, waiting for result...\n");
    recv(s, &res, sizeof(res), 0);
    if(res == -1) 
    {
        printf("Divide by zero\n");
    }
    else if(res == -2) 
    {
        printf("Invalid operator\n");
    }
    else {
        printf("Result = %d\n", res);
    }
    close(s);
    return 0;
}
