#include "chessgame.h"
#include "ui_chessgame.h"

ChessGame::ChessGame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChessGame)
{
    ui->setupUi(this);
}

ChessGame::~ChessGame()
{
    delete ui;
}

