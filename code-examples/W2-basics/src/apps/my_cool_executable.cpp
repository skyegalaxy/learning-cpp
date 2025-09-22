#include <iostream>
#include "my_cool_library.hpp"
// without the include guard, 
// everything from my_cool_library.hpp will be blindly pasted in again
#include "my_cool_library.hpp"

int main(int argc, char** argv) {
    std::cout<< MyCoolLibrary::MY_COOL_CONSTANT << std::endl;
    std::cout<< MyCoolLibrary::my_cool_library_function() << std::endl;
    return 0;
}