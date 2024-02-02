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
// template <typename T, typename VST> //Ԫ�����͡�������
// void travIn_I2( BinNodePosi<T> x, VST& visit) { //��������������㷨��������#2��
//    printf("travIn_I2\n");
   
//    Stack<BinNodePosi<T>> S; //����ջ
//    while ( true ) {
//       if ( x ) {
//          S.push( x ); //���ڵ��ջ
//          x = x->lc; //�������������
//       } else if ( !S.empty() ) {
//          x = S.pop(); //��δ���ʵ�������Ƚڵ���ջ
//          visit( x->data ); //���ʸ����Ƚڵ�
//          x = x->rc; //�������ȵ�������
//       } else
//          break; //�������
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
