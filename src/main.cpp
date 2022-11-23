#include <iostream>
#include "Pool.hpp"

auto main() -> int{
    Sr::Pool main;
    Sr::Pool child;
    main.AddChild(&child);
    main.SetName("serj");
    std::cout << child.GetParentName() << std::endl;
    return 0;
}