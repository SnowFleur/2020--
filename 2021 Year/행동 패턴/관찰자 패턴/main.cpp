


#include"Clinet.h"
#include"World.h"

#include<memory>

int main() {

    std::unique_ptr< CWorld> ptr = std::make_unique<CWorld>();
    ptr->Run();
}