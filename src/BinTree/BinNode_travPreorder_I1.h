/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "Stack/Stack.h"

// /**
//  * Because the recursive version is a kind of "tail call",
//  * so we can get the iterative version as follows
// */
// template <typename T, typename VST> //元素类型、操作器
// void travPre_I1( BinNodePosi<T> x, VST& visit ) { //二叉树先序遍历算法（迭代版#1）
//    printf("travPre_I1\n");
   
//    Stack<BinNodePosi<T>> S; //辅助栈
//    if ( x ) S.push( x ); //根节点入栈
//    while ( !S.empty() ) { //在栈变空之前反复循环
//       x = S.pop(); 
//       visit( x->data ); //弹出并访问当前节点，其非空孩子的入栈次序为先右后左
//       if ( HasRChild( *x ) ) S.push( x->rc );
//       if ( HasLChild( *x ) ) S.push( x->lc );
//    }
// }


// template <typename T, typename VST>
// void travPre_I1(BinNodePosi<T> node, VST &visit) {
//    printf("travPre_I1: my rewriting\n");
//    if(nullptr == node) return;

//    Stack<BinNodePosi<T>> stack;
//    stack.push(node);
//    while (!stack.empty())
//    {
//       node = stack.pop();
//       visit(node->data);

//       if(HasRChild(*node)) {
//          stack.push(node->rc);
//       }

//       if(HasLChild(*node)) {
//          stack.push(node->lc);
//       }      
//    }
// }


template <typename T, typename VST>
void travPre_I1(BinNodePosi<T> x, VST& visit) {
   printf("src/BinTree/BinNode_travPreorder_I1.h  004\n");
   Stack<BinNodePosi<T>> stack;
   stack.push(x);

   while (stack.empty() == false)
   {
      x = stack.pop();
      if(x) {
         visit(x->data);
         stack.push(x->rc);
         stack.push(x->lc);
      }
   }
}