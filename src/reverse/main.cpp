#include "reverse/reverse.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    if(argc < 2) {
        printf("Error:%s num\n", argv[0]);
        exit(1);
    }
    int num = atoi(argv[1]);
    if (num <= 0) {
        printf("Error: invalid num %d\n", num);
        exit(1);
    }
    int* array = (int*)malloc(num * sizeof(int));

    srand((unsigned int)time(0));
    for(int i=0; i<num; ++i) {
        array[i] = rand() % 200 - 100;
    }
    print(array, num);

    reverse(array, num);
    print(array, num);

    reverse_R(array, 0, num-1);
    print(array, num);

    reverse_I0(array, 0, num-1);
    print(array, num);

    reverse_I1(array, 0, num-1);
    print(array, num);

    free(array);

    return 0;
}
