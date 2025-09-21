// This is a comment. 

/*
    This is a multi-line comment.
*/

#include <iostream>
#include <limits>  // numeric limits of types
#include <cstdint> // for fixed width integer types

// I'm lazy and don't wanna write std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), etc
// for all the following examples, so if you're a fan of the whole brevity thing, 
// the 'using' keyword can come in handy for type aliasing. See the scope example for more.
using i_limits = std::numeric_limits<signed int>;
using ui_limits = std::numeric_limits<unsigned int>;
using short_limits = std::numeric_limits<short>;
using ushort_limits = std::numeric_limits<unsigned short>;
using long_limits = std::numeric_limits<long>;
using ulong_limits = std::numeric_limits<unsigned long>;
using long_long_limits = std::numeric_limits<long long>;
using ulong_long_limits = std::numeric_limits<unsigned long long>;

using float_limits = std::numeric_limits<float>;
using double_limits = std::numeric_limits<double>;
using long_double_limits = std::numeric_limits<long double>;

using char_limits = std::numeric_limits<char>;
using uchar_limits = std::numeric_limits<unsigned char>;

int main(int argc, char** argv) {

    // Integer types
    int a = -42; // The default integer is signed and guaranteed to be at least 16 bits. 
                // On 32 or 64 bit systems, guaranteed to be at least 32 bits.

    unsigned int b = 8675309; // Unsigned: never less than zero.

    short int this_will_overflow = 32768;

    // for short int and long int, you don't actually need to specify "int"
    short this_wont_overflow = -32768; 
    std::cout<<this_will_overflow<<", "<<this_wont_overflow<<std::endl;

    // Starting in C++11, you can use fixed width types (they're just type aliases)
    int16_t some_fixed_width_int = 69;
    uint64_t some_other_fixed_width_int = 12345678910;

    // Hilariously, int8_t and uint8_t are actually just an alias for char and unsigned char. 
    // The compiler will let you just get away with the following.
    uint8_t some_fixed_width_char = 69;

    std::cout<<some_fixed_width_char<<", "<<some_fixed_width_int<<", "<<some_other_fixed_width_int<<std::endl;

    std::cout << "default int ranges from: " <<
        i_limits::min() << " to " << i_limits::max() << std::endl;

    std::cout << "unsigned int ranges from: " <<
        ui_limits::min() << " to " << ui_limits::max() << std::endl;

    std::cout << "short int ranges from: " <<
        short_limits::min() << " to " << short_limits::max() << std::endl;

    std::cout << "unsigned short int ranges from: " <<
        ushort_limits::min() << " to " << ushort_limits::max() << std::endl;

    std::cout << "long int ranges from: " <<
        long_limits::min() << " to " << long_limits::max() << std::endl;

    std::cout << "unsigned long int ranges from: " <<
        ulong_limits::min() << " to " << ulong_limits::max() << std::endl;

    std::cout << "long long int ranges from: " <<
        long_long_limits::min() << " to " << long_long_limits::max() << std::endl;

    std::cout << "unsigned long long int ranges from: " <<
        ulong_long_limits::min() << " to " << ulong_long_limits::max() << std::endl;

    // Floating point types
    std::cout << "float ranges from: " <<
        float_limits::min() << " to " << float_limits::max() << std::endl;

    std::cout << "double ranges from: " <<
        double_limits::min() << " to " << double_limits::max() << std::endl;

    std::cout << "long double ranges from: " <<
        long_double_limits::min() << " to " << long_double_limits::max() << std::endl;

    // Character types
    std::cout << "char ranges from: " <<
        char_limits::min() << " to " << char_limits::max() << " - (" <<
        static_cast<int>(char_limits::min()) << " to " <<static_cast<int>(char_limits::max()) << 
        ")" << std::endl;
    std::cout << "unsigned char ranges from: " <<
        uchar_limits::min() << " to " << uchar_limits::max() << " - (" <<
        static_cast<int>(uchar_limits::min()) << " to " <<static_cast<int>(uchar_limits::max()) << 
        ")" << std::endl;

    int some_number;
    //double some_number = 8.76; // won't compile. some_number was first defined as an int

    return 0;
}