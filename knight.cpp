#include "knight.h"

using namespace std;

string Knight::getName(){
    return ("Koń");
}

array<array<bool,8>,8> Knight::checkPossibleMove(array<int, 2> position,  array<array<Pawn*,8>,8> ChessBoard){
    array<array<bool,8>,8> possibleMoves;
    string color = ChessBoard[position[0]][position[1]]->getColor();
    string actualColor;

    for(int row=0; row<8; row++){
        for(int col=0; col<8; col++){
            possibleMoves[row][col] = false;
        }
    }
    //góra
    if((position[0] + 2) < 8 && (position[1] + 1) < 8){
      actualColor = ChessBoard[position[0] + 2][position[1] +1]->getColor();
      if(actualColor != color){
          possibleMoves[position[0] + 2][position[1]+1] = true;
      }
    }
    //dół
    if((position[0] + 1) < 8 && (position[1] + 2) < 8){
      actualColor = ChessBoard[position[0] + 1][position[1] +2]->getColor();
      if(actualColor != color){
          possibleMoves[position[0] + 1][position[1]+2] = true;
      }
    }
    //lewo
    if((position[0] - 1) >= 0 && (position[1] + 2) < 8){
      actualColor = ChessBoard[position[0] - 1][position[1] +2]->getColor();
      if(actualColor != color){
          possibleMoves[position[0] - 1][position[1]+2] = true;
      }
    }
    //prawo
    if((position[0] - 2) >= 0 && (position[1] + 1) < 8){
      actualColor = ChessBoard[position[0] - 2][position[1] +1]->getColor();
      if(actualColor != color){
          possibleMoves[position[0] - 2][position[1]+1] = true;
      }
    }
    //prawa góra
    if((position[0] - 1) >= 0 && (position[1] - 2) >= 0){
      actualColor = ChessBoard[position[0] - 1][position[1] - 2]->getColor();
      if(actualColor != color){
          possibleMoves[position[0] - 1][position[1]-2] = true;
      }
    }
    //prawy dół
    if((position[0] - 2) >= 0 && (position[1] - 1) >= 0){
      actualColor = ChessBoard[position[0] - 2][position[1] - 1]->getColor();
      if(actualColor != color){
          possibleMoves[position[0] - 2][position[1]-1] = true;
      }
    }
    //lewa góra
    if((position[0] + 1) < 8 && (position[1] - 2) >= 0){
      actualColor = ChessBoard[position[0]+1][position[1]-2]->getColor();
      if(actualColor != color){
          possibleMoves[position[0]+1][position[1]-2] = true;
      }
    }
    //lewy dół
    if((position[0] + 2) < 8 && (position[1] - 1) >= 0){
      actualColor = ChessBoard[position[0]+2][position[1]-1]->getColor();
      if(actualColor != color){
          possibleMoves[position[0]+2][position[1]-1] = true;
      }
    }


    return possibleMoves;
}


