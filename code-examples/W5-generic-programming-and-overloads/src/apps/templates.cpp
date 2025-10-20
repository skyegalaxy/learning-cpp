#include "templates.hpp"

using std::cout;
using std::endl;

int main(int argc, char** argv) 
{
    // explicitly telling the compiler
    // to use the int version
    // (needed pre-CTAD, introduced in C++17)

    // instantiates and calls max<int>(int, int)
    cout << max<int>(12, 5) << endl;

    // Class Template Argument Deduction 
    // allows the compiler to determine 
    // what type the template is

    // instantiates and calls max<double>(double, double)
    cout << max(1.4, 6.2) << endl; 

    // Uses the already instantiated definition max<int>(int, int)
    cout << max(1, 64) << endl; 

    // instantiates and calls max<unsigned>(unsigned, unsigned)
    cout << max<>(6U, 49U) << endl; 

    // instantiates and calls max<char>(char, char)
    cout << max('b', 'a') << endl; 

    // this particular set of types is a bad idea for this example
    cout << max<int, unsigned int>(-5, 4) << endl; 

    print(42);
    print("secrets");
    print(9 + 10 == 21);

    return 0;
}