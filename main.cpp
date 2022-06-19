#include <iostream>
#include <cmath>
#include <string>

// 26 Rows/Cols MAX
const int ROWS = 3;
const int COLS = 3;
const int r = (ROWS * 2) + 1;
const int c = (COLS * 2) + 1;
char alphabet[26] = { 'A', 'B', 'C', 'D',
                      'E', 'F', 'G', 'H',
                      'I', 'J', 'K', 'L',
                      'M', 'N', 'O', 'P',
                      'Q', 'R', 'S', 'T',
                      'U', 'V', 'W', 'X',
                      'Y', 'Z' };

class Player {
    std::string name = "";
public:
     explicit Player(std::string _name) {
        name = _name;
    }
};

class Computer : public Player {
public:
    Computer(std::string name) : Player(name) {

    }
};


class Board {
    char sps[ROWS][COLS] = {};
    bool single_player = true;
    bool running = true;
    Player players[2] = { Player(""), Player("")};
    Player current_player = Player("");

public:
    Board() {
        pop_sps();
        init_prompt();
        current_player = decide_starter();
//        while(running) {
//
//        }
        std::cout << "";
    }

    void draw_board() {
        int col_i = 0;
        int row_i = 0;
//      col indicator
        std::cout << "   ";
        for (int row = 0; row < ROWS; row++) {
            if(row > sizeof(alphabet)) {
                std::cout << "  " << alphabet[col_i] << alphabet[col_i] << " ";
            } else {
                std::cout << "  " << alphabet[col_i] << " ";
            }
            col_i++;
        }
        std::cout << std::endl;
        for(int col = 0; col < c; col++) {
            if(!isEven(col)) {
                if(row_i + 1 >= 10) {
                    std::cout << row_i + 1;
                } else {
                    std::cout << row_i + 1 << " ";
                }
                row_i++;
            } else {
                std::cout << "  ";
            }
            for(int row = 0; row < r; row++) {
                std::cout << " ";
//              is this a top or bottom bar?
                if(isEven(col)) {
                    std::cout << "-";
                } else {
                    if(isEven(row)) {
                        std::cout << "|";
                    } else {
                        std::cout << sps[col_i][row_i];
                    }
                }
            }
            std::cout << std::endl;
        }
    };
private:
    void br(int n) {
        for(int i = 0; i < n; i++) {
            std::cout << std::endl;
        }
    }
    bool isEven(double n) {
        return static_cast<int>(n) % 2 == 0;
    }
    void pop_sps() {
        int col_i = 0;
        int row_i = 0;
        for(int col = 0; col < c; col++) {
            for(int row = 0; row < r; row++) {
                sps[col_i][row_i] = 'x';
                row_i++;
            }
            col_i++;
        }
    }
    void init_prompt() {
        int player_count;
        bool c1 = false;
        while(!c1) {
            std::cout << "How many players? (1 or 2): ";
            std::cin >> player_count;
            switch(player_count) {
                case 1:
                    single_player = true;
                    c1 = true;
                    break;
                case 2:
                    single_player = false;
                    c1 = true;
                    break;
                default:
                    std::cout << "Thats not an option. Try again..." << std::endl;
                    break;
            }
        }
        br(1);
        for(int pls = 0; pls < player_count; pls++) {
            std::string name;
            std::cout << "Enter player " << pls + 1 << "'s name: ";
            std::cin >> name;
            players[pls] = Player("");
        }
        if(single_player) {
            players[1] = Computer(std::string());
        }
    }
    void player_turn() {
//      current_player takes a turn
    }
    Player decide_starter() {
        int r = rand() % 2;
        return players[r];
    }
};

Board b;

int main() {

    return 0;
}
