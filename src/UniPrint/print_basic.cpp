/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

// #pragma once

#include "UniPrint/print.h"

void print ( char* x ) {  printf ( " %s", x ? x : "<NULL>" );  } //字符串特别处理
void print ( const char* x ) {  printf ( " %s", x ? x : "<NULL>" );  } //字符串特别处理
template <typename T> 
void print ( T* x ) {  
    if(x) {
        print(*x);
    } else {
        printf(" <NULL>" );
    }
}
template <typename T> void print ( T& x ) {  UniPrint::p ( x );  }
template <typename T> void print ( const T& x ) {  UniPrint::p ( x );  } //for Stack


/******************************************************************************************
 * 基本类型
 ******************************************************************************************/
void UniPrint::p( int e ) { printf( " %04d", e ); }
void UniPrint::p( size_t e ) { p( (int)e ); } // Rank型0xFFFFFFFF在打印前先转换为-1，以便观察
void UniPrint::p( float e ) { printf( " %4.3f", e ); }
void UniPrint::p( double e ) { printf( " %4.3f", e ); }
// void UniPrint::p( char e ) { printf( " %c", ( 31 < e ) && ( e < 128 ) ? e : '$' ); }
void UniPrint::p( char e ) { printf( " %c", ( 31 < e ) ? e : '$' ); }
   
template <typename T> 
void UniPrint::p( T* s ) //所有指针
{ 
    s ? p( *s ) : print( "<NULL>" ); 
} //统一转为引用


// void UniPrint::p( VStatus e ) {
//    switch ( e ) {
//       case UNDISCOVERED:   printf ( "U" ); break;
//       case DISCOVERED:     printf ( "D" ); break;
//       case VISITED:        printf ( "V" ); break;
//       default:             printf ( "X" ); break;
//    }
// }
// void UniPrint::p( EType e ) {
//    switch ( e ) {
//       case UNDETERMINED:   printf ( "U" ); break;
//       case TREE:           printf ( "T" ); break;
//       case CROSS:          printf ( "C" ); break;
//       case BACKWARD:       printf ( "B" ); break;
//       case FORWARD:        printf ( "F" ); break;
//       default:             printf ( "X" ); break;
//    }
// }
