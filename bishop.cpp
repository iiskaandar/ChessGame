#include "bishop.h"

using namespace std;

string Bishop::getName(){
    return ("Goniec");
}

array<array<bool,8>,8> Bishop::checkPossibleMove(array<int, 2> position,  array<array<Pawn*,8>,8> ChessBoard){
    array<array<bool,8>,8> possibleMoves;
    int startRow = 0;
    int startCol = 0;
    int endRow = 7;
    int endCol = 7;
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
    //poziom
   /* if(startRow != endRow){
        for(int i=startRow; i<endRow; i++){
            possibleMoves[i][i] = true;
        }
    }
    if(startCol != endCol){
        for(int i=startCol; i<endCol; i++){
            possibleMoves[i][i] = true;
        }
    }*/

    possibleMoves[position[0]][position[1]] = false;

    return possibleMoves;
}
