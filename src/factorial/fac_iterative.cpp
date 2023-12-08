/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include "factorial/fac.h"

int64_t facI ( int n ) { int64_t f = 1; while ( n > 1 ) f *= n--; return f; } //½×³ËÔËËã£¨µü´ú°æ£©