#include <iostream>

using std::cout;
using std::endl;

int add (int a, int b) {
    return a + b;
}

double add (double a, double b) {
    return a + b;
}

/*
double add (double a, double b, double c = 14.5) {
    return a + b + c;
}
*/

void print_int(int x) 
{
    cout << x << endl;
}

// We can mark certain function calls as "deleted"
// so a compiler error happens when called with the specific type.
void print_int(char) = delete;
void print_int(bool) = delete;

void foo(int a) {}
void foo(double a) {}


// A bit more about default args:
// every parameter to the right of the first default argument must have default arguments
// no syntax yet to support explicitly passing overridden values while leaving args to the left default
// e.g. for some function with signature

void some_func(int x = 4, int y = 6, int z = 10) {}

// there's no way to do
// some_func(,,4)
// default args cannot be redeclared
// default args must be declared before use (put it in the forward declaration)


// int add(int x = 0, int y, int z); // not allowed

int add(int a, int b = 4);
// not allowed: redefinition of default arg b
//int add(int a, int b = 17); 

int main(int argc, char** argv) 
{
    //some_func(,,42);
    // add (1.4, 5.7);

    //foo(16L); // ambiguous conversion from long int to either double or int
    print_int(12);
    //print_int('a');
    //print_int(false);

    return 0;
}