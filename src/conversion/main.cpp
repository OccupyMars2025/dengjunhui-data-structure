/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include "conversion/convert.h"

/******************************************************************************************
 * 进制转换
 ******************************************************************************************/
int main ( int argc, char* argv[] ) {
   Stack<char> s1, s2; 
   int64_t calculated_n;

   for(int base = 2; base <= 30; ++base) {
      std::cout << "base = " << base << std::endl;
      for (int64_t n = 1; n <= 10000; ++n) {
         convert_Iterative ( s1, n, base ); //进制转换   
         convert_Recursive(s2, n, base);
         // printf ( "%ld_(10) = ", n );
         assert(s1.size() == s2.size());
         calculated_n = 0;
         while ( !s1.empty()) {
            char c1 = s1.pop(), c2 = s2.pop();
            assert(c1 == c2);
            // printf ("%c", c1); 
            if(isdigit(c1)) {
               calculated_n = calculated_n * base + (c1 - '0');
            } else if(isalpha(c1) && (c1 >= 'A')) {
               calculated_n = calculated_n * base + (c1 - 'A' + 10);
            } else {
               assert(0);
            }
         }
         assert(calculated_n == n);
         // printf ( "_(%d)\n", base ); 
      }
   }

   return 0;
}