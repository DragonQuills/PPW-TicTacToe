#include "TTT.h"

int main() {
  TTT *ttt = new TTT();
  ttt->CreateBoard();

  ttt->DisplayBoard();
  Position p = ttt->GetPlayerChoice();
  return 0;
}
