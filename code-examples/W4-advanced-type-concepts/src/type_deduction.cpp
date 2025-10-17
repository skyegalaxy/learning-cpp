#include <iostream>
#include <typeinfo>
#include <string>
#include <memory>
#include <vector>

using std::cout;
using std::endl;
// this allows us to declare string literals with the s suffix
using std::string_literals::operator""s;


// you can use 'auto' to deduce a return type,
// but there's not a lot of good reasons to do this.
// if I were a developer using an API that had an 'auto' return type,
// and needed to dig into the code to figure out a bug I was encountering,
// I'd probably not be too happy having the return type 
// obscured down further in the function body
auto mul (int a, int b) {
    return a * b;
}

int main(int argc, char** argv) 
{
    // All objects need to be of an explicit type, 
    // however some literals have an implicitly determined type
    // depending on their format.

    // The 'auto' keyword can be used in place of a type specifier
    // to deduce the type of object from its initializer.

    // Here we'll introduce the auto keyword as well as literal suffixes.

    // Default literal values
    auto d {4.6}; // default floating point type is a double, NOT float
    auto i {46}; // int
    auto b {true}; // bool
    auto c {'^'}; // char
    auto cstr = "hi, I'm a C string!"; // const char[20]

    cout << typeid(d).name() << endl;
    cout << typeid(i).name() << endl;
    cout << typeid(b).name() << endl;
    cout << typeid(c).name() << endl;
    cout << typeid(cstr).name() << endl;

    // Literal suffixes
    auto f {6.12f}; // 'f' indicates a float literal.
    auto f2 {8.14F}; // all of these work for upper or lowercase
    auto u {192436U}; // unsigned int
    auto l {16720429612l}; // long int
    auto ll {796ll}; // long long int
    auto ull {98235454llu}; // long long unsigned int
    auto str {"hi, I'm a std::string"s}; // std::string literal. only works with the std::string_literals namespace

    cout << typeid(f).name() << endl;
    cout << typeid(f2).name() << endl;
    cout << typeid(u).name() << endl;
    cout << typeid(l).name() << endl;
    cout << typeid(ll).name() << endl;
    cout << typeid(ull).name() << endl;
    cout << typeid(str).name() << endl;

    return 0;
}