#include "rook.h"
#include <array>

using namespace std;

string Rook::getName(){
    return ("Wieża");
}

bool Rook::checkMove(int position[2], int propositionPosition[2]){
    if ((position[0] == propositionPosition[0]) || (position[1] == propositionPosition[1])){
        return true;
    }
    else return false;
}

array<array<bool,8>,8> Rook::checkPossibleMove(int position[2],  array<array<Pawn*,8>,8> ChessBoard){
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
            } else {
                //zbijanie
                startCol = i;
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

    possibleMoves[position[0]][position[1]] = false;

    return possibleMoves;
}

