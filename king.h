#include "chessgame.h"

using namespace std;

class King : public Pawn
{
public:
    string getName() override;
    int whiteStartRow = 7;
    int whiteStartColumn = 4;
    int blackStartRow = 0;
    int blackStartColumn = 4;
};
