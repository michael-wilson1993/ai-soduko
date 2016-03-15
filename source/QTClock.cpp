#include "QTClock.h"

QTClock::QTClock(bool timeTracker, int miliseconds, QWidget *parent): QWidget(parent)
{


	timer = new QTimer();
	
	if(miliseconds > 0)
	{
		connect(timer, SIGNAL(timeout()), this, SLOT(ClockLoop()));
		iterationTime = miliseconds;
		timer->start(miliseconds);
	}
	else
	{
		connect(timer, SIGNAL(timeout()), this, SLOT(singleSendInfo()));
		iterationTime = 1000;
	}
	count = 1;
	
	keepTrack = timeTracker;

}
QTClock::~QTClock()
{
	std::cerr << "QTClock.h : deleted timer"<< std::endl;
	delete timer;
	std::cerr << "QTClock.h : deleted timer - success "<< std::endl;
}
void QTClock::ClockLoop()
{
	// counts and sets timer to one second intervals
	timer->start(iterationTime);
	if (keepTrack)
		count++;
	emit tick(count);
}
void QTClock::SingleClockLoop()
{
	timer->start(iterationTime);
}

void QTClock::singleSendInfo()
{
	emit tick(count);
}

void QTClock::reset()
{
	count = 0;
}
