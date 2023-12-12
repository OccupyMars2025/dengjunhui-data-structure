/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

//在有序列表内节点p（可能是trailer）的n个真前驱中，找到不大于e的最后者
template <typename T> 
ListNodePosi<T> List<T>::search( T const& e, Rank n, ListNodePosi<T> p ) const {
   for(int count=1; count <= n; ++count) {
      p = p->pred;
      if(p == header) {
         return header;
      }
      if(p->data <= e) {
         return p;
      }
   }
   return p->pred;  //返回最终停止的位置
} //失败时返回区间左边界的前驱（可能是header）——调用者可据此判断查找是否成功