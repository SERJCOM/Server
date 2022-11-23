#pragma once
#include <string>
#include <array>
#include "Server.hpp"

namespace sr{
    const int MAX_CHILD_COUNT = 5;
    const size_t MAX_PARENT_COUNT = 1;
class Pool: public Server{
    public:
        Pool():Server(){}

        Pool(std::string ip, unsigned short port):Server(ip, port){}

        void SetName(std::string name){
            poolName = name;
        }
        void AddChild(Pool* child){
            child->parent = this;
            children[currentChildNum] = child;
            currentChildNum++;
        }

        std::string GetParentName(){
            if(parent == nullptr)   return "";
            else    return parent->poolName;
        }

    
    private:
        int currentChildNum = 0;
        std::array<class Pool*, MAX_CHILD_COUNT> children;
        Pool *parent = nullptr;
        std::string poolName;
       
};

};