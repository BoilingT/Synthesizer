#include "Wave.h"
#include <math.h>

double Wave::sine(double amplitude, double frequency, double time, double phase)
{
	//y(t) = A * sin(f * (t - c))
	return amplitude * sin(MATH_DOUBLE_PI * frequency * (time - phase));
}

double Wave::triangle(double amplitude, double frequency, double time, double phase)
{
	return 0.0;
}

double Wave::square(double amplitude, double frequency, double time, double phase)
{
	return 0.0;
}

double Wave::sawtooth(double amplitude, double frequency, double time, double phase)
{
	return 0.0;
}
