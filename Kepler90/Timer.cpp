#include "Timer.h"
#include <ctime>


Timer::Timer(double time_scale) : TIME_SCALE(time_scale)
{
	last_time = clock();
}

double Timer::Tick()
{
	clock_t current_time = clock();
	double elapsed = (double)(current_time - last_time) / (CLOCKS_PER_SEC / TIME_SCALE);
	last_time = current_time;
	return elapsed;
}

