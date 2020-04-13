#include "chessgame.h"

using namespace std;

class Knight : public Pawn
{
public:
    string getName() override;
    int leftWhiteStartRow = 7;
    int leftWhiteStartColumn = 1;
    int rightWhiteStartRow = 7;
    int rightWhiteStartColumn = 6;
    int leftBlackStartRow = 0;
    int leftBlackStartColumn = 1;
    int rightBlackStartRow = 0;
    int rightBlackStartColumn = 6;
};
