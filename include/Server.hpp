#pragma once
#include <SFML/Network.hpp>
#include <string>
#include <iostream>

namespace sr{
class Server{
public:
    Server(std::string ip, unsigned short port){
        IP = ip;
        this->port = port;
    }

    Server(){
        IP = "192.168.0.1";
        port = 1024;
    }

    void SetIP(std::string ip){
            IP = ip;
    }

    void SetPort(unsigned short port){
        this->port = port;
    }

    void Bind(){
        if (socket.bind(port) != sf::Socket::Done)
        {
            std::cout << "ERROR||BIND" << std::endl;
        }
    }

    void Send(std::string message, sf::IpAddress ip, unsigned short _port){
        if (socket.send(message.c_str(), message.size(), ip, _port) == sf::Socket::Done){
            std::cout << "ERROR||SEND" << std::endl;
        }
    }

    void Receive(){
        char message[100];
        size_t received;
        sf::Socket::Status status = socket.receive(&message, 100, received, IP, port);
        if (status == sf::Socket::Done){
            std::cout << "AAAAA" << std::endl;
            std::cout << message << std::endl;
        }
        else{
            std::cout << "status" << std::endl;
        }
        //return message;
    }


private:
    sf::IpAddress IP;
    sf::UdpSocket  socket;
    unsigned short port;
    sf::Socket::Status status;
    std::string data;
};
};