/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

// template <typename T> //在以S栈顶节点为根的子树中，找到最高左侧可见叶节点
// static void gotoLeftmostLeaf( Stack<BinNodePosi<T>>& stack ) { //沿途所遇节点依次入栈
//    if(stack.empty()) return;

//    BinNodePosi<T> node;
//    while (node = stack.top())
//    {
//       if(HasLChild(*node)) {
//          if(HasRChild(*node)) {
//             stack.push(node->rc);
//          }
//          stack.push(node->lc);
//       }else{
//          stack.push(node->rc);
//       }
//    }
//    stack.pop();
// }

// template <typename T, typename VST>
// void travPost_I( BinNodePosi<T> x, VST& visit ) { //二叉树的后序遍历（迭代版）
//    printf("travPost_I\n");

//    if(nullptr == x) return;

//    Stack<BinNodePosi<T>> stack;
//    stack.push(x);
//    while (!stack.empty())
//    {
//       if(stack.top() != x->parent) { 
//          gotoLeftmostLeaf(stack);
//       }
//       x = stack.pop();
//       visit(x->data);
//    }
// }

// Wrong !!!!
// template <typename T>
// static void goToDeepestVisibleFromLeftLeafNode(Stack<BinNodePosi<T>> &stack){
//    if (stack.empty()) return;

//    BinNodePosi<T> node;
//    while (node = stack.top())
//    {
//       if(HasRChild(*node)) {
//          stack.push(node->rc);
//       }
//       stack.push(node->lc);
//    }
//    stack.pop();
// }


// template <typename T>
// static void goToDeepestLeafVisibleFromLeft(Stack<BinNodePosi<T>> &stack){
//    if (stack.empty()) return;

//    BinNodePosi<T> node;
//    while (node = stack.top())
//    {
//       if(HasLChild(*node)) {
//          if(HasRChild(*node)) {
//             stack.push(node->rc);
//          }
//          stack.push(node->lc);
//       } else {
//          stack.push(node->rc);
//       }
//    }
//    stack.pop();
// }

// template <typename T, typename VST>
// void travPost_I2(BinNodePosi<T> node, VST& visit) {
//    printf("travPost_I\n");

//    if(nullptr == node) return;

//    Stack<BinNodePosi<T>> stack;
//    stack.push(node);
//    while (!stack.empty())
//    {
//       if(node->parent != stack.top()) {
//          goToDeepestLeafVisibleFromLeft(stack);
//       }
//       node = stack.pop();
//       visit(node->data);
//    }
// }



/*
The core idea of this algorithm:
go along left branch when possible
stack.push(x->rc)
stack.push(x->lc)
*/
template <typename T>
static void goAlongLeftBranchWhenPossible(Stack<BinNodePosi<T>>& stack) {
   if(stack.empty() == true) {
      assert(0);
   }

   BinNodePosi<T> x;
   while (x = stack.top())
   {
      if(x->lc) {
         if(x->rc) {
            stack.push(x->rc);
         }
         stack.push(x->lc);
      }else {
         stack.push(x->rc);
      }
   }
   stack.pop();
}

template <typename T, typename VST>
void travPost_I2(BinNodePosi<T> x, VST& visit) {
   printf("src/BinTree/BinNode_travPostorder_I2.h 003\n");
   if(nullptr == x) {
      return;
   }

   Stack<BinNodePosi<T>> stack;
   stack.push(x);
   while (stack.empty() == false)
   {
      if(x->parent != stack.top()) {
         goAlongLeftBranchWhenPossible(stack);
      }
      x = stack.pop();
      visit(x->data);
   }
}