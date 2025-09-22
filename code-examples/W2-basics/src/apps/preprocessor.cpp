// The preprocessor is a simple text search and replace system
// that runs before any code is compiled.

//include is also a preprocessor directive
#include <iostream>

// provides a way to define constants
#define PI 3.141526

// We can also define string literals this way
#define DONT_WRITE_STRINGS_LIKE_THIS "technically a string" 

// you can pass arguments to preprocessor macros
#define PRINT_TWO_ARGS(a, b) std::cout<< a << b << std::endl


#define PREPROC_FLAG // this boolean flag is now visible the preprocessor
#undef PREPROC_FLAG

#ifdef PREPROC_FLAG // compiles only if PREPROC_FLAG is defined
int a{53};
#endif

#ifndef PREPROC_FLAG // compiles only if PREPROC_FLAG is NOT defined
double a{678910.12345};
#endif


int main(int argc, char** argv) {
    std::cout << a << std::endl;
    std::cout << DONT_WRITE_STRINGS_LIKE_THIS << std::endl;

    // this code won't compile at all because the macro will always be false
    #if 0
    int* uninitialized_ptr;
    int& segfault_causer = *uninitialized_ptr;
    std::cout << segfault_causer << std::endl;
    #endif

    return 0;
}


