#include "QButtonCoor.h"

QButtonCoor::QButtonCoor(int xx, int yy)
{
	x = xx;
	y = yy;
	connect(this, SIGNAL(clicked()), this, SLOT(sendCoor()));
}

void QButtonCoor::sendCoor()
{
	emit sendingCoor(x,y);
}

void QButtonCoor::setTextFromInt(int value)
{
	setText(IntToString(value));
}

int QButtonCoor::stringToInt(std::string changer)
{
	int ret;
	for(int x = 0; x < changer.size();x++)
	{
		ret *= 10;
		ret += (changer.at(x)-48);
	}
	return ret;
}

QString QButtonCoor::IntToString(int changer)
{
	QString ret = "", tempS = "";
	int temp;
	while(changer != 0)
	{
		temp = changer%10;
		changer /= 10;
		tempS += (temp + 48);
	}
	for(int x = tempS.size()-1; x >= 0; x--)
		ret += tempS.at(x);
	return ret;
}
