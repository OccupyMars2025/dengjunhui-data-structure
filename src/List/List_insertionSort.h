/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

//���б�����ʼ��λ��p�����Ϊn����������������
template <typename T> 
void List<T>::insertionSort( ListNodePosi<T> p, Rank n ) { // valid(p) && Rank(p) + n <= size
   /*DSA*/
   printf ( "InsertionSort ...\n" );
   for ( int count = 0; count < n; count++ ) { //��һΪ���ڵ�
      insert( search( p->data, count, p ), p->data ); //�����ʵ���λ�ò�����
      p = p->succ; 
      remove( p->pred ); //ת����һ�ڵ�
   }
}