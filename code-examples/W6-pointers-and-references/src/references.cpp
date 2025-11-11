#include <iostream>
#include <vector>
#include <string>


using std::cout;
using std::endl;


// we can return by const or non-const reference,
// but the object it refers to must exist after the function returns.
const std::string& get_program_name() {
    // only initialized once, then reused on consecutive function calls
    static const std::string program_name{"references"}; 
    return program_name;
}

// In general, non-const static local variables returned by reference
// are not idiomatic and should be avoided.
int& get_next_id() {
    static int id_x {0};
    ++id_x;
    return id_x;
}

// It's generally okay to return reference parameters by reference
const std::string& first_alphabetical(const std::string& a, const std::string& b) {
    // We can use operator< on std::string to determine which comes first alphabetically
	return (a < b) ? a : b; 
}


// calling on a vector results in a copy
void print_value(std::vector<int> vec) {
    for (const auto& e : vec) {
        cout << e << endl;
    }
}    // vec is destroyed here

// no copy created, underlying object is referenced
// (can't be called on const refs)
void print_ref(std::vector<int>& vec) {
    for (const auto& e : vec) {
        cout << e << endl;
    }
    // Warning! by passing as a non-const ref, 
    // the underlying object can be mutated 
    // if it wasn't declared const
    vec.emplace_back(35);
}

// no copy created, underlying object is referenced
// and immutable (since we pass as a const reference)
void print_const_ref(const std::vector<int>& vec) {
    for (const auto& e : vec) {
        cout << e << endl;
    }
    //vec.emplace_back(35); // invalid, vec is a const ref
}

int main(int argc, char** argv) 
{
    // normal int
    int a {4}; 

    // non-const reference to int.
    int& aref(a);

    // should print "4, 4"
    cout << a << ", " << aref << endl;

    a = 3;
    // should print "3, 3"
    cout << a << ", " << aref << endl;

    // operations on the reference apply to the object being referenced.
    aref = 126;

    // should print "126, 126"
    cout << a << ", " << aref << endl;

    // invalid: references must always be initialized
    //int& uninitialized_ref; 

    // valid: lvalue reference to a const int.
    const int& caref {a}; 

    // invalid: can't modify a reference to const
    //caref = 12; 

    const int MY_CONSTANT {42};

    // invalid: non-const references can only be bound to mutable values
    //int& non_const_ref{MY_CONSTANT}; 


    int xx {42};

    // invalid: can't convert from int to double&
    //double& xref {xx}; 

    int x { 5 };
    int y { 6 };

    // ref is now an alias for x
    int& ref { x }; 

    // assigns 6 (the value of y) to x (the object being referenced by ref)
    // This does NOT change ref into a reference to variable y!
    ref = y; 
    cout << x << endl; // user is expecting this to print 5

    int q {5};
    {
        int& r {q};
    } // r dies here, q is unaware


    return 0;
}