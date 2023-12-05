/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once


// ============== start: To be deleted later ==================


template <typename T> static bool lt( T* a, T* b ) { return lt( *a, *b ); } // less than
template <typename T> static bool lt( T& a, T& b ) { return a < b; } // less than
template <typename T> static bool eq( T* a, T* b ) { return eq( *a, *b ); } // equal
template <typename T> static bool eq( T& a, T& b ) { return a == b; } // equal


// ============== end: To be deleted later ==================


//从起始于位置p的n个元素中选出最大者
template <typename T> 
ListNodePosi<T> List<T>::selectMax( ListNodePosi<T> p, Rank n ) {
   ListNodePosi<T> max = p; //最大者暂定为首节点p
   for ( ListNodePosi<T> cur = p; 1 < n; n-- ) //从首节点p出发，将后续节点逐一与max比较
   {
      if(cur == trailer || cur->succ == trailer) {
         printf("List<T>::selectMax: error: surpass list bound\n");
         exit(1);
      }
      if ( !lt( ( cur = cur->succ )->data, max->data ) ) //若当前元素不小于max，则
         max = cur; //更新最大元素位置记录
   }

   return max; //返回最大节点位置
}