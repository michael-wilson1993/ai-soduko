/*
	- Michael Wilson
	- mainWin.h
	- Human Computer Interaction
	- prof: Wendy Osborn
	- march 11/16
*/

#pragma once
#include "GHeader.h"
#include "QButtonCoor.h"
#include "getNum.h"
#include "QTObject.h"
#include <vector>
#include <string>
#include <iostream>
#include "canvas.h"

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
	void setnum(const int &xx, const int &yy);
	void clearBoard();
	void returnNum(const int &xx, const int &yy, const int &val);

private:
	QButtonCoor *board[9][9];
	getNum *getNum_w;
	Canvas *paint;
	QPushButton *clear_b, *solve_b, *gen_b, *close_b;


};