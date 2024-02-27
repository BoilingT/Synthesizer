#include "Wave.h"
#include <math.h>

double Wave::value(double amplitude, double frequency, double time)
{
	//y(t) = A * sin(f * (t - c))
	return amplitude * sin(2 * 3.14f * frequency * time);
}
