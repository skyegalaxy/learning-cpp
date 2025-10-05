#include <iostream>
#include <vector>
#include <string>
#include <random>

using std::cout;
using std::cin;
using std::endl;

void conditional_branching() 
{
    int num {};
    cout << "enter a number" << endl;
    cin >> num;

    if (num > 0) {
        cout << num << " is positive"<< endl;
    }
    else if (num < 0) {
        cout << num << " is negative"<< endl;
    }
    else {
        cout << num << " is zero"<< endl;
    }

    bool some_condition = false;

    // EITHER all statements inside the if expression
    // must be bracketed, 
    // OR the line immediately following the conditional
    // will be within the scope of the if expression.
    if (some_condition) 
        cout << "some condition has been met" << endl;
        cout << "this code will always run. This isn't python!" << endl;

    /*
    equivalent to
    if (some_condition) {
        cout << "some condition has been met"<<endl;
    }
    cout << "this code will always run. This isn't python!" << endl;
    */

    int x = 4;
    int y = 7;

    if (x >= 4) {
        cout << "we'll reach this block of code " << endl;
    }
    if (y < 8) {
        cout << "and this one too, because we didn't use else if" << endl;
    }


    // Be careful with the "=" vs "==" operators.
    // Since assignment expression returns a value,
    // the following will compile but it's not semantically what you want

    int problems = 99;
    
    if (problems = 100) {
        cout << "oh no, more problems" << endl;
    }
}

void multiple_conditionals()
{
    int x = 4;
    int y = 2;
    
    // Logical and: &&
    // Logical or: ||
    // Logical not: !
    
    // Since the first condition fails, the second one will not be checked
    if (x != 4 && y < 3) { 
        cout << "this condition" << endl;
    }
    // First condition met, but second condition fails
    if (x >= 4 && y > 4) {
        cout << "that condition" << endl;
    }
    // Both conditions met, so we'll actually execute this branch
    if (x == 4 && y == 2) {
        cout << "the other condition" << endl;
    }
    // Although the first condition fails, the second condition is true so we'll branch
    if (x == 7 || y > 1) {
        cout << "the OTHER other condition" << endl;
    }
    // You can chain multiple conditionals, use parens, etc
    if (!(x < 3) && ((y >= 2) || (x < 6))) {
        cout << "the other other Other condition" << endl;
    }
}


void ternary_operator()
{
    int x = 10, y = 19;
    int max_val = (x > y) ? x : y;

    /*
    equivalent to 
    if (x > y) {
        max_value = x;    
    } else {
        max_value = y;
    }
    */
}

void switch_statements(unsigned int num_cars)
{
    switch(num_cars)
    {
        case 0:
            cout << "lucky you, you get to bike and take transit everywhere!" << endl;
        case 1:
            cout << "yeah that's fair"
                    "especially if you have to commute a long way for work" << endl;
            break;
        case 2:
            cout << "ok I guess like maybe if you're a couple "
                    "or you need a truck for heavy lifting or something?" << endl;
            break;
        default:
            cout << "yeah you're part of the problem" << endl;
    }
}

void switch_fallthroughs() 
{
    switch (2)
    {
        case 1:
            cout << "this statement won't evaluate if num < 2" << endl;
        case 2:
            cout <<" but this one will "<< endl;
        case 3:
            cout <<" and this will " << endl;
        case 4:
            cout <<" this one too " << endl;
        case 5:
            cout <<" and this one " << endl;
    }
}


void for_loops() 
{
    // A vector is a dynamic array. 
    // We're initializing a vector containing integer types here.
    // pre-C++17: std::vector<int> arr;

    /*
    Traditional for-loop.
    for (init-statement; condition; end-expression)
    statement;
    */
    std::vector arr {-95, 612, 779, 124, -7};

    for (size_t i = 0; i < arr.size(); i++) 
    {
        cout << arr[i] << endl;
    }

    size_t j;

    for (j = arr.size(); j > 0; j--) 
    {
        cout << arr[j] << endl;
    }

    for (int num : arr) // range-based for loop.
    { 
        cout << num << endl;
    }

    // range-based for loop, with const references (avoid copy)
    for (const int& num : arr) 
    { 
        cout << num << endl;
    }

    /*
    fun fact: none of the for loop statements need to be filled in.
    for (;;) {
        cout << "infinite for loop ";
    }
    */
}

void while_loops()
{

/*
while (condition)
    statement
*/

int i = 0;
while (i < 5) {
    cout << i << endl;
    i++;
}

/*
do
{
    statement;
} 
while (condition);

condition is false from the start.
the block of code will execute at least once.
*/

i = 10;
do {
    cout << i << endl;
    i++;
}
while (i < 5);

}


void goto_hell(bool do_skip)
{
    int x{17};

    // initialize a pointer to an int, but don't give it an address
    int* y;

    if (do_skip)
        goto hell; 

    // assign y to the address of x;
    y = &x;

    hell: 
    // if y remains a null pointer, this will cause the program to crash.
    int z = *y;
    std::cout<<z<<std::endl;

    /*
    loopforever: // statement label where the goto statement will branch to
    cout << "you're stuck here forever!"<<endl;
    goto loopforever; // this is the goto statement itself
    */
}

int main(int argc, char** argv) {

    conditional_branching();
    multiple_conditionals();
    ternary_operator();
    switch_statements(2);
    switch_fallthroughs();
    for_loops();
    while_loops();
    goto_hell(false);
    return 0;
}