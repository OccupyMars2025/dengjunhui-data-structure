/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include "_share/util.h"
#include <cassert>

int countOnes ( unsigned int n );
int countOnes1 ( unsigned int n );
int countOnes2 ( unsigned int n );

int main ( int argc, char* argv[] ) { //二进制数位1计数算法测试入口
   for ( unsigned int i = 0; i <= UINT32_MAX; i++ ) {
      int num_ones = countOnes(i);
      int num_ones_v1 = countOnes1(i);
      int num_ones_v2 = countOnes2(i);
      assert(num_ones == num_ones_v1 && num_ones == num_ones_v2);

      printf ( "%7u = %7X, number of ones = %6d\n", i, i, num_ones);
   }

   return 0;
}