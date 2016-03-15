#pragma once
#include "GHeader.h"


class QButtonCoor: public QPushButton
{
		Q_OBJECT
public:

	QButtonCoor(int xx, int yy);
	void setVal(int value) {val = value;};
	void setTextFromInt(int value);
	int stringToInt(std::string changer);
	QString IntToString(int changer);
	
private slots:
	void sendCoor();

signals:
	void sendingCoor(const int &xx, const int &yy);



public:
	int x,y, val;
};