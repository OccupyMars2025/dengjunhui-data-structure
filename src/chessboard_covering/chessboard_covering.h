/**
 * solution to the exercise [1-24] on page 18 of the exercise book
*/

#pragma once

#include <iostream>
#include <cmath>
#include <cassert>

#define N 4

void place_basic_block(int x, int y, int dx, int dy);
void cover_chessboard(int n, int x, int y, int dx, int dy);
void print_chessboard();
void clear_chessboard();

