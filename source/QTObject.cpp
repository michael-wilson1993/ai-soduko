#include "QTObject.h"

QTObject::QTObject(int r,int g, int b, bool con, bool fill, QString textStr, int SX, int SY) : red(r), green(g), blue(b), solid(fill), connect(con)
{
	if(textStr.size() > 0)
	{
		textString = textStr;
		text = true;
		shapes.push_back(coor(SX,SY));
	}
	else
	{
		text =false;
	}
}

QTObject::~QTObject()
{
	//delet pointers if needed.
}