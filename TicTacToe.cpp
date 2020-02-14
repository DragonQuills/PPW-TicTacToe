#include "TTT.h"

int main() {
  TTT *ttt = new TTT();
  ttt->CreateBoard();
  SquareType curr_player = SquareType::O;
  for(int i = 0; i < 9; i++){
    ttt->DisplayBoard();
    switch(curr_player){
      case (SquareType::X):
        std::cout << "It is currently X's turn.\n";
        break;
      case (SquareType::O):
        std::cout << "It is currently O's turn.\n";
        break;
    }
    Position p = ttt->GetPlayerChoice();
    ttt->PlaceMarker(p, curr_player);
    switch(curr_player){
      case (SquareType::X):
        curr_player = SquareType::O;
        break;
      case (SquareType::O):
        curr_player = SquareType::X;
        break;
    }
  }
  return 0;
}
