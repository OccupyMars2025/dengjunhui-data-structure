#include <iostream>

uint64_t ackermann(uint64_t m, uint64_t n) {
    if(0 == m) {
        return n + 1;
    } else if(m > 0 && 0 == n) {
        return ackermann(m - 1, 1);
    } else {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}
