/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

//�����б�Ĺ鲢����ǰ�б�����p���n��Ԫ�أ����б�L����q���m��Ԫ�ع鲢
template <typename T> 
ListNodePosi<T> List<T>::merge( ListNodePosi<T> p, Rank n,
                    List<T>& L, ListNodePosi<T> q, Rank m ) {
// this.valid(p) && Rank(p) + n <= size && this.sorted(p, n)
// L.valid(q) && Rank(q) + m <= L._size && L.sorted(q, m)
// ע�⣺�ڱ�mergeSort()����ʱ��this == &L && Rank(p) + n = Rank(q)
   ListNodePosi<T> pp = p->pred; //�鲢֮��p���ܲ���ָ���׽ڵ㣬�����ȼ��䣬�Ա��ڷ���ǰ����
   
   // Caution: when p == q is true, then we're done
   while ( ( 0 < m ) && ( q != p ) ) //q��δ���磨����mergeSort()�У�p����δ���磩֮ǰ
   {
      if ( ( 0 < n ) && ( p->data <= q->data ) ) //��p��δ������v(p) <= v(q)����
      { 
         p = p->succ; 
         n--; 
      } //pֱ�Ӻ��ƣ�����ɹ���
      else //���򣬽�qת����p֮ǰ������ɹ���
      { 
         q = q->succ;
         insert( L.remove( q->pred ), p ); 
         m--; 
      }
   }

   return pp->succ; //���µ��׽ڵ�
}