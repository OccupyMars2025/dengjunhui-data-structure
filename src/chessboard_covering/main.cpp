#include "chessboard_covering.h"


int main(int argc, char const *argv[])
{
    cover_chessboard(N, 0, 0, +1, +1);
    print_chessboard();
    clear_chessboard();

    cover_chessboard(N, (1 << N)-1, 0, -1, +1);
    print_chessboard();
    clear_chessboard();

    cover_chessboard(N, (1 << N)-1, (1 << N)-1, -1, -1);
    print_chessboard();
    clear_chessboard();

    cover_chessboard(N, 0, (1 << N)-1, +1, -1);
    print_chessboard();
    clear_chessboard();

    return 0;
}
