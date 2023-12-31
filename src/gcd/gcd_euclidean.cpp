/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/
#include <cstdint>

// int64_t gcdEU_R ( int64_t a, int64_t b ) { //assert: 0 <= min(a, b)
//    return ( 0 == b ) ? a : gcdEU_R ( b, a % b );
// }

// int64_t gcdEU ( int64_t a, int64_t b ) { //assert: 0 <= min(a, b)
//    while ( true ) {
//       if ( 0 == a ) return b;
//       if ( 0 == b ) return a;
//       if ( a > b ) a %= b;
//       else       b %= a;
//    }
// }


int64_t gcdEU_R ( int64_t a, int64_t b ) { 
   if(0 == b) {
      return a;
   } else {
      return gcdEU_R(b, a % b);
   }
}


int64_t gcdEU (int64_t a, int64_t b) {
   while (true)
   {
      if(0 == a) {
         return b;
      }
      if(0 == b) {
         return a;
      }
      if(a > b) {
         a %= b;
      } else {
         b %= a;
      }
   }
}
