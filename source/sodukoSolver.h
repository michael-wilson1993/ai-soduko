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
	sodukoSolver();
	~sodukoSolver();
	//sodukoBoard solve(sodukoBoard b, int x, int y, int val);
	bool solve(int x, int y, int val);
	bool startSolve();
	sodukoBoard* solveReturn(sodukoBoard *t);

private:
	sodukoBoard *board;
	
};

