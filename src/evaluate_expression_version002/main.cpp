#include <iostream>
#include <string>
#include <cstring>
#include "evaluate_expression_version002/evaluate_expression.h"


// don't use "const char *argv[]"
int main(int argc, char *argv[])
{
    if(argc < 2) {
        assert(0);
    }
    char *expression = argv[1];

    remove_space(expression);
    std::cout << "After removing space,\nlen=" << strlen(expression) << ", expression=\"" << expression << "\"" << std::endl;
    // char *rpn = new char[10 + 4 * strlen(expression)];
    std::string rpn;
    double result = evaluate_expression(expression, rpn);
    std::cout << "rpn:\"" << rpn << "\"" << std::endl << "result:" << result << std::endl;
    
    return 0;
}
