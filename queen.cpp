#include "queen.h"

using namespace std;

string Queen::getName(){
    return ("Królowa");
}

int Queen::getwhiteStartRow(){
    return Queen::whiteStartRow;
}
int Queen::getwhiteStartColumn(){
    return Queen::whiteStartColumn;
}
int Queen::getblackStartRow(){
    return Queen::blackStartRow;
}
int Queen::getblackStartColumn(){
    return Queen::blackStartColumn;
}

QString Queen::getIconName(){
    if(Queen::getColor() == "white"){
        return("queen1");
    } else {
        return("queen");
    }
}
/*!
 * \brief Queen::checkPossibleMove Function return possible movex of object
 * \param position Current position of object
 * \param ChessBoard Current position of all object on chess board
 * \return List boolean, which field is possible to move on
 */
array<array<bool,8>,8> Queen::checkPossibleMove(array<int, 2> position,  array<array<Pawn*,8>,8> ChessBoard){
    array<array<bool,8>,8> possibleMoves;
    int startRow = 0;
    int startCol = 0;
    int endRow = 7;
    int endCol = 7;
    string color = ChessBoard[position[0]][position[1]]->getColor();
    string actualColor;
    //prawo
    for(int row=0; row<8; row++){
        for(int col=0; col<8; col++){
            possibleMoves[row][col] = false;
        }
    }
    if ((position[0]+1) < 8){
        for(int i = (position[0] + 1); i<8; i++){
            actualColor = ChessBoard[i][position[1]]->getColor();
            if(actualColor == ""){

            } else if (actualColor == color){
                endRow = i - 1;
                break;
            } else {
                //zbijanie
                endRow = i;
                break;
            }
        }
    }

    //lewo
    if ((position[0] - 1) >= 0){
        for(int i = (position[0] - 1); i>=0; i--){
            actualColor = ChessBoard[i][position[1]]->getColor();
            if(actualColor == ""){

            } else if (actualColor == color){
                startRow = i + 1;
                break;
            } else {
                //zbijanie
                startRow = i;
                break;
            }
        }
    }

    //przód
    if((position[1] + 1) < 8) {
        for(int i = (position[1] + 1); i<8; i++){
            actualColor = ChessBoard[position[0]][i]->getColor();
            if(actualColor == ""){

            } else if (actualColor == color){
                endCol = i - 1;
                break;
            } else {
                //zbijanie
                endCol = i;
                break;
            }
        }
    }

    //tył
    if((position[1] - 1) >= 0 ){
        for(int i = (position[1] - 1); i>=0; i--){
            actualColor = ChessBoard[position[0]][i]->getColor();
            if(actualColor == ""){

            } else if (actualColor == color){
                startCol = i + 1;
                break;
            } else {
                //zbijanie
                startCol = i;
                break;
            }
        }
    }
    //poziom
    if(startRow != endRow){
        for(int i=startRow; i<endRow; i++){
            possibleMoves[i][position[1]] = true;
        }
    }
    if(startCol != endCol){
        for(int i=startCol; i<endCol; i++){
            possibleMoves[position[0]][i] = true;
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



