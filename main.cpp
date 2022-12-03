#include <iostream>

const int board[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

void instructions();
char askYesNo(std::string question);
int askNumber(std::string question, int high, int low = 0);
char humanPiece();
char opponent(char piece);
void displayBoard(const char* board[]);
char winner(const char* board[]);
bool isLegal(const char* board[], int move);
int humanMove(const char* board[], char human);
int computerMove(const char* board[], char computer);
void announceWinner(char winner, char computer, char human);


int main() {

    return 0;
}

