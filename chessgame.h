#ifndef CHESSGAME_H
#define CHESSGAME_H
#include <tuple>
#include "pawn.h"
#include "ui_chessgame.h"
#include <iostream>
#include <string>
#include <array>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ChessGame; }
QT_END_NAMESPACE

class ChessGame : public QMainWindow
{
    Q_OBJECT

public:
    ChessGame(QWidget *parent = nullptr);
    ~ChessGame();

private:
    Ui::ChessGame *ui;
    array<array<Pawn*,8>,8> ChessBoard;
    array<int, 2> selectedPosition = {-1, -1};
    array<int, 2> propositionPosition;
    array<array<bool,8>,8> possibleMoves;
    string turn = "white";
    bool isWinner = false;

private slots:
    void FieldPressed();
    void SetBoard();
    void SetPawn(Pawn* pawn, int columnt, int row, string color);
    void SetSelectedPosition(int row, int col);
    void SetSelectedProposition(int row, int col);
    void CheckPossibleMoves(Pawn* pawn);
    void MovePawn();
    void TryToMovePawn();
    bool CheckPosition();
    void ResetPosition();
    void ChangeTurn();
    void CheckLoss();
    void UndisableButtons();
    void UndisablePossibleMoves();
    void DisableAllButtons();
    void AddIcon(QString url, QPushButton* button);

};
#endif // CHESSGAME_H
