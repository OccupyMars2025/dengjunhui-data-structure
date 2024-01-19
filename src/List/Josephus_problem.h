/**
 * https://en.wikipedia.org/wiki/Josephus_problem
*/
#pragma once

#include "List/List_implementation.h"

// ========== start: attempt 1 ========
// /*
// Error: this function reports the error "Segmentation fault (core dumped)"
// Can you see why ?

// Very interesting ! The logic is correct, when we exit this function, 
// the destructor of List will be called, but the directions of some pointers have been changed,
// so the destructor fails ! It seems that I have to declare a subclass CircularList in which I have
// to rewrite the destructor
// */
// int josephus(int n, int k) {
//     assert((n > 1) && (k > 0));

//     List<int> circle;
//     for(int i = 1; i <= n; ++i) {
//         circle.insertAsLast(i);
//     }
//     ListNodePosi<int> first = circle.first();
//     ListNodePosi<int> last = circle.last();
//     first->pred = last;
//     last->succ = first;
//     // now the circle has been constructed

//     ListNodePosi<int> p = first;
//     while (circle.size() > 1)
//     {
//         for(int i = 1; i <= k; ++i) {
//             p = p->succ;
//         }
//         circle.remove(p->pred);
//     }

//     return p->data;
// }
// ========== end: attempt 1 ========


// // ========== start: attempt 2 ========
// /*
// the "header" node is in the circular list, so "counting k" and "remove"
// becomes tedious, the 2nd attempt fails
// */
// template <typename T>
// class CircularList: List<T>{
// private:
//     ListNodePosi<T> header;
//     Rank _size;

// public:
//     CircularList() {
//         header = new ListNode<T>();
//         header->succ = header;
//         header->pred = header;
//         _size = 0;
//     }

//     ~CircularList() {
//         while (header->succ != header)
//         {
//             remove(header->succ);
//         }
//         delete header;
//         // std::cout << "~CircularList()" << std::endl;
//     }

//     ListNodePosi<T> insertAsFirst( T const& e ) {
//         // It seems this->insertAsFirst(e) doesn't work
//         return List<T>::insertAsFirst(e);
//     }

//     ListNodePosi<T> first() const {
//         return header->succ;
//     }

//     Rank size() const {
//         return _size;
//     }

//     T remove( ListNodePosi<T> p ) {
//         // return this->remove(p);
//         return List<T>::remove(p);
//     }
// };


// int josephus(int n, int k) {
//     assert((n > 1) && (k > 0));

//     CircularList<int> circle;
//     for(int i = n; i >= 1; --i) {
//         circle.insertAsFirst(i);
//     }

//     ListNodePosi<int> p = circle.first();
//     while (circle.size() > 1)
//     {
//         for(int i = 1; i <= k; ++i) {
//             p = p->succ;
//         }
//         circle.remove(p->pred);
//     }

//     return p->data;
// }

// ========== end: attempt 2 ========






// ========== start: attempt 3 ========
/*
1. don't derive from List
2. no sentinel node in the circular list


drawback: circle.remove(p->pred)  may remove the "first" node
*/
// template <typename T>
// class CircularList{
// public:
//     ListNodePosi<T> first;
//     Rank _size;

//     CircularList() {
//         first = NULL;
//         _size = 0;
//     }

//     ~CircularList() {
//         while (_size > 1)
//         {
//             remove(first->succ);
//         }
//         if(_size == 1) {
//             delete first;
//             _size = 0;
//         }
//     }

//     ListNodePosi<T> insertAsLast( T const& e ) {
//         if(0 == _size) {
//             first = new ListNode<T>(e);
//             first->succ = first;
//             first->pred = first;
//             ++_size;
//             return first;
//         } else {
//             ListNodePosi<T> new_node = new ListNode<T>(e);
//             new_node->pred = first->pred;
//             new_node->succ = first;

//             first->pred->succ = new_node;
//             first->pred = new_node;
//             ++_size;
//             return new_node;
//         }
//     }

//     ListNodePosi<T> first_node() {
//         return first;
//     }

//     Rank size(){
//         return _size;
//     }

//     T remove( ListNodePosi<T> p ) {
//         T data = p->data;
//         if(_size > 1) {
//             p->pred->succ = p->succ;
//             p->succ->pred = p->pred;
//             delete p;
//         } else {
//             // size = 1
//             assert(p == first);
//             delete first;
//             first = NULL;
//         }
//         --_size;

//         return data;
//     }
// };


// int josephus(int n, int k) {
//     assert((n > 1) && (k > 0));

//     CircularList<int> circle;
//     for(int i = 1; i <= n; ++i) {
//         circle.insertAsLast(i);
//     }

//     ListNodePosi<int> p = circle.first_node();
//     while (circle.size() > 1)
//     {
//         for(int i = 1; i <= k; ++i) {
//             p = p->succ;
//         }
//         circle.remove(p->pred);
//     }

//     return p->data;
// }
// ========== end: attempt 3 ========


// ========== start: attempt 4 ========
/*
don't declare a new class, just use ListNode directly in jesephus()
*/


int josephus(int n, int k) {
    assert((n > 1) && (k > 0));

    ListNodePosi<int> first = new ListNode<int>(1);
    first->succ = first;
    first->pred = first;
    ListNodePosi<int> p = first;
    for(int i = 2; i <= n; ++i) {
        p = p->insertAsSucc(i);
    }

    p = first;
    ListNodePosi<int> p2;
    while (p->succ != p)
    {
        for(int i = 1; i <= k; ++i) {
            p = p->succ;
        }
        // now delete p->pred
        p2 = p->pred;
        p2->pred->succ = p;
        p->pred = p2->pred;
        delete p2;
        p2 = NULL;
    }

    return p->data;
}

// ========== end: attempt 4 ========
