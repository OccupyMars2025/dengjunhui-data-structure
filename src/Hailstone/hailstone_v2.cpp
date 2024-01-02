#include <iostream>
#include <cassert>
#include "Hailstone/hailstone.h"

/*
non-recursive version.
return the length of the Hailstone sequence
*/
// uint64_t hailstone_v2(int n) {
//     if (n <= 0) {
//         std::cout << "Illegal argument n = " << n << std::endl;
//         exit(1);
//     }
//     uint64_t length = 0;

//     while (n >= 1)
//     {
//         ++length;
//         if(1 == n) break;
//         if(n % 2 == 0) {
//             n = n / 2;
//         } else {
//             n = 3 * n + 1;
//         }
//     }
    
//     return length;
// }

uint64_t hailstone_v2(int n) {
    assert(n >= 1);
    uint64_t length = 0;

    while (n >= 1)
    {
        ++length;
        if(1 == n){
            break;
        } else if(1 & n){
            n = 3 * n + 1;
        } else {
            n >>= 1;
        }
    }
    return length;
}