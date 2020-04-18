#include "king.h"

using namespace std;

string King::getName(){
    return ("Król");
}

int King::getwhiteStartRow(){
    return King::whiteStartRow;
}
int King::getwhiteStartColumn(){
    return King::whiteStartColumn;
}
int King::getblackStartRow(){
    return King::blackStartRow;
}
int King::getblackStartColumn(){
    return King::blackStartColumn;
}

QString King::getIconName(){
    if(King::getColor() == "white"){
        return("king1");
    } else {
        return("king");
    }
}

/*!
 * \brief King::checkPossibleMove Function return possible movex of object
 * \param position Current position of object
 * \param ChessBoard Current position of all object on chess board
 * \return List boolean, which field is possible to move on
 */
array<array<bool,8>,8> King::checkPossibleMove(array<int, 2> position,  array<array<Pawn*,8>,8> ChessBoard){
    array<array<bool,8>,8> possibleMoves;
    string color = ChessBoard[position[0]][position[1]]->getColor();
    string actualColor;

    for(int row=0; row<8; row++){
        for(int col=0; col<8; col++){
            possibleMoves[row][col] = false;
        }
    }
    //góra
    if((position[0] + 1) < 8){
      actualColor = ChessBoard[position[0] + 1][position[1]]->getColor();
      if(actualColor != color){
          possibleMoves[position[0] + 1][position[1]] = true;
      }
    }
    //dół
    if((position[0] - 1) >= 0){
      actualColor = ChessBoard[position[0] - 1][position[1]]->getColor();
      if(actualColor != color){
          possibleMoves[position[0] - 1][position[1]] = true;
      }
    }
    //lewo
    if((position[1] - 1) >= 0){
      actualColor = ChessBoard[position[0]][position[1]-1]->getColor();
      if(actualColor != color){
          possibleMoves[position[0]][position[1]-1] = true;
      }
    }
    //prawo
    if((position[1] + 1) < 8){
      actualColor = ChessBoard[position[0]][position[1]+1]->getColor();
      if(actualColor != color){
          possibleMoves[position[0]][position[1]+1] = true;
      }
    }
    //prawa góra
    if((position[0] + 1) < 8 && (position[1] + 1) < 8){
      actualColor = ChessBoard[position[0]+1][position[1]+1]->getColor();
      if(actualColor != color){
          possibleMoves[position[0]+1][position[1]+1] = true;
      }
    }
    //prawy dół
    if((position[0] - 1) >= 0 && (position[1] + 1) < 8){
      actualColor = ChessBoard[position[0]-1][position[1]+1]->getColor();
      if(actualColor != color){
          possibleMoves[position[0]-1][position[1]+1] = true;
      }
    }
    //lewa góra
    if((position[0] + 1) < 8 && (position[1] - 1) >= 0){
      actualColor = ChessBoard[position[0]+1][position[1]-1]->getColor();
      if(actualColor != color){
          possibleMoves[position[0]+1][position[1]-1] = true;
      }
    }
    //lewy dół
    if((position[0] - 1) >= 0 && (position[1] - 1) >= 0){
      actualColor = ChessBoard[position[0]-1][position[1]-1]->getColor();
      if(actualColor != color){
          possibleMoves[position[0]-1][position[1]-1] = true;
      }
    }


    return possibleMoves;
}

