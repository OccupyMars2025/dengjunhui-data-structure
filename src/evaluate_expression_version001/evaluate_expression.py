"""
https://www.geeksforgeeks.org/python-evaluate-expression-given-in-string/
https://realpython.com/python-eval-function/

"""

import random
import numpy as np


operators = ['+', '-', '*', '/']
operands = list(np.arange(0.5, 20, 0.5))  # Use integers from 1 to 10 as operands
expression = ""
parentheses_nest_depth = 0


def generate_one_operation_unit():
    operator = random.choice(operators)
    operand = str(random.choice(operands))
    return f"{operator}{operand}"
    
    
def generate_expression():
    """
    generate an arithmetic expression 
    which contains only binary operator and may have nested parentheses

    """
    global expression
    global parentheses_nest_depth
    for _ in range(random.randint(1, 4)): 
        # print(f"len={len(expression)}, expression=\"{expression}\"")
        # add a pair of parentheses
        if random.choice([0, 1]) == 0:
            if len(expression.strip()) > 0 and expression[-1] != "(":
                expression += random.choice(operators) + "("
            else:
                expression += "("
            parentheses_nest_depth += 1
            if parentheses_nest_depth < 5:
                # Caution: this is the interesting part
                generate_expression()
            else:
                expression += str(random.choice(operands))
                expression += generate_one_operation_unit() 
            expression += ")"
            parentheses_nest_depth -= 1
        else:
            if len(expression.strip()) == 0 or expression[-1] == "(":
                expression += str(random.choice(operands))
            expression += generate_one_operation_unit() 
    
    return expression


def compare_precedence(operator1: str, operator2: str):
    operator_to_index_dict = {"+": 0, "-": 1, "*": 2, "/": 3, "(": 4, ")": 5}
    precedences = [
        [1, 1, -1, -1, -1, 1],
        [1, 1, -1, -1, -1, 1],
        [1, 1,  1,  1, -1, 1],
        [1, 1,  1,  1, -1, 1],
        [-1, -1, -1, -1, -1, 0]
    ]
    return precedences[operator_to_index_dict[operator1]][operator_to_index_dict[operator2]]


def evaluate_expression(expression: str):
    """
    use loop and stack
    """
    # stack of chars
    operator_stack = [] 
    # stack of doubles
    operand_stack = []
    i = 0
    while i < len(expression):
        if expression[i].isdigit() or ("." == expression[i]):
            operand = expression[i]
            i += 1
            while (i < len(expression)) and (expression[i].isdigit() or ("." == expression[i])):
                operand += expression[i]
                i += 1
            operand_stack.append(float(operand))
        elif expression[i] in "+-*/)":
            while len(operator_stack) > 0 and compare_precedence(operator_stack[-1], expression[i]) > 0:
                operator = operator_stack.pop(-1)
                operand_2 =  operand_stack.pop(-1)
                operand_1 = operand_stack.pop(-1)
                if "+" == operator:
                    operand_stack.append(operand_1 + operand_2)
                elif "-" == operator:
                    operand_stack.append(operand_1 - operand_2)
                elif "*" == operator:
                    operand_stack.append(operand_1 * operand_2)
                elif "/" == operator:
                    operand_stack.append(operand_1 / operand_2)
                else:
                    assert False
            if expression[i] == ")":
                operator_stack.pop(-1)
            else:
                operator_stack.append(expression[i])
            i += 1
        elif expression[i] == "(":
            operator_stack.append("(")
            i += 1
        else:
            assert expression[i] == " "
            i += 1
               
    assert len(operator_stack) in {0, 1, 2}
    while len(operator_stack) > 0:
        operator = operator_stack.pop(-1)
        operand_2 =  operand_stack.pop(-1)
        operand_1 = operand_stack.pop(-1)
        if "+" == operator:
            operand_stack.append(operand_1 + operand_2)
        elif "-" == operator:
            operand_stack.append(operand_1 - operand_2)
        elif "*" == operator:
            operand_stack.append(operand_1 * operand_2)
        elif "/" == operator:
            operand_stack.append(operand_1 / operand_2)
        else:
            assert False
            
    assert len(operand_stack) == 1
    return operand_stack[0]
        
    
if __name__ == "__main__":
    # while True:
    #     print("The result:", eval(input("Enter an expression:")))
    count_of_ZeroDivisionError = 0
    for _ in range(100):
        try:
            # expression = input("Enter an arithmetic expression:")
            expression = ""            
            generate_expression()
            print(f"len={len(expression)}, expression=\"{expression}\"")
            # input()
            result_1 = evaluate_expression(expression)
            result_2 = eval(expression)
            assert result_1 == result_2
            print("result:", result_1, "\n\n")
        except ZeroDivisionError as e:
            count_of_ZeroDivisionError += 1
            print(e)
    print("count_of_ZeroDivisionError: ", count_of_ZeroDivisionError)
