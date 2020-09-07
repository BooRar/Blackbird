// Copyright (c) 2013-2016, Matt Godbolt
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions are met:
// 
// Redistributions of source code must retain the above copyright notice, this 
// list of conditions and the following disclaimer.
// 
// Redistributions in binary form must reproduce the above copyright notice, 
// this list of conditions and the following disclaimer in the documentation 
// and/or other materials provided with the distribution.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
// POSSIBILITY OF SUCH DAMAGE.

#include "seasocks/PrintfLogger.h"
#include "seasocks/Server.h"
#include "seasocks/StringUtil.h"
#include "seasocks/WebSocket.h"

#include <cstring>
#include <iostream>
#include <memory>
#include <set>
#include <sstream>
#include <string>

#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <unistd.h>

/* Simple server that echo any text or binary WebSocket messages back. */

using namespace seasocks;
using namespace std;

//;
//string & getTrades();
class jono {
public:
	string n;
 string & getTrades()
	{
		//string  n;
		//n.clear();
		n = "this is the string you looking for";
		return n;
	}
 char * memread()
 {
	 //grab shared memory and send 
								// ftok to generate unique key 
	// key_t key = ftok("shmfile", 65);
	 key_t key = ftok("/tmp/page0", 0);
	
	 // shmget returns an identifier in shmid 
	 int shmid = shmget(key, 170, 0666 | IPC_CREAT);

	 // shmat to attach to shared memory 
	 char *str = (char*)shmat(shmid, (void*)0, 0);
	// shmctl(shmid, IPC_RMID, NULL);
	 return str;
 }
 char * memread1()
 {
	 //grab shared memory and send 
								// ftok to generate unique key 
	 //key_t key = ftok("shmfile1", 65);
	 key_t key = ftok("/tmp/page1", 0);

	 // shmget returns an identifier in shmid 
	 int shmid = shmget(key, 170, 0666 | IPC_CREAT);

	 // shmat to attach to shared memory 
	 char *str = (char*)shmat(shmid, (void*)0, 0);
	 // shmctl(shmid, IPC_RMID, NULL);
	 return str;
 }
 char * memread2()
 {
	 //grab shared memory and send 
								// ftok to generate unique key 
	// key_t key = ftok("shmfile1", 65);
	 key_t key = ftok("/tmp/page2", 0);

	 // shmget returns an identifier in shmid 
	 int shmid = shmget(key, 170, 0666 | IPC_CREAT);

	 // shmat to attach to shared memory 
	 char *str = (char*)shmat(shmid, (void*)0, 0);
	 // shmctl(shmid, IPC_RMID, NULL);
	 return str;
 }
 char * memread3()
 {
	 //grab shared memory and send 
								// ftok to generate unique key 
	 //key_t key = ftok("shmfile1", 65);
	 key_t key = ftok("/tmp/page3", 0);

	 // shmget returns an identifier in shmid 
	 int shmid = shmget(key, 170, 0666 | IPC_CREAT);

	 // shmat to attach to shared memory 
	 char *str = (char*)shmat(shmid, (void*)0, 0);
	 // shmctl(shmid, IPC_RMID, NULL);
	 return str;
 }
};
//extending classes looks like polymorphism derived class 

class EchoHandler : public WebSocket::Handler {
public:
	virtual void onConnect(WebSocket* /*connection*/) {
	}

	virtual void onData(WebSocket* connection, const uint8_t* data, size_t length) {
		connection->send(data, length); // binary
		std::cout << "on data binanry "<< std::endl;
		std::cout << data << std::endl;
	}

	virtual void onData(WebSocket* connection, const char* data) {
		//strcmp(value, "0.3c")
		jono jo;

		if (strcmp(data,"JonoYourock") == 0)
		{
			
			data = jo.getTrades().c_str();
			

			connection->send(data);
		}
		if (strcmp(data ,"trade") == 0)
		{
			connection->send("Trade");
		}
		if (strcmp(data , "data") == 0)
		{
			data = jo.memread();
			connection->send(data);
			data = jo.memread1();
			connection->send(data);
			data = jo.memread2();
			connection->send(data);
			data = jo.memread3();
			connection->send(data);

		}
		if (strcmp(data, "fees") == 0)
		{
			connection->send("Fees");
		}


			//connection->send("FratBoy has said speak"); // text
		//connection->send(data); // text
		//std::cout << "on data text " << std::endl;
		//std::cout << data << std::endl;
	}

	virtual void onDisconnect(WebSocket* /*connection*/) {
	}
};

int main(int /*argc*/, const char* /*argv*/[]) {
	jono jo;
	cout <<jo.getTrades() <<endl;
    std::shared_ptr<Logger> logger(new PrintfLogger(Logger::DEBUG));

    Server server(logger);
    std::shared_ptr<EchoHandler> handler(new EchoHandler());
    server.addWebSocketHandler("/", handler);
    server.serve("/dev/null", 8000);
    return 0;
}
