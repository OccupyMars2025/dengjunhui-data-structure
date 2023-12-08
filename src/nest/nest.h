/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

#include <iostream>
using namespace std;

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "UniPrint/print.h"

#include "Stack/Stack.h"

/******************************************************************************************
 * 显示表达式片段 exp[lo, hi)，与原表达式对齐
 ******************************************************************************************/
void displaySubstring ( const char exp[], Rank lo, Rank hi ) {
   for ( Rank i = 0; i < lo; i++ ) printf ( " " );
   for ( Rank i = lo; i < hi; i++ ) printf ( "%c", exp[i] );
   printf ( "\n" );
}

/******************************************************************************************
 * 显示表达式扫描进度
 ******************************************************************************************/
void displayProgress ( const char exp[], Rank i, Stack<char>& S ) {
// 表达式
//    system ( "clear" );
   printf ( "\n%s\n", exp );
   for ( Rank j = 0; j < i; j++ )   printf ( "-" );
   printf ( "^\n\n\n" );
// 栈
   print ( S ); 
}

//删除 exp[lo, hi)不含括号的最长前缀、后缀
void trim ( const char exp[], Rank& lo, Rank& hi ) { 
   while ( ( lo < hi ) && ( exp[lo] != '(' ) && ( exp[lo] != ')' ) ) lo++; //查找第一个和
   while ( ( lo < hi ) && ( exp[hi-1] != '(' ) && ( exp[hi-1] != ')' ) ) hi--; //最后一个括号
}

//切分 exp[lo, hi)，使exp匹配仅当子表达式匹配
Rank divide ( const char exp[], Rank lo, Rank hi ) { 
    // now, exp[lo] is "("
   int crc = 1; //crc为[lo, mi)范围内左、右括号数目之差
   while ( ( 0 < crc ) && ( ++lo < hi ) ) //逐个检查各字符，直到左、右括号数目相等，或者越界
      if ( exp[lo] == '(' ) crc ++;
      else if ( exp[lo] == ')' ) crc --;
   return lo;
}

//检查表达式 exp[lo, hi)是否括号匹配（递归版), only check "()"
bool paren_Recursive ( const char exp[], Rank lo, Rank hi ) { 
   displaySubstring ( exp, lo, hi );
   trim ( exp, lo, hi ); 
   if ( lo >= hi ) return true; //清除不含括号的前缀、后缀
   if ( ( exp[lo] != '(' ) || ( exp[hi-1] != ')' ) ) return false; //首、末字符非左、右括号，则必不匹配
   Rank mi = divide ( exp, lo, hi ); //确定适当的切分点
   return paren_Recursive ( exp, lo + 1, mi ) && paren_Recursive ( exp, mi + 1, hi ); //分别检查左、右子表达式
}


//表达式括号匹配检查，可兼顾三种括号 [lo, hi)
bool paren_UsingStack ( const char exp[], Rank lo, Rank hi ) { 
   Stack<char> S; //使用栈记录已发现但尚未匹配的左括号
   for ( Rank i = lo; i < hi; i++ ) /* 逐一检查当前字符 */ {
      switch ( exp[i] ) { //左括号直接进栈；右括号若与栈顶失配，则表达式必不匹配
         case '(': 
         case '[': 
         case '{': 
            S.push ( exp[i] ); 
            break;
         case ')': 
            if ( ( S.empty() ) || ( '(' != S.pop() ) ) 
               return false; 
            break;
         case ']': 
            if ( ( S.empty() ) || ( '[' != S.pop() ) ) 
               return false; 
            break;
         case '}': 
            if ( ( S.empty() ) || ( '{' != S.pop() ) ) 
               return false; 
            break;
         default: 
            break; //非括号字符一律忽略
      } 
      displayProgress ( exp, i, S );
   }
   return S.empty(); //最终栈空，当且仅当匹配
}