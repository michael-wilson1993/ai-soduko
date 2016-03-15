#include "sodukoSolver.h"
#include <iostream>



sodukoSolver::sodukoSolver(sodukoBoard *t)
{
	board = t;
}


sodukoSolver::~sodukoSolver()
{
}

void sodukoSolver::startSolve()
{
	int x, y;
	board->nextSpot(x, y);
	for (int var = 1; var <= 9; var++)
		if (solve(x,y, var))
		{
			std::cout << "worked!!!";
			break;
		}
}
sodukoBoard sodukoSolver::solve(sodukoBoard b, int x, int y, int val)
{
	b.set(x, y, val);
	if (b.isSolved())
		return b;
	int nextX, nextY;
	b.nextSpot(nextX, nextY);
	for (int xx = 0; xx < 9; xx++)
	{
		sodukoBoard sol = solve(b, nextX, nextY, val);
		if (sol.isSolved())
			return sol;
	}
	return b;
}

bool sodukoSolver::solve(int x, int y, int val)
{
	if (!board->set(x, y, val))
	{
		board->hardSet(x, y, 0);
		return false;
	}
	if (board->isSolved())
		return true;
	int nextx, nexty;
	board->nextSpot(nextx, nexty);
	for (int var = 1; var <= 9; var++)
		if (solve(nextx, nexty, var))
			return true;
	board->hardSet(x, y, 0);
	return false;
}

