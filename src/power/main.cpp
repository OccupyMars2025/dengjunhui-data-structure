/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include <iostream>
#include "power/Power.h"

using namespace std;

/******************************************************************************************
 * 测试Power
 ******************************************************************************************/
int main ( int argc, char* argv[] ) {
   int64_t base; 
   int exponent;
   if ( 2 > argc ) {  
      cout << "Usage: " << argv[0] << " <base>" << endl; 
      return 1;  
   } //检查参数
   base = atol ( argv[1] ); 
   assert(base >= 2);

   for(exponent = 0; exponent < 20; ++exponent) {
      //迭代版
      int64_t pow_1 =  power2BF_I (exponent);
      int64_t pow_2 =  power2_I (exponent);
      //递归版
      int64_t pow_3 = power2BF (exponent);
      int64_t pow_4 = power2 (exponent);

      assert(pow_1 == pow_2);
      assert(pow_1 == pow_3);
      assert(pow_1 == pow_4);
      printf("2 ^ %d = %ld\n", exponent, pow_1);

      //通用算法迭代版
      int64_t pow_5 = powerBF (base, exponent);
      int64_t pow_6 = power (base, exponent);
      assert(pow_5 == pow_6);
      printf("%ld ^ %d = %ld\n", base, exponent, pow_5);
   }

   return 0;
}