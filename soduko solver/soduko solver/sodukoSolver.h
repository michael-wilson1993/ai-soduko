#pragma once
#include "sodukoBoard.h"

class sodukoSolver
{
public:
	sodukoSolver(sodukoBoard *t);
	~sodukoSolver();
	sodukoBoard solve(sodukoBoard b, int x, int y, int val);
	bool solve(int x, int y, int val);
	void startSolve();

private:
	sodukoBoard *board;
	
};

