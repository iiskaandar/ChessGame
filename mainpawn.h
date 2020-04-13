#include "chessgame.h"

using namespace std;

class MainPawn : public Pawn
{
public:
    bool firstMove = true;
    string getName() override;
    bool getFirstMove() override;
    void setFirstMove(bool isFirstMove) override;
    array<array<bool,8>,8> checkPossibleMove(int position[2], array<array<Pawn*,8>,8> ChessBoard) override;
};
