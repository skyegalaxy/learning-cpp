#pragma once
/*
For the other example, templates.hpp,
We've stuck our full function definitions inside of a .hpp file
instead of a .cpp file.

Normally, we would have forward declarations inside of a header file
and implementations inside of a .cpp file,
but templates can't be forward-declared without the applicable types being generated.

There's a fragile trick we can do to allow for spec -> hpp, impl -> cpp,
but it's not optimal
*/
template<typename T>
T mul(T a, T b);