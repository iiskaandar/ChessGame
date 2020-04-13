#include "chessgame.h"

using namespace std;

class Rook : public Pawn
{
public:
    string getName() override;
    bool checkMove(int position[2], int propositionPosition[2]) override;
    array<array<bool,8>,8> checkPossibleMove(int position[2], array<array<Pawn*,8>,8> ChessBoard) override;
    int leftWhiteStartRow = 7;
    int leftWhiteStartColumn = 0;
    int rightWhiteStartRow = 7;
    int rightWhiteStartColumn = 7;
    int leftBlackStartRow = 0;
    int leftBlackStartColumn = 0;
    int rightBlackStartRow = 0;
    int rightBlackStartColumn = 7;
};
