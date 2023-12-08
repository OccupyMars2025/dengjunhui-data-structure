/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "Vector/Vector.h"

template <typename T> 
void crc ( Vector<T> & V ) { //ͳ������������������Ԫ��֮�ͣ�
   T crc = 0; 
   Crc<T> *visit = new Crc<T> ( crc );
   V.traverse ( *visit ); //��crcΪ�����������б���
   printf ( "total_sum =" ); print ( crc ); printf ( "\n" ); //���ͳ�Ƶõ�������
}