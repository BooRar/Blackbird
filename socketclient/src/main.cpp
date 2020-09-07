#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <unistd.h>
int main()
{
std::cout << "Welcome to the socket client " <<std::endl;
//create socket
 int network_socket;
 network_socket = socket(AF_INET , SOCK_STREAM , 0 );

//specify an address forthe network_socket
//
struct sockaddr_in server_address;
server_address.sin_family = AF_INET;
server_address.sin_port = htons(9002);
server_address.sin_addr.s_addr = INADDR_ANY ; //ip adress of the server

int connection_status = connect(network_socket , (struct sockaddr *) &server_address , sizeof(server_address));


 if (connection_status == -1)
 {
         printf("Connection Failed  \n");
 }
char server_response[256];
 recv(network_socket , &server_response, sizeof(server_response),0);

//print out the data from server
printf("the is data %s\n",server_response);
//
//close
close(network_socket);


return 0;



}
