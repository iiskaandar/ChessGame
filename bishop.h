#include "chessgame.h"

using namespace std;

class Bishop : public Pawn
{
public:
    string getName() override;
    int leftWhiteStartRow = 7;
    int leftWhiteStartColumn = 2;
    int rightWhiteStartRow = 7;
    int rightWhiteStartColumn = 5;
    int leftBlackStartRow = 0;
    int leftBlackStartColumn = 2;
    int rightBlackStartRow = 0;
    int rightBlackStartColumn = 5;
};
