#ifndef CHESSGAME_H
#define CHESSGAME_H
#include <tuple>
#include "pawn.h"
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
    int selectedPosition[2] = {-1, -1};
    int propositionPosition[2];
    array<array<bool,8>,8> possibleMoves;

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

};
#endif // CHESSGAME_H
