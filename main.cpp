#include <iostream>

const int board[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

void displayBoard(const int* board) {
    std::cout << board[0] << " | "  << board[1] << " | "  << board[2] << std::endl;
    std::cout << "---------" << std::endl;
    std::cout << board[3] << " | "  << board[4] << " | "  << board[5] << std::endl;
    std::cout << "---------" << std::endl;
    std::cout << board[6] << " | "  << board[7] << " | "  << board[8] << std::endl << std::endl;
}

void welcomeMessage() {
    std::cout << "\n\n";
    std::cout << "------ Welcome to the Emsi mini project - Tic Tac Toe game ------ \n\n";
    std::cout << "Make your move known by entering a number, 0 - 8. \n";
    std::cout << "The numbers corresponds to the emsi desired board position, as illustrated: \n\n";
}

int main() {

    return 0;
}
