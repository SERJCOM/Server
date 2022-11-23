#pragma once
#include <iostream>
#include <string>
#include <array>

namespace Server{
    const int MAX_CHILD_COUNT = 5;
    const size_t MAX_PARENT_COUNT = 1;

class Pool{
    public:
        Pool(){
        
        }
        void SetName(std::string name){
            poolName = name;
        }
        void AddChild(Pool* child){
            children[currentChildNum] = child;
            currentChildNum++;
        }

    
    private:
        int currentChildNum = 0;
        std::array<class Pool*, MAX_CHILD_COUNT> children;
        Pool *parent = nullptr;
        std::string poolName;
};

};