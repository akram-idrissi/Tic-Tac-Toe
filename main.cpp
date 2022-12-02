#include <iostream>

const int board[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

void displayBoard(const int* board) {
    std::cout << board[0] << " | "  << board[1] << " | "  << board[2] << std::endl;
    std::cout << "---------" << std::endl;
    std::cout << board[3] << " | "  << board[4] << " | "  << board[5] << std::endl;
    std::cout << "---------" << std::endl;
    std::cout << board[6] << " | "  << board[7] << " | "  << board[8] << std::endl << std::endl;
}

int main() {

    return 0;
}