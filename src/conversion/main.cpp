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
   if ( (argc < 3) || (argc % 2 != 1)) //参数检查
   { 
      cout << "Usage: " << argv[0] << " <integer> <base>" << endl; 
      return -1; 
   }

   for ( int i = 1; i < argc; i += 2 ) {
      int64_t n = atol ( argv[i] ); //待转换的十进制数
      if ( 0 >= n ) //参数检查
      { 
         cout << "But " << n << " is not a positive integer" << endl;   
         return -2; 
      }

      int base = atoi ( argv[i+1] ); //目标进制
      if ( 2 > base || base > 16 ) //参数检查
      { 
         cout << "But " << base << " is not between 2 and 16" << endl; 
         return -2; 
      }

      Stack<char> S; //用栈记录转换得到的各数位
      convert_Iterative ( S, n, base ); //进制转换
      printf ( "%ld_(10) = ", n );
      while ( !S.empty() ) 
         printf ( "%c", ( S.pop() ) ); //逆序输出栈内数位，即正确结果
      printf ( "_(%d)\n", base ); 
      
      convert_Recursive(S, n, base);
      printf ( "%ld_(10) = ", n );
      while ( !S.empty() ) 
         printf ( "%c", ( S.pop() ) ); //逆序输出栈内数位，即正确结果
      printf ( "_(%d)\n", base ); 
   }

   return 0;
}