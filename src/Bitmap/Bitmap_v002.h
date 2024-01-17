/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

#include <cstdlib>
#include <cstdio>
#include <memory.h>
#include <cassert>
#include <iostream>
using Rank = int32_t;

/*
make the initialization and reset more quickly, 
so you don't have to set all the bytes to 0 byte by byte,

this class supports only set() and test() interfaces, 
doesn't support clear() 
*/
class Bitmap_v002
{
private:
   Rank *the_whole_range;
   Rank n;
   Rank *present_elements;
   // top = the number of present elements
   Rank top; 
public:
   void init(Rank n) {
      if (n < 3) n = 3;
      this->n = n;
      the_whole_range = new Rank[n];
      present_elements = new Rank[n];
      top = 0;      
   }
   /*
   n : size of the bitmap
   */
   Bitmap_v002(Rank n = 3) {
      init(n);
   }
   ~Bitmap_v002() {
      delete [] the_whole_range;
      delete [] present_elements;
   }

   Rank size() {
      return top;
   }
   
   void set(Rank k) {
      expand(k);

      if(!test(k)) {
         the_whole_range[k] = top;
         present_elements[top] = k;
         ++top;
      }
   }

   /*
   prove: "test(k) is true" is a necessary and sufficient condition for "k is set"
   proof: apply mathematical induction to "top"
   */
   bool test(Rank k) {
      expand(k);
      Rank i = the_whole_range[k];
      bool is_present = (0 <= i) && (i < top) && (present_elements[i] == k);
      return is_present;
   }

   void reset() {
      top = 0;
   }

   void expand(Rank k) {
      if(k < n) return;

      Rank *old_the_whole_range = the_whole_range;
      Rank old_n = n;
      Rank *old_present_elements = present_elements;
      Rank old_top = top; 
      init(2 * k);

      memcpy(the_whole_range, old_the_whole_range, old_n * sizeof(Rank));
      memcpy(present_elements, old_present_elements, old_top * sizeof(Rank));
      top = old_top;

      delete [] old_the_whole_range;
      delete [] old_present_elements;
   }

   /*
   for any integer i in [0, n), if i is in this set, print "1", else print "0"
   */
   void print(Rank n) {
      expand(n-1);

      for(Rank i = 0; i < n; ++i) {
         std::cout << (test(i) ? "1" : "0");
      }
      std::cout << std::endl;
   }
};

