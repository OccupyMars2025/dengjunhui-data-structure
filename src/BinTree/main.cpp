/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include "BinTree_test.h"
#include <cassert>

template <typename T>
struct Constant
{
   T value;
   Constant(T value): value(value) {}

   void operator()(T& e) {
      e = value;
   }
};

template <typename T>
struct CheckIfEqual
{
   T value;
   CheckIfEqual(T value): value(value) {}

   void operator()(const T& e) {
      assert(e == value);
   }
};


int testID = 0; //测试编号

// 随机生成期望高度为h的二叉树
template <typename T> 
bool randomBinTree ( BinTree<T> & bt, BinNodePosi<T> x, int h ) {
   if ( 0 >= h ) return false; //至多h层
   if ( 0 < dice ( h ) ) //以1/h的概率终止当前分支的生长
      randomBinTree ( bt, bt.insert ( x, dice ( ( T ) h * h * h ) ), h - 1 );
   if ( 0 < dice ( h ) ) //以1/h的概率终止当前分支的生长
      randomBinTree ( bt, bt.insert ( dice ( ( T ) h * h * h ), x ), h - 1 );
   return true;
}

// 在二叉树中随机确定一个节点位置
template <typename T> 
BinNodePosi<T> randomPosiInBinTree ( BinNodePosi<T> root ) {
   if ( !HasChild ( *root ) ) return root;
   if ( !HasLChild ( *root ) )
      return dice ( 6 ) ? randomPosiInBinTree ( root->rc ) : root;
   if ( !HasRChild ( *root ) )
      return dice ( 6 ) ? randomPosiInBinTree ( root->lc ) : root;
   return dice ( 2 ) ?
          randomPosiInBinTree ( root->lc ) :
          randomPosiInBinTree ( root->rc ) ;
}

template <typename T> 
void  testBinTree ( int h ) { //测试二叉树
   printf ( "\n  ==== Test %2d. Generate a BinTree of height <= %d \n", testID++, h );
   BinTree<T> bt; 
   print ( bt );
   
   bt.insert ( dice ( ( T ) h * h * h ) ); 
   print ( bt );

   randomBinTree<T> ( bt, bt.root(), h ); 
   print ( bt );
   
   printf ( "\n  ==== Test %2d. Double and increase all nodes by traversal\n", testID++ );
   Double<T> *double_visit = new Double<T>();
   Increase<T> *increase_visit = new Increase<T>();
   Constant<T>* assign_constant_visit = new Constant<T>(3);
   CheckIfEqual<T> *check_if_equal_visit = new CheckIfEqual<T>(3);

   // bt.travPre ( *double_visit ); 
   // bt.travPre ( *increase_visit ); 
   // print ( bt );

   // bt.travIn ( *double_visit ); 
   // bt.travIn ( *increase_visit ); 
   // print ( bt );
   
   bt.travPost ( *double_visit ); 
   bt.travPost ( *increase_visit ); 
   print ( bt );
   bt.travPost(*assign_constant_visit);
   print(bt);
   bt.travIn(*check_if_equal_visit);


   

   // bt.travLevel ( *double_visit ); 
   // bt.travLevel ( *increase_visit ); 
   // print ( bt );

   // printf("check Hailstone\n");
   // Hailstone<T> hs; 
   // bt.travIn ( hs ); 
   // print ( bt );

//    printf ( "\n  ==== Test %2d. Remove/release subtrees in the Tree\n", testID++ );
//    while ( !bt.empty() ) {
//       BinNodePosi<T> p = randomPosiInBinTree ( bt.root() ); //随机选择一个节点
//       if ( dice ( 2 ) ) {
//          printf ( "removing " ); 
//          print ( p->data ); 
//          printf ( " ...\n" );

//          printf ( "%d node(s) removed\n", bt.remove ( p ) ); 
//          print ( bt );
//       } else {
//          printf ( "releasing " ); 
//          print ( p->data ); 
//          printf ( " ...\n" );

//          BinTree<T>* S = bt.secede ( p ); 
//          print ( S );
//          printf ( "%d node(s) released\n", S->size() ); 
//          release ( S ); 
//          print ( bt );
//       }
//    }
}

int main ( int argc, char* argv[] ) { //测试二叉树
   if ( 2 > argc ) { printf ( "Usage: %s <size of test>\n", argv[0] ); return 1; }
   srand ( ( unsigned int ) time ( NULL ) );
   testBinTree<int> ( atoi ( argv[1] ) ); //元素类型可以在这里任意选择
   return 0;
}