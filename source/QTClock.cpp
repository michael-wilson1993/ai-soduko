#include "QTClock.h"

QTClock::QTClock(bool timeTracker, int miliseconds, QWidget *parent): QWidget(parent)
{
	timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(ClockLoop()));
	timer->start(miliseconds);
	count = 1;
	iterationTime = miliseconds;
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

void QTClock::reset()
{
	count = 0;
}
