#pragma once
#include <ctime>

class Timer
{
public:
	Timer(double time_scale);
	double Tick();

private:
	clock_t last_time;
	const double TIME_SCALE;
};

