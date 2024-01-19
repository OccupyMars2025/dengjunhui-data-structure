/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

#include <iostream>

// template <typename T> 
// Rank List<T>::dedup() {
//    Rank oldSize = _size; ListNodePosi<T> p = first();
//    for ( Rank r = 0; p != trailer; p = p->succ ) //O(n)
//       if ( ListNodePosi<T> q = find(p->data, r, p) )
//          remove(q); //此时q与p雷同，但删除前者更为简明
//       else 
//          r++; //r为无重前缀的长度
//    return oldSize - _size; //删除元素总数
// }



template <typename T> 
Rank List<T>::dedup() {
   std::cout << "src/List/List_deduplicate.h v002" << std::endl;

   if(_size < 2) {
      return 0;
   }
   ListNodePosi<T> p, p2, p3;
   Rank old_size = _size;

   for(p = header->succ; p != trailer; p = p->succ) {
      p2 = p->succ;
      while (p2 != trailer)
      {
         if(p->data == p2->data) {
            p3 = p2->succ;
            remove(p2);
            p2 = p3;
         } else {
            p2 = p2->succ;
         }
      }      
   }

   return old_size - _size;
}