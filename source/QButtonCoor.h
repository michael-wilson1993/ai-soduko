/*
	- Michael Wilson
	- QButtonCoor.h
	- AI 
	- prof: Yllias Chali
*/

#pragma once
#include "GHeader.h"


class QButtonCoor: public QPushButton
{
		Q_OBJECT // needed to be a QT OBject
public:
	// constructor, sets coordinates for the button
	QButtonCoor(int xx, int yy);
	// setVal sets the value contained in the button
	void setVal(int value) {val = value;};
	// setTextFromInt sets the text in the button from a integer value
	void setTextFromInt(int value);
	// stringToInt converts a string to a integer value
	int stringToInt(std::string changer);
	// intToString converts a integer into a QString (QString is needed for the button)
	QString IntToString(int changer);
	
private slots:
	// slot that emits sendingCoor to the program. activated when a button is clicked
	void sendCoor();

signals:
	// sendingCoor will send a x and y value which is the coordinates of the button. gets sent to the whole program who is connected to it.
	void sendingCoor(const int &xx, const int &yy);



public:
	int x,y, val;
};