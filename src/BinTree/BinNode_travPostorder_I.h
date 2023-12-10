/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //在以S栈顶节点为根的子树中，找到最高左侧可见叶节点
static void gotoLeftmostLeaf( Stack<BinNodePosi<T>>& stack ) { //沿途所遇节点依次入栈
   if(stack.empty()) return;

   BinNodePosi<T> node;
   while (node = stack.top())
   {
      if(HasLChild(*node)) {
         if(HasRChild(*node)) {
            stack.push(node->rc);
         }
         stack.push(node->lc);
      }else{
         stack.push(node->rc);
      }
   }
   stack.pop();
}

template <typename T, typename VST>
void travPost_I( BinNodePosi<T> x, VST& visit ) { //二叉树的后序遍历（迭代版）
   printf("travPost_I\n");

   if(nullptr == x) return;

   Stack<BinNodePosi<T>> stack;
   stack.push(x);
   while (!stack.empty())
   {
      if(stack.top() != x->parent) { 
         gotoLeftmostLeaf(stack);
      }
      x = stack.pop();
      visit(x->data);
   }
}
