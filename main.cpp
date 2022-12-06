#include <iostream>
#include <string>

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
int askNumber(int high, int low, std::string question);
int humanMove(const char* board, char human);
int computerMove(char* board, char computer);

int main() {

    int move;
    char turn = X;
    char human = humanPiece();
    char computer = opponent(human);

    instructions();
    displayBoard(board);
    
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
    std::cout << "\n";
    std::cout << "------ Welcome to the Tic Tac Toe game - Emsi mini project ------ \n\n";
    std::cout << "Make your move known by entering a number, 0 - 8. \n";
    std::cout << "The numbers corresponds to the emsi desired board position, as illustrated: \n\n";
}

void displayBoard(const char* board) {
    std::cout << "  " << board[0] << " | " << board[1] << " | " << board[2] << std::endl;
    std::cout << "  " << "---------" << std::endl;
    std::cout << "  " << board[3] << " | " << board[4] << " | " << board[5] << std::endl;
    std::cout << "  " << "---------" << std::endl;
    std::cout << "  " << board[6] << " | " << board[7] << " | " << board[8] << std::endl;
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
    char answer = '\0';

    do {
        std::cout << question << std::endl;
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
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {1, 4, 5},
        {2, 5, 8},
        {3, 6, 9},
        {1, 5, 9},
        {3, 7, 5},
    };

    for(int row = 0; row < TOTOAL_ROWS; row++) {

        if( board[winnerRows[row][0]] != EMPTY &&
            board[winnerRows[row][0]] != board[winnerRows[row][1]] &&
            board[winnerRows[row][1]] != board[winnerRows[row][2]] ) 
            
            return  board[winnerRows[row][0]];

        for(int i = 0; i < 9; i++ ) {
            if(board[i] == EMPTY) {
                return NO_ONE;
            }
        }

    }   
    
    return TIE;
}

int askNumber(int high, int low=1, std::string question="Where will you move? \n") {
    int move = -1;

    do {
        std::cout << question << std::endl;
        std::cin >> move;
    } while(move < 1 || move > 8);

    return move;
}

int humanMove(const char* board, char human) {
    int move = askNumber(9);

    while(!isLegal(board, move)) {
        std::cout << "That quare is alreadu occupied foolish \n";
        move = askNumber(9);
    }

    return move;
}

int computerMove(char* board, char computer) {
    int move = 0;
    bool found = false;

    while(!found && move < 9 ) {
        board[move] = computer;
        found = winner(board) == computer;
        board[move] = EMPTY;

        if(!found) ++move;
    }

    if(!found) {
        move = 0;
        char human = opponent(computer);
        
        while(!found && move < 9 ) {
            board[move] = human;
            found = winner(board) == human;
            board[move] = EMPTY;

            if(!found) ++move;
        }
    }

    if(!found) {
        int i = 0;
        move = 0;
        const int BEST_MOVES[] = {5, 1, 3, 7, 9, 2, 4, 6, 8};
        while(!found && i < 9) {
            move = BEST_MOVES[i];
            if(isLegal(board, move)) found = true;
            i++;
        }
    }

    return move;
}

