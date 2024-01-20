/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include  "nest/nest.h"
#include <cassert>

int main(int argc, char const *argv[])
{
   // char characters[] = "0123456789+-*/^ ()[]{}";
   char characters[] = "0123456789+-*/^ ()";
   // char characters[] = "()";
   // char characters[] = "12()[]{}";
   for(int expression_length = 1; expression_length < 50; ++expression_length) {
      char *expression = new char[expression_length + 1];
      expression[expression_length] = '\0';
      for(int test_count = 1; test_count <= 10000; ++test_count) {
         for(int i = 0; i < expression_length; ++i) {
            expression[i] = characters[rand() % sizeof(characters)];
         }

         std::cout << "(length=" << expression_length << ")\"" << expression << "\"" << std::endl;
         bool result_v001 = is_all_parentheses_matched_Using_stack(expression, 0, expression_length);
         bool result_v002 = paren_UsingStack(expression, 0, expression_length);
         bool result_v003 = is_all_parentheses_matched_Recursive_version(expression, 0, expression_length);
         bool result_v004 = paren_Recursive (expression, 0, expression_length);
         assert(result_v001 == result_v004);
         assert((result_v001 == result_v002) && (result_v001 == result_v003));
      }
      delete [] expression;
   }
   return 0;
}


// /******************************************************************************************
//  * 检查表达式括号是否匹配
//  ******************************************************************************************/
// int main ( int argc, char* argv[] ) {
// // 检查参数
//    if ( 2 > argc ) { //至少要提供一个待检查的字符串
//       fprintf ( stderr, "\nUsage: %s <string#1> <string#2> ... \n", argv[0] );
//       fprintf ( stderr, "For example: %s (a[i-1][j+1])+a[i+1][j-1])*2\n", argv[0] );
//       return -1;
//    }
// // 逐一检查各串是否匹配
//    for ( int i = 1; i < argc; i++ ) {
//       char* s = argv[i];   
//       printf ( "\ncheck: %s\n", s );
//       printf("string_length: %lu\n", strlen(s));
      
//       bool result_v001 = is_all_parentheses_matched_Iterative_version(s, 0, strlen(s));
//       bool result_v002 = paren_UsingStack(s, 0, strlen(s));
//       bool result_v003 = paren_Recursive (s, 0, strlen(s));
//       assert((result_v001 == result_v002) && (result_v001 == result_v003));

//       // printf("paren_UsingStack \n");
//       // if (true == paren_UsingStack ( s, 0, strlen ( s ) )) {
//       //    printf ( "\n%s: match\n", s );
//       // } else {
//       //    printf ( "\n%s: NOT match\n", s );
//       // }

//       // printf("paren_Recursive\n");
//       // if (true == paren_Recursive ( s, 0, strlen ( s ) )) {
//       //    printf ( "\n%s: match\n", s );
//       // } else {
//       //    printf ( "\n%s: NOT match\n", s );
//       // }   
//    }
//    return 0;
// }