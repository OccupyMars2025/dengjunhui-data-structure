/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

// template <typename T> 
// Rank Vector<T>::uniquify() { //���������ظ�Ԫ���޳��㷨����Ч�棩
//    Rank i = 0, j = 0; //���Ի��조���ڡ�Ԫ�ص���
//    while ( ++j < _size ) //��һɨ�裬ֱ��ĩԪ��
//       if ( _elem[i] != _elem[j] ) //������ͬ��
//          _elem[++i] = _elem[j]; //���ֲ�ͬԪ��ʱ����ǰ����������ǰ���Ҳ�
//    _size = ++i; shrink(); //ֱ�ӽس�β������Ԫ��
//    return j - i; //������ģ�仯��������ɾ��Ԫ������
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