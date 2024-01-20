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

// ========== start: my code =============
/*
the expression is expression[low, high)
*/
bool is_all_parentheses_matched_Using_stack(const char expression[], int low, int high) {
   Stack<char> s;

   for(int i = low; i < high; ++i) {
      switch (expression[i])
      {
      case '(':
      case '[':
      case '{':
         s.push(expression[i]);
         break;
      
      case ')':
         if(s.empty() || ('(' != s.pop())) {
            return false;
         }
         break;

      case ']':
         if(s.empty() || ('[' != s.pop())) {
            return false;
         }
         break;

      case '}':
         if(s.empty() || ('{' != s.pop())) {
            return false;
         }
         break;

      default:
         break;
      }
   }

   return s.empty();
}


void trim_expression(const char expression[], int& low, int& high) {
   if(low >= high) {
      return;
   }
   high -= 1;
   while (low <= high)
   {
      if((expression[low] != '(') && (expression[low] != '[') && (expression[low] != '{')
      && (expression[low] != ')') && (expression[low] != ']') && (expression[low] != '}')) {
         low += 1;
      } else {
         break;
      }
   }
   
   while (low <= high)
   {
      if((expression[high] != '(') && (expression[high] != '[') && (expression[high] != '{')
      && (expression[high] != ')') && (expression[high] != ']') && (expression[high] != '}')) {
         high -= 1;
      } else {
         break;
      }
   }
   high += 1;
}

/*
expression[low] is one of the left parentheses
expression[high-1] is one of the right parentheses
*/
int divide_expression(const char expression[], int low, int high) {
   char left_parenthesis = expression[low];
   char right_parenthesis;
   switch (left_parenthesis)
   {
   case '(':
      right_parenthesis = ')';
      break;
   
   case '[':
      right_parenthesis = ']';
      break;

   case '{':
      right_parenthesis = '}';
      break;

   default:
      assert(0);
      break;
   }

   int count = 1;
   int i;
   for(i = low + 1; i < high; ++i) {
      if(expression[i] == left_parenthesis) {
         ++count;
      } else if(expression[i] == right_parenthesis) {
         --count;
      }
      if(0 == count) {
         return i;
      }
   }
   return high;
}
/*
the expression is expression[low, high)
*/
bool is_all_parentheses_matched_Recursive_version(const char expression[], int low, int high) {
   trim_expression(expression, low, high);
   if(low >= high) {
      return true;
   }
   if((expression[low] != '(') && (expression[low] != '[') && (expression[low] != '{')) {
      return false;
   }
   high -= 1;
   if((expression[high] != ')') && (expression[high] != ']') && (expression[high] != '}')) {
      return false;
   }
   high += 1;
   int divide_index = divide_expression(expression, low, high);
   if(divide_index == high) {
      return false;
   }
   return is_all_parentheses_matched_Recursive_version(expression, low + 1, divide_index)
       && is_all_parentheses_matched_Recursive_version(expression, divide_index + 1, high);
}

// ========== end: my code =============


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
Rank divide ( const char exp[], Rank lo, Rank hi) { 
    // now, exp[lo] is "("
   int crc = 1; //crc为[lo, mi)范围内左、右括号数目之差
   while ( ( 0 < crc ) && ( ++lo < hi ) ) {//逐个检查各字符，直到左、右括号数目相等，或者越界
      if ( exp[lo] == '(' ) crc ++;
      else if ( exp[lo] == ')' ) crc --;
   }
   return lo;
}

//检查表达式 exp[lo, hi)是否括号匹配（递归版), only check "()"
bool paren_Recursive ( const char exp[], Rank lo, Rank hi ) { 
   // displaySubstring ( exp, lo, hi );
   trim ( exp, lo, hi ); 
   if ( lo >= hi ) return true; //清除不含括号的前缀、后缀
   if ( ( exp[lo] != '(' ) || ( exp[hi-1] != ')' ) ) return false; //首、末字符非左、右括号，则必不匹配
   
   Rank mi = divide ( exp, lo, hi); //确定适当的切分点
   if(mi == hi) {
      return false;
   }
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
      // displayProgress ( exp, i, S );
   }
   return S.empty(); //最终栈空，当且仅当匹配
}