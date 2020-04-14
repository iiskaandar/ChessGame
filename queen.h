#include "chessgame.h"

using namespace std;

class Queen : public Pawn
{
public:
    string getName() override;
    array<array<bool,8>,8> checkPossibleMove(array<int, 2> position, array<array<Pawn*,8>,8> ChessBoard) override;
    QString getIconName() override;
    int whiteStartRow = 7;
    int whiteStartColumn = 3;
    int blackStartRow = 0;
    int blackStartColumn = 3;
};
