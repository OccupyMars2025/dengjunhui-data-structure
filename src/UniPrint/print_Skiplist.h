/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * Skiplist
 ******************************************************************************************/

template <typename K, typename V> //e��value
void UniPrint::p ( Skiplist<K, V>& s ) { //����
   printf ( "[name]%s  [address]%p  [height]%d   [size]%d:\n", typeid ( s ).name(), (void*) &s, s.height(), s.size() ); //������Ϣ
   s.traverse ( print ); //ͨ��print()�����������Ԫ��
   printf ( "\n" );
}
