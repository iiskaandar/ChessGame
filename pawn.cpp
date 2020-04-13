#include "chessgame.h"
#include <QDebug>
#include <array>

using namespace std;

string Pawn::getName(){
    return Pawn::name;
}

void Pawn::setColor(string color){
    Pawn::color = color;
}

bool Pawn::checkMove(int position[2], int propositionPosition[2]){
    qInfo() << position;
    qInfo() << propositionPosition;
    return(false);
}

array<array<bool,8>,8> Pawn::checkPossibleMove(int position[2], array<array<Pawn*,8>,8> ChessBoard){
    array<array<bool,8>,8> possibleMoves;
    return(possibleMoves);
}

string Pawn::getColor(){
    return (Pawn::color);
}

bool Pawn::getFirstMove(){
    return ( Pawn::firstMove);
}

void Pawn::setFirstMove(bool isFirstMove){
    Pawn::firstMove = isFirstMove;
}
