//Example code: A simple server side code, which echos back the received message.
//Handle multiple socket connections with select and fd_set on Linux
#include <stdio.h>
#include <string.h>   //strlen
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>   //close
#include <arpa/inet.h>    //close
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h> //FD_SET, FD_ISSET, FD_ZERO macros
#include <iostream>
#include <string>

#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <unistd.h>

using namespace std;

// converts character array
// to string and returns it
string convertToString(char* a, int size)
{
	int i;
	string s = "";
	for (i = 0; i < size; i++) {
		s = s + a[i];
	}
	return s;
}

string extractCommand(char* a, int size)
{
	int i;
	string s = "";
	for (i = 4; i < size; i++) {
		s = s + a[i];
	}

	return s;
}
// char stringToChar()
// {
// // assigning value to string s
//     string s("geeksforgeeks");
//     // declaring character array : p
//     //char p[s.length()];
//      char p[1025];
//
//     int i;
//     for (i = 0; i < sizeof(p); i++) {
//         p[i] = s[i];
//         cout << p[i];
//     }
//     return *p;
// }


void convStringToChar(char* myout, std::string convMe)
{
	int i;
	int len = convMe.length();
	for (i = 0; i < len; i++)
	{
		//  std::cout << "As a char, " << convMe[i] << "!\n";
		myout[i] = convMe[i];
	}
	//ZeroFill the buffer
	myout[len] = '\0';
}

#define TRUE   1
#define FALSE  0
#define PORT 8888


int main(int argc, char *argv[])
{
	int opt = TRUE;
	int master_socket, addrlen, new_socket, client_socket[30],
		max_clients = 30, activity, i, valread, sd;
	int max_sd;
	struct sockaddr_in address;

	char buffer[1025];  //data buffer of 1K
	//char commands[5];  //data buffer of 1K

	char help[1025];
	char trade[1025];




	//stings
	//string myString;
	string command;
	//string help;

	//set of socket descriptors
	fd_set readfds;

	//a message
	char *message = "ECHO BlackBird Socket Daemon v2.0 \r\n";

	//initialise all client_socket[] to 0 so not checked
	for (i = 0; i < max_clients; i++)
	{
		client_socket[i] = 0;
	}

	//create a master socket
	if ((master_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}

	//set master socket to allow multiple connections ,
	//this is just a good habit, it will work without this
	if (setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt,
		sizeof(opt)) < 0)
	{
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}

	//type of socket created
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	//bind the socket to localhost port 8888
	if (bind(master_socket, (struct sockaddr *)&address, sizeof(address)) < 0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	printf("Listener on port %d \n", PORT);

	//try to specify maximum of 3 pending connections for the master socket
	if (listen(master_socket, 3) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}

	//accept the incoming connection
	addrlen = sizeof(address);
	puts("Waiting for connections ...");

	while (TRUE)
	{
		//clear the socket set
		FD_ZERO(&readfds);

		//add master socket to set
		FD_SET(master_socket, &readfds);
		max_sd = master_socket;

		//add child sockets to set
		for (i = 0; i < max_clients; i++)
		{
			//socket descriptor
			sd = client_socket[i];

			//if valid socket descriptor then add to read list
			if (sd > 0)
				FD_SET(sd, &readfds);

			//highest file descriptor number, need it for the select function
			if (sd > max_sd)
				max_sd = sd;
		}

		//wait for an activity on one of the sockets , timeout is NULL ,
		//so wait indefinitely
		activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);

		if ((activity < 0) && (errno != EINTR))
		{
			printf("select error");
		}

		//If something happened on the master socket ,
		//then its an incoming connection
		if (FD_ISSET(master_socket, &readfds))
		{
			if ((new_socket = accept(master_socket,
				(struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0)
			{
				perror("accept");
				exit(EXIT_FAILURE);
			}

			//inform user of socket number - used in send and receive commands
			printf("New connection , socket fd is %d , ip is : %s , port : %d \n", new_socket, inet_ntoa(address.sin_addr), ntohs
			(address.sin_port));

			//send new connection greeting message
			if (send(new_socket, message, strlen(message), 0) != strlen(message))
			{
				perror("send");
			}

			puts("Welcome message sent successfully");

			//add new socket to array of sockets
			for (i = 0; i < max_clients; i++)
			{
				//if position is empty
				if (client_socket[i] == 0)
				{
					client_socket[i] = new_socket;
					printf("Adding to list of sockets as %d\n", i);

					break;
				}
			}
		}

		//else its some IO operation on some other socket
		for (i = 0; i < max_clients; i++)
		{
			sd = client_socket[i];

			if (FD_ISSET(sd, &readfds))
			{
				//Check if it was for closing , and also read the
				//incoming message
				if ((valread = read(sd, buffer, 1024)) == 0)
				{
					//Somebody disconnected , get his details and print
					getpeername(sd, (struct sockaddr*)&address, \
						(socklen_t*)&addrlen);
					printf("Host disconnected , ip %s , port %d \n",
						inet_ntoa(address.sin_addr), ntohs(address.sin_port));

					//Close the socket and mark as 0 in list for reuse
					close(sd);
					client_socket[i] = 0;
				}

				//Echo back the message that came in
				else
				{
					//set the string terminating NULL byte on the end
					//of the data read
					buffer[valread] = '\0';

					//   Testing Stuff
					//std::cout << "CLIENT buffer : "<<buffer<<std::endl;
					//std::cout << "CLIENT valread : "<<valread<<std::endl;



					//compars the char to a string character by caracter to char X 3 places
					if (strncmp(buffer, "run:", 4) == 0) {

						//   buffer["COMMAND RUNNING \0"];
						//send(sd , buffer , strlen(buffer) , 0 );

//COMMAND CENTRE
//int bufsize=  sizeof(buffer)/ sizeof(char);
						int bufsize = valread;

						std::string command = extractCommand(buffer, bufsize);
						//std::string::erase(command, ' ');
						string str;
						string str2 = buffer;
						str = str2.substr(4, 7);
						std::cout << "substring : " << str << std::endl;


						std::cout << "ORIGIONAL : " << buffer << std::endl;
						std::cout << "COMMAND : " << command << std::endl;
						int leno = command.length();
						std::cout << "Length : " << leno << std::endl;

						std::cout << "cmd CHAR 0 : " << command[0] << std::endl;
						std::cout << "cmd CHAR 1 : " << command[1] << std::endl;
						std::cout << "cmd CHAR 2 : " << command[2] << std::endl;
						std::cout << "cmd CHAR 3 : " << command[3] << std::endl;
						std::cout << "cmd CHAR 4 : " << command[4] << std::endl;
						std::cout << "cmd CHAR 5 : " << command[5] << std::endl;
						std::cout << "cmd CHAR 6 : " << command[6] << std::endl;
						//return 0;
						//
						//if the command --==help print something
						char foo[] = "help";
						char com[4];
						com[0] = command[0];
						com[1] = command[1];
						com[2] = command[2];
						com[3] = command[3];

						char com2[4];
						com2[4] = foo[1];
						com2[4] = foo[2];
						com2[4] = foo[3];
						com2[4] = foo[4];

						std::cout << "hlp CHAR 0 : " << foo[0] << std::endl;
						std::cout << "hlp CHAR 1 : " << foo[1] << std::endl;
						std::cout << "hlp CHAR 2 : " << foo[2] << std::endl;
						std::cout << "hlp CHAR 3 : " << foo[3] << std::endl;
						std::cout << "hlp CHAR 4 : " << foo[4] << std::endl;
						std::cout << "hlp CHAR 5 : " << foo[5] << std::endl;
						std::cout << "hlp CHAR 6 : " << foo[6] << std::endl;
						//std::cout<<"a is of type: "<<typeid(command).name()<<std::endl; // Output 'a is of type int'
						  // std::cout<<"b is of type: "<<typeid(b).name()<<std::endl; // Output 'b is of type someClass'
						if (str == "help")
						{
							std::cout << "Help Request : " << std::endl;
							std::string text = "COMMANDS : help , data , CLOSE ,TRADE \n\r";
							int tlen = text.length();
							convStringToChar(help, text);
							//        help = stringToChar();
							std::string go = help;
							std::cout << go << std::endl;
							help[tlen] ='\0';
							//send(sd , help , sizeof(text) , 0 );
							send(sd, help, tlen+1, 0);
						}
						if (str == "data")
						{
							std::cout << "Data Out : " << std::endl;
							std::string text = "EXCANGE : BitFinex  | MARKETDATA  ASK:32304 BID:45535 CLOSE:434556  \n\r";
							
							while (str == "data") {
								usleep(1000000);
								//grab shared memory and send 
								// ftok to generate unique key 
								key_t key = ftok("shmfile", 65);

								// shmget returns an identifier in shmid 
								int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

								// shmat to attach to shared memory 
								char *str = (char*)shmat(shmid, (void*)0, 0);

								//printf("Data read from memory: %s\n", str);

								//char newline[2] = "\r";
								//newline[2] = '\0';

								// destroy the shared memory 
								//shmctl(shmid, IPC_RMID, NULL);

								//convStringToChar(trade, str);
								int tlen = strlen(str);// .length();
								str[tlen + 2] = '\0';
								str[tlen+1] = '\n';
								str[tlen] = '\r';
								//str[tlen+1] = '\0';
								
								send(sd, str, tlen+3 , 0);
								//send(sd, newline, 2, 0);

								//detach from shared memory 
								shmdt(str);

								// destroy the shared memory 
								shmctl(shmid, IPC_RMID, NULL);
								//convStringToChar(trade, text);

							}
							//sample stuff
							//int tlen = text.length();
							//trade[tlen] = '\0';
							//for (int i = 0; i < 5; i++) {
							//	cout << i << "\n";
							//	send(sd, trade, tlen + 1, 0);
							//}
							
							
							
							//        help = stringToChar();
							std::string go = trade;
							std::cout << go << std::endl;
							
							//send(sd , help , sizeof(text) , 0 );
							
						}

					}

					else {

						//send(sd ,buffer , strlen(buffer) , 0 );
						//send(sd, "", 4, 0);
						// Do an extrat
						std::cout << "CLIENT MESSAGES : " << buffer << std::endl;
					}
				}
			}
		}
	}

	return 0;
}
