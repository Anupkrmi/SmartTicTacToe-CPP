#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void printBoard(char board[]){

    cout << "   " << board[0] << "   |   " << board[1] << "   |   " << board[2] << endl;
    cout << "------------------------" << endl;
    cout << "   " << board[3] << "   |   " << board[4] << "   |   " << board[5] << endl;
    cout << "------------------------" << endl;
    cout << "   " << board[6] << "   |   " << board[7] << "   |   " << board[8] << endl;

}

int input(char board[]){
    int validInp = -1;

    cout << "Enter Position : ";
    cin >> validInp;

    validInp--;

    if(validInp > 9 || validInp < 0){
        cout << "Invalid Input" << endl;
        validInp = -1;
        return validInp;
    }
    
    if(board[validInp] == ' '){
        if(validInp < 9 && validInp >= 0){
            return validInp;
        }else{
            cout << "Invalid Input" << endl;
            validInp = -1;
            return validInp;
        }
    }else{
        cout << "Invalid Input" << endl;
        validInp = -1;
        return validInp;
    }
 
}

void chance(char turn, char board[]){

    int pos = -1;
    do{
        pos = input(board);
    }while(pos == -1);
    board[pos] = turn;

}

void compChance(char board[], int compMove){

    int pos = -1;
    pos = compMove;
    board[pos] = 'O';

}

bool isWin(char board[]){

    // win in vertical
    
    for(int i = 0; i < 3; i++){
        if(board[i] == ' ' || board[i+3] == ' ' || board[i+6] == ' '){
            continue;
        }

        if(board[i] == board[i+3] && board[i+3] == board[i+6]){
            return true;
        }else{
            continue;
        }
    }

    // win in horizontal
    for(int i = 0; i <= 6; i = i + 3){
        if(board[i] == ' ' || board[i+1] == ' ' || board[i+2] == ' '){
            continue;
        }

        if(board[i] == board[i+1] && board[i+1] == board[i+2]){
            return true;
        }else{
            continue;
        }
    }

    // win in diagonal
    for(int i = 0; i < 3; i++){
        if(board[i] == ' ' || board[i+4] == ' ' || board[i+8] == ' '){
            continue;
        }else if(board[i] == ' ' || board[i+2] == ' ' || board[i+4] == ' '){
            continue;
        }

        if(board[i] == board[i+4] && board[i+4] == board[i+8] || board[i] == board[i+2] && board[i+2] == board[i+4]){
            return true;
        }else{
            continue;
        }
    }
    
    return false;
}

int difficulty(){
    int difficulty = 0;

    cout << "( 1-Easy, 2-Medium, 3-Hard )" << endl;
    cout << "Enter game difficulty : ";
    cin >> difficulty;
    
    if(difficulty == 1){
        cout << "You chosed easy difficulty..." << endl;
        return 1;
    }else if(difficulty == 2){
        cout << "You chosed medium difficulty..." << endl;
        return 2;
    }else if(difficulty == 3){
        cout << "You chosed hard difficulty..." << endl;
        return 3;
    }else{
        cout << "Invalid Input" << endl;
        return 0;
    }
}

int easyAI(char board[]){
    // randomly generate any position that is free

    int freePos[9];
    int count = 0;

    for(int i = 0; i < 9; i++){
        if(board[i] == ' '){
            freePos[count] = i;
            count++;
        }
    }

    if(count == 0){
        return -1;
    }

    int r = rand() % count;

    return freePos[r];
}

int mediumAI(char board[]){
    // Logic :-
    // 1. if Comp is winning - play there
    // 2. if opponent is winning - block
    // 3. capture centre
    // 4. capture corners
    // 5. random

    bool win;

    // 1. Step I :
    for(int i = 0; i < 9;i++){
        if(board[i] == ' '){
            compChance(board, i);
        }else{
            continue;
        }
        win = isWin(board);

        if(win){
            board[i] = ' ';
            return i;
        }else{
            board[i] = ' ';
        }
    }

    // 2. Step II :
    for(int i = 0; i < 9; i++){
        if(board[i] == ' '){
            board[i] = 'X';
            win = isWin(board);
            if(win){
                board[i] = ' ';
                return i;
            }else{
                board[i] = ' ';                
                continue;
            }
        }
    }

    // 3. Step III :
    if(board[4] == ' '){
        return 4;
    }

    // 4. Step IV :
    if(board[0] == ' '){
        return 0;
    }else if(board[2] == ' '){
        return 2;
    }else if(board[6] == ' '){
        return 6;
    }else if(board[8] == ' '){
        return 8;
    }

    // 5. Step V :
    int move = -1;
    move = easyAI(board);
    return move;

}


int main(){
    srand(time(0));
    // all Variable : 
    char board[9];
    bool win = false;
    int level = 0;
    int player = 0;
    int compMove;

    cout << "   Tic-Tac-Toe Game" << endl;
    cout << "---------------------" << endl;

    for(int i = 0; i < 9; i++){
        board[i] = ' ';
    }

    while(player != 1 && player != 2){
        cout << "1-Single Player, 2-Two Player" << endl;
        cout << "Enter Number of player: ";
        cin >> player;

        if(player == 1 || player == 2){
            continue;
        }else{
            cout << "Invalid Input" << endl;
        }
    }   

    printBoard(board);

    if(player == 2){
        char turn;
        turn = ' ';
        for(int i = 0; i < 9; i++){
            if(i%2 == 0){
                turn = 'X';
            }else{
                turn = 'O';
            }
            cout << turn << "'s chance -" << endl;
            chance(turn, board);
            printBoard(board);
            win = isWin(board);

            if(win){
                cout << turn << " is the Winner" << endl;
                break;
            }else{
                continue;
            }

        }
        if(win){
            return 0;
        }else{
            cout << "Its a draw !!" << endl;
            return 0;
        }
    }else{
        while(level == 0){
            level = difficulty();
        }

        printBoard(board);

        char turn;
        turn = ' ';
        for(int i = 0; i < 9; i++){
            if(i%2 == 0){
                turn = 'X';
                cout << turn << "'s chance -" << endl;
                chance(turn, board);
                printBoard(board);
                win = isWin(board);

                if(win){
                    cout <<"You are the Winner" << endl;
                    break;
                }else{
                    continue;
                }

            }else{
                turn = 'O';
                cout << "Computer's Turn - " << endl;
                if(level == 1){
                    compMove = easyAI(board);
                }else if(level == 2){
                    compMove = mediumAI(board);
                }//else if(level == 3){
                        //     hard();
                        // }
                        
                compChance(board, compMove);                        
                printBoard(board);
                win = isWin(board);

                if(win){
                    cout <<"Computer is the Winner" << endl;
                    break;
                }else{
                    continue;
                }

            }

        }
        if(win){
            return 0;
        }else{
            cout << "Its a draw !!" << endl;
            return 0;
        }
    }


    
    
}