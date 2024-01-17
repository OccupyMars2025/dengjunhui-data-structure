/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include <cstdio>
#include <iostream>
#include <cmath>
#include <cassert>
#include "_share/rand.h"
#include "Bitmap/Bitmap.h"
#include "prime/Eratosthenes.h"
#include "prime/primeNLT.h"

/******************************************************************************************
 * 主函数
 ******************************************************************************************/
#define PRIMEFILE "prime-bitmap.txt" //用于记录指定区间内素数分布的比特图文件

bool is_prime(Rank k) {
   if(k < 2) return false;
   if((k == 2) || (k == 3)) {
      return true;
   }
   for(Rank i = 2; i <= ceil(sqrt(k)); ++i) {
      if(k % i == 0) {
         return false;
      }
   }
   return true;
}

int main ( int argc, char* argv[] ) {
   if ( 2 > argc ) { 
      printf ( "Usage: %s <maxInt>\n", argv[0] ); 
      return -1; 
   }
   srand((unsigned int)time(NULL)); //随机种子
   //srand( 31415926 ); //固定种子（假种子，调试用）
   int n = atoi( argv[1] ); //简化起见，不考虑非正的情况
   if(n < 10) n = 10;
   Eratosthenes( n, PRIMEFILE );

   Bitmap bitmap(PRIMEFILE, n);
   bitmap.print(n);
   for(Rank i = 0; i < n; ++i) {
      assert(is_prime(i) != bitmap.test(i));
      if(is_prime(i)) {
         std::cout << " " << i;
      }
   }
   std::cout << "\ntest ok!" << std::endl;

   // for ( int i = 0; i <= 13; i++ ) { //做13次随机测试（限于MAX_RAND，覆盖范围不超过0x7FFF）
   //    int low = dice( n );
   //    printf( "The smallest prime number no less than %8d (%05X) is %8d\n", low, low,
   //            primeNLT( low, n, PRIMEFILE ) );
   // }
   // for ( int i = 0; i < 13; i++ ) { //做13次等间距测试
   //    printf( "The smallest prime number no less than %8d (%05X) is %8d\n", n * i / 11,
   //            n * i / 11, primeNLT( n * i / 11, n, PRIMEFILE ) );
   // }
   return 0;
}
