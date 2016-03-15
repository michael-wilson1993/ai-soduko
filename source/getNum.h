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
	getNum(QWidget *parent = 0);
	~getNum();
	void setCoor(int xx, int yy) {x=xx;y=yy;};

signals:
	void sendInfo(const int &xx, const int &yy, const int &val);

private slots:
	void sendInfoSlot(const int &xx, const int &yy);


private:
	int x, y, value;
	QButtonCoor *nums[3][3];

};