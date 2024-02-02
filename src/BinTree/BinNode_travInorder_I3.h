/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

// template <typename T, typename VST> //Ԫ�����͡�������
// void travIn_I3( BinNodePosi<T> x, VST& visit ) { //��������������㷨��������#3�����踨��ջ��
//    printf("travIn_I3\n");
   
//    bool backtrack = false; //ǰһ���Ƿ�մ����������ݡ���ʡȥջ����O(1)�����ռ�
//    while ( true ) {
//       if ( !backtrack && HasLChild( *x ) ) //�����������Ҳ��Ǹոջ��ݣ���
//          x = x->lc; //�������������
//       else { //���򡪡�����������ոջ��ݣ��൱������������
//          visit( x->data ); //���ʸýڵ�
//          if ( HasRChild( *x ) ) { //�����������ǿգ���
//             x = x->rc; //������������������
//             backtrack = false; //���رջ��ݱ�־
//          } else { //���������գ��� now, x can be left child, right child, or the root
//             if ( !( x = x->succ() ) ) break; //���ݣ����ִ�ĩ�ڵ�ʱ���˳����أ�
//             backtrack = true; //�����û��ݱ�־
//          }
//       }
//    }
// }


// // backtrack + succ()
// template <typename T, typename VST> //Ԫ�����͡�������
// void travIn_I3( BinNodePosi<T> x, VST& visit ) { //��������������㷨��������#3�����踨��ջ��
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