#include <iostream>
#include <cstring>
#include <functional>
#include <cstdint>
#include <typeinfo>

using std::cout; 
using std::endl;

void raw_bit_copy_without_conversion()
{
    int n{51};
    float f;
    // The bits from n are copied into f,
    // but the underlying bit representation of float differs from int,
    // so the code is certainly not gonna display "51"
    std::memcpy(&f, &n, sizeof(float));
    cout << "float memcpy'd over to an int: " << f << endl;
}

void implicit_conversions()
{
    double d{3}; // implicitly converts integer literal 3 to a double
    d = 6; // implicitly converts integer literal 6 to a doubles

    
    std::function<float()>some_fn([] {
        return 3.00000001; // double literal implicitly converted to float
    });

    float f = some_fn(); 
    std::cout<<f<<std::endl;

    // integer values converted to a boolean
    if (17) {
        cout << "integers that are nonzero are implicitly \"true\""<<endl;
    }
    if (0) {
        cout << "this code shouldn't be reached" << endl;
    }

    std::function<void(const long)>some_other_fn([](const long n) {});

    int a = 4;
    some_other_fn(a); // int implicitly converted to long

    // int bad_convert{"26"}; // won't compile. can't convert const char to int
}   

void explicit_conversions()
{
    // old way, C Style cast
    double a = (double)42;
    // alternate "function style" cast
    double b = double(42); 

    // Modern way, static_cast (preferred way in C++)
    double c = static_cast<double>(42);

    // Reinterpret cast is primarily used to convert pointer types.
    int n {51};

    // We create a pointer to a float, and store the address of d (an integer),
    // but converted as if it were a pointer to a float.
    // You'll notice this yields the same result as our memcpy example from earlier.
    // Reinterpret cast can introduce undefined behavior and should be avoided whenever possible.
    float* f = reinterpret_cast<float*>(&n);
    cout << "pointer to int reinterpret_casted as a pointer to float: " << *f << endl;
}

float fast_inv_sqrt(float x, int num_gauss_newton_iterations = 1)
{
    float y = x; // current guess y = sqrt(x)
    uint32_t* i = reinterpret_cast<uint32_t*>(&y); // i points to current guess y, interpreted as uint32

    constexpr uint32_t exp_mask = 0x7F800000; // 0xFF<<23
    constexpr uint32_t magic_number = 0x5f000000; // 190<<23

    // initial guess using magic number
    *i = magic_number - ((*i >> 1) & exp_mask);

    // refine guess using some Newton iterations
    for (size_t i = 0; i < num_gauss_newton_iterations; ++i)
    {
        y = (x * y * y + 1) / (2 * x * y);
    }

    return y;
}

// note for the future: 
// isn't it silly how we're having to define
// a different print function for each type?
void print_integer(int i) 
{
    cout << i << endl;
}

void print_double(double d) 
{
    cout << d << endl;
}

void numeric_promotions()
{
    short s{12};
    print_integer(s); // numeric promotion of short to int
    print_integer('a'); // numeric promotion of char to int

    // "true" will convert to 1 when promoted to an int
    // whereas "false" converts to 0
    print_integer(true); 

    print_double(8.6f); // float literal promoted to double
    print_double(96.523124321);
}

void narrowing_conversions()
{
    double d{3.1415};
    print_integer(d); // compiler warning: implicit narrowing conversion
    print_integer(static_cast<int>(d)); // explicitly narrowing, so no compiler warning

    // Some constexpr conversions aren't considered narrowing by the compiler.
    // Since constexpr asserts that a value is known at compile time, 
    // we won't get compiler errors so long as the source value is preserved.
    constexpr int n1{ 5 };
    unsigned int u1 { n1 };

    constexpr int n2 { -5 };
    // unsigned int u2 { n2 };  // won't compile. sign is not preserved

    // int a {3.1415}; // won't compile. brace initialization won't allow narrowing conversion

    // Strangely, narrowing a constexpr floating point type
    // is not technically considered narrowing by the compiler,
    // even when there's loss of precision.
    constexpr double my_extremely_precise_number {0.426421124085756};
    float totally_not_narrowing{my_extremely_precise_number};
    cout << totally_not_narrowing << endl;
}

void arithmetic_conversions()
{ 
    // Certain operators require both operands to have the same type.
    // if we invoke one of them with operands of different types, 
    // one of the operands will be implicitly converted to match 
    // using a set of rules called the usual arithmetic conversions.
    
    int my_int{2};
    double my_double{3.5};
    cout << "Types for my_int and my_double: " << endl;
    cout << typeid(my_int).name()<< ", " << typeid(my_double).name() << endl;

    // The above code should print out 'i, d' (for integer and double)
    // but what about the following expression? 
    auto sum = my_int + my_double;
    cout << typeid(sum).name() << ' ' << sum << endl; 

    // Short is not on the priority list for operator+, 
    // so both operands get promoted to int.
    short l {9};
    short r {10};

    cout << typeid(l + r).name() << endl;

    // Things start to get weird when we throw signedness into the mix.
    // -3 is promoted to an unsigned that's larger than 5
    cout << std::boolalpha << (-3 < 5u) << endl; 
}

int main(int argc, char** argv) 
{
    raw_bit_copy_without_conversion();
    implicit_conversions();
    explicit_conversions();
    numeric_promotions();
    narrowing_conversions();
    arithmetic_conversions();
    return 0;
}