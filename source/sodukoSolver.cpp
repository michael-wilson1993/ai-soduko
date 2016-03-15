#include "sodukoSolver.h"
#include <iostream>



sodukoSolver::sodukoSolver()
{
	
}


sodukoSolver::~sodukoSolver()
{
}

bool sodukoSolver::startSolve()
{
	int x, y;
	board->nextSpot(x, y);

	for (int var = 1; var <= 9; var++)
	{
		//std::cerr << var << "\n";
		if (solve(x,y, var))
		{
			std::cerr << "solved!!!!!";
			return true;
		}
	}
		return false;
}
// sodukoBoard sodukoSolver::solve(sodukoBoard b, int x, int y, int val)
// {
// 	b.set(x, y, val);
// 	std::cerr << val << "\n";
// 	if (b.isSolved())
// 		return b;
// 	int nextX, nextY;
// 	b.nextSpot(nextX, nextY);
// 	for (int xx = 0; xx < 9; xx++)
// 	{
// 		sodukoBoard sol = solve(b, nextX, nextY, val);
// 		if (sol.isSolved())
// 			return sol;
// 	}
// 	return b;
// }

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
	if(!board->nextSpot(nextx, nexty))
		return true;
	for (int var = 1; var <= 9; var++)
		if (solve(nextx, nexty, var))
			return true;
	board->hardSet(x, y, 0);
	return false;
}

sodukoBoard* sodukoSolver::solveReturn(sodukoBoard *t)
{
	board = t;

	if(startSolve())
		return board;
	else
		return new sodukoBoard();
}

