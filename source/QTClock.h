/*
	- Michael Wilson
	- QTClock.h
	- AI 
	- prof: Yllias Chali
*/
#pragma once
#include "GHeader.h"


class QTClock: public QWidget
{
	Q_OBJECT// makes this item a QOBJECT
public:
	//constructor that starts the timer
	QTClock(bool timeTracker = false, int miliseconds = 1000, QWidget *parent = 0);
	//destructor
	~QTClock();
	public slots:
	// slot the starts a single loop of 1 second
	void SingleClockLoop();
	// sends the info by emitting tick
	void singleSendInfo();
	//reset will reset the clock
	void reset();

	private slots:
	//ClockLoop is a slot to emit tick to the program
	void ClockLoop();

	signals:
	// tick is a signal that gets sent every milisecond that is specified in the constructor
	void tick(const int &info);

private:

	//timer for the clock base
QTimer *timer;
// count is the amount of loops that this clock has gone through
int count;
// iterationTime is the amount of time between each tick. how fast the clock will loop
int iterationTime;
// keepTrack will determine whether the program wants to keep track of the amout of loops that have occured
bool keepTrack;



};