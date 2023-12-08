/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * 将Print各方法的实现部分，简洁地引入Print.h
 * 效果等同于将这些实现直接汇入Print.h
 * 在export尚未被编译器支持前，如此可将定义与实现分离，以便课程讲解
 ******************************************************************************************/

// #include "print_BinNode.h"
// #include "print_BinTree.h"
// #include "print_BTree.h"
// #include "print_PQ_List.h"
// #include "print_PQ_ComplHeap.h"
// #include "print_PQ_LeftHeap.h"
// #include "print_Entry.h"
// #include "print_Quadlist.h"
// #include "print_Skiplist.h"
// #include "print_Hashtable.h"
// #include "print_GraphMatrix.h"

#include "print_traversable.cpp"
#include "print_basic.cpp"