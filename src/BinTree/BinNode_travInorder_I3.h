/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

// template <typename T, typename VST> //元素类型、操作器
// void travIn_I3( BinNodePosi<T> x, VST& visit ) { //二叉树中序遍历算法（迭代版#3，无需辅助栈）
//    printf("travIn_I3\n");
   
//    bool backtrack = false; //前一步是否刚从左子树回溯——省去栈，仅O(1)辅助空间
//    while ( true ) {
//       if ( !backtrack && HasLChild( *x ) ) //若有左子树且不是刚刚回溯，则
//          x = x->lc; //深入遍历左子树
//       else { //否则——无左子树或刚刚回溯（相当于无左子树）
//          visit( x->data ); //访问该节点
//          if ( HasRChild( *x ) ) { //若其右子树非空，则
//             x = x->rc; //深入右子树继续遍历
//             backtrack = false; //并关闭回溯标志
//          } else { //若右子树空，则 now, x can be left child, right child, or the root
//             if ( !( x = x->succ() ) ) break; //回溯（含抵达末节点时的退出返回）
//             backtrack = true; //并设置回溯标志
//          }
//       }
//    }
// }


// // backtrack + succ()
// template <typename T, typename VST> //元素类型、操作器
// void travIn_I3( BinNodePosi<T> x, VST& visit ) { //二叉树中序遍历算法（迭代版#3，无需辅助栈）
//    printf("travIn_I3\n");
   
//    bool backtrack = false;

//    while (true)
//    {
//       if(backtrack==false && HasLChild(*x)) {
//          x = x->lc;
//       } else {
//          visit(x->data);
//          if(HasRChild(*x)) {
//             backtrack = false;
//             x = x->rc;
//          } else {
//             backtrack = true;
//             x = x->succ();
//             if(nullptr == x) {
//                return;
//             }
//          }
//       }
//    }
// }


template <typename T, typename VST>
void travIn_I3(BinNodePosi<T> x, VST& visit) {
   printf("src/BinTree/BinNode_travInorder_I3.h  003 \n");

   bool backtrack = false;

   while (true)
   {
      if((backtrack == false) && (x->lc)) {
         x = x->lc;
      } else {
         visit(x->data);
         if(x->rc) {
            x = x->rc;
            backtrack = false;
         } else {
            x = x->succ();
            if(nullptr == x) {
               return;
            }
            backtrack = true;
         }
      }   
   }  
}