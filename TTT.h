#include <iostream>
#include <map> // to map SquareType to an emoji unicode


enum class SquareType { Empty, X, O };

struct Position {
	int row;
	int col;

	// already implemented for you!
	bool operator==(const Position &other) {
		return row == other.row && col == other.col;
	}
	bool operator!=(const Position &other) {
		return !(row == other.row && col == other.col);
	}
	Position():row(0),col(0){}
	Position(const int r, const int c):row(r), col(c){}
};

std::string SquareTypeStringify(SquareType sq);

class TTT{
public:
	TTT();
  // already implemented in line
  int get_rows() const {return sizeof(arr_) / sizeof(arr_[0]); }  // code to find size of a 2d array from
  int get_cols() const {return sizeof(arr_[0]) / sizeof(int); }		// https://stackoverflow.com/questions/10274162/how-to-find-2d-array-size-in-c

  SquareType get_square_value(Position pos) const;

	// set the value of a square to the given SquareType
	void SetSquareValue(Position pos, SquareType value);

  // Create a TTT board with all empty squares
  void CreateBoard();

  // Print out the board to the command line
  void DisplayBoard();

  // Prompt for a position and verify it
  int GetPlayerChoice();

  // Chance the square at pos to the given SquareType
  void PlaceMarker(Position pos, SquareType sq);

private:
  SquareType arr_[3][3];

	int rows_; // might be convenient but not necessary
	int cols_;
};
