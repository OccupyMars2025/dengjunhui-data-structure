#include "Hailstone/hailstone.h"
#include <cassert>
#include <cstdint>

int main(int argc, char const *argv[])
{
    uint64_t min_length = UINT64_MAX, max_length = 0;

    for (int i = 1; i < 100000; i++)
    {
        uint64_t result_01 = hailstone_v1(i);
        uint64_t result_02 = hailstone_v2(i);
        assert(result_01 == result_02);
        std::cout << "n = " << i << ": " << result_01 << std::endl; 
        if(result_01 < min_length) {
            min_length = result_01;
        }
        if(result_01 > max_length) {
            max_length = result_01;
        }
    }
    // min length = 1, max length = 351
    std::cout << "min length = " << min_length << ", max length = " << max_length << std::endl;
    return 0;
}
