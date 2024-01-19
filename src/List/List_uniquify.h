/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

// template <typename T> 
// Rank List<T>::uniquify() { //成批剔除重复元素，效率更高
//    if ( _size < 2 ) return 0; //平凡列表自然无重复
//    Rank oldSize = _size; //记录原规模
//    ListNodePosi<T> p = first(); ListNodePosi<T> q; //p为各区段起点，q为其后继
//    while ( trailer != ( q = p->succ ) ) //反复考查紧邻的节点对(p, q)
//       if ( p->data != q->data ) p = q; //若互异，则转向下一区段
//       else remove( q ); //否则（雷同）直接删除后者，不必如向量那样间接地完成删除
//    return oldSize - _size; //列表规模变化量，即被删除元素总数
// }



// // the p3 is not necessary
// template <typename T> 
// Rank List<T>::uniquify() { 
//    if(_size < 2) return 0;

//    Rank old_size = _size;
//    ListNodePosi<T> p1 = header->succ, p2 = p1->succ, p3; 
//    while(p2 != trailer) {
//       if(p1->data == p2->data) {
//          p3 = p2->succ;
//          remove(p2);
//          p2 = p3;
//       } else {
//          p1 = p2;
//          p2 = p2->succ;
//       }
//    }

//    return old_size - _size;
// }


template <typename T> 
Rank List<T>::uniquify() {
   // std::cout << "src/List/List_uniquify.h " << std::endl;
   if(_size < 2) return 0;

   Rank old_size = _size;

   ListNodePosi<T> p1 = header->succ, p2 = p1->succ;
   while (p2 != trailer)
   {
      if(p1->data == p2->data) {
         remove(p2);
      } else {
         p1 = p2;
      }
      p2 = p1->succ;
   }
   
   return old_size - _size;
}