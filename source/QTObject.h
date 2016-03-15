/*
	- Michael Wilson
	- QTOcject.h
	- AI 
	- prof: Yllias Chali
*/

#pragma once
#include "GHeader.h"
#include <ctime>
#include <iostream>

// helper struck to contain coordinates easier
struct coor
{
	coor(int xx,int yy) {x = xx; y= yy;};
	int x,y; // basicly a pair of integers
};

class QTObject
{
public:
	// QTObject is the constructor
	//rgb are the RGB valuse
	// fill determines weather or not to fill the object with color
	// textSTr sx sy are a string and coordinates where to put that string on the screen
	QTObject(int r=255,int g=255, int b = 255, bool con = false, bool fill = false, QString textStr = "", int SX = 0, int SY = 0);
	// destructor
	~QTObject();
	// nextCoor sets the next coordinate in the shapes vector
	void nextCoor(int x, int y) {shapes.push_back(coor(x,y));};
	//setwater was a value determining if the object is water (this was for a different project)
	void setWater() {iswater = true;};
	// red green blue are the ints that hold the RGB values
	int red, green, blue;
	// this will make the initial shape
	std::vector< coor > shapes;
	//solid is if the shape is filled in with a colour
	// connect is if the shapes last and first coordinate are connected...
	bool solid, connect, text;
	// determines whether or not this object is water
	bool iswater;
	// the textString that needs to be displayed
	QString textString;
};