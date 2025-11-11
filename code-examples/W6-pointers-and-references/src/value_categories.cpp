#include <iostream> 

using std::cout;
using std::endl;

int return_an_int()
{
    return 17;
}

int main(int argc, char** argv) 
{
    // 5 is an rvalue expression
    int x{ 5 }; 

    // 1.2 is an rvalue expression
    const double d{ 1.2 }; 

    // x is a modifiable lvalue expression
    int y { x }; 

    // d is a non-modifiable lvalue expression
    const double e { d }; 

    // return_an_int() is an rvalue expression 
    // (since the result is returned by value)
    int z { return_an_int() }; 

    // x + 1 is an rvalue expression
    int w { x + 1 }; 

    // the result of static casting d to an int 
    // is an rvalue expression
    int q { static_cast<int>(d) }; 


    // y is evaluated, "converting" the lvalue to an rvalue
    x = y;

    // 9 and 10 are rvalues, operator+ returns an rvalue
    cout << 9 + 10;

    // '52' is an rvalue, not a modifiable lvalue expression
    // and assignment requires the left operand to be a modifiable lvalue
    //52 = x; 

    return 0;
}