#include <iostream>

const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';
char board[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

// prototypes
void instructions();
void displayBoard(const char* board);
void announceWinner(char winner, char computer, char human);
bool isLegal(const char* board, int move);
char askYesNo(std::string question);
char humanPiece();
char opponent(char piece);
char winner(const char* board);
int askNumber(std::string question, int high, int low = 0);
int humanMove(const char* board, char human);
int computerMove(const char* board, char computer);

int main() {

    int move;
    char turn = X;
    instructions();
    const int NUM_SQUARES = 9;
    char human = humanPiece();
    char computer = opponent(human);

    
    while(winner(board) == NO_ONE) {
        if(move = human) {
            move = humanMove(board, human);
            board[move] = human;
        } 
        else {
            move = computerMove(board, human);
            board[move] = computer;
        }
        displayBoard(board);
        turn = opponent(turn);
    }

    announceWinner(winner(board), computer, human);

    return 0;
}

void instructions() {
    std::cout << "\n";
    std::cout << "------ Welcome to the Tic Tac Toe game - Emsi mini project ------ \n\n";
    std::cout << "Make your move known by entering a number, 0 - 8. \n";
    std::cout << "The numbers corresponds to the emsi desired board position, as illustrated: \n\n";
}

void displayBoard(const char* board) {
    std::cout << board[0] << " | " << board[1] << " | " << board[2] << std::endl;
    std::cout << "---------";
    std::cout << board[3] << " | " << board[4] << " | " << board[5] << std::endl;
    std::cout << "---------";
    std::cout << board[6] << " | " << board[7] << " | " << board[8] << std::endl;
}

void announceWinner(char winner, char computer, char human) {
    if(winner == human) {
        std::cout << winner <<  " wins \n";
        std::cout << "human wins \n";
    } 
    else if(winner == computer) {
        std::cout << winner <<  " wins \n";
        std::cout << "Computer wins \n";
    } else {
        std::cout <<  "No one wins \n";
        std::cout << "It's a tie... \n";
    }
}

