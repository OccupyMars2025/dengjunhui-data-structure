/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once
#include <cassert>

template <typename T>
static BinNodePosi<T> goAlongLeftBranchWhenPossible(BinNodePosi<T> x) {
   while (true)
   {
      if(x->lc) {
         x = x->lc;
      } else if (x->rc) {
         x = x->rc;
      } else {
         return x;
      }
   }
}


/*
Don't use the stack
*/
template <typename T, typename VST>
void travPost_I1(BinNodePosi<T> x, VST& visit) {
   printf("src/BinTree/BinNode_travPostorder_I1.h  001\n");

   while (true)
   {
      x = goAlongLeftBranchWhenPossible(x);
      visit(x->data);

      /**
       * the core part: Discussing it case by case.
       * now x has been visited, so the subtree that has x as the root has been traversed
       * 
       * case 1: (IsLChild(*x) && (x->parent->rc == nullptr))
       * case 2: (IsLChild(*x) && (x->parent->rc != nullptr))
       * case 3: (IsRChild(*x))
       * case 4: (IsRoot(*x))
      */
      while (IsRChild(*x) || (IsLChild(*x) && (x->parent->rc == nullptr)))
      {
         x = x->parent;
         visit(x->data);
      }

      /*
      caution: now, "visit(x->data)" must have been executed,
      you don't need to visit x again
      */
      if(IsRoot(*x)) {
         // visit(x->data);
         return;
      } else {
         x = x->parent->rc;
      }
   }
}