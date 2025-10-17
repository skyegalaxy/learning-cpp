#include <iostream>
#include <string> 
#include <unordered_map>
#include <array>
#include <chrono>
#include <functional>

using std::cout;
using std::endl;
using std::string_literals::operator""s; 

struct MyCoolStruct {
    int n;
    std::string s;
};

void all_about_const()
{
    // Variables can be declared immutable with the 'const' keyword.
    // Values can be determined either at compile-time or runtime, 
    // depending on if the value is a constant expression
    // or returned from a function.

    // Values declared const are stored in the executable.

    const double PI = 3.1415926;
    //PI = 3.15; // won't compile, PI declared const

    const int random_number = rand(); // determined at runtime

    const MyCoolStruct s {100, "gecs"};

    int val = 27;
    int val2 = 95;

    // Const reference, rudimentary example
    const double& pi_ref = PI;

    // pointer to a const int. 
    // The pointer can point elsewhere, 
    // but the data it points to can't be modified
    const int* ptr2const = &random_number; 
    ptr2const = &val2; 
    // *ptr2const = 4;

    // const pointer to an int. 
    // the pointer can't point elsewhere, 
    // but the data it points to can be modified
    int* const constptr = &val;
    // constptr = &val2;
    *constptr = 5;


    // When iterating through containers, 
    // it's best practice to use const references
    // if you don't need to modify the underlying data.
    std::unordered_map<std::string, unsigned int> some_hashmap {
        {"foo", 81},
        {"abc", 123},
        {"I love strings", 9999999}
    };

    for (const auto& it : some_hashmap) { // range based for loop, using an unordered map iterator
        cout << it.first << ", " << it.second << endl;
    }

    for (const auto& [s, n] : some_hashmap) { // structured binding syntax - new in C++17
        cout << s << ", " << n << endl;
    }

}

// From now on, most of the time we'll end up using const references
// unless you explicitly want to modify the value in place,
// or pass a copy to a function
void my_cool_function(const MyCoolStruct& my_struct) {
    // my_struct.n = 45; // won't compile, my_struct is a const reference
}

// fib can evaluate either at compile time or runtime.
constexpr long fib(long n) {
    return (n < 2) ? 1 : fib(n-1) + fib(n-2);
}

constexpr int mul (int a, int b) {
    return a * b;
}

struct MyCustomPoint2iStruct {
    int m_x {};
    int m_y {};
};


void intro_to_constexpr()
{
    // The constexpr keyword declares that an expression can be evaluated at compile-time,
    // or before the program is ever executed.
    constexpr double TWO_PI = 6.28318530718;

    // Functions declared as constexpr can be evaluated at compile time.
    // This can be incredibly useful for both offloading computations to the compiler
    // and saving CPU cycles during runtime.
    // We can see an example of this in action by using our constexpr fib function.
    using namespace std::chrono;

    auto constexpr_start = high_resolution_clock::now();
    constexpr long compiletime_fib_result = fib(24); // 24 is a constant literal, so fib will evaluate during compile-time here.
    auto constexpr_stop = high_resolution_clock::now();
    auto constexpr_duration = duration_cast<nanoseconds> (constexpr_stop - constexpr_start);

    auto nonconstexpr_start = high_resolution_clock::now();
    long a {24}; 
    const long runtime_fib_result = fib(a); // a was not declared constexpr, so fib will execute at runtime here
    auto nonconstexpr_stop = high_resolution_clock::now();
    auto nonconstexpr_duration = duration_cast<nanoseconds> (nonconstexpr_stop - nonconstexpr_start);

    cout << "nanoseconds took to calculate fib(24) (" << compiletime_fib_result << ") during compile-time: " << constexpr_duration.count() << endl;
    cout << "nanoseconds took to calculate fib(24) (" << runtime_fib_result << ") during runtime: " << nonconstexpr_duration.count() << endl;

    // Functions that evaluate at compile-time are also great
    // for initializing objects whose size must be known at compile time.
    constexpr std::array<int, mul(3, 4)> my_arr {1, 2, 3, 4, 5};
    
    // Struct aggregates and classes with only constexpr constructors and member methods
    // can also be evaluated at compile-time.
    constexpr MyCustomPoint2iStruct p1 {12, 4};
}

int main(int argc, char** argv) 
{

    all_about_const();
    intro_to_constexpr();

    return 0;
}