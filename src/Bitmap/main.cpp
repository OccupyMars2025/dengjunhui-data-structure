/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include "_share/util.h"
#include "Bitmap/Bitmap.h"
#include "Bitmap/Bitmap_v002.h"
#include "Bitmap/Bitmap_v003.h"
#include "Bitmap/Bitmap_v004.h"

/******************************************************************************************
 * 测试位图
 * n: size of bitmap
 * t: number of round of test
 ******************************************************************************************/
int test_Bitmap( int n, int t ) {
   assert((n > 0) && (t > 0));

   bool* B = new bool[n]; //常规位图
   Bitmap M ( n ); //高效位图
   while ( t-- > 0 ) { //重复使用位图多次
      memset ( B, 0, n * sizeof ( bool ) ); //逐位清零，O(n)
      M.reset(); //逻辑清零，O(1)
      for ( int i = 0; i < 3 * n; i++ ) { //反复地
         Rank k = dice ( n ); //在随机位置上
         if ( dice ( 2 ) ) { //以50%的概率插入
            B[k] = true; M.set ( k );
         } else { //或50%的概率清除
            B[k] = false; M.clear ( k );
         }
      }
      // M.set( 20 ); //有时可卖个破绽，以反向测试本测试程序
      int k;
      for ( k = 0; k < n; k++ ) //逐位地对比
         if ( B[k] != M.test ( k ) ) //一旦发现不合
            break; //随即退出
      if ( k < n ) { //并报告（assert:: k == n+1）
         printf ( "\n B[]:" );
         for ( int j = 0; j <= k; j++ ) { 
            printf ( "%c", B[j] ? '1' : '0' );
         }
         printf ( "\n M[]:" );
         M.print(k+1);
         printf ( "\n" );
         exit(1);
      }
   }
   delete [] B;
   return 0;
}

/*
Bitmap_v002 doesn't support clear()
*/
int test_Bitmap_v002( int n, int t ) {
   assert((n > 0) && (t > 0));

   Bitmap bitmap(n);
   Bitmap_v002 bitmap_v002( n ); //高效位图
   while ( t-- > 0 ) { //重复使用位图多次
      bitmap.reset();
      bitmap_v002.reset(); //逻辑清零，O(1)
      for ( int i = 1; i < 4 * n; i++ ) { //反复地
         Rank k = dice ( i ); //在随机位置上
         bitmap.set(k);
         bitmap_v002.set(k);
      }
      // bitmap_v002.set( 19 ); //有时可卖个破绽，以反向测试本测试程序
      int k;
      for ( k = 0; k < 4 * n; k++ ) //逐位地对比
         if ( bitmap.test(k) != bitmap_v002.test(k) ) //一旦发现不合
            break; //随即退出
      if ( k < 4 * n ) { //并报告（assert:: k == n+1）
         printf("the mismatch index: %d\n", k);
         printf ( "\n      bitmap[]:" );
         bitmap.print(k+1);
         printf ( "\n bitmap_v002[]:" );
         bitmap_v002.print(k+1);
         printf ( "\n" );
         exit(1);
      }
   }
   return 0;
}


int test_Bitmap_v003_and_v004( int n, int t ) {
   assert((n > 0) && (t > 0));

   Bitmap bitmap(n);
   Bitmap_v003 bitmap_v003( n ); 
   Bitmap_v004 bitmap_v004( n ); 
   while ( t-- > 0 ) { //重复使用位图多次
      bitmap.reset();
      bitmap_v003.reset();
      bitmap_v004.reset(); //逻辑清零，O(1)
      for ( int i = 1; i < 4 * n; i++ ) { //反复地
         Rank k = dice ( i ); //在随机位置上
         // std::cout << " set(" << k << ")" << std::endl;
         if(dice(2)) {
            bitmap.set(k);
            // bitmap.print(k+1);
            bitmap_v003.set(k);
            bitmap_v004.set(k);
            // bitmap_v004.print(k+1);
         } else {
            bitmap.clear(k);
            bitmap_v003.clear(k);
            bitmap_v004.clear(k);
         }
      }
      // bitmap_v003.set(28); //有时可卖个破绽，以反向测试本测试程序
      int k;
      for ( k = 0; k < 4 * n; k++ ) //逐位地对比
         if (!((bitmap.test(k) == bitmap_v003.test(k)) && (bitmap.test(k) == bitmap_v004.test(k)))) //一旦发现不合
            break; //随即退出
      if ( k < 4 * n ) { 
         printf("the mismatch index: %d\n", k);
         printf ( "\n      bitmap[]:" );
         bitmap.print(k+1);
         printf ( "\n bitmap_v003[]:" );
         bitmap_v003.print(k+1);
         printf ( "\n bitmap_v004[]:" );
         bitmap_v004.print(k+1);
         printf ( "\n" );
         exit(1);
      }
   }
   return 0;
}


/******************************************************************************************
 * 测试位图
 ******************************************************************************************/
int main( int argc, char* argv[] ) {
   //  unsigned char c = 1;
   //  std::cout <<  (c & 1) << ", " << (c & 0x80) << std::endl;

   //  uint16_t n = 0x0102;
   //  unsigned char *char_array = (unsigned char*)(&n);
   //  std::cout << (int)char_array[0] << ", " << (int)char_array[1] << std::endl;
   //  return 0;

   // if ( 3 > argc ) { 
   //    printf( "Usage: %s <bitmap size> <#test>\n", argv[0] ); 
   //    return 1; 
   // }
   // srand((unsigned int)time(NULL)); //随机种子
   // //srand( 31415926 ); //固定种子（假种子，调试用）
   // return testBitmap(atoi(argv[1]), atoi(argv[2])); //启动测试
   
   srand((unsigned int)time(NULL)); 
   for(int n = 1; n < 100; ++n) {
      test_Bitmap(n, 100);
      test_Bitmap_v002(n, 100);
      test_Bitmap_v003_and_v004(n, 100);
      std::cout << "n = "<< n << std::endl;
   }
   std::cout << "test ok!" << std::endl;
}