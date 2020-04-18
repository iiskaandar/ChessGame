#include "chessgame.h"
#include "ui_chessgame.h"
#include "king.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "mainpawn.h"
#include <vector>
#include <string>
#include <QDebug>
#include <cmath>

ChessGame::ChessGame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChessGame)
{
    ui->setupUi(this);
    QPushButton *numButtons[64];
    for(int column=0; column<8; ++column){
        for(int row=0; row<8; ++row) {
            QString butName = "field_" + QString::number(column) + QString::number(row) ;
            numButtons[(row+1)*(column+1)] = ChessGame::findChild<QPushButton *>(butName);
            numButtons[(row+1)*(column+1)]->setText("");
            numButtons[(row+1)*(column+1)]->setDisabled(true);
            connect(numButtons[(row+1)*(column+1)], SIGNAL(released()), this,
                    SLOT(FieldPressed()));
        }

    }
    ChessGame::SetBoard();
    ui->turn->setText(QString::fromStdString(ChessGame::turn));
    UndisableButtons();

}

ChessGame::~ChessGame()
{
    delete ui;
}

/*!
 * \brief ChessGame::UndisableButtons undisable white or black buttons depends on turn
 */
void ChessGame::UndisableButtons(){
    string color = ChessGame::turn;
    for(int row=0; row <8; row++){
        for(int col=0; col<8; col++){
            QString field = "field_" + QString::number(row) + QString::number(col);
            QPushButton *button = ChessGame::findChild<QPushButton *>(field);
            if(ChessGame::ChessBoard[row][col]->getColor() == color){
                button->setDisabled(false);
            }
        }
    }
}

/*!
 * \brief ChessGame::DisableAllButtons Disable all buttons on the chess board
 */
void ChessGame::DisableAllButtons(){
    for(int row=0; row <8; row++){
        for(int col=0; col<8; col++){
            QString field = "field_" + QString::number(row) + QString::number(col);
            QPushButton *button = ChessGame::findChild<QPushButton *>(field);
            button->setDisabled(true);
        }
    }
}

/*!
 * \brief ChessGame::UndisablePossibleMoves Undisable buttons on which selected object can move
 */
void ChessGame::UndisablePossibleMoves(){
    for(int row=0; row <8; row++){
        for(int col=0; col<8; col++){
            if(ChessGame::possibleMoves[row][col] == true){
                QString field = "field_" + QString::number(row) + QString::number(col);
                QPushButton *button = ChessGame::findChild<QPushButton *>(field);
                button->setDisabled(false);
            }
        }
    }
}

/*!
 * \brief ChessGame::FieldPressed When button is pressed this function checks what has to be done to move on this object
 */
void ChessGame::FieldPressed(){
    QPushButton *button = (QPushButton *)sender();
    QString butName = button->objectName();
    int row = butName.split("_")[1][0].digitValue();
    int col = butName.split("_")[1][1].digitValue();

    if(ChessGame::selectedPosition[0] >= 0){
        SetSelectedProposition(row, col);
        TryToMovePawn();
     } else {
        SetSelectedPosition(row, col);
        CheckPossibleMoves(ChessGame::ChessBoard[row][col]);
        UndisablePossibleMoves();
     }

}

void ChessGame::SetSelectedPosition(int row, int col){
    ChessGame::selectedPosition[0] = row;
    ChessGame::selectedPosition[1] = col;
}

void ChessGame::CheckPossibleMoves(Pawn* pawn){
    ChessGame::possibleMoves = pawn->checkPossibleMove(ChessGame::selectedPosition, ChessGame::ChessBoard);
}

void ChessGame::SetSelectedProposition(int row, int col){
    ChessGame::propositionPosition[0] = row;
    ChessGame::propositionPosition[1] = col;
}

/*!
 * \brief ChessGame::TryToMovePawn Make move of object on chess board, and checks if is winner
 */
void ChessGame::TryToMovePawn(){
    bool isRightPosition = CheckPosition();
    if(isRightPosition){
        if(ChessGame::ChessBoard[ChessGame::selectedPosition[0]][ChessGame::selectedPosition[1]]->getName() == "Pion"){
          ChessGame::ChessBoard[ChessGame::selectedPosition[0]][ChessGame::selectedPosition[1]]->setFirstMove(false);
        }
        MovePawn();
        if(!ChessGame::isWinner){
          ChangeTurn();
        }

    }
    ResetPosition();
    DisableAllButtons();
    UndisableButtons();
}

/*!
 * \brief ChessGame::ChangeTurn After move position of object is changed turn
 */
void ChessGame::ChangeTurn(){
    if(ChessGame::turn == "white"){
        ChessGame::turn = "black";
    } else {
        ChessGame::turn = "white";
    }
    ui->turn->setText(QString::fromStdString(ChessGame::turn));
}

/*!
 * \brief ChessGame::MovePawn if it is possible, move pawn and reset last position of object
 */
void ChessGame::MovePawn(){
    CheckLoss();
    Pawn* pawnToMove = ChessGame::ChessBoard[ChessGame::selectedPosition[0]][ChessGame::selectedPosition[1]];
    ChessGame::ChessBoard[ChessGame::propositionPosition[0]][ChessGame::propositionPosition[1]] = pawnToMove;
    QString field = "field_" + QString::number(ChessGame::propositionPosition[0]) + QString::number(ChessGame::propositionPosition[1]);
    QPushButton *button = ChessGame::findChild<QPushButton *>(field);
    button->setText(QString::fromStdString(pawnToMove->getName()));
    AddIcon(pawnToMove->getIconName(), button);
    Pawn* nullPawn = new Pawn();
    ChessGame::ChessBoard[ChessGame::selectedPosition[0]][ChessGame::selectedPosition[1]] = nullPawn;
    QString fieldNull = "field_" + QString::number(ChessGame::selectedPosition[0]) + QString::number(ChessGame::selectedPosition[1]);
    QPushButton *nullButton = ChessGame::findChild<QPushButton *>(fieldNull);
    nullButton->setText(QString::fromStdString(nullPawn->getName()));
    nullButton->setIcon(QIcon());
}

/*!
 * \brief ChessGame::CheckLoss Check if is winner or looser
 */
void ChessGame::CheckLoss(){
    if(ChessGame::ChessBoard[ChessGame::propositionPosition[0]][ChessGame::propositionPosition[1]]->getName() == "Król"){
        string lostMessage = ChessGame::ChessBoard[ChessGame::propositionPosition[0]][ChessGame::propositionPosition[1]]->getColor() + " lost";
        ui->turn->setText(QString::fromStdString(lostMessage));
        ChessGame::isWinner = true;
    }
}


void ChessGame::ResetPosition(){
    ChessGame::selectedPosition[0] = -1;
    ChessGame::selectedPosition[1] = -1;
}

bool ChessGame::CheckPosition(){
    bool isRightPosition = ChessGame::possibleMoves[ChessGame::propositionPosition[0]][ChessGame::propositionPosition[1]];
    return (isRightPosition);
}

/*!
 * \brief ChessGame::SetBoard Add all pawn on chess board
 */
void ChessGame::SetBoard(){
    for(int row=0; row<8; row++){
        for(int col=0; col<8; col++){
           Pawn* nullPawn = new Pawn();
           ChessGame::ChessBoard[row][col] = nullPawn;
        }
    }
    Rook *leftWhiteRook = new Rook;
    ChessGame::SetPawn(leftWhiteRook, leftWhiteRook->getleftWhiteStartColumn(), leftWhiteRook->getleftWhiteStartRow(), "white");
    Rook *rightWhiteRook= new Rook;
    ChessGame::SetPawn(rightWhiteRook, rightWhiteRook->getrightWhiteStartColumn(), rightWhiteRook->getrightWhiteStartRow(), "white");
    Rook *leftBlackRook = new Rook;
    ChessGame::SetPawn(leftBlackRook, leftBlackRook->getleftBlackStartColumn(), leftBlackRook->getleftBlackStartRow(), "black");
    Rook *rightBlackRook = new Rook;
    ChessGame::SetPawn(rightBlackRook, rightBlackRook->getrightBlackStartColumn(), rightBlackRook->getrightBlackStartRow(), "black");
    Knight *leftWhiteKnight = new Knight;
    ChessGame::SetPawn(leftWhiteKnight, leftWhiteKnight->getleftWhiteStartColumn(), leftWhiteKnight->getleftWhiteStartRow(), "white");
    Knight *rightWhiteKnight = new Knight;
    ChessGame::SetPawn(rightWhiteKnight, rightWhiteKnight->getrightWhiteStartColumn(), rightWhiteKnight->getrightWhiteStartRow(), "white");
    Knight *leftBlackKnight = new Knight;
    ChessGame::SetPawn(leftBlackKnight, leftBlackKnight->getleftBlackStartColumn(), leftBlackKnight->getleftBlackStartRow(), "black");
    Knight *rightBlackKnight = new Knight;
    ChessGame::SetPawn(rightBlackKnight, rightBlackKnight->getrightBlackStartColumn(), rightBlackKnight->getrightBlackStartRow(), "black");
    Bishop *leftWhiteBishop = new Bishop;
    ChessGame::SetPawn(leftWhiteBishop, leftWhiteBishop->getleftWhiteStartColumn(), leftWhiteBishop->getleftWhiteStartRow(), "white");
    Bishop *rightWhiteBishop = new Bishop;
    ChessGame::SetPawn(rightWhiteBishop, rightWhiteBishop->getrightWhiteStartColumn(), rightWhiteBishop->getrightWhiteStartRow(), "white");
    Bishop *leftBlackBishop = new Bishop;
    ChessGame::SetPawn(leftBlackBishop, leftBlackBishop->getleftBlackStartColumn(), leftBlackBishop->getleftBlackStartRow(), "black");
    Bishop *rightBlackBishop = new Bishop;
    ChessGame::SetPawn(rightBlackBishop, rightBlackBishop->getrightBlackStartColumn(), rightBlackBishop->getrightBlackStartRow(), "black");
    King *whiteKing = new King;
    ChessGame::SetPawn(whiteKing, whiteKing->getwhiteStartColumn(), whiteKing->getwhiteStartRow(), "white");
    King *blackKing = new King;
    ChessGame::SetPawn(blackKing, blackKing->getblackStartColumn(), blackKing->getblackStartRow(), "black");
    Queen *whiteQueen = new Queen;
    ChessGame::SetPawn(whiteQueen, whiteQueen->getwhiteStartColumn(), whiteQueen->getwhiteStartRow(), "white");
    Queen *blackQueen = new Queen;
    ChessGame::SetPawn(blackQueen, blackQueen->getblackStartColumn(), blackQueen->getblackStartRow(), "black");

    for(int i=0; i<8; i++){
        MainPawn *blackMainPawn = new MainPawn;
        ChessGame::SetPawn(blackMainPawn, i, 1, "black");
        MainPawn *whiteMainPawn = new MainPawn;
        ChessGame::SetPawn(whiteMainPawn, i, 6, "white");
    }

}

/*!
 * \brief ChessGame::SetPawn Set individual pawn
 * \param pawn Class which is inherited of Pawn abstraction
 * \param column Current column
 * \param row Current row
 * \param color What color of pawn
 */
void ChessGame::SetPawn(Pawn* pawn, int column, int row, string color){
    pawn->setColor(color);
    ChessGame::ChessBoard[row][column] = pawn;
    QString field = "field_" + QString::number(row) + QString::number(column);
    QPushButton *button = ChessGame::findChild<QPushButton *>(field);
    button->setText(QString::fromStdString(pawn->getName()));
    AddIcon(pawn->getIconName(), button);
}

/*!
 * \brief ChessGame::AddIcon Add icon to button of pawn
 * \param url Url to image of icon
 * \param button To which button has to add icon
 */
void ChessGame::AddIcon(QString url, QPushButton* button){
    QIcon icon;
    QPixmap qpm;
    if(qpm.load(":/images/"+url+".png"))
    {
        icon.addPixmap(qpm);
        button->setIcon(icon);
    }
}



