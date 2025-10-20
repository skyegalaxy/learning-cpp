#include "forward_declared_templates.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char** argv) 
{
    mul(1, 4);
    mul(2.5f, 4.6f);
    // mul wasn't instantiated for unsigned int
    //mul(5U, 7); 
    return 0;
}