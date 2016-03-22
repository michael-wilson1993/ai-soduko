/*
	- Michael Wilson
	- sodukoSolver.h
	- AI 
	- prof: Yllias Chali
*/

#pragma once
#include "sodukoBoard.h"

class sodukoSolver
{
public:
	//constructor
	sodukoSolver();
	//destructor
	~sodukoSolver();
	//solve will solve the board using recursion
	bool solve(int x, int y, int val);
	//start solve will start the "solve" function with the base case properly
	bool startSolve();
	// solveReturn will return the solved board
	sodukoBoard* solveReturn(sodukoBoard *t);


private:
	// holds the board that needs to be solved
	sodukoBoard *board;
	
};

