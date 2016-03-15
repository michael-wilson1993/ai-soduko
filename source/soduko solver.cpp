// soduko solver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "sodukoSolver.h"
#include "sodukoBoard.h"

int main()
{
	sodukoBoard *ab;
	ab = new sodukoBoard;
	ab->generateBoard(58);
	ab->printSolution();
	ab->draw();
	sodukoSolver soduko(ab);
	soduko.startSolve();
	
    return 0;
}

