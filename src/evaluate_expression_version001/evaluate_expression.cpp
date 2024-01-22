#include "evaluate_expression/evaluate_expression.h"

/*
no space exists in the generated expression

TODO: make the generated expression more complex

this function is ugly !
*/
void generate_expression(std::string& expression, int& current_num_of_additions, int max_num_of_additions,   
    int& current_parentheses_depth, int max_parentheses_depth){
    static std::string operators_string = "+-*/";
    static int num_of_operators = operators_string.length();

    for(int i = 0; i < 2; ++i) {
    if(rand() % 100 < 50) {
        // add a pair of parentheses
        if(0 < current_num_of_additions && expression[expression.length() - 1] != '(') {
            // now expression[-1] is "part of a number" or ')'
            expression.push_back(operators_string[rand() % num_of_operators]);
        }
        expression.push_back('(');
        ++current_num_of_additions;
        ++current_parentheses_depth;
        if(rand() % 2 == 0 && current_parentheses_depth < max_parentheses_depth && current_num_of_additions < max_num_of_additions) {
            generate_expression(expression, current_num_of_additions, max_num_of_additions, current_parentheses_depth, max_parentheses_depth);
        } else {
            for(int i = 0; i < rand() % 10 + 1; ++i) {
                expression.append(std::to_string((rand()%100)/10.0));
                expression.push_back(operators_string[rand() % num_of_operators]);
                expression.append(std::to_string((rand()%100)/10.0));
            }
        }
        
        --current_parentheses_depth;
        expression.push_back(')');
    } else {
        if(0 == current_num_of_additions || expression[expression.length() - 1] == '(') {
            expression.append(std::to_string((rand()%100)/10.0));
            ++current_num_of_additions;
        }
        for(int i = 0; i < rand() % 10 + 1; ++i) {
            ++current_num_of_additions;
            expression.push_back(operators_string[rand() % num_of_operators]);
            expression.append(std::to_string((rand()%100)/10.0));
        }
        if(rand() % 2 == 1) {
            generate_expression(expression, current_num_of_additions, max_num_of_additions, current_parentheses_depth, max_parentheses_depth);
        }
    }
    }
}


bool is_operator(char c) {
    return ('+' == c || '-' == c || '*' == c || '/' == c || '(' == c || ')' == c);
}

int compare_precedence(char op1, char op2) {
    static std::map<char, int> op_to_index = {
        {'+', 0},
        {'-', 1},
        {'*', 2},
        {'/', 3},
        {'(', 4},
        {')', 5}
    };
    static int precedences[5][6] = {
        {1, 1, -1, -1, -1, 1},
        {1, 1, -1, -1, -1, 1},
        {1, 1,  1,  1, -1, 1},
        {1, 1,  1,  1, -1, 1},
        {-1, -1, -1, -1, -1, 0}
    };

    return precedences[op_to_index[op1]][op_to_index[op2]];
}

double evaluate_expression(const std::string& expression) {
    int length = expression.length();

    int i = 0;
    Stack<char> operator_stack;
    Stack<double> operand_stack;
    std::string num_string;
    while (i < length)
    {
        if(isdigit(expression[i]) || ('.' == expression[i])) {
            num_string.clear();
            do
            {
                num_string.push_back(expression[i]);
                ++i;
            } while ((i < length) && (isdigit(expression[i]) || ('.' == expression[i])));  
            operand_stack.push(std::stod(num_string));          
        } else if(is_operator(expression[i])) {
            if('(' == expression[i]) {
                operator_stack.push('(');
                ++i;
                continue;
            }

            while ((operator_stack.size() > 0)
                && (compare_precedence(operator_stack.top(), expression[i]) > 0))
            {
                char op = operator_stack.pop();
                assert(operand_stack.size() >= 2);
                double x2 = operand_stack.pop();
                double x1 = operand_stack.pop();
                switch (op)
                {
                case '+':
                    operand_stack.push(x1 + x2);
                    break;

                case '-':
                    operand_stack.push(x1 - x2);
                    break;

                case '*':
                    operand_stack.push(x1 * x2);
                    break;

                case '/':
                    operand_stack.push(x1 / x2);
                    break;
                
                default:
                    assert(0);
                    break;
                }
            }
            if(')' == expression[i]) {
                assert(operator_stack.size() > 0);
                char c = operator_stack.pop();
                assert('(' == c);
            } else {
                operator_stack.push(expression[i]);
            }
            ++i;
        } else {
            assert(' ' == expression[i]);
            ++i;
        }
    }

    /*
    The following part is ugly, 
    Can't we squeeze the following part into the above "while" loop ?
    How to handle it elegantly ?
    */
    int num_of_remaining_operators = operator_stack.size();
    assert(num_of_remaining_operators == 0 || num_of_remaining_operators == 1 || num_of_remaining_operators == 2);
    if(num_of_remaining_operators > 0) {
        while (operator_stack.size() > 0)
        {
            char op = operator_stack.pop();
            assert(operand_stack.size() >= 2);
            double x2 = operand_stack.pop();
            double x1 = operand_stack.pop();
            switch (op)
            {
            case '+':
                operand_stack.push(x1 + x2);
                break;

            case '-':
                operand_stack.push(x1 - x2);
                break;

            case '*':
                operand_stack.push(x1 * x2);
                break;

            case '/':
                operand_stack.push(x1 / x2);
                break;
            
            default:
                assert(0);
                break;
            }
        }
    }
    
    assert(operand_stack.size() == 1);
    return operand_stack.pop();
}