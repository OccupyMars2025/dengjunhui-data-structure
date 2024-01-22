
#include <iostream>
#include <cassert>
#include <cmath>
#include <map>
#include "evaluate_expression_version002/evaluate_expression.h"
#include "UniPrint/print.h"
#include "Stack/Stack.h"


void remove_space(char *expression) {
    for(char *p1 = expression - 1, *p2 = expression; (p1 < expression) || (*p1); ++p2) {
        while (isspace(*p2))
        {
            ++p2;
        }
        *++p1 = *p2;
    }
}

char compare_precedence(char op1, char op2) {
    static const int num_operators = 9;
    static std::map<char, int> char_to_index = {
        {'+', 0}, {'-', 1}, {'*', 2}, {'/', 3},
        {'^', 4}, {'!', 5}, {'(', 6}, {')', 7}, 
        {'\0', 8}
    };

    static const char precedences[num_operators][num_operators] = {
              /* +    -    *    /    ^    !    (    )    \0  */
        /* + */{'>', '>', '<', '<', '<', '<', '<', '>', '>'},
        /* - */{'>', '>', '<', '<', '<', '<', '<', '>', '>'},
        /* * */{'>', '>', '>', '>', '<', '<', '<', '>', '>'},
        /* / */{'>', '>', '>', '>', '<', '<', '<', '>', '>'},
        /* ^ */{'>', '>', '>', '>', '>', '<', '<', '>', '>'},
        /* ! */{'>', '>', '>', '>', '>', '>', '<', '>', '>'},
        /* ( */{'<', '<', '<', '<', '<', '<', '<', '=', ' '},
        /* ) */{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        /* \0*/{'<', '<', '<', '<', '<', '<', '<', ' ', '='},
    };

    return precedences[char_to_index[op1]][char_to_index[op2]];
}

/*
it will increase the pointer to point to the next non-digit
*/
double read_number(char *&expression, std::string &num_string) {
    while (isdigit(*expression) || ('.' == (*expression)))
    {
        num_string.push_back(*expression);
        ++expression;
    }
    return std::stod(num_string);
}


/*
 unary operator, 
currently only support '!' (factorial)
*/
double calculate(char op, double x) {
    assert('!' == op);
    assert(((double)(int)x) == x);
    assert(((int)x) >= 0);
    unsigned n = (int)x;

    unsigned long result = 1;
    for(unsigned i = 2; i <= n; ++i) {
        result *= i;
    }

    return result;
}

double calculate(double x1, char op, double x2) {
    switch (op)
    {
    case '+':
        return x1 + x2;
        break;
    
    case '-':
        return x1 - x2;
        break;
        
    case '*':
        return x1 * x2;
        break;
        
    case '/':
        return x1 / x2;
        break;

    case '^':
        return std::pow(x1, x2);
        break;
    
    default:
        assert(0);
        break;
    }
}


// now "expression" has no space in it
double evaluate_expression(char* expression, std::string& rpn) {
    Stack<char> stack_for_operators;
    Stack<double> stack_for_operands;

    // '\0' works as the head sentinel
    stack_for_operators.push('\0');
    char op;
    std::string num_string;
    while (!stack_for_operators.empty())
    {
        if(isdigit(*expression) || ('.' == (*expression))) {
            num_string.clear();
            double x = read_number(expression, num_string);
            stack_for_operands.push(x);
            rpn.append(num_string);
            rpn.push_back(' ');
        } else {
            switch (compare_precedence(stack_for_operators.top(), *expression))
            {
            case '<':
                stack_for_operators.push(*expression);
                ++expression;
                break;
            
            case '=':
                stack_for_operators.pop();
                ++expression;
                break;

            case '>':
                op = stack_for_operators.pop();
                rpn.push_back(op);
                rpn.push_back(' ');
                // 1+3!+4
                if('!' == op) {
                    double x = stack_for_operands.pop();
                    stack_for_operands.push(calculate(op, x));
                } else {
                    double x2 = stack_for_operands.pop();
                    double x1 = stack_for_operands.pop();
                    stack_for_operands.push(calculate(x1, op, x2));
                }
                break;

            default:
                // the format of the expression is illegal
                assert(0);
                break;
            }
        }
    }

    /*
    if the format of the expression is legal
    */
    assert(1 == stack_for_operands.size());

    return stack_for_operands.pop();   
}