#include "sodukoBoard.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


sodukoBoard::sodukoBoard()
{
	srand(time(NULL));
	solved = false;
	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			board[x][y] = 0;
		}
	}
}


sodukoBoard::~sodukoBoard()
{
}
bool sodukoBoard::hardSet(int x, int y, int value)
{

	board[x][y] = value;
	return true;
}
bool sodukoBoard::set(int x, int y, int value)
{
	//draw();
	int xx = x ;
	int yy = y ;
	if (xx < 0 || xx > 8) // if the x value is off the board return false
		return false;
	if (yy < 0 || yy > 8) // if the y value is off the board return false
		return false;
	if (value < 1 || value > 9) // if the value itself is less than 1 or greater than 9 return false
		return false;
	if (checkRow( x,  y,  value) && checkCol(x, y, value) && checkSet(x, y, value)) // checks constraints
	{
		board[xx][yy] = value; // value is assigned and return true...
		return true;
	}
	return false;
}

bool sodukoBoard::checkRow(int x, int y, int value)
{
	bool flag = true; // default true untill proven otherwise
	for (int xx = 0; xx < 9; xx++) // spans the size of the board
	{
		if (board[xx][y] == value)
			flag = false;
	}
	return flag;
}
bool sodukoBoard::checkCol(int x, int y, int value)
{
	bool flag = true; // default true untill proven otherwise
	for (int yy = 0; yy < 9; yy++) // spans the size of the board
	{
		if (board[x][yy] == value)
			flag = false;
	}
	return flag;
}
bool sodukoBoard::checkSet(int x, int y, int value)
{
	int Gx=x, Gy= y;
	getBlock(Gx, Gy);
	int loopX= Gx *3, loopY = Gy *3;
	bool flag = true;
	for (int LX = loopX; LX < loopX + 3; LX++)
	{
		for (int LY = loopY; LY < loopY + 3; LY++)
		{
			if (board[LX][LY] == value)
				flag = false;
		}
	}
	return flag;
}

bool sodukoBoard::nextSpot(int &x, int &y)
{
	//gets next spot
	for (int xx = 0; xx < 9; xx++)
	{
		for (int yy = 0; yy < 9; yy++)
		{
			if (board[xx][yy] == 0)
			{
				x = xx;
				y = yy;
				return true;
			}
		}
	}
	solved = true;
	//printSolution();
	return false;
}

void sodukoBoard::getBlock(int &x, int &y)
{
	//determines what block of x we are in
	if (x >= 0 && x < 3)
		x = 0;
	else if (x > 2 && x < 6)
		x = 1;
	else if (x > 5 && x < 9)
		x = 2;
	//determines what block of y we are in
	if (y >= 0 && y < 3)
		y = 0;
	else if (y > 2 && y < 6)
		y = 1;
	else if (y > 5 && y < 9)
		y = 2;
}

void sodukoBoard::printSolution()
{
	ofstream fout;
	if (solved)
	{
		fout.open("solution.txt", fstream::app);
		fout << "############################################" << endl;
		fout << "########        Solution           #########" << endl;
		fout << "############################################" << endl;
	}
	else
	{
		fout.open("solution.txt");
		fout << "############################################" << endl;
		fout << "########        puzzle             #########" << endl;
		fout << "############################################" << endl;

	}
	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			if (y % 3 == 0)
				fout << " ";
			fout << board[x][y] << " ";
		}
		if ((x + 1) % 3 == 0)
			fout << "\n";
		fout << "\n";
	}
	fout.close();
}

void sodukoBoard::draw()
{
	system("cls");
	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			if (y % 3 == 0)
				std::cout << " ";
			std::cout << board[x][y] << " ";
		}
		if ((x + 1) % 3 == 0)
			std::cout << "\n";
		std::cout << "\n";
	}
	system("pause>nul");
}

void sodukoBoard::generateBoard(int amount)
{
	int x, y, count = 0;

	while (count < amount)
	{
		cout << "\n" << count << "\n";
		x = rand() % 9;
		y = rand() % 9;
		if (board[x][y] == 0)
		{
			if (set(x, y, rand() % 9))
				count++;
		}

	}
}

void sodukoBoard::clear()
{
	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			board[x][y] = 0;
		}
	}
	solved = false;
}