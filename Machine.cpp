#include "Machine.h"

int Machine::leftTime()
{
    return left_time;
}

int Machine::process()
{
    return processing;
}

void Machine::nextTime()
{
    if(left_time > 0)
        left_time--;
}

void Machine::nextWP(int time)
{
    processing++;
    left_time = time;
}

void Machine::reset()
{
    processing = -1;
    left_time = 0;
}
