/*
	- Michael Wilson
	- QTClock.h
	- Human Computer Interaction
	- prof: Wendy Osborn
	- march 11/16
*/

#pragma once
#include "GHeader.h"


class QTClock: public QWidget
{
	Q_OBJECT
public:
	QTClock(bool timeTracker = false, int miliseconds = 1000, QWidget *parent = 0);
	~QTClock();
	public slots:
	void reset();

	private slots:
	void ClockLoop();

	signals:
	void tick(const int &info);

private:

	//timer for the clock base
QTimer *timer;
int count;
int iterationTime;
bool keepTrack;



};