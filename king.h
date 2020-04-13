#include "chessgame.h"

using namespace std;

class King : public Pawn
{
public:
    string getName() override;
    array<array<bool,8>,8> checkPossibleMove(array<int, 2> position, array<array<Pawn*,8>,8> ChessBoard) override;
    int whiteStartRow = 7;
    int whiteStartColumn = 4;
    int blackStartRow = 0;
    int blackStartColumn = 4;
};
