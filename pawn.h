#include "chessgame.h"
#include <string>

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
  virtual bool checkMove(int position[2], int propositionPosition[2]);
  virtual bool getFirstMove();
  virtual void setFirstMove(bool isFirstMove);
 virtual array<array<bool,8>,8>  checkPossibleMove(int position[2], array<array<Pawn*,8>,8> ChessBoard);
public:
 Pawn(){};
};
