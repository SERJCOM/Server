#include <iostream>
#include "Pool.hpp"
#include <iostream>

auto main() -> int{
    int mode;
    std::cin >> mode;
    std::cout << mode << std::endl;
    std::string ip;
    std::cin >> ip;
    int port;
    std::cin >> port;
    sr::Pool main(ip, port);
    main.Bind();
    main.SetName("serj");
    if(mode == 1){
        std::cin >> port;
        main.Send("hello", ip, port);
    }
    else{
        while(true) {
            std::cout << mode << std::endl;
            main.Receive();
        }
    }
    return 0;
}