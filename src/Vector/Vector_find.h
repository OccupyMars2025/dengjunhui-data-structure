/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

//������������˳�����e���ɹ��򷵻����ĳ���λ�ã����򷵻�lo-1
template <typename T> 
Rank Vector<T>::find ( T const& e, Rank lo, Rank hi ) const { //0 <= lo < hi <= _size
   while (lo <= --hi)
   {
      if (e == _elem[hi]){
         break;
      }
   }   
   return hi; 
}
