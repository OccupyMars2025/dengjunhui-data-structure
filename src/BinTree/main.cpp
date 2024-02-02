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

template <typename T>
struct PrintData
{
   void operator()(const T& e) {
      print(e);
   }
};

template <typename T>
struct CollectTraversalSequence {
   Queue<T>& queue;

   CollectTraversalSequence(Queue<T>& queue) : queue(queue) {}
   void operator()(const T& e) {
      queue.enqueue(e);
   }
};

template <typename T>
void compare_traversal_sequences(BinTree<T>& bintree, int preorder_inorder_postorder, int algorithm_1, int algorithm_2) 
{
   Queue<T> queue001, queue002;

   CollectTraversalSequence<T> * collect_traversal_sequence001 = new CollectTraversalSequence<T>(queue001);
   CollectTraversalSequence<T> * collect_traversal_sequence002 = new CollectTraversalSequence<T>(queue002);
   
   switch (preorder_inorder_postorder)
   {
   case 0:
      // preorder
      printf("Validate preorder:\n");
      bintree.travPre(*collect_traversal_sequence001, algorithm_1);
      bintree.travPre(*collect_traversal_sequence002, algorithm_2);
      break;

   case 1:
      // inorder
      printf("Validate inorder:\n");
      bintree.travIn(*collect_traversal_sequence001, algorithm_1);
      bintree.travIn(*collect_traversal_sequence002, algorithm_2);
      break;
   
   default:
      assert(0);
      break;
   }
 
   assert(queue001.size() == queue002.size());
   assert(queue001.size() > 0);
   while (queue001.empty() == false)
   {
      T data001 = queue001.dequeue();
      T data002 = queue002.dequeue();
      assert(data001 == data002);
      print(data001);
   }
   printf("\nSuccess: The 2 traversal sequences are the same\n\n");
}



int testID = 0; //测试编号

// 随机生成期望高度为h的二叉树
template <typename T> 
bool randomBinTree ( BinTree<T> & bt, BinNodePosi<T> x, int h ) {
   if ( 0 >= h ) return false; //至多h层
   if ( 0 < dice ( h ) ) //以1/h的概率终止当前分支的生长
      randomBinTree ( bt, bt.insertAsRC ( x, dice ( ( T ) h * h * h ) ), h - 1 );
   if ( 0 < dice ( h ) ) //以1/h的概率终止当前分支的生长
      randomBinTree ( bt, bt.insertAsLC ( x, dice ( ( T ) h * h * h ) ), h - 1 );
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
void checkPredecessorAndSuccessor(BinTree<T> &binary_tree) {
   if(binary_tree.size() == 0) {
      printf("Error: empty tree\n");
      exit(1);
   }
   BinNodePosi<T> node = binary_tree.root();
   BinNodePosi<T> predecessor, successor;

   int count = 1;
   while (0 < count--)
   {
      while (predecessor = node->pred())
      {
         assert(predecessor->succ() == node);
         node = predecessor;
      }
      
      print(node->data);
      while (successor = node->succ())
      {
         print(successor->data);
         assert(successor->pred() == node);
         node = successor;
      }
      printf("\n");
   }
}

template <typename T> 
void  testBinTree ( int h ) { //测试二叉树
   printf ( "\n  ==== Test %2d. Generate a BinTree of height <= %d \n", testID++, h );
   BinTree<T> bt; 
   print ( bt );
   
   bt.insertAsRoot ( dice ( ( T ) h * h * h ) ); 
   print ( bt );

   randomBinTree<T> ( bt, bt.root(), h ); 
   print ( bt );
   
   // printf ( "\n  ==== Test %2d. Double and increase all nodes by traversal\n", testID++ );
   printf ( "\n  ==== Test %2d. validate different traversal algorithms\n", testID++ );
   Double<T> *double_visit = new Double<T>();
   Increase<T> *increase_visit = new Increase<T>();
   Constant<T>* assign_constant_visit = new Constant<T>(3);
   CheckIfEqual<T> *check_if_equal_visit = new CheckIfEqual<T>(4);
   PrintData<T> *print_data_visit = new PrintData<T>();

   print(bt); 
   // compare_traversal_sequences(bt, 0, 0, 2);
   // compare_traversal_sequences(bt, 1, 0, 1);
   // compare_traversal_sequences(bt, 1, 0, 2);
   // compare_traversal_sequences(bt, 1, 0, 3);
   compare_traversal_sequences(bt, 1, 0, 4);
   // bt.travPre ( *print_data_visit, 0 );
   // printf("\n");
   // // bt.travPre ( *double_visit, 0 );
   // bt.travPre ( *print_data_visit, 1 ); 
   // printf("\n");
   // bt.travPre ( *increase_visit, 0 ); 
   // print ( bt );
   // bt.travPre(*assign_constant_visit, 0);
   // print(bt);
   // bt.travIn(*check_if_equal_visit);

   // bt.travIn ( *double_visit ); 
   // bt.travIn ( *increase_visit ); 
   // print ( bt );
   // checkPredecessorAndSuccessor(bt);
   // travIn_R(bt.root(), *print_data_visit);
   // printf("\n");
   
   // travIn_I4(bt.root(), *assign_constant_visit);
   // print(bt);
   // travIn_I4(bt.root(), *increase_visit);
   // print(bt);
   // travIn_R(bt.root(), *check_if_equal_visit);

   // bt.travPost ( *double_visit ); 
   // bt.travPost ( *increase_visit ); 
   // print ( bt );
   // bt.travPost(*assign_constant_visit);
   // print(bt);
   // bt.travIn(*check_if_equal_visit);


   

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
   if ( 2 > argc ) { 
      printf ( "Usage: %s <size of test>\n", argv[0] ); 
      return 1; 
   }
   srand ( ( unsigned int ) time ( NULL ) );
   testBinTree<int> ( atoi ( argv[1] ) ); //元素类型可以在这里任意选择
   return 0;
}