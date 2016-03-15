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
	void solve_slot();
	void setnum(const int &xx, const int &yy);
	void clearBoard();
	void returnNum(const int &xx, const int &yy, const int &val);
	void animTick(const int &info);
	void generate_slot();

private:
	QButtonCoor *board[9][9];
	sodukoBoard *SBoard;
	sodukoSolver solver;
	getNum *getNum_w;
	Canvas *paint;
	QTClock * colorClock;
	QPushButton *clear_b, *solve_b, *gen_b, *close_b;


};