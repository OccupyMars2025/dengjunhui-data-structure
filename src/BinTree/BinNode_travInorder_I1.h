/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

// template <typename T> //�ӵ�ǰ�ڵ�����������֧�������룬ֱ��û�����֧�Ľڵ�
// static void goAlongLeftBranch( BinNodePosi<T> x, Stack<BinNodePosi<T>>& S ) {
//    while ( x ) { 
//       S.push( x ); 
//       x = x->lc; 
//    } //��ǰ�ڵ���ջ���漴������֧���룬����ֱ��������
// }

// /*
// think of the visit(node) + inorder(subtree) method, 
// check the path of inorder
// page 128, picture 5.19
// */
// template <typename T, typename VST> //Ԫ�����͡�������
// void travIn_I1( BinNodePosi<T> x, VST& visit ) { //��������������㷨��������#1��
//    printf("travIn_I1\n");
   
//    Stack<BinNodePosi<T>> S; //����ջ
//    while ( true ) {
//       goAlongLeftBranch( x, S ); //�ӵ�ǰ�ڵ������������ջ
//       if ( S.empty() ) break; //ֱ�����нڵ㴦�����
//       x = S.pop(); 
//       visit( x->data ); //����ջ���ڵ㲢����֮
//       x = x->rc; //ת��������
//    }
// }


template <typename T>
static void goAlongLeftmostPath(BinNodePosi<T> x, Stack<BinNodePosi<T>>& stack) {
   while (x)
   {
      stack.push(x);
      x = x->lc;
   }
}

template <typename T, typename VST>
void travIn_I1(BinNodePosi<T> x, VST& visit) {
   printf("src/BinTree/BinNode_travInorder_I1.h  002 \n");

   Stack<BinNodePosi<T>> stack;
   while (true)
   {
      goAlongLeftmostPath(x, stack);
      if(stack.empty() == true) {
         break;
      }
      x = stack.pop();
      visit(x->data);
      x = x->rc;
   }

   // Stack<BinNodePosi<T>> stack;
   // stack.push(x);
   // while (stack.empty() == false)
   // {
   //    goAlongLeftmostPath(stack.pop(), stack);
   //    if(stack.empty() == true) {
   //       break;
   //    }
   //    x = stack.pop();
   //    if(x) {
   //       visit(x->data);
   //       stack.push(x->rc);
   //    }
   // }
}