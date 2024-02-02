/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

// /**
//  * Just an equivalent version of "travIn_I1"
// */
// template <typename T, typename VST> //元素类型、操作器
// void travIn_I2( BinNodePosi<T> x, VST& visit) { //二叉树中序遍历算法（迭代版#2）
//    printf("travIn_I2\n");
   
//    Stack<BinNodePosi<T>> S; //辅助栈
//    while ( true ) {
//       if ( x ) {
//          S.push( x ); //根节点进栈
//          x = x->lc; //深入遍历左子树
//       } else if ( !S.empty() ) {
//          x = S.pop(); //尚未访问的最低祖先节点退栈
//          visit( x->data ); //访问该祖先节点
//          x = x->rc; //遍历祖先的右子树
//       } else
//          break; //遍历完成
//    }
// }




template <typename T, typename VST>
void travIn_I2(BinNodePosi<T> x, VST& visit) {
   printf("src/BinTree/BinNode_travInorder_I2.h  002\n");

   Stack<BinNodePosi<T>> stack;

   while (true)
   {
      if(x) {
         stack.push(x);
         x = x->lc;
      }else if(stack.empty() == false) {
         x = stack.pop();
         visit(x->data);
         x = x->rc;
      } else {
         return;
      }
   }
}
