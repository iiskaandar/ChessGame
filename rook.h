#include "chessgame.h"

using namespace std;

class Rook : public Pawn
{
public:
    string getName() override;
    array<array<bool,8>,8> checkPossibleMove(array<int, 2> position, array<array<Pawn*,8>,8> ChessBoard) override;
    int leftWhiteStartRow = 7;
    int leftWhiteStartColumn = 0;
    int rightWhiteStartRow = 7;
    int rightWhiteStartColumn = 7;
    int leftBlackStartRow = 0;
    int leftBlackStartColumn = 0;
    int rightBlackStartRow = 0;
    int rightBlackStartColumn = 7;
};
