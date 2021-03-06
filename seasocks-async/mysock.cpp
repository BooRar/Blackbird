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

/* Simple server that echo any text or binary WebSocket messages back. */

using namespace seasocks;



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
		
		if (strcmp(data,"JonoYourock"))
		{
			connection->send("FratBoy has said speak");
		}
		if (strcmp(data ,"trade"))
		{
			connection->send("Trade");
		}
		if (strcmp(data , "data"))
		{
			connection->send("Data");
		}
		if (strcmp(data, "fees"))
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
    std::shared_ptr<Logger> logger(new PrintfLogger(Logger::DEBUG));

    Server server(logger);
    std::shared_ptr<EchoHandler> handler(new EchoHandler());
    server.addWebSocketHandler("/", handler);
    server.serve("/dev/null", 8000);
    return 0;
}
