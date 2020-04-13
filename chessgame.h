#ifndef CHESSGAME_H
#define CHESSGAME_H

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
};
#endif // CHESSGAME_H
