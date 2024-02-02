/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

// template <typename T, typename VST> //Ԫ�����͡�������
// void travIn_I4( BinNodePosi<T> x, VST& visit ) { //���������������������#4������ջ���־λ��
//    printf("travIn_I4\n");
   
//    while ( true )
//       if ( HasLChild( *x ) ) //��������������
//          x = x->lc; //�������������
//       else { //����
//          visit ( x->data ); //���ʵ�ǰ�ڵ㣬��
//          while ( !HasRChild( *x ) ) //���ϵ������ҷ�֧��
//             if ( ! ( x = x->succ() ) ) return; //������ֱ�Ӻ�̣���û�к�̵�ĩ�ڵ㴦��ֱ���˳���
//             else visit ( x->data ); //�����µĵ�ǰ�ڵ�
//          x = x->rc; //��ֱ�����ҷ�֧����ת��ǿյ�������
//       }
// }


// template <typename T, typename VST> //Ԫ�����͡�������
// void travIn_I4( BinNodePosi<T> node, VST& visit ) { //���������������������#4������ջ���־λ��
//    while (true)
//    {
//       if(HasLChild(*node)) {
//          node = node->lc;
//       } else {
//          visit(node->data);
//          while (!HasRChild(*node)) {
//             node = node->succ();
//             if(nullptr == node){
//                return;
//             }
//             visit(node->data);
//          }
//          node = node->rc;
//       }
//    }
// }



/**
 * 1. Don't use stack
 * 2. Don't use "backtrack"
 * 3. Use succ()
*/
template <typename T, typename VST>
void travIn_I4(BinNodePosi<T> x, VST& visit) {
   printf("src/BinTree/BinNode_travInorder_I4.h  003\n");

   while (true)
   {
      while (x->lc)
      {
         x = x->lc;
      }

      visit(x->data);

      while (x->rc == nullptr)
      {
         x = x->succ();
         if(x == nullptr) {
            return;
         }
         visit(x->data);
      }
      x = x->rc;
   }
}


