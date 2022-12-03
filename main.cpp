#include <iostream>

const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';
const char board[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

// prototypes
void instructions();
char askYesNo(std::string question);
int askNumber(std::string question, int high, int low = 0);
char humanPiece();
char opponent(char piece);
void displayBoard(const char* board);
char winner(const char* board);
bool isLegal(const char* board, int move);
int humanMove(const char* board, char human);
int computerMove(const char* board, char computer);
void announceWinner(char winner, char computer, char human);

int main() {
    
    while(winner(board) == NO_ONE) {

    }


    return 0;
}

void instructions() {
    std::cout << "\n";
    std::cout << "------ Welcome to the Tic Tac Toe game - Emsi mini project ------ \n\n";
    std::cout << "Make your move known by entering a number, 0 - 8. \n";
    std::cout << "The numbers corresponds to the emsi desired board position, as illustrated: \n\n";
}

