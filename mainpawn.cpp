#include "mainpawn.h"

using namespace std;

string MainPawn::getName(){
    return ("Pion");
}

bool MainPawn::getFirstMove(){
    return (MainPawn::firstMove);
}

void MainPawn::setFirstMove(bool isFirstMove){
    MainPawn::firstMove = isFirstMove;
}

array<array<bool,8>,8> MainPawn::checkPossibleMove(array<int, 2> position,  array<array<Pawn*,8>,8> ChessBoard){
    array<array<bool,8>,8> possibleMoves;
    string color = ChessBoard[position[0]][position[1]]->getColor();
    string actualColor;
    int numberOfMoves = 1;

    if(MainPawn::firstMove){
        numberOfMoves = 2;
    }
    for(int row=0; row<8; row++){
        for(int col=0; col<8; col++){
            possibleMoves[row][col] = false;
        }
    }

    if(color == "black"){
        if((position[0]+numberOfMoves) < 8){
            for(int i = (position[0]+1); i < (position[0] + numberOfMoves +1); i++){
                actualColor = ChessBoard[i][position[1]]->getColor();
                if(actualColor == ""){
                    possibleMoves[i][position[1]] = true;
                }
            }
        }
        if((position[0] + 1) < 8 && (position[1]+1) <8){
          actualColor = ChessBoard[position[0] + 1][position[1]+1]->getColor();
          if(actualColor == "white"){
              possibleMoves[position[0] + 1][position[1]+1] = true;
          }
        }
        if((position[0] + 1) < 8 && (position[1]-1) >= 0){
          actualColor = ChessBoard[position[0] + 1][position[1]-1]->getColor();
          if(actualColor == "white"){
              possibleMoves[position[0] + 1][position[1]-1] = true;
          }
        }

    }

    if(color == "white"){
        if((position[0]-numberOfMoves) >= 0){
            for(int i = (position[0]-1); i > (position[0] - numberOfMoves -1); i--){
                actualColor = ChessBoard[i][position[1]]->getColor();
                if(actualColor == ""){
                    possibleMoves[i][position[1]] = true;
                }
            }
        }
        if((position[0] - 1) >= 0 && (position[1]-1) >=0){
          actualColor = ChessBoard[position[0] - 1][position[1]-1]->getColor();
          if(actualColor == "black"){
              possibleMoves[position[0] - 1][position[1]-1] = true;
          }
        }
        if((position[0] - 1) >= 0 && (position[1]+1) < 8){
          actualColor = ChessBoard[position[0] - 1][position[1]+1]->getColor();
          if(actualColor == "black"){
              possibleMoves[position[0] - 1][position[1]+1] = true;
          }
        }

    }


    return possibleMoves;
}


