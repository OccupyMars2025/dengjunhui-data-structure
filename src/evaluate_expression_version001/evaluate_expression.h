#pragma once
// #pragma warning(disable : 4996)

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <map>


#include "UniPrint/print.h"
#include "Stack/Stack.h" //使用栈


void generate_expression(std::string& expression, int& current_num_of_additions, int max_num_of_additions,   
    int& current_parentheses_depth, int max_parentheses_depth);
bool is_operator(char c);
int compare_precedence(char op1, char op2);
double evaluate_expression(const std::string& expression);