/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "prime/primeNLT.h"
#include "Entry/Entry.h"

template <typename K, typename V> 
Hashtable <K, V>::Hashtable( Rank c ) { //创建散列表，容量为
   M = primeNLT( c, 1048576, std::string(PRIME_TABLE).c_str()); //不小于c的素数M
   N = 0; ht = new Entry<K, V>*[M]; //开辟桶数组（假定成功）
   memset( ht, 0, sizeof( Entry<K, V>* ) * M ); //初始化各桶
   removed = new Bitmap( M ); //用位图记录懒惰删除位：总数 = removed->size() = removed->top
    // printf("A bucket array has been created with capacity = %d\n\n", M);
}
