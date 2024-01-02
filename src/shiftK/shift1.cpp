/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include "UniPrint/print_int_array.h"
#include "shiftK/shift.h"

// int shift ( int* A, int n, int s, int t ); //从A[s]出发，以t为间隔循环左移，O(3n)

// int shift1 ( int* A, int n, int k ) { //通过GCD(n, k)轮迭代，将数组循环左移k位，O(n)
//    if ( k < 1 ) return 0;
//    int mov = 0, s = 0;
//    while ( mov < n ) { //O(GCD(n, k)) = O(n*k/LCM(n, k))
//       mov += shift ( A, n, s++, k );                                     
//       printf ( "== move *%3d\n", mov ); 
//       print ( A, n );
//    }
//    return mov;  // I think the return value must be equal to "n"
// }

#include <cassert>

int shift1(int* A, int n, int k) {
   k = k % n;
   int move = 0, start = 0;
   while (move < n)
   {
      move += shift(A, n, start++, k);
      printf("==move %d\n", move);
      print(A, n);
   }
   assert(move == n);

   return move;
}