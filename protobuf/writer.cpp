#include <iostream>
#include "lm.helloworld.pb.h"

void ListMessage(const lm::helloworld &message)
{
    std::cout << message.id() << std::endl;
    std::cout << message.str() << std::endl;
}

int main()
{
    lm::helloworld obj1;
    obj1.set_id(100);
    obj1.set_str("shit!");
    if (!obj1.SerializeToOstream(&std::cout)) {

    }
}
