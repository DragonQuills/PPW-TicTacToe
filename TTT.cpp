#include "TTT.h"

std::string SquareTypeStringify(SquareType sq){
  //uses a map to avoid using lots of if if else statements
  std::map<SquareType, std::string> EmojiMap = {
    {SquareType::Empty, "\U00002B1C"},
    {SquareType::X, "\U0000274C"},
    {SquareType::O, "\U00002B55"},
  };
  return EmojiMap[sq];
}

TTT::TTT(){
  rows_ = this->get_rows();
  cols_ = this->get_cols();
  return;
}

SquareType TTT::get_square_value(Position pos) const{
  if( (pos.row >= 0 && pos.row <rows_) && (pos.col >= 0 && pos.col < cols_)){
    // if the position given is on the board, give that square type.
    return arr_[pos.row][pos.col];
  }
  // otherwise return a wall (so that it won't display as a valid move option)
  return SquareType::Empty;
}

void TTT::SetSquareValue(Position pos, SquareType value){
  if( (pos.row >= 0 && pos.row <rows_) && (pos.col >= 0 && pos.col < cols_)){
    // if the position given is on the board, set that square;
    arr_[pos.row][pos.col] = value;
  }
  else{
    std::cout << "Error! Invalid position (not on board)"<<std::endl;
  }
  return;
}

void TTT::CreateBoard(){
  for(int i = 0; i < rows_; i++){
    for(int j = 0; j < cols_; j++){
      Position new_pos = Position(i, j);
      this->SetSquareValue(new_pos, SquareType::Empty);
    }
  }
}

void TTT::DisplayBoard(){
  for(int i = 0; i < rows_; i++){
    for(int j = 0; j < cols_; j++){
      SquareType sq =this->get_square_value(Position(i, j));
      std::cout << SquareTypeStringify(sq);
    }
    std::cout << "\n";
  }
}

Position TTT::GetPlayerChoice(){
  int row = -1;
  int col = -1;
  while((row < 0 || row > rows_) || (col < 0 || col > cols_)){
    std::cout << "What row would you like to place your marker on?" << std::endl;
    std::string temp = "";
    std::cin>>temp;
    try{
      row = std::stoi(temp);
    }
    catch(...){
      std::cout << "That isn't a number. Try again.\n";
      continue;
    }
    std::cout << "What column would you like to place your marker on?" << std::endl;
    std::cin>>temp;
    try{
      col = std::stoi(temp);
    }
    catch(...){
      std::cout << "That isn't a number. Try again.\n";
      continue;
    }
    std::cout << "You picked (" << row << ", " << col << ")\n";
    std::cout << "Is this correct? (y/n)\n";
    std::string choice;
    std::cin>>choice;
    if(choice != "y"){
      row = -1;
      col = -1;
      continue;
    }
    if ((row < 0 || row > rows_) || (col < 0 || col > cols_)){
      std::cout<<"Invalid choice. Please pick a row and column on the board.\n";
    }
  }
  return Position(row-1, col-1);
}
