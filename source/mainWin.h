/*
	- Michael Wilson
	- mainWin.h
	- AI 
	- prof: Yllias Chali
*/

#pragma once
#include "GHeader.h"
#include "QButtonCoor.h"
#include "getNum.h"
#include "QTObject.h"
#include "QTClock.h"
#include <vector>
#include <string>
#include <iostream>
#include "canvas.h"
#include "sodukoBoard.h"
#include "sodukoSolver.h"

class CInsert;
class QLabel;
class QPushButton;
class QTableWidget;
class QListWidget;
class QListWidgetItem;
class QTableView;


class mainWin: public QMainWindow
{
Q_OBJECT
public:
	//constructor
	mainWin();
public slots:
	// solve slot is a slot the allows me to connect a button to this function, when i press the connected button it will solve the current soduko board
	void solve_slot();
	// setnum is a slot that allows me to set the number located at the certain part of the board
	void setnum(const int &xx, const int &yy);
	// clearBoard is a slot that clears the current board
	void clearBoard();
	// returnnum is a slot that returns the location and the value at a certain location so the board can be updated with it,
	// xx,yy is the loation, and val is the value that will be set at the location
	void returnNum(const int &xx, const int &yy, const int &val);
	// animTick is the slot that allows animation to happen
	void animTick(const int &info);
	// generate_slot is a slot that allows the program to connect a button to the generate function in sodukoBoard
	void generate_slot();

private:
	// GUI of the board using buttons
	QButtonCoor *board[9][9];
	// the actual soduko board that contains all the values
	sodukoBoard *SBoard;
	// soduko solver will solve the SBoard
	sodukoSolver solver;
	// getNum_w is a widget that has 1 - 9 buttons so you can choose what value you want to be in that certain box
	getNum *getNum_w;
	// paint is a canvas that is behind the buttons, allowing me to draw the lines for the board
	Canvas *paint;
	// colorClock is a clock that changes the color of a block after selecting its value,
	QTClock * colorClock;
	// buttons in the main windows that clears, solves, generates the board, close will close the main window
	QPushButton *clear_b, *solve_b, *gen_b, *close_b;


};