#include <iostream>
#include <string> 
// "::" - the Scope Resolution operator
// Reference objects and variables within namespaces, structs, classes, etc

using std::cout;
using std::endl;


namespace MyCoolNamespace {
    int a{42};

    namespace MyNestedNamespace {
        std::string a {"forty two"};
    } // namespace MyNestedNamespace

} // namespace MyCoolNamespace

namespace MyOtherNamespace {
    short a {420};

} // namespace MyOtherNamespace

int main(int argc, char** argv) {
    
    cout << MyCoolNamespace::a << endl;
    cout << MyCoolNamespace::MyNestedNamespace::a <<endl;
    cout << MyOtherNamespace::a <<endl;

    {
        // this a will go out of scope and be destroyed
        // once the flow of execution exits these curly brackets.
        double a = 0.420;
    }
    //cout << a << endl; // won't compile. a went out of scope

    // The following is a demonstration of why it's a bad idea to do "using namespace"
    // instead of "using Namespace::ThingIWant"
    using namespace MyCoolNamespace;
    using namespace MyCoolNamespace::MyNestedNamespace;
    using namespace MyOtherNamespace;

    //cout << a << endl; // won't compile. a is ambiguous.

    // Now let's declare a variable, but not initialize it.
    int b;
    cout << b << endl; // compiles, but technically undefined behavior since b was never initialized

    return 0;
}