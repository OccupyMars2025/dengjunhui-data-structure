/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "Stack/Stack.h" //引入栈模板类
#include "BinNode_travPostorder_R.h"
#include "BinNode_travPostorder_I1.h"
#include "BinNode_travPostorder_I2.h"

/*
it seems "template <typename T, typename VST>" does not work
*/
template <typename T> template <typename VST> //元素类型、操作器
void BinNode<T>::travPost(VST& visit, int algorithm_id) { //二叉树后序遍历算法统一入口
   // switch ( rand() % 2 ) { //此处暂随机选择以做测试，共两种选择
   switch(algorithm_id){
      case 0 : travPost_R( this, visit ); break; //递归版
      case 1 : travPost_I1( this, visit ); break; //迭代版
      case 2 : travPost_I2( this, visit ); break; //迭代版
      default : 
         assert(0);
         break;
   }
}