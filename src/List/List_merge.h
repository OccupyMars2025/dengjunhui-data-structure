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
         insertBefore( p, L.remove( q->pred )); 
         m--; 
      }
   }

   return pp->succ; //���µ��׽ڵ�
}



/*
the list elements in the index range [rank(p), rank(p) + n) are sorted,
the list elements in the index range [rank(q), rank(q) + m) are sorted,
rank(p) + n <= rank(q)

remove the whole right part, insert each element in the right part into the left part
*/
template <typename T> 
void List<T>::merge_002( ListNodePosi<T>& p, Rank n, ListNodePosi<T> q, Rank m ) {
   // std::cout << "src/List/List_merge.h  merge_002()" << std::endl;

   // actually there is no need to use middle_sentinel
   /*
   if the two parts have no elements in between, just like in mergeSort(),
   middle_sentinel will help you prevent from crossing bounds, just remove it at the end of the function
   */
   // ListNodePosi<T> middle_sentinel = insertBefore(q, (T)0);


   // another trick
   ListNodePosi<T> pred_of_logical_first_node = p->pred;
   while ((n > 0) && (m > 0))
   {
      // only "<" to insertBefore, so we keep the merge sort stable 
      if(q->data < p->data) {
         q = q->succ;
         insertBefore(p, remove(q->pred));
         --m;
      } else {
         p = p->succ;
         --n;
      }
   }

   if((m > 0) && (p != q)) {
      while (m > 0)
      {
         q = q->succ;
         insertBefore(p, remove(q->pred));
         --m;
      }
   }

   p = pred_of_logical_first_node->succ;
   // remove(middle_sentinel);
}