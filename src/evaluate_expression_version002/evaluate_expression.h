#pragma once

#include <iostream>
#include <cassert>
#include <cmath>
#include <map>


void remove_space(char *expression);
char compare_precedence(char op1, char op2);
double read_number(char *&expression, std::string &num_string);
double calculate(char op, double x);
double calculate(double x1, char op, double x2);
double evaluate_expression(char* expression, std::string& rpn);