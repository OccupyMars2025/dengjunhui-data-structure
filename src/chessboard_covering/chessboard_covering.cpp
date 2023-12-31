/**
 * solution to the exercise [1-24] on page 18 of the exercise book
*/

#include "chessboard_covering.h"

bool chessboard[1 << N][1 << N] = {{false}};

/*
I view (x,y) as the vertex coordinate, but thus it is hard to verify 
my algorithm, instead you should view (x, y) as the coordinate of one
smallest basic square, so you can verify your algorithm using 2-d array.
To change the perspective, you only need to change "s*2" to "s*2-1" in the code
*/
// /*
// (x, y) is the vertex opposite to the notch
// */
// void place_basic_block(int x, int y, int dx, int dy) {

// }
// /**
//  * (dx, dy) = (+1/-1, +1/-1)
//  * we start from cover_chessboard(n, 0, 0, +1, +1)
//  * (x, y) is the vertex opposite to the notch
// */
// void cover_chessboard(int n, int x, int y, int dx, int dy) {
//     if(n == 1) {
//         place_basic_block(x, y, dx, dy);
//         return;
//     }
//     int s = 1 << (n-1);
//     place_basic_block(x + dx*(s - 1), y + dy*(s - 1), dx, dy);

//     cover_chessboard(n-1, x       , y       ,  dx,  dy);
//     cover_chessboard(n-1, x+dx*s  , y+dy*s  ,  dx,  dy);
//     cover_chessboard(n-1, x+dx*s*2, y       , -dx,  dy);
//     cover_chessboard(n-1, x       , y+dy*s*2,  dx, -dy);
// }


/*
(x, y) is the coordinates of the smallest square opposite to the notch
*/
void place_basic_block(int x, int y, int dx, int dy) {
    assert(false == chessboard[x][y]);
    assert(false == chessboard[x+dx][y]);
    assert(false == chessboard[x][y+dy]);
    
    chessboard[x][y] = true;
    chessboard[x+dx][y] = true;
    chessboard[x][y+dy] = true;
}
/**
 * (dx, dy) = (+1/-1, +1/-1)
 * we start from cover_chessboard(n, 0, 0, +1, +1)
 * (x, y) is the coordinates of the smallest square opposite to the notch
*/
void cover_chessboard(int n, int x, int y, int dx, int dy) {
    if(n == 1) {
        place_basic_block(x, y, dx, dy);
        return;
    }
    int s = 1 << (n-1);
    place_basic_block(x + dx*(s - 1), y + dy*(s - 1), dx, dy);

    cover_chessboard(n-1, x       , y       ,  dx,  dy);
    cover_chessboard(n-1, x+dx*s  , y+dy*s  ,  dx,  dy);
    cover_chessboard(n-1, x+dx*(s*2-1), y       , -dx,  dy);
    cover_chessboard(n-1, x       , y+dy*(s*2-1),  dx, -dy);
}


void print_chessboard() {
    int length = 1 << N;
    for(int y = length - 1; y >= 0; --y) {
        for(int x = 0; x <= length - 1; ++x) {
            if(chessboard[x][y]) {
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


void clear_chessboard() {
    int length = 1 << N;
    for(int i=0; i < length; ++i) {
        for(int j=0; j < length; ++j) {
            chessboard[i][j] = false;
        }
    }
}