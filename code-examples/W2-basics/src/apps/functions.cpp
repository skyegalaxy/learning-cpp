#include <iostream>
#include <string>


using std::cout;
using std::endl; 

// Takes no arguments,
// returns no values
void printTheBeeMovieIntro() {
    cout << 
    "According to all known laws "
    "of aviation,"
    "there is no way a bee "
    "should be able to fly."
    "Its wings are too small to get "
    "its fat little body off the ground. "
    "The bee, of course, flies anyway "
    "because bees don't care "
    "what humans think is impossible."
    << endl;
}

// Takes two doubles (by value),
// returns an double
double add(double a, double b) {
    return a + b;
}

// from a compiler perspective, the following two statements
// will refer to *the same function* in memory
// and are not considered overloaded functions.

int mul(int a, int b); // forward declaration

int mul(int x, int y) { // implementation
    return x * y;
}


std::string this_was_undefined_behavior_pre_cpp17() {

    std::string message = "but I have heard it works even if you don't believe in it";
    // Fun fact! Until C++17, the calls to "replace" in the following expression 
    // did not have a consistent order of evaluation.
    // From C++17 on, the evaluation of function calls is sequenced relative to each other, 
    // generally resulting in FirstSecond due to operator precedence rules concerning <<
    message.replace(0, 4, "").replace(message.find("even"), 4, "only")
           .replace(message.find(" don't"), 6, "");

    // Expected: "I have heard it works only if you believe in it"
    return message;
}



int main(int argc, char** argv) {

    printTheBeeMovieIntro();

    // the function prints a string literal instead of returning a string
    // so we can't print its output.

    //cout << printTheBeeMovieIntro() << endl; // (won't compile)

    // the literals 5 and 9 will be cast to doubles
    double sum = add(5, 9);

    // we can call non-void functions without doing anything with the value
    add(100000.01, 9.43); 


    // we can't cast string literals to ints
    //double everything_nice = add ("sugar", "spice"); // (won't compile)


    int prod = mul(5, 9);



    cout<<this_was_undefined_behavior_pre_cpp17()<<endl;
    return 0;
}