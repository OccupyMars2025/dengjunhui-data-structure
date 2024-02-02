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
// template <typename T, typename VST> //Ԫ�����͡�������
// void travPre_I1( BinNodePosi<T> x, VST& visit ) { //��������������㷨��������#1��
//    printf("travPre_I1\n");
   
//    Stack<BinNodePosi<T>> S; //����ջ
//    if ( x ) S.push( x ); //���ڵ���ջ
//    while ( !S.empty() ) { //��ջ���֮ǰ����ѭ��
//       x = S.pop(); 
//       visit( x->data ); //���������ʵ�ǰ�ڵ㣬��ǿպ��ӵ���ջ����Ϊ���Һ���
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