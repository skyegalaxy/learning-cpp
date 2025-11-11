#include <iostream>
#include <cstddef> // for NULL
#include <vector>
#include <optional> // for std::optional (C++17)

using std::cout;
using std::endl;


struct MyInputData {
    int n;
    uint8_t* buff;
};

struct MyOutputData {

    std::string result;
};


bool could_fail(const MyInputData& in) {
    return false;
}

bool some_operation_that_can_fail(const MyInputData& in, MyOutputData& out) {

    if (could_fail(in)) {
        out = MyOutputData();
        return true;
    }

    return false;
}

std::optional<MyOutputData> some_operation_that_can_fail(const MyInputData& in) {

    if (could_fail(in)) {
        return MyOutputData();
    }

    return std::nullopt;
}

template<typename T>
void print_something_that_might_not_exist(std::optional<const T> obj = std::nullopt) {
    if (obj.has_value()) {
        cout << *obj << endl;
    } else {
        cout <<"obj is null" << endl;
    }
}


// calling on a vector results in a copy
void print_value(std::vector<int> vec) {
    for (const auto& e : vec) {
        cout << e << endl;
    }
}    // vec is destroyed here

// no copy created, underlying object is referenced
// (can't be called on const refs)
void print_by_addr(std::vector<int>* vec) {

    if (!vec) {
        return;
    }

    for (const auto& e : *vec) {
        cout << e << endl;
    }
    // Warning! by passing as a non-const address, 
    // the underlying object can be mutated 
    // if it wasn't declared const
    vec->emplace_back(35);
}

// no copy created, underlying object is referenced
// and immutable (since we pass as a const ptr)
void print_by_const_addr(const std::vector<int>* vec) {

    if (!vec) {
        return;
    }

    for (const auto& e : *vec) {
        cout << e << endl;
    }
    //vec.emplace_back(35); // invalid, vec is a const ptr
}

int main(int argc, char** argv) 
{

    int my_int {31};

    // we initialize ptr_to_int by getting the address of my_int 
    // (with operator&)
    int* ptr_to_int = &my_int;

    cout << my_int <<" lives at address "<< std::hex << ptr_to_int << endl;



    int x{5};

     // an uninitialized pointer (holds a garbage address)
    int* ptr;       
     // a null pointer
    int* ptr2{};
    // a pointer initialized with the address of variable x
    int* ptr3{&x}; 


    // Outdated pointer literals
    if (ptr2 == NULL) {
        cout << "ptr2 is null" << endl;
    }
    if (ptr2 == 0) {
        cout << "ptr2 is null" << endl;
    }

    // Modern C++ way of checking pointer validity
    if (!ptr2) {
        cout << "ptr2 is null" << endl;
    }
    if (ptr2 == nullptr) {
        cout << "ptr2 is null" << endl;
    }


    int val {99999};
    int val2 {702425};
    // pointer to a const int. 
    // The pointer can point elsewhere, 
    // but the data it points to can't be modified
    const int* ptr2const = &val; 
    ptr2const = &val2; 
    // *ptr2const = 4;

    // const pointer to an int. 
    // the pointer can't point elsewhere, 
    // but the data it points to can be modified
    int* const constptr = &val;
    // constptr = &val2;
    *constptr = 5;

    return 0;
}