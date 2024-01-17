#pragma once

#include <iostream>
#include <cstdint>
#include <cstring>
#include <cassert>
using Rank = int32_t;


// class Bitmap { //位图Bitmap类：以空间作为补偿，节省初始化时间（既允许插入，亦支持删除）
// private:
//    Rank* F; Rank N; //规模为N的向量F，记录[k]被标记的次序（即其在栈T[]中的秩）
//    Rank* T; Rank top; //容量为N的栈T，记录被标记各位秩的栈，以及栈顶指针

// public:
//    Bitmap( Rank n = 8 ) //按指定（或默认）规模创建比特图（为测试暂时选用较小的默认值）
//    { 
//       N = n; 
//       F = new Rank[N];
//       T = new Rank[N]; 
//       top = 0; 
//    } //在O(1)时间内隐式地初始化
//    ~Bitmap() { delete[] F; delete[] T; } //析构时释放空间

// // 接口
//    inline void reset() { top = 0; } //复位：从逻辑上切断所有校验环，O(1)

//    Rank size() { return top; } //查询规模
//    
//    
//    inline void set ( Rank k ) { //插入：从逻辑上将B[k]置为true，O(1)
//       if ( ! test ( k ) ) { //忽略已带标记的位
//          T[ top ] = k; 
//          F[ k ] = top++; //创建校验环
//       }
//    }

//    inline void clear( Rank k ) { //删除：从逻辑上将B[k]置为false，O(1)
//       if ( test ( k ) ) //忽略不带标记的位
//          if ( --top > 0 ) { //清除校验环，同时回收栈T的空闲单元（留意对空栈的处理）
//             if(F[k] == top) {
//                return;
//             }
//             F[ T[ top ] ] = F[ k ]; 
//             T[ F[ k ] ] = T[ top ];
//          }
//    }

//    inline bool test( Rank k ) //从逻辑上判断B[k]是否为true，O(1)
//    {  return ( 0 <= F[ k ] ) && ( F[ k ] < top ) && ( k == T[ F[ k ] ] );  }
// };




/*
support set(), clear(), test()

when clearing k, move present_elements[top - 1] to present_elements[the_whole_range[k]],
then --top .
present_elements[0, top) are all elements that are present in the set.
When setting k, just the_whole_range[k] = top ...
*/
class Bitmap_v003
{
private:
    Rank *the_whole_range;
    Rank *present_elements;
    Rank n, top;
public:
    void init(Rank n) {
        if(n < 3) n = 3;
        this->n = n;
        the_whole_range = new Rank[n];
        present_elements = new Rank[n];
        top = 0;
    }

    Bitmap_v003(Rank n = 3) {
        init(n);
    }

    ~Bitmap_v003() {
        delete [] the_whole_range;
        delete [] present_elements;
    }

    void reset() {
        top = 0;
    }

    Rank size() {
        return top;
    }

    void expand(Rank k) {
        if(k < n) return;

        Rank *old_the_whole_range = the_whole_range;
        Rank *old_present_elements = present_elements;
        Rank old_n = n;
        Rank old_top = top;
        init(2 * k);

        memcpy(the_whole_range, old_the_whole_range, old_n * sizeof(Rank));
        memcpy(present_elements, old_present_elements, old_top * sizeof(Rank));
        top = old_top;

        delete [] old_the_whole_range;
        delete [] old_present_elements;
    }

    bool test(Rank k) {
        assert(k >= 0);
        expand(k);

        Rank i = the_whole_range[k];
        bool is_present = (0 <= i) && (i < top) && (present_elements[i] == k);
        return is_present;
    }

    void set(Rank k) {
        assert(k >= 0);
        expand(k);
        if(!test(k)) {
            the_whole_range[k] = top;
            present_elements[top] = k;
            ++top;
        }
    }

    void clear(Rank k) {
        assert(k >= 0);
        expand(k);
        if(test(k)) {
            Rank i = the_whole_range[k];
            if((top > 1) && (i != top - 1)) {
                the_whole_range[present_elements[top - 1]] = i;
                present_elements[i] = present_elements[top - 1];
            }
            --top;
        }
    }

    void print(Rank n) {
        assert(n > 0);
        expand(n - 1);

        for(Rank k = 0; k < n; ++k) {
            std::cout << (test(k) ? "1" : "0");
        }
        std::cout << std::endl;
    }
};