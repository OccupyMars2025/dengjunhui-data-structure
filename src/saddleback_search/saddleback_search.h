#pragma once

#include <iostream>
#include <utility>
#include <iomanip>
#include "Vector/Vector.h"

int** create_2d_array(int n);
void delete_2d_array(int **A, int n);
void print_2d_array(int **A, int n);
void saddleback_search(int **A, int n, int x, Vector<std::pair<int, int>>& vector_for_matched_indices);
void brute_force_search(int **A, int n, int x, Vector<std::pair<int, int>>& vector_for_matched_indices);
void validate_array(int **A, int n);
void compare_indices(Vector<std::pair<int, int>>& v1, Vector<std::pair<int, int>>& v2);
void print_matched_indices(Vector<std::pair<int, int>>& v);