/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

// template <typename T> 
// Rank Vector<T>::uniquify() { //有序向量重复元素剔除算法（高效版）
//    Rank i = 0, j = 0; //各对互异“相邻”元素的秩
//    while ( ++j < _size ) //逐一扫描，直至末元素
//       if ( _elem[i] != _elem[j] ) //跳过雷同者
//          _elem[++i] = _elem[j]; //发现不同元素时，向前移至紧邻于前者右侧
//    _size = ++i; shrink(); //直接截除尾部多余元素
//    return j - i; //向量规模变化量，即被删除元素总数
// }


// template <typename T> 
// Rank Vector<T>::uniquify() {
//    Rank oldSize = _size, i = 1, j;
//    while (i < _size)
//    {
//       if (_elem[i] != _elem[i-1]) {
//          ++i;
//       } else {
//          for(j = i + 1; j < _size; ++j) {
//             if(_elem[j] != _elem[i-1]) {
//                break;
//             }
//          }
//          remove(i, j);
//       }
//    }
   
//    return oldSize - _size;
// }


// template <typename T> 
// Rank Vector<T>::uniquify() {
//    Rank oldSize = _size;
//    Rank i = 0, j = 1;
//    while (j < _size) {
//       if (_elem[i] != _elem[j]) {
//          ++i;
//          _elem[i] = _elem[j];
//       }
//       ++j;
//    }
//    _size = i + 1;
//    shrink();

//    return oldSize - _size;
// }



template <typename T> 
Rank Vector<T>::uniquify() {
   printf("src/Vector/Vector_uniquify.h  v3\n");
   Rank oldSize = _size;
   Rank i = 0;
   for(Rank j = 1; j < _size; ++j)
   {
      if(_elem[j] != _elem[i]) {
         ++i;
         _elem[i] = _elem[j];
      }
   }
   _size = i + 1;
   shrink();

   return oldSize - _size;
}