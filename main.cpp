#include <iostream>
#include <string>

const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';
char board[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

// prototypes
void instructions();
void displayBoard(const char* board);
void announceWinner(char winner, char computer, char human);
bool isLegal(const char* board, int move);
char askYesNo(std::string question);
char humanPiece();
char opponent(char piece);
char winner(const char* board);
int askNumber(int high, int low, std::string question);
int humanMove(const char* board, char human);
int computerMove(char board[], char computer);

int main() {
    int move;
    char turn = X;

    instructions();

    char human = humanPiece();
    char computer = opponent(human);

    while(winner(board) == NO_ONE) {
        if(turn == human) {
            move = humanMove(board, human);
            board[move] = human;
        } 
        else {
            move = computerMove(board, computer);
            board[move] = computer;
        }
        displayBoard(board);
        turn = opponent(turn);
    }

    announceWinner(winner(board), computer, human);

    return 0;
}

void instructions() {
    std::cout << "\n ------ Welcome to the Tic Tac Toe game - Emsi mini project ------ \n\n";
    std::cout << "Make your move known by entering a number, 0 - 8. \n";
    std::cout << "The numbers corresponds to the desired board position, as illustrated: \n\n";
    std::cout << "   0 | 1 | 2"  << std::endl;
    std::cout << "   ---------" << std::endl;
    std::cout << "   3 | 4 | 5"  << std::endl;
    std::cout << "   ---------" << std::endl;
    std::cout << "   6 | 7 | 8"  << std::endl << std::endl;
}

void displayBoard(const char* board) {
    std::cout << "  " << board[0] << " | " << board[1] << " | " << board[2] << std::endl;
    std::cout << "  " << "---------" << std::endl;
    std::cout << "  " << board[3] << " | " << board[4] << " | " << board[5] << std::endl;
    std::cout << "  " << "---------" << std::endl;
    std::cout << "  " << board[6] << " | " << board[7] << " | " << board[8] << std::endl << std::endl;
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

bool isLegal(const char* board, int move) {
    return board[move] == EMPTY;
}

char askYesNo(std::string question = "Do you want to start first ? \n ") {
    char answer;

    do {
        std::cout << question;
        std::cin >> answer;
    } while(answer != 'y' && answer != 'n');

    return answer;
}

char humanPiece() {
    char answer = askYesNo();
    return answer == 'y' ? X : O; 
}

char opponent(char piece) {
    return piece == X ? O : X; 
}

char winner(const char* board) {
    const int TOTOAL_ROWS = 8;
    const int winnerRows[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6},
    };

    for(int row = 0; row < TOTOAL_ROWS; row++) {

        if( board[winnerRows[row][0]] != EMPTY &&
            board[winnerRows[row][0]] == board[winnerRows[row][1]] &&
            board[winnerRows[row][1]] == board[winnerRows[row][2]] ) 
            
            return  board[winnerRows[row][0]];
    }   

    for(int i = 0; i < 9; i++ ) {
        if(board[i] == EMPTY) {
            return NO_ONE;
        }
    }
    
    return TIE;
}

int askNumber(int high, int low=0, std::string question="Where will you move? \n") {
    int move;

    do {
        std::cout << question;
        std::cin >> move;
    } while(move < low || move > high);

    return move;
}

int humanMove(const char* board, char human) {
    int move = askNumber(8);

    while(!isLegal(board, move)) {
        std::cout << "That square is already occupied foolish \n";
        move = askNumber(8);
    }

    return move;
}

int computerMove(char* board, char computer) {
    int move = 0;
    bool found = false;

    while(!found && move < 9) {
        if(isLegal(board, move)) {
            board[move] = computer;
            found = winner(board) == computer;
            board[move] = EMPTY;
        }
        

        if(!found) ++move;
    }

    if(!found) {
        move = 0;
        char human = opponent(computer);
        
        while(!found && move < 9) {
            if(isLegal(board, move)) {
                board[move] = human;
                found = winner(board) == human;
                board[move] = EMPTY;
            }

            if(!found) ++move;
        }
    }   

    if(!found) {
        int i = 0;
        move = 0;
        const int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};
        while(!found && i < 9) {
            move = BEST_MOVES[i];
            if(isLegal(board, move)) found = true;
            i++;
        }
    }

    return move;
}
