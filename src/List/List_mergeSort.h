/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

//�б�Ĺ鲢�����㷨������ʼ��λ��p��n��Ԫ������
// Caution: the argument is "ListNodePosi<T>& p", NOT "ListNodePosi<T> p"
// After calling mergeSort(), the argument that is passed to "ListNodePosi<T>& p" will
// still point to the first node of the sorted interval
template <typename T> 
void List<T>::mergeSort( ListNodePosi<T>& p, Rank n ) { // valid(p) && Rank(p) + n <= size
   /*DSA*/
   printf ( "\tmergeSort [%3d]\n", n );
   
   if ( n < 2 ) return; //��������Χ���㹻С����ֱ�ӷ��أ�����...
   Rank m = n >> 1; //���е�Ϊ��
   ListNodePosi<T> q = p; 
   for ( Rank i = 0; i < m; i++ ) 
      q = q->succ; //�ҵ������б����

   mergeSort( p, m ); mergeSort( q, n - m ); //ǰ�������б���ֱ�����
   p = merge( p, m, *this, q, n - m ); //�鲢
} //ע�⣺�����p��Ȼָ��鲢������ģ��£����