#include "chessgame.h"

using namespace std;

class Queen : public Pawn
{
public:
    string getName() override;
    int whiteStartRow = 7;
    int whiteStartColumn = 3;
    int blackStartRow = 0;
    int blackStartColumn = 3;
};
