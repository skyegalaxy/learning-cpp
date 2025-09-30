#include <iostream>
#include <bitset>

using std::cout; 
using std::endl;

void bitwise_operators() 
{
    std::bitset<4> x {0b1100};
    // that's right, operator<< is used for both stream insertion AND left shift
    cout << (x >> 1) << endl; // shift x right by 1, yielding 0110
    cout << (x << 1) << endl; // shift x left by 1, yielding 1000
    cout << ~x << endl; // flip all bits in x

    std::bitset<4> y{0b0110};
    cout << (x & y) << endl; // each bit is set when both corresponding bits in x and y are 1
    cout << (x | y) << endl; // each bit is set when either corresponding bit in x and y is 1
    cout << (x ^ y) << endl; // each bit is set when corresponding bits in x and y differ
}

int main(int argc, char** argv) {

    bitwise_operators();
    return 0;
}