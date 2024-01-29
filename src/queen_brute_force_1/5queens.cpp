/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include "queen.h"

void place5Queens_BruteForce() { //5皇后蛮力算法
   /*
   solu[i] means one queen is in the row i, column solu[i]
   */
   int solu[5]; //解法
   int nCandidate = 0; //候选解总数
   for ( solu[0] = 0; solu[0] < 5; solu[0]++ )
      for ( solu[1] = 0; solu[1] < 5; solu[1]++ )
         for ( solu[2] = 0; solu[2] < 5; solu[2]++ )
            for ( solu[3] = 0; solu[3] < 5; solu[3]++ )
               for ( solu[4] = 0; solu[4] < 5; solu[4]++ ) {
                  nCandidate++;
                  /* waste too much computing resources
                  if solu[0] = solu[1], then collide ( solu, 1 ) will always return true 
                  no matter what values solu[2], solu[3], solu[4] take
                  */
                  if ( collide ( solu, 0 ) ) continue;
                  if ( collide ( solu, 1 ) ) continue;
                  if ( collide ( solu, 2 ) ) continue;
                  if ( collide ( solu, 3 ) ) continue;
                  if ( collide ( solu, 4 ) ) continue;
                  nSolu++; displaySolution ( solu, 5 );
               }
   printf ( "%d Queens, %d Solution(s), %d Candidate(s), %d Check(s)\n\a\a", 5, nSolu, nCandidate, nCheck ); //输出解的总数
}