/*
	- Michael Wilson
	- getNum.h
	- AI 
	- prof: Yllias Chali
*/

#pragma once
#include <QDialog>
#include "QButtonCoor.h"


// QT classes needed for GUI
class QTimer;
class Canvas;
class QLabel;
class QPushButton;
class QGridgeLayout;

class getNum :public QDialog
{
	Q_OBJECT
public:
	//constructor
	getNum(QWidget *parent = 0);
	//destructor
	~getNum();
	// stores the coordinate of the button in mainWin
	void setCoor(int xx, int yy) {x=xx;y=yy;};

signals:
	// sendinfo is a signal that sends the x,y of the button on the mainWin with the value it needs to get changed to.
	void sendInfo(const int &xx, const int &yy, const int &val);

private slots:
	//sendInfoSlot is a slot that emits sendInfo signal to the rest of the program
	void sendInfoSlot(const int &xx, const int &yy);


private:
	int x, y, value;
	QButtonCoor *nums[3][3];

};