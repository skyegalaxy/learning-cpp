#pragma once
#include <iostream>


using std::cout;
using std::endl;

/*
// this whole pattern kind of sucks, doesn't it?
+
int max(int a, int b) {
    return (a > b) ? a : b;
}

double max(double a, double b) {
    return (a > b ? a : b);
}

// If only we could write one function to use with both types...
// Oh wait, we totally can!
*/

template<typename T> // template parameter declaration.
// defines T as a type template parameter.
T max (T a, T b) { // function template definition for max<T>
    return (a > b) ? a : b;
}

// We can also have templates with multiple types.
// In this example, because we would return one of two types
// we declare 'auto' as the return type to avoid narrowing conversions
template <typename T1, typename T2>
auto max(T1 a, T2 b) {
    return (a > b) ? a : b;
}


/*
C++20 introduced abbreviated function templates

e.g. 

auto max(auto a, auto b) {
    return (a > b) ? a : b;
}

is shorthand for the above function C++20 onwards
*/

template<typename T>
void print(T thing) {
    cout << thing << endl;
}

// template specialization of print() with type bool
template<> 
void print(bool thing) {
    cout << std::boolalpha << thing << endl;
}

// We can also use delete
// to prevent our template from being called with a specific type
template<>
void print(void* random_data) = delete;