/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> static void print ( const T& x );
template <typename T> static void print ( T& x );

#define PRINT(x)  { print(x); crc(x); checkOrder(x); printf("\n"); }

#include <cstdio> //����C���ϸ���������ʽ
#include "Huffman/HuffChar.h" //Huffman���ַ�
#include "BinTree/BinTree.h" //������
#include "Huffman/HuffTree.h" //Huffman��
#include "BST/BST.h" //����������
// #include "AVL/AVL.h" //AVL��
#include "Splay/Splay.h" //��չ��
// #include "RedBlack/RedBlack.h" //�����
// #include "BTree/BTree.h" //����������
// #include "Entry/Entry.h" //����
// #include "Skiplist/Quadlist.h" //�Ĳ��
// #include "Skiplist/Skiplist.h" //��ת��
// #include "Hashtable/Hashtable.h" //ɢ�б�
// #include "PQ_List/PQ_List.h" //�����б�ʵ�ֵ����ȼ�����
// #include "PQ_ComplHeap/PQ_ComplHeap.h" //������ȫ��ʵ�ֵ����ȼ�����
// #include "PQ_LeftHeap/PQ_LeftHeap.h" //������ʽ��ʵ�ֵ����ȼ�����
#include "Graph/Graph.h" //ͼ
#include "GraphMatrix/GraphMatrix.h" //�����ڽӾ���ʵ�ֵ�ͼ


class UniPrint {
public:
   static void p ( int );
   static void p ( size_t );
   static void p ( float );
   static void p ( double );
   static void p ( char );
   static void p ( HuffChar& ); //Huffman�������ַ�
   static void p ( VStatus ); //ͼ�����״̬
   static void p ( EType ); //ͼ�ߵ�����

   // template <typename K, typename V> static void p( Entry<K, V>& ); // Entry
   template <typename T> static void p( BinNode<T>& ); // BinTree�ڵ�
   template <typename T> static void p( BinTree<T>& ); //������
   // template <typename T> static void p( BTree<T>& ); // B-��
   template <typename T> static void p( BST<T>& ); // BST
   // template <typename T> static void p( AVL<T>& ); // AVL
   // template <typename T> static void p( RedBlack<T>& ); // RedBlack
   template <typename T> static void p( Splay<T>& ); // Splay
   // template <typename T> static void p( Quadlist<T>& ); // Quadlist
   // template <typename K, typename V> static void p( Skiplist<K, V>& ); // Skiplist
   // template <typename K, typename V> static void p( Hashtable<K, V>& ); // Hashtable
   // template <typename T> static void p( PQ_List<T>& ); // PQ_List
   // template <typename T> static void p( PQ_ComplHeap<T>& ); // PQ_ComplHeap
   // template <typename T> static void p( PQ_LeftHeap<T>& ); // PQ_LeftHeap
   template <typename Tv, typename Te> static void p( GraphMatrix<Tv, Te>& ); // Graph
   template <typename T> static void p( T& ); //�������б��֧��traverse()�������������Խṹ
   template <typename T> static void p( T* s ) //����ָ��
   { s ? p( *s ) : printf( "<NULL>" ); } //ͳһתΪ����
}; //UniPrint


/******************************************************************************************
 * ����Ԫ�ء����ݽṹͨ������ӿ�
 ******************************************************************************************/
static void print ( char* x ) {  printf ( " %s", x ? x : "<NULL>" );  } //�ַ����ر���
static void print ( const char* x ) {  printf ( " %s", x ? x : "<NULL>" );  } //�ַ����ر���
template <typename T> static void print ( T* x ) 
{  
   if(x) {
      print ( *x );
   } else {
      printf ( " <NULL>" );  
   }
}

template <typename T> static void print ( T& x ) {  UniPrint::p ( x );  }
template <typename T> static void print ( const T& x ) {  UniPrint::p ( x );  } //for Stack


#include "print_implementation.h"