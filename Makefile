CXX = g++
CXXFLAGS	= -std=c++17 -Wall

all: TicTacToe

clean:
	rm TTT.o TicTacToe

run: TicTacToe
	./TicTacToe

TicTacToe: TTT.o TicTacToe.cpp
	$(CXX) $(CXXFLAGS) TicTacToe.cpp TTT.o -o TicTacToe

TTT.o: TTT.cpp
	$(CXX) $(CXXFLAGS) -c TTT.cpp
