#include "chessgame.h"
#include <string>
#include <QString>

using namespace std;

class Pawn {
private:
 string name;
 string color = "";
 bool firstMove;
public:

 void setColor(string color);
 string getColor();
  virtual string getName();
  virtual bool getFirstMove();
  virtual void setFirstMove(bool isFirstMove);
 virtual array<array<bool,8>,8>  checkPossibleMove(array<int, 2> position, array<array<Pawn*,8>,8> ChessBoard);
 virtual QString getIconName();
public:
 Pawn(){};
};
