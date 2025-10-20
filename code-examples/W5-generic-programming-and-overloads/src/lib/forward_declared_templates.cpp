#include "forward_declared_templates.hpp"

template<typename T>
T mul(T a, T b) {
    return a * b;
}

// explicit instantiations of mul for int and float.
// if our template definition is in a .cpp file,
// we'll have to do this for every type we intend to use it with
template int mul(int a, int b);
template float mul(float a, float b);
