/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

//删除合法节点p
template <typename T> 
T List<T>::remove( ListNodePosi<T> p ) { 
   T e = p->data; //备份待删除节点的数值（假定T类型可直接赋值）
   p->pred->succ = p->succ; 
   p->succ->pred = p->pred; //短路联接
   delete p; _size--; //释放节点，更新规模
   return e; //返回备份的数值
} //O(1)