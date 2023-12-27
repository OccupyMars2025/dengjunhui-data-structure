/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

// #pragma warning(disable : 4996 4800)
#include <cstdlib>
#include <cstdio>
#include <memory.h>
#include <cstdint>
// #include "_share/release.h"
using Rank = int32_t;

class Bitmap { //位图Bitmap类
private:
   unsigned char* M;
   Rank N, _sz; //位图空间M[]，N*sizeof(char)*8个比特中含_sz个有效位
protected:
   void init( Rank n )
   { 
      M = new unsigned char[N = ( n + 7 ) / 8]; 
      memset( M, 0, N ); 
      _sz = 0; 
   }
public:
   Bitmap( Rank n = 8 ) { init( n ); } //按指定容量创建位图（为测试暂时选用较小的默认值）
   Bitmap( const char* file, Rank n = 8 ) { //按指定或默认规模，从指定文件中读取位图
      init( n );
      FILE* fp = fopen( file, "r" ); 
      fread( M, sizeof( char ), N, fp ); 
      fclose( fp );
      for ( Rank k = 0, _sz = 0; k < n; k++ ) 
         _sz += test(k);
   }
   ~Bitmap() { delete[] M; M = NULL; _sz = 0; } //析构时释放位图空间

   Rank size() { return _sz; }

   void reset() {
      memset( M, 0, N ); 
      _sz = 0; 
   }
   
   void set   ( Rank k ) { 
      expand( k ); 
      if(!test(k)) {
         _sz++; 
         M[k >> 3] |=   ( 0x80 >> ( k & 0x07 ) ); 
      }
   }
   void clear ( Rank k ) { 
      expand( k ); 
      if(test(k)) {
         _sz--; 
         M[k >> 3] &= ~ ( 0x80 >> ( k & 0x07 ) ); 
      }
   }
   bool test  ( Rank k ) { 
      expand( k ); 
      return M[k >> 3] & ( 0x80 >> ( k & 0x07 ) );
   }

   void dump( char* file ) //将位图整体导出至指定的文件，以便对此后的新位图批量初始化
   { 
      FILE* fp = fopen( file, "w" ); 
      fwrite( M, sizeof ( char ), N, fp ); 
      fclose( fp ); 
   }
   
   //将前n位转换为字符串——
   char* bits2string( Rank n ) { 
      expand( n - 1 ); //此时可能被访问的最高位为bitmap[n - 1]
      char* s = new char[n + 1]; s[n] = '\0'; //字符串所占空间，由上层调用者负责释放
      for ( Rank i = 0; i < n; i++ ) 
         s[i] = test( i ) ? '1' : '0';
      return s; //返回字符串位置
   }

   void expand( Rank k ) { //若被访问的Bitmap[k]已出界，则需扩容
      if ( k < 8 * N ) return; //仍在界内，无需扩容
      Rank oldN = N; 
      unsigned char* oldM = M;
      Rank oldSize = _sz;
      init( 2 * k ); //与向量类似，加倍策略
      memcpy( M, oldM, oldN );
      _sz = oldSize;
      delete[] oldM; //原数据转移至新空间
   }

   void print( Rank n ) //逐位打印以检验位图内容，非必需接口
   {  
      expand( n ); 
      for ( Rank i = 0; i < n; i++ ) 
         printf( test ( i ) ? "1" : "0" );  
      printf("\n");
   }
};
