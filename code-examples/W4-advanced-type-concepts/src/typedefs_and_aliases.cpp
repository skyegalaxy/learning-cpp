#include <iostream>
#include <unordered_map>
#include <utility>
#include <typeinfo>

using std::cout;
using std::endl;

// Type aliasing lets you create a shorthand for an existing type.

// This can be really convenient when you're using the same verbose type
// in multiple places and want to cut down on how much code you're writing.

// A type alias can also make the intent of your code much clearer,
// for example, geometric points in cartesian space

// 'typedef' is C's way of declaring type aliases.
// Left over in the language for compatibility reasons.

// typedef std::pair<int, int> Point2i;
using Point2i = std::pair<int, int>;

// They have largely been replaced with the 'using' keyword,
// and should be preferred over typedef.
using Point2f = std::pair<float, float>;
using Point2d = std::pair<double, double>;

// with typedef, FuncType is buried in the typedef and harder to read
typedef float (*FuncType)(double, std::string); 

// using makes FuncType much clearer
using FuncType = float(*)(double, std::string);

// you can also create composite type aliases using other type aliases.
using StringToPointMap = std::unordered_map<std::string, Point2d>;

int main(int argc, char** argv) 
{
    std::unordered_map<std::string, std::pair<double, double>> house_locations {
        {"living_room", {2.3, 5.6}},
        {"bathroom", {4.1, 4.62}},
        {"bedroom", {8.4, 9.172}},
    };

    StringToPointMap city_locations {
        {"downtown", {81.6, 20.9}},
        {"city_hall", {17.99, 0.3}},
        {"market", {46.2, 2.773}},
        {"train_station", {36.4, 7.09}}
    };

    // These should show the same type.
    cout << typeid(house_locations).name() << endl;
    cout << typeid(city_locations).name() << endl;

    return 0;
}