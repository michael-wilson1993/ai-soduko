/*
	- Michael Wilson
	- sodukoBoard.h
	- AI 
	- prof: Yllias Chali
*/

#pragma once

#include <fstream>
#include <iostream>
using namespace std;
class sodukoBoard
{
public:
	//constructor
	sodukoBoard();
	//destructor
	~sodukoBoard();
	// sets the value on the board, if the is a valid move, return true, else return false
	bool set(int x, int y, int value);
	// nextSpot returns the spot that is next available, if there is a spot available, return true, else return false
	bool nextSpot(int &x, int &y);
	// is solved returns the value that depicts if the board is solved or not
	bool isSolved() { return solved; };
	// print solution prints the solution to a text file
	void printSolution();
	// hardset, sets the value at that part of the board without checking if it is a valid move
	bool hardSet(int x, int y, int value);
	// draw is for consols, this will draw the current board to the console
	void draw();
	// generateBoard will generate a random board with the amount of values passed in through the scope
	void generateBoard(int amount);
	// getVal returns the value at x,y on the board
	int getVal(int x, int y) {return board[x][y];};
	// clear clears the board to 0's
	void clear();

private:
	// getBlock returns the starting point of the block, pass in current location, it sets the values to the start of the "block" 3x3
	void getBlock(int &x, int &y);
	// checkRow - checks the row with value given, if it is found in the row it returns false - not valid move, else true - valid move
	bool checkRow(int x, int y, int value);
	// checkCol - checks the col with value given, if it is found in the col it returns false - not valid move, else true - valid move
	bool checkCol(int x, int y, int value);
	//checkSet will check the current block if that value is present, if the value is already in the block it returns false - not valid move, else true - valid move
	bool checkSet(int x, int y, int value);
	
	// board is a 9x9 board that contains integers
	int board[9][9];
	// if the board has no 0's present it is solved
	bool solved;
	
};

