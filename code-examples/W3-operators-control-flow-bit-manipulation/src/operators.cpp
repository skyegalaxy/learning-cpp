#include <iostream>

using std::cout;
using std::endl;

// assign values to variables
void assignment_operator() 
{
    int a, b;
    a = 10;           // a:10, b:?
    b = 4;            // a:10, b:4
    a = b;            // a:4,  b:4
    b = 7;            // a:4,  b:7
    cout << "a: " << a << ", b: " << b << endl;

    int x;
    // assignment operations are expressions that can be evaluated.
    // for the fundamental types, this evaluates to the one assigned in the operation.
    int y = 2 * (x = 5); 

    cout << "y = " << y << endl;
}

// Basic maths
void arithmetic_operators() 
{
    unsigned short x = 9000 + 1;
    int y = 4 - 86;
    float z = 56.71 * 100;
    double w = x / z;
    bool is_even = (x % 2) == 0;
}

// inplace modification of variables
void compound_assignment() 
{
    int x{5};
    x += 4;  // equivalent to x = x + 4
    x-=2;    //               x = x - 5
    x*= 780; //               x = x * 780;
    x /= 3;  //               x = x / 3;

    x++; // suffix increment
    --x; // prefix increment

    int prefix_x = 4;
    int suffix_x = prefix_x;

    int prefix_y = ++prefix_x; // prefix_x = 4, prefix_y = 4
    int suffix_y = suffix_x++; // prefix_x = 4, prefix_y = 3
}

// compare two expressions
void compare(int a, int b) 
{
    cout
      << a << " equals " << b <<": " << (a == b) << endl
      << a << " does not equal "<< b <<": " << (a != b) << endl
      << a << " greater than "<< b <<": "<< (a > b) << endl
      << a << " greater than or equal to "<< b <<": " << (a >= b) << endl
      << a << " less than "<< b <<": "<< (a < b) << endl;
}

int main(int argc, char** argv) 
{
    assignment_operator();
    arithmetic_operators();
    compound_assignment();
    
    compare(1, 2);
    compare(6, 6);
    compare(-4, 1);

    return 0;
}