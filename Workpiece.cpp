#include "Workpiece.h"

int Workpiece::beingPro()
{
	return being_processed;
}

int Workpiece::leftTime()
{
	return left_time;
}

void Workpiece::nextTime()
{
	if (left_time > 0)
		left_time--;
}

void Workpiece::nextMachine(int time)
{
	being_processed++;
	left_time = time;
}

void Workpiece::reset()
{
	being_processed = -1;
	left_time = 0;
}
