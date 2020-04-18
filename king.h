#include "chessgame.h"

using namespace std;

class King : public Pawn
{
private:
    int whiteStartRow = 7;
    int whiteStartColumn = 4;
    int blackStartRow = 0;
    int blackStartColumn = 4;
public:
    string getName() override;
    array<array<bool,8>,8> checkPossibleMove(array<int, 2> position, array<array<Pawn*,8>,8> ChessBoard) override;
    QString getIconName() override;
    int getwhiteStartRow();
    int getwhiteStartColumn();
    int getblackStartRow();
    int getblackStartColumn();
};
