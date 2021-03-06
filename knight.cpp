#include "knight.h"

using namespace std;

string Knight::getName(){
    return ("Koń");
}

int Knight::getleftWhiteStartRow(){
    return Knight::leftWhiteStartRow;
}
int Knight::getleftWhiteStartColumn(){
    return Knight::leftWhiteStartColumn;
}
int Knight::getrightWhiteStartRow(){
    return Knight::rightWhiteStartRow;
}
int Knight::getrightWhiteStartColumn(){
    return Knight::rightWhiteStartColumn;
}
int Knight::getleftBlackStartRow(){
    return Knight::leftBlackStartRow;
}
int Knight::getleftBlackStartColumn(){
    return Knight::leftBlackStartColumn;
}
int Knight::getrightBlackStartRow(){
    return Knight::rightBlackStartRow;
}
int Knight::getrightBlackStartColumn(){
    return Knight::rightBlackStartColumn;
}

QString Knight::getIconName(){
    if(Knight::getColor() == "white"){
        return("horse1");
    } else {
        return("horse");
    }
}

/*!
 * \brief Knight::checkPossibleMove Function return possible movex of object
 * \param position Current position of object
 * \param ChessBoard Current position of all object on chess board
 * \return List boolean, which field is possible to move on
 */
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


