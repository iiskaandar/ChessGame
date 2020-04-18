#include "chessgame.h"

using namespace std;

class Bishop : public Pawn
{
private:
    int leftWhiteStartRow = 7;
    int leftWhiteStartColumn = 2;
    int rightWhiteStartRow = 7;
    int rightWhiteStartColumn = 5;
    int leftBlackStartRow = 0;
    int leftBlackStartColumn = 2;
    int rightBlackStartRow = 0;
    int rightBlackStartColumn = 5;
public:
    string getName() override;
    array<array<bool,8>,8> checkPossibleMove(array<int, 2> position, array<array<Pawn*,8>,8> ChessBoard) override;
    QString getIconName() override;
    int getleftWhiteStartRow();
    int getleftWhiteStartColumn();
    int getrightWhiteStartRow();
    int getrightWhiteStartColumn();
    int getleftBlackStartRow();
    int getleftBlackStartColumn();
    int getrightBlackStartRow();
    int getrightBlackStartColumn();

};
