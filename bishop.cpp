#include "bishop.h"

using namespace std;

string Bishop::getName(){
    return ("Goniec");
}

int Bishop::getleftWhiteStartRow(){
    return Bishop::leftWhiteStartRow;
}
int Bishop::getleftWhiteStartColumn(){
    return Bishop::leftWhiteStartColumn;
}
int Bishop::getrightWhiteStartRow(){
    return Bishop::rightWhiteStartRow;
}
int Bishop::getrightWhiteStartColumn(){
    return Bishop::rightWhiteStartColumn;
}
int Bishop::getleftBlackStartRow(){
    return Bishop::leftBlackStartRow;
}
int Bishop::getleftBlackStartColumn(){
    return Bishop::leftBlackStartColumn;
}
int Bishop::getrightBlackStartRow(){
    return Bishop::rightBlackStartRow;
}
int Bishop::getrightBlackStartColumn(){
    return Bishop::rightBlackStartColumn;
}

QString Bishop::getIconName(){
    if(Bishop::getColor() == "white"){
        return("bishop1");
    } else {
        return("bishop");
    }
}

/*!
 * \brief Bishop::checkPossibleMove Function return possible movex of object
 * \param position Current position of object
 * \param ChessBoard Current position of all object on chess board
 * \return List boolean, which field is possible to move on
 */
array<array<bool,8>,8> Bishop::checkPossibleMove(array<int, 2> position,  array<array<Pawn*,8>,8> ChessBoard){
    array<array<bool,8>,8> possibleMoves;
    string color = ChessBoard[position[0]][position[1]]->getColor();
    string actualColor;
    //prawy - przód
    for(int row=0; row<8; row++){
        for(int col=0; col<8; col++){
            possibleMoves[row][col] = false;
        }
    }
    if ((position[0]+1) < 8 && (position[1]+1) < 8){
        int col = position[1]+1;
        for(int i = (position[0] + 1); i<8; i++){
            if(col < 8){
                actualColor = ChessBoard[i][col]->getColor();
                if(actualColor == ""){
                    possibleMoves[i][col] = true;
                } else if (actualColor == color){
                    break;
                } else {
                    possibleMoves[i][col] = true;
                    break;
                }
            }
            col++;
        }
    }

    //lewy tył
    if ((position[0] - 1) >= 0 && (position[1] - 1) >= 0){
        int col = position[1] - 1;
        for(int i = (position[0] - 1); i>=0; i--){
            if(col >= 0){
                actualColor = ChessBoard[i][col]->getColor();
                if(actualColor == ""){
                    possibleMoves[i][col] = true;
                } else if (actualColor == color){
                    break;
                } else {
                    possibleMoves[i][col] = true;
                    break;
                }
            }
            col--;
        }
    }

    //przód
    if((position[0] + 1) < 8 && (position[1] - 1) >= 0) {
        int col = position[1] - 1;
        for(int i = (position[0] + 1); i<8; i++){
            if(col >= 0){
                actualColor = ChessBoard[i][col]->getColor();
                if(actualColor == ""){
                    possibleMoves[i][col] = true;
                } else if (actualColor == color){
                    break;
                } else {
                    possibleMoves[i][col] = true;
                    break;
                }
            }
            col--;

        }
    }

    //tył
    if((position[0] - 1) >= 0 && (position[1]+1) < 8){
        int col = position[1] + 1;
        for(int i = (position[0] - 1); i>=0; i--){
            if(col < 8){
                actualColor = ChessBoard[i][col]->getColor();
                if(actualColor == ""){
                    possibleMoves[i][col] = true;
                } else if (actualColor == color){
                    break;
                } else {
                  possibleMoves[i][col] = true;
                  break;
                }
            }
            col++;
        }
    }

    possibleMoves[position[0]][position[1]] = false;

    return possibleMoves;
}
