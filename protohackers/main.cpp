#include "platform_socket.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include <thread>

long unsigned int serverSocket = 0;


void handleClient(long unsigned int clientSocket) {
    char buffer[4096];

   while(true){

      int received = recv(clientSocket, buffer, sizeof(buffer), 0);
      if (received <= 0)
         break;

      std::cout<< "Received " << received << " bytes"<< std::endl;
      std::cout<<buffer<<std::endl;

      rapidjson::Document document;
      if(document.Parse(buffer).HasParseError()) {
         printf("Parsing error, bail with some response");
         break;
      }
      rapidjson::Value::MemberIterator isPrimeField = document.FindMember("isPrime");
      rapidjson::Value::MemberIterator numberField = document.FindMember("number");
      if (isPrimeField == document.MemberEnd() || numberField == document.MemberEnd()) {
         printf("Schema mismatch, bail with some response");
         break;
      }
      
      send(clientSocket, buffer, received, 0); 
   }
}


void acceptClients() {
    while (true) {
        long unsigned int clientSocket = accept(serverSocket, nullptr, nullptr);
        if (clientSocket != INVALID_SOCKET) {
           printf("Client connected on socket %d\n", (int)clientSocket);
           std::thread(handleClient, clientSocket).detach();
        }
    }
}


void parseJsonTest(){
       // 1. Parse a JSON string into DOM.
    const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
    rapidjson::Document d;
    d.Parse(json);

    // 2. Modify it by DOM.
    rapidjson::Value& s = d["stars"];
    s.SetInt(s.GetInt() + 1);

    // 3. Stringify the DOM
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    d.Accept(writer);

    // Output {"project":"rapidjson","stars":11}
    std::cout << buffer.GetString() << std::endl;
}


int main() {
   parseJsonTest();
   socket_init();
   serverSocket = socket(AF_INET, SOCK_STREAM, 0);
   sockaddr_in serverAddr{};
   serverAddr.sin_family = AF_INET;
   serverAddr.sin_port = htons(PORT);
   serverAddr.sin_addr.s_addr = INADDR_ANY;
   
   if(!bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == 0) {
      printf("Error binding server socket.");
   }
   if(!(listen(serverSocket, 40) == 0)) {
      printf("Error starting server listen.");
   }
   std::cout << "[Server] Listening on port " << PORT << "\n";
   
   acceptClients();
   socket_close(serverSocket);
}
