/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "_share/util.h"
#include "UniPrint/print.h"
#include "Stack/Stack.h"

void convert_Recursive ( Stack<char>& S, int64_t n, int base ) { //整数n的1<base<=16进制打印（递归版）
   static char digit[] = "0123456789ABCDEF"; //数位符号，如有必要可相应扩充
   if ( 0 < n ) { //在尚有余数之前，反复地
      S.push ( digit[n % base] ); //逆向记录当前最低位，再
      convert_Recursive ( S, n / base, base ); //通过递归得到所有更高位
   }
} //新进制下由高到低的各数位，自顶而下保存于栈S中


void convert_Iterative ( Stack<char>& S, int64_t n, int base ) { //整数n的1<base<=16进制打印（迭代版）
   char digit[] = "0123456789ABCDEF"; //数位符号，如有必要可相应扩充
   while ( n > 0 ) { //由低到高，逐一计算出新进制下的各数位
      printf ( "%ld = %ld * %d + %ld\n", n , n/base, base, n%base );
      S.push ( digit[ n % base ] ); //余数（当前位）入栈
      n /= base; //n更新为其对base的除商
      print ( S ); 
   }
} //新进制下由高到低的各数位，自顶而下保存于栈S中