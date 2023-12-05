/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

#include<iostream>
using namespace std;


#include "List.h"
// #include "UniPrint/print.h"


// ============== start: To be deleted later ==================

#define PRINT(x)  { print(x); crc(x); checkOrder(x); printf("\n"); }

class UniPrint {
public:
   static void p ( int );
   // static void p ( size_t );
   // static void p ( float );
   // static void p ( double );
   // static void p ( char );
   // static void p ( HuffChar& ); //Huffman（超）字符
   // static void p ( VStatus ); //图顶点的状态
   // static void p ( EType ); //图边的类型

   // template <typename K, typename V> static void p( Entry<K, V>& ); // Entry
   // template <typename T> static void p( BinNode<T>& ); // BinTree节点
   // template <typename T> static void p( BinTree<T>& ); //二叉树
   // template <typename T> static void p( BTree<T>& ); // B-树
   // template <typename T> static void p( BST<T>& ); // BST
   // template <typename T> static void p( AVL<T>& ); // AVL
   // template <typename T> static void p( RedBlack<T>& ); // RedBlack
   // template <typename T> static void p( Splay<T>& ); // Splay
   // template <typename T> static void p( Quadlist<T>& ); // Quadlist
   // template <typename K, typename V> static void p( Skiplist<K, V>& ); // Skiplist
   // template <typename K, typename V> static void p( Hashtable<K, V>& ); // Hashtable
   // template <typename T> static void p( PQ_List<T>& ); // PQ_List
   // template <typename T> static void p( PQ_ComplHeap<T>& ); // PQ_ComplHeap
   // template <typename T> static void p( PQ_LeftHeap<T>& ); // PQ_LeftHeap
   // template <typename Tv, typename Te> static void p( GraphMatrix<Tv, Te>& ); // Graph
   template <typename T> static void p( T& ); //向量、列表等支持traverse()遍历操作的线性结构
   // template <typename T> static void p( T* s ) //所有指针
   // { s ? p( *s ) : print( "<NULL>" ); } //统一转为引用
}; //UniPrint


// template <typename T> static void print ( T* x ) {  x ? print ( *x ) : printf ( " <NULL>" );  }
template <typename T> void print ( T& x ) {  UniPrint::p ( x );  }
template <typename T> void print ( const T& x ) {  UniPrint::p ( x );  } //for Stack
// static void print ( char* x ) {  printf ( " %s", x ? x : "<NULL>" );  } //字符串特别处理
// static void print ( const char* x ) {  printf ( " %s", x ? x : "<NULL>" );  } //字符串特别处理



/******************************************************************************************
 * 向量、列表等支持traverse()遍历操作的线性结构
 ******************************************************************************************/
template <typename T> //元素类型
void UniPrint::p ( T& s ) { //引用
   printf ( "[name]%s [address]%p [size]%d:\n", typeid ( s ).name(), (void*)&s, s.size() ); //基本信息
   s.traverse ( print ); //通过print()遍历输出所有元素
   printf ( "\n" );
}


void UniPrint::p( int e ) { printf( " %04d", e ); }
// void UniPrint::p( size_t e ) { p( (int)e ); } // Rank型0xFFFFFFFF在打印前先转换为-1，以便观察
// void UniPrint::p( float e ) { printf( " %4.3f", e ); }
// void UniPrint::p( double e ) { printf( " %4.3f", e ); }
// void UniPrint::p( char e ) { printf( " %c", ( 31 < e ) && ( e < 128 ) ? e : '$' ); }


// #include "List.h"


template <typename T> struct Crc { //函数对象：累计T类对象的特征（比如总和），以便校验对象集合
   T& c;
   Crc ( T& crc ) : c ( crc ) {}
   virtual void operator() ( T& e ) { c += e; } //假设T可直接相加
};

template <typename T> void crc ( List<T> & L ) { //统计列表的特征（所有元素总和）
   T crc = 0;
   Crc<T>* visitor = new Crc<T> ( crc );
   L.traverse ( *visitor ); //以crc为基本操作进行遍历
   printf ( "total-sum =" ); print ( crc ); printf ( "\n" ); //输出统计得到的特征
}

template <typename T> 
struct CheckOrder { //函数对象：判断一个T类对象是否局部有序
   // Caution: you CANNOT use "T& pred;", otherwise you will modify the List data in-place
   T pred; int& u;
   CheckOrder( int& unsorted, T& first ) : pred( first ), u( unsorted ) {}
   virtual void operator()( T& e ) { if ( pred > e ) u++; pred = e; }
};

template <typename T> 
void checkOrder( List<T>& L ) { //判断列表是否整体有序
   int nInv = 0; //逆序计数器
   CheckOrder<T>* visitor = new CheckOrder<T>( nInv, L.first()->data );
   L.traverse( *visitor ); //进行遍历
   if ( 0 < nInv )
      printf( "Unsorted with %d adjacent inversion pair(s)\n", nInv );
   else
      printf( "Sorted\n" );
}

#include <cstdio>



// ============== end: To be deleted later ==================



