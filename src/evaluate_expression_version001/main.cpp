/*
This folder "src/evaluate_expression/"  is created by myself,
the original algorithms by professor dengjunhui is in src/rpn/
*/

#include "evaluate_expression/evaluate_expression.h"
#include <python3.10/Python.h>

int main(int argc, char const *argv[])
{    
    srand((unsigned int)time(NULL));

    std::string expression;
    int current_num_of_additions;
    int max_num_of_additions = 200; 
    int current_parentheses_depth;
    int max_parentheses_depth = 50;

    for(int i = 0; i < 100; ++i) {
        expression.clear();
        current_num_of_additions = 0;
        current_parentheses_depth = 0;

        generate_expression(expression, current_num_of_additions, max_num_of_additions,   
            current_parentheses_depth, max_parentheses_depth);
        std::cout << "len=" << expression.length() << ", expression=\"" << expression << "\"" << std::endl;
        double result = evaluate_expression(expression);
        std::cout << "result:" << result << "\n" << std::endl;
    }
    return 0;
}
