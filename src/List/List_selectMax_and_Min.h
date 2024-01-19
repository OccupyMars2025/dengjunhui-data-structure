/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

//从起始于位置p的n个元素中选出最大者
// if there are multiple maximum elements, choose that with the largest index,
// so that the selection sort which uses selectMax() is stable 
template <typename T> 
ListNodePosi<T> List<T>::selectMax( ListNodePosi<T> p, Rank n ) {
   ListNodePosi<T> max = p; //最大者暂定为首节点p
   for ( ListNodePosi<T> cur = p; 1 < n; n-- ) //从首节点p出发，将后续节点逐一与max比较
   {
      if(cur == trailer || cur->succ == trailer) {
         printf("List<T>::selectMax: error: surpass list bound\n");
         exit(1);
      }
      // Caution: pay attention to the "equality" situation
      if ( !lt( ( cur = cur->succ )->data, max->data ) ) //若当前元素不小于max，则
         max = cur; //更新最大元素位置记录
   }

   return max; //返回最大节点位置
}


//从起始于位置p的n个元素中选出最小者
// if there are multiple minimum elements, choose that with the smallest index,
// so that the selection sort which uses selectMin() is stable 
template <typename T> 
ListNodePosi<T> List<T>::selectMin( ListNodePosi<T> p, Rank n ) {
   ListNodePosi<T> pointer_to_min = p;

   for(Rank i = 1; i < n; ++i) {
      p = p->succ;
      // don't use "<="
      if(p->data < pointer_to_min->data) {
         pointer_to_min = p;
      }
   }

   return pointer_to_min;
}