#include <iostream>
#include <cmath>
#include <string>

const int ROWS = 3;
const int COLS = 3;
const int r = (ROWS * 2) + 1;
const int c = (COLS * 2) + 1;

class Board {
    char sps[r][c] = {};
public:
    Board() {
        pop_sps();
    }

    void draw_board() {
        for(int col = 0; col < c; col++) {
            for(int row = 0; row < r; row++) {
                std::cout << " ";
//              is this a top or bottom bar?
                if(isEven(col)) {
                    std::cout << "-";
                } else {
                    if(isEven(row)) {
                        std::cout << "|";
                    } else {
                        std::cout << sps[col][row];
                    }
                }
            }
            std::cout << std::endl;
        }
    };
private:
    bool isEven(double n) {
        return static_cast<int>(n) % 2 == 0;
    }
    void pop_sps() {
        for(int col = 0; col < c; col++) {
            for(int row = 0; row < r; row++) {
                sps[col][row] = ' ';
            }
        }
    }
};

Board b;

int main() {
    b.draw_board();
    return 0;
}
