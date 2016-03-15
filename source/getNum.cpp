#include "getNum.h"

getNum::getNum(QWidget *parent) : QDialog(parent)
{
	setStyleSheet("background-color: #000000");
	setWindowFlags(Qt::Popup);
	for(int x = 0; x < 3; x++)
		for(int y = 0; y < 3; y++)
		{
			nums[x][y] = new QButtonCoor(x,y);
			nums[x][y]->setVal((x+1)+(y*3)); // fix values
			nums[x][y]->setTextFromInt((x+1)+(y*3));
			nums[x][y]->setStyleSheet("background-color: #FFFFFF");
			connect(nums[x][y], SIGNAL(sendingCoor(const int &, const int &)), this, SLOT(sendInfoSlot(const int &, const int &)));

		}

	// creates a grid for the window
	QGridLayout *gridLayout = new QGridLayout;
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			gridLayout->addWidget(nums[x][y], y,x,1,1);
		}
	}
	setLayout(gridLayout);
}

getNum::~getNum()
{

}

void getNum::sendInfoSlot(const int &xx, const int &yy)
{
	int num = nums[xx][yy]->val;
	emit sendInfo(x,y,num);
}