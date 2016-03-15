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
	sodukoBoard();
	~sodukoBoard();
	bool set(int x, int y, int value);
	bool nextSpot(int &x, int &y);
	bool isSolved() { return solved; };
	void printSolution();
	bool hardSet(int x, int y, int value);
	void draw();
	void generateBoard(int amount);
	int getVal(int x, int y) {return board[x][y];};
	void clear();

private:
	void getBlock(int &x, int &y);
	bool checkRow(int x, int y, int value);
	bool checkCol(int x, int y, int value);
	bool checkSet(int x, int y, int value);
	
	int board[9][9];
	bool solved;
	
};

